#include "server.h"


static ConnectionParameters connectionParameters;
static void param(Slave self)
{
connectionParameters = Slave_getConnectionParameters(self);	
};

void slaveCreate(ConnectionParameters connectionParameters,int Aarg1,int Aarg2)
{
	T104Slave_create(connectionParameters, Aarg1, Aarg2);
};	


/*void clock(Slave self)
{
	Slave_setClockSyncHandler(self, clockSyncHandler, NULL);
};
*/
bool
clockSyncHandler (void* parameter, MasterConnection connection, ASDU asdu, CP56Time2a newTime)
{
    printf("Process time sync command with time "); printf("\n");

    printf("%02i:%02i:%02i %02i/%02i/%04i", CP56Time2a_getHour(newTime),
                             CP56Time2a_getMinute(newTime),
                             CP56Time2a_getSecond(newTime),
                             CP56Time2a_getDayOfMonth(newTime),
                             CP56Time2a_getMonth(newTime) + 1,
                             CP56Time2a_getYear(newTime) + 2000);
	printf("\n");
};

void serverz::setasduhandler(Slave self)
{
	Slave_setASDUHandler(self, serverz::asduHandlerz, NULL);
};

void interro(Slave self)
{
	Slave_setInterrogationHandler(self, interrogationHandler, NULL);
};

bool
interrogationHandler (void* parameter, MasterConnection connection, ASDU asdu,uint8_t qoi)
{
	printf("Received interrogation for groups %i\n", qoi);
	
    struct sCP56Time2a timestamp;
    CP56Time2a_createFromMsTimestamp(&timestamp, Hal_getTimeInMs());
    MasterConnection_sendACT_CON(connection, asdu, false);
    ASDU newAsdu = ASDU_create(connectionParameters, M_ME_NB_1, false, INTERROGATED_BY_STATION,
            0, 1, false, false);
    InformationObject io = (InformationObject) MeasuredValueScaled_create(NULL, 100, -1, IEC60870_QUALITY_GOOD);
    ASDU_addInformationObject(newAsdu, io);

    ASDU_addInformationObject(newAsdu, (InformationObject)
		MeasuredValueScaled_create((MeasuredValueScaled) io, 101, 23, IEC60870_QUALITY_GOOD));

    ASDU_addInformationObject(newAsdu, (InformationObject)
		MeasuredValueScaled_create((MeasuredValueScaled) io, 102, 2300, IEC60870_QUALITY_GOOD));

    InformationObject_destroy(io);

    MasterConnection_sendASDU(connection, newAsdu);

    newAsdu = ASDU_create(connectionParameters, M_SP_TB_1, false, INTERROGATED_BY_STATION,
                0, 1, false, false);

    io = (InformationObject) SinglePointWithCP56Time2a_create(NULL, 104, true, IEC60870_QUALITY_GOOD, &timestamp);

    ASDU_addInformationObject(newAsdu, io);

    ASDU_addInformationObject(newAsdu, (InformationObject)
		SinglePointWithCP56Time2a_create((SinglePointWithCP56Time2a) io, 105, false, IEC60870_QUALITY_GOOD, &timestamp));

    InformationObject_destroy(io);

    MasterConnection_sendASDU(connection, newAsdu);


    newAsdu = ASDU_create(connectionParameters, M_IT_TB_1, false, INTERROGATED_BY_STATION,
                0, 1, false, false);

    BinaryCounterReading bcr = BinaryCounterReading_create(NULL, 12345678, 0, false, false, true);

    io = (InformationObject) IntegratedTotalsWithCP56Time2a_create(NULL, 200, bcr, &timestamp);

    ASDU_addInformationObject(newAsdu, io);

    BinaryCounterReading_destroy(bcr);

    InformationObject_destroy(io);

    MasterConnection_sendASDU(connection, newAsdu);

    newAsdu = ASDU_create(connectionParameters, M_SP_NA_1, true, INTERROGATED_BY_STATION,
            0, 1, false, false);

    ASDU_addInformationObject(newAsdu, io = (InformationObject) SinglePointInformation_create(NULL, 300, true, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 301, false, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 302, true, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 303, false, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 304, true, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 305, false, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 306, true, IEC60870_QUALITY_GOOD));
    ASDU_addInformationObject(newAsdu, (InformationObject) SinglePointInformation_create((SinglePointInformation) io, 307, false, IEC60870_QUALITY_GOOD));

    InformationObject_destroy(io);

    MasterConnection_sendASDU(connection, newAsdu);

    MasterConnection_sendACT_TERM(connection, asdu);

    return true;
};

bool
serverz::asduHandlerz(void* parameter, MasterConnection connection, ASDU asdu)
{
	
    if (ASDU_getTypeID(asdu) == C_SC_NA_1) {
        printf("received single command\n");

        if  (ASDU_getCOT(asdu) == ACTIVATION) {
            InformationObject io = ASDU_getElement(asdu, 0);

            if (InformationObject_getObjectAddress(io) == 5000) {
                SingleCommand sc = (SingleCommand) io;

                printf("IOA: %i switch to %i\n", InformationObject_getObjectAddress(io),
                        SingleCommand_getState(sc));

                ASDU_setCOT(asdu, ACTIVATION_CON);
            }
            else
                ASDU_setCOT(asdu, UNKNOWN_INFORMATION_OBJECT_ADDRESS);

            InformationObject_destroy(io);
        }
        else
            ASDU_setCOT(asdu, UNKNOWN_CAUSE_OF_TRANSMISSION);

        MasterConnection_sendASDU(connection, asdu);

        return true;
    }

    return false;
};
