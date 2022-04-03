// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


//======================

void VFALU::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VFALU::traceInit, &VFALU::traceFull, &VFALU::traceChg, this);
}
void VFALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VFALU* t=(VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VFALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFALU* t=(VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VFALU::traceInitThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VFALU::traceFullThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFALU::traceInitThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+7,"clock",-1);
	vcdp->declBit  (c+8,"reset",-1);
	vcdp->declBus  (c+9,"io_input1",-1,31,0);
	vcdp->declBus  (c+10,"io_input2",-1,31,0);
	vcdp->declBus  (c+11,"io_aluCtl",-1,3,0);
	vcdp->declBus  (c+12,"io_rmm",-1,2,0);
	vcdp->declBus  (c+13,"io_result",-1,31,0);
	vcdp->declBit  (c+7,"FALU clock",-1);
	vcdp->declBit  (c+8,"FALU reset",-1);
	vcdp->declBus  (c+9,"FALU io_input1",-1,31,0);
	vcdp->declBus  (c+10,"FALU io_input2",-1,31,0);
	vcdp->declBus  (c+11,"FALU io_aluCtl",-1,3,0);
	vcdp->declBus  (c+12,"FALU io_rmm",-1,2,0);
	vcdp->declBus  (c+13,"FALU io_result",-1,31,0);
	vcdp->declBit  (c+14,"FALU signBitIn1",-1);
	vcdp->declBit  (c+15,"FALU signBitIn2",-1);
	vcdp->declBus  (c+16,"FALU expBitIn1",-1,7,0);
	vcdp->declBus  (c+17,"FALU fracBitIn1",-1,22,0);
	vcdp->declBus  (c+18,"FALU fracBitIn2",-1,22,0);
	// Tracing: FALU _extraRes_T // Ignored: Inlined leading underscore at FALU.v:15
	// Tracing: FALU _extraRes_T_1 // Ignored: Inlined leading underscore at FALU.v:16
	vcdp->declBus  (c+1,"FALU extraRes",-1,23,0);
	vcdp->declBus  (c+2,"FALU res_lo",-1,22,0);
	// Tracing: FALU _res_T_4 // Ignored: Inlined leading underscore at FALU.v:19
	// Tracing: FALU _res_T_8 // Ignored: Inlined leading underscore at FALU.v:20
	// Tracing: FALU _res_T_9 // Ignored: Inlined leading underscore at FALU.v:21
	// Tracing: FALU _res_T_12 // Ignored: Inlined leading underscore at FALU.v:22
	vcdp->declBus  (c+3,"FALU res",-1,23,0);
	vcdp->declBus  (c+4,"FALU resSignBit",-1,1,0);
	vcdp->declBus  (c+19,"FALU expP1",-1,7,0);
	// Tracing: FALU _io_result_T // Ignored: Inlined leading underscore at FALU.v:26
	vcdp->declBit  (c+5,"FALU io_result_hi_hi",-1);
	vcdp->declBus  (c+6,"FALU io_result_lo",-1,22,0);
	// Tracing: FALU _io_result_T_3 // Ignored: Inlined leading underscore at FALU.v:29
	// Tracing: FALU _io_result_T_13 // Ignored: Inlined leading underscore at FALU.v:30
	// Tracing: FALU _io_result_T_14 // Ignored: Inlined leading underscore at FALU.v:31
	// Tracing: FALU _io_result_T_15 // Ignored: Inlined leading underscore at FALU.v:32
	// Tracing: FALU _io_result_T_16 // Ignored: Inlined leading underscore at FALU.v:33
    }
}

void VFALU::traceFullThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->FALU__DOT__extraRes),24);
	vcdp->fullBus  (c+2,((0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
					   >> 1U))),23);
	vcdp->fullBus  (c+3,(vlTOPp->FALU__DOT__res),24);
	vcdp->fullBus  (c+4,((3U & (vlTOPp->FALU__DOT__res 
				    >> 0x16U))),2);
	vcdp->fullBit  (c+5,((1U & (vlTOPp->FALU__DOT__res 
				    >> 0x17U))));
	vcdp->fullBus  (c+6,((0x7fffffU & vlTOPp->FALU__DOT__res)),23);
	vcdp->fullBit  (c+7,(vlTOPp->clock));
	vcdp->fullBit  (c+8,(vlTOPp->reset));
	vcdp->fullBus  (c+9,(vlTOPp->io_input1),32);
	vcdp->fullBus  (c+10,(vlTOPp->io_input2),32);
	vcdp->fullBus  (c+11,(vlTOPp->io_aluCtl),4);
	vcdp->fullBus  (c+12,(vlTOPp->io_rmm),3);
	vcdp->fullBus  (c+13,(vlTOPp->io_result),32);
	vcdp->fullBit  (c+14,((1U & (vlTOPp->io_input1 
				     >> 0x1fU))));
	vcdp->fullBit  (c+15,((1U & (vlTOPp->io_input2 
				     >> 0x1fU))));
	vcdp->fullBus  (c+16,((0xffU & (vlTOPp->io_input1 
					>> 0x17U))),8);
	vcdp->fullBus  (c+17,((0x7fffffU & vlTOPp->io_input1)),23);
	vcdp->fullBus  (c+18,((0x7fffffU & vlTOPp->io_input2)),23);
	vcdp->fullBus  (c+19,((0xffU & ((IData)(1U) 
					+ (vlTOPp->io_input1 
					   >> 0x17U)))),8);
    }
}
