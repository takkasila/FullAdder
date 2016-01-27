#ifndef FADDERGATE
#define FADDERGATE

#include "systemc.h"
#include "AND.h"
#include "OR.h"
#include "NOR.h"
#include "Not.h"

SC_MODULE(FA1) 
{
	OR2  or1, or8;
	OR3  or2;
	AND2 and3, and4, and5;
	AND3 and6;
	NOR2 nor7;
	NOT  inv9;

	sc_in<bool> A, B, CI;
	sc_out<bool> CO, SUM;

	sc_signal<bool>     or_1;
	sc_signal<bool>     or_2;
	sc_signal<bool>     and_3;
	sc_signal<bool>     and_4;
	sc_signal<bool>     and_5;
	sc_signal<bool>     and_6;
	sc_signal<bool>     nor_7;
	
	SC_CTOR(FA1): or1("or1"), or8("or8")
	, or2("or2")
	, and3("and3"), and4("and4"), and5("and5")
	, and6("and6")
	, nor7("nor7")
	, inv9("inv9")
	{
		or1.a(A); or1.b(B); or1.o(or_1);
		or2.a(A); or2.b(B); or2.c(CI); or2.o(or_2);
		and3.a(or_1); and3.b(CI); and3.o(and_3);
		and4.a(A); and4.b(B); and4.o(and_4);
		and5.a(nor_7); and5.b(or_2); and5.o(and_5);
		and6.a(A); and6.b(B); and6.c(CI); and6.o(and_6);
		nor7.a(and_3); nor7.b(and_4); nor7.o(nor_7);
		or8.a(and_5); or8.b(and_6); or8.o(SUM);
		inv9.a(nor_7); inv9.o(CO);
	}
};

SC_MODULE(FA2)
{
	FA1 fad1_1, fad1_2;

	sc_in<bool> a0, a1, b0, b1, CI;
	sc_out<bool> sum0, sum1, CO;

	sc_signal<bool> c_temp;

	SC_CTOR(FA2) : fad1_1("fad1_1"), fad1_2("fad1_2")
	{
		fad1_1.A(a0);
		fad1_1.B(b0);
		fad1_1.CI(CI);
		fad1_1.CO(c_temp);
		fad1_1.SUM(sum0);

		fad1_2.A(a1);
		fad1_2.B(b1);
		fad1_2.CI(c_temp);
		fad1_2.CO(CO);
		fad1_2.SUM(sum1);
	}
};



#endif