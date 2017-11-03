#!/usr/bin/python
import sys
import time
import iec60870
import threading
import traceback
import signal


def signal_handler(signal, frame):
	global running
	running =0
	print('You pressed Ctrl+C!')
	#sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)

running = 1

class pCallback(iec60870.Callback):
    def __init__(self):
        iec60870.Callback.__init__(self)
    def clockSyncHandler(self):
        print "callback described in Python and passed through C++ to C"
class Slave(iec60870.Callback):
	def __init__(self):
		self._slave=iec60870.T104Slave_create(None, 100, 102)
                #connectionparam=iec60870.Slave_getConnectionParameters(self._slave)
		slave = self._slave
		#iec60870.interro(slave)
		#iec60870.clock(slave)
		iec60870.Slave_start(self._slave)
		print slave
		time.sleep(1)
		#print (type(self._slave))
                 
        def run(self, param, connection, asdu, newTime):
            print newTime
            print "run callback described in Python and passed through C++ to C"
        def clocksync(self):
           iec60870.Slave_setClockSyncHandler(self._slave, self.run(), None)   
           print "stantan"
        def start(self):
		global running
		while running:
			#connectionparam=iec60870.Slave_getConnectionParameters(self._slave)
			
			#iec60870.Slave_setInterrogationHandler(self._slave,iec60870.interrogationHandler, None)
			
			"""aAsdu = iec60870.ASDU_create(connectionparam, iec60870.M_ME_NB_1, False, iec60870.PERIODIC, 0, 1, False, False)
			connectionparam=iec60870.Slave_getConnectionParameters(self._slave)

        	io = iec60870.InformationObject(iec60870.MeasuredValueScaled_create(None, 110, 2, iec60870.IEC60870_QUALITY_GOOD))
        	iec60870.ASDU_addInformationObject(aAsdu, io)
        	iec60870.Slave_enqueueASDU(self._slave, aAsdu)"""
        	time.sleep(0.5)

		
	def stop(self):
		print 2	

def main():
#        cal=pCallback()
        Sslave=Slave()

       
        Sslave.clocksync()
	Sslave.start()
if __name__== "__main__":
    main()

	



