#include "iostream"
#include "../src/inc/api/iec60870_slave.h"
#include "../src/inc/api/iec60870_common.h"


class Callback {
	public:
			virtual ~Callback() { std::cout << "Callback::~Callback()" << std:: endl; }
			virtual void run(void* parameter, MasterConnection connection, ASDU asdu, sCP56Time2a) { std::cout << "Callback::run()" << std::endl;
		       	}
};









