// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


//======================

void VNFALU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VNFALU::traceChgThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
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

void VNFALU::traceChgThis__2(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->NFALU__DOT__xorSign));
        vcdp->chgBus(c+9,(vlTOPp->NFALU__DOT__resFrac),23);
        vcdp->chgBus(c+17,(vlTOPp->NFALU__DOT__resExp),8);
        vcdp->chgBus(c+25,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_48))),24);
        vcdp->chgBus(c+33,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_48))),23);
        vcdp->chgBus(c+41,(vlTOPp->NFALU__DOT__temExp),8);
    }
}

void VNFALU::traceChgThis__3(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+49,(vlTOPp->clock));
        vcdp->chgBit(c+57,(vlTOPp->reset));
        vcdp->chgBus(c+65,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+73,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+81,(vlTOPp->io_aluCtl),4);
        vcdp->chgBus(c+89,(vlTOPp->io_rmm),3);
        vcdp->chgBus(c+97,(vlTOPp->io_result),32);
        vcdp->chgBit(c+105,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->chgBit(c+113,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->chgBus(c+121,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+129,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+137,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBit(c+145,((1U & ((vlTOPp->io_input1 
                                    & vlTOPp->io_input2) 
                                   >> 0x1fU))));
    }
}
