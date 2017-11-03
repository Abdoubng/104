#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include "iec60870_slave.h"
#include "hal_thread.h"
#include "hal_time.h"

#ifndef SERVER_H
#define SERVER_H


class serverz
{
	public:
serverz();


//void clock(Slave self);


/*static bool
clockSyncHandler (void* parameter, MasterConnection connection, ASDU asdu, CP56Time2a newTime);


static void setasduhandler(Slave self);


static bool
interrogationHandler (void* parameter, MasterConnection connection, ASDU asdu,uint8_t qoi);
*/

	
static bool
asduHandlerz(void* parameter, MasterConnection connection, ASDU asdu);

static void param(Slave self);



~serverz();

	
private:
void* parameter;
MasterConnection connection;
ASDU asdu;
};
#endif
