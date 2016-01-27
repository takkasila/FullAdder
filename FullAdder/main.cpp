#include "systemc.h"
#include "FADDER.h"

int sc_main(int argc, char* argv [])
{
	FA2 fa2("fa2");

	sc_signal<bool> inA0, inA1, inB0, inB1, inCI;
	sc_signal<bool> outCO, outSUM0, outSUM1;

	fa2.a0(inA0);
	fa2.a1(inA1);
	fa2.b0(inB0);
	fa2.b1(inB1);
	fa2.CI(inCI);

	fa2.CO(outCO);
	fa2.sum0(outSUM0);
	fa2.sum1(outSUM1);

	sc_trace_file *res = sc_create_vcd_trace_file("FA2");
	sc_trace(res, inA0, "A0");
	sc_trace(res, inA1, "A1");
	sc_trace(res, inB0, "B0");
	sc_trace(res, inB1, "B1");
	sc_trace(res, inCI, "CI");
	sc_trace(res, outCO, "CO");
	sc_trace(res, outSUM0, "SUM0");
	sc_trace(res, outSUM1, "SUM1");

	for (int f1 = 0; f1 < 2; f1++)
	for (int f2 = 0; f2 < 2; f2++)
	for (int f3 = 0; f3 < 2; f3++)
	for (int f4 = 0; f4 < 2; f4++)
	for (int f5 = 0; f5 < 2; f5++)
	{
		inCI = f1;
		inA0 = f2;
		inA1 = f3;
		inB0 = f4;
		inB1 = f5;
		sc_start(1, SC_NS);
	}

	inCI = 0;
	inA0 = 1;
	inA1 = 0;
	inB0 = 1;
	inB1 = 0;
	sc_start(1, SC_NS);

	sc_close_vcd_trace_file(res);
	return 0;
}