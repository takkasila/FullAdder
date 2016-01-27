#ifndef NORGATE
#define NORGATE

#include "systemc.h"
#include "OR.h"
#include "Not.h"
SC_MODULE(NOR2)
{
	NOT not1;
	OR2 or2;

	sc_in<bool> a, b;
	sc_out<bool> o;

	sc_signal<bool> or2_1;

	SC_CTOR(NOR2) : not1("not1"), or2("or2")
	{
		or2.a(a);
		or2.b(b);
		or2.o(or2_1);

		not1.a(or2_1);
		not1.o(o);
	}
};

#endif