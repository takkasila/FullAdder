#ifndef NOTGATE
#define NOTGATE
#include "systemc.h"

SC_MODULE(NOT)
{
	sc_in<bool> a;
	sc_out<bool> o;

	SC_CTOR(NOT)
	{
		SC_METHOD(not_process);
		sensitive << a;
	}

	void not_process()
	{
		o.write(!a.read());
	}
};
#endif