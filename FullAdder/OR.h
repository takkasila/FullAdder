#ifndef ORGATE
#define ORGATE
#include "systemc.h"

SC_MODULE(OR2)
{
	sc_in<bool> a, b;
	sc_out<bool> o;
	SC_CTOR(OR2)
	{
		SC_METHOD(or_process);
		sensitive << a << b;
	}
	void or_process()
	{
		o.write(a.read() || b.read());
	}
};

SC_MODULE(OR3)
{
	sc_in<bool> a, b, c;
	sc_out<bool> o;
	SC_CTOR(OR3)
	{
		SC_METHOD(or_process);
		sensitive << a << b << c;
	}

	void or_process()
	{
		o.write(a.read() || b.read() || c.read());
	}
};

#endif