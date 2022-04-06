// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


//======================

void VNFALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VNFALU::traceInit, &VNFALU::traceFull, &VNFALU::traceChg, this);
}
void VNFALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VNFALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VNFALU* t = (VNFALU*)userthis;
    VNFALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VNFALU::traceInitThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VNFALU::traceFullThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VNFALU::traceInitThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+49,"clock", false,-1);
        vcdp->declBit(c+57,"reset", false,-1);
        vcdp->declBus(c+65,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+73,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+81,"io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+89,"io_rmm", false,-1, 2,0);
        vcdp->declBus(c+97,"io_result", false,-1, 31,0);
        vcdp->declBit(c+49,"NFALU clock", false,-1);
        vcdp->declBit(c+57,"NFALU reset", false,-1);
        vcdp->declBus(c+65,"NFALU io_input1", false,-1, 31,0);
        vcdp->declBus(c+73,"NFALU io_input2", false,-1, 31,0);
        vcdp->declBus(c+81,"NFALU io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+89,"NFALU io_rmm", false,-1, 2,0);
        vcdp->declBus(c+97,"NFALU io_result", false,-1, 31,0);
        vcdp->declBit(c+105,"NFALU signBitIn1", false,-1);
        vcdp->declBit(c+113,"NFALU signBitIn2", false,-1);
        vcdp->declBus(c+121,"NFALU expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+129,"NFALU fracBitIn1", false,-1, 22,0);
        vcdp->declBus(c+137,"NFALU fracBitIn2", false,-1, 22,0);
        vcdp->declBit(c+1,"NFALU xorSign", false,-1);
        vcdp->declBit(c+145,"NFALU andSign", false,-1);
        vcdp->declBus(c+9,"NFALU resFrac", false,-1, 22,0);
        vcdp->declBus(c+17,"NFALU resExp", false,-1, 7,0);
        vcdp->declBus(c+25,"NFALU temFrac", false,-1, 23,0);
        vcdp->declBus(c+33,"NFALU io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+41,"NFALU temExp", false,-1, 7,0);
    }
}

void VNFALU::traceFullThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->NFALU__DOT__xorSign));
        vcdp->fullBus(c+9,(vlTOPp->NFALU__DOT__resFrac),23);
        vcdp->fullBus(c+17,(vlTOPp->NFALU__DOT__resExp),8);
        vcdp->fullBus(c+25,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_48))),24);
        vcdp->fullBus(c+33,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_48))),23);
        vcdp->fullBus(c+41,(vlTOPp->NFALU__DOT__temExp),8);
        vcdp->fullBit(c+49,(vlTOPp->clock));
        vcdp->fullBit(c+57,(vlTOPp->reset));
        vcdp->fullBus(c+65,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+73,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+81,(vlTOPp->io_aluCtl),4);
        vcdp->fullBus(c+89,(vlTOPp->io_rmm),3);
        vcdp->fullBus(c+97,(vlTOPp->io_result),32);
        vcdp->fullBit(c+105,((1U & (vlTOPp->io_input1 
                                    >> 0x1fU))));
        vcdp->fullBit(c+113,((1U & (vlTOPp->io_input2 
                                    >> 0x1fU))));
        vcdp->fullBus(c+121,((0xffU & (vlTOPp->io_input1 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+129,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+137,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBit(c+145,((1U & ((vlTOPp->io_input1 
                                     & vlTOPp->io_input2) 
                                    >> 0x1fU))));
    }
}
