// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


//======================

void VFALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFALU* t=(VFALU*)userthis;
    VFALU__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VFALU::traceChgThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFALU::traceChgThis__2(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->FALU__DOT__extraRes),24);
	vcdp->chgBus  (c+2,((0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
					  >> 1U))),23);
	vcdp->chgBus  (c+3,(vlTOPp->FALU__DOT__res),24);
	vcdp->chgBus  (c+4,((3U & (vlTOPp->FALU__DOT__res 
				   >> 0x16U))),2);
	vcdp->chgBit  (c+5,((1U & (vlTOPp->FALU__DOT__res 
				   >> 0x17U))));
	vcdp->chgBus  (c+6,((0x7fffffU & vlTOPp->FALU__DOT__res)),23);
    }
}

void VFALU::traceChgThis__3(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+7,(vlTOPp->clock));
	vcdp->chgBit  (c+8,(vlTOPp->reset));
	vcdp->chgBus  (c+9,(vlTOPp->io_input1),32);
	vcdp->chgBus  (c+10,(vlTOPp->io_input2),32);
	vcdp->chgBus  (c+11,(vlTOPp->io_aluCtl),4);
	vcdp->chgBus  (c+12,(vlTOPp->io_rmm),3);
	vcdp->chgBus  (c+13,(vlTOPp->io_result),32);
	vcdp->chgBit  (c+14,((1U & (vlTOPp->io_input1 
				    >> 0x1fU))));
	vcdp->chgBit  (c+15,((1U & (vlTOPp->io_input2 
				    >> 0x1fU))));
	vcdp->chgBus  (c+16,((0xffU & (vlTOPp->io_input1 
				       >> 0x17U))),8);
	vcdp->chgBus  (c+17,((0x7fffffU & vlTOPp->io_input1)),23);
	vcdp->chgBus  (c+18,((0x7fffffU & vlTOPp->io_input2)),23);
	vcdp->chgBus  (c+19,((0xffU & ((IData)(1U) 
				       + (vlTOPp->io_input1 
					  >> 0x17U)))),8);
    }
}
