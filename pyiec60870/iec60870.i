/* File : iec60870.i */
%module iec60870
/*%module(directors="1") callbacks*/ 
%include "stdint.i"
%ignore T104Slave_createSecure;
%{
#include "iec60870_master.h"
#include "iec60870_common.h"
#include "iec60870_slave.h"
#include "information_objects.h"
#include "callbacks.h"

%}
%include "iec60870_master.h"
%include "iec60870_common.h"
%include "iec60870_slave.h"
/*%feature("director") Callback;*/
%include "information_objects.h"
%include "callbacks.h"

