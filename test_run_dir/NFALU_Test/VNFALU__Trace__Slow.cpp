// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


//======================

void VNFALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VNFALU::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VNFALU::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VNFALU::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VNFALU::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+8,"clock", false,-1);
        tracep->declBit(c+9,"reset", false,-1);
        tracep->declBus(c+10,"io_input1", false,-1, 31,0);
        tracep->declBus(c+11,"io_input2", false,-1, 31,0);
        tracep->declBus(c+12,"io_aluCtl", false,-1, 3,0);
        tracep->declBus(c+13,"io_rmm", false,-1, 2,0);
        tracep->declBus(c+14,"io_result", false,-1, 31,0);
        tracep->declBit(c+8,"NFALU clock", false,-1);
        tracep->declBit(c+9,"NFALU reset", false,-1);
        tracep->declBus(c+10,"NFALU io_input1", false,-1, 31,0);
        tracep->declBus(c+11,"NFALU io_input2", false,-1, 31,0);
        tracep->declBus(c+12,"NFALU io_aluCtl", false,-1, 3,0);
        tracep->declBus(c+13,"NFALU io_rmm", false,-1, 2,0);
        tracep->declBus(c+14,"NFALU io_result", false,-1, 31,0);
        tracep->declBit(c+15,"NFALU signBitIn1", false,-1);
        tracep->declBit(c+16,"NFALU signBitIn2", false,-1);
        tracep->declBus(c+17,"NFALU expBitIn1", false,-1, 7,0);
        tracep->declBus(c+18,"NFALU fracBitIn1", false,-1, 22,0);
        tracep->declBus(c+19,"NFALU fracBitIn2", false,-1, 22,0);
        tracep->declBit(c+1,"NFALU xorSign", false,-1);
        tracep->declBit(c+20,"NFALU andSign", false,-1);
        tracep->declBus(c+2,"NFALU resFrac", false,-1, 23,0);
        tracep->declBus(c+3,"NFALU resExp", false,-1, 7,0);
        tracep->declBus(c+4,"NFALU temFrac", false,-1, 23,0);
        tracep->declBus(c+5,"NFALU io_result_lo", false,-1, 22,0);
        tracep->declBus(c+6,"NFALU temExp", false,-1, 7,0);
        tracep->declBus(c+7,"NFALU io_result_lo_2", false,-1, 22,0);
    }
}

void VNFALU::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VNFALU::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VNFALU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->NFALU__DOT__xorSign));
        tracep->fullIData(oldp+2,(vlTOPp->NFALU__DOT__resFrac),24);
        tracep->fullCData(oldp+3,(vlTOPp->NFALU__DOT__resExp),8);
        tracep->fullIData(oldp+4,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_50))),24);
        tracep->fullIData(oldp+5,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_50))),23);
        tracep->fullCData(oldp+6,(vlTOPp->NFALU__DOT__temExp),8);
        tracep->fullIData(oldp+7,((0x7fffffU & vlTOPp->NFALU__DOT__resFrac)),23);
        tracep->fullBit(oldp+8,(vlTOPp->clock));
        tracep->fullBit(oldp+9,(vlTOPp->reset));
        tracep->fullIData(oldp+10,(vlTOPp->io_input1),32);
        tracep->fullIData(oldp+11,(vlTOPp->io_input2),32);
        tracep->fullCData(oldp+12,(vlTOPp->io_aluCtl),4);
        tracep->fullCData(oldp+13,(vlTOPp->io_rmm),3);
        tracep->fullIData(oldp+14,(vlTOPp->io_result),32);
        tracep->fullBit(oldp+15,((1U & (vlTOPp->io_input1 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+16,((1U & (vlTOPp->io_input2 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+17,((0xffU & (vlTOPp->io_input1 
                                             >> 0x17U))),8);
        tracep->fullIData(oldp+18,((0x7fffffU & vlTOPp->io_input1)),23);
        tracep->fullIData(oldp+19,((0x7fffffU & vlTOPp->io_input2)),23);
        tracep->fullBit(oldp+20,((1U & ((vlTOPp->io_input1 
                                         & vlTOPp->io_input2) 
                                        >> 0x1fU))));
    }
}
