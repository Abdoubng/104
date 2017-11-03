#include "iostream"

class Callback {
        public:
              virtual ~Callback() { std::cout << "Callback::~Callback()" << std:: endl; }
              virtual void run(*void parameter, void* parameter, MasterConnection connection, ASDU asdu, CP56Time2a newTime)
			      { std::cout << "Callback::run()" << std::endl; }
};









