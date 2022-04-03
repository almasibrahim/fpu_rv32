// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


//======================

void VFALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VFALU::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VFALU::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VFALU::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VFALU::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+7,"clock", false,-1);
        tracep->declBit(c+8,"reset", false,-1);
        tracep->declBus(c+9,"io_input1", false,-1, 31,0);
        tracep->declBus(c+10,"io_input2", false,-1, 31,0);
        tracep->declBus(c+11,"io_aluCtl", false,-1, 3,0);
        tracep->declBus(c+12,"io_rmm", false,-1, 2,0);
        tracep->declBus(c+13,"io_result", false,-1, 31,0);
        tracep->declBit(c+7,"FALU clock", false,-1);
        tracep->declBit(c+8,"FALU reset", false,-1);
        tracep->declBus(c+9,"FALU io_input1", false,-1, 31,0);
        tracep->declBus(c+10,"FALU io_input2", false,-1, 31,0);
        tracep->declBus(c+11,"FALU io_aluCtl", false,-1, 3,0);
        tracep->declBus(c+12,"FALU io_rmm", false,-1, 2,0);
        tracep->declBus(c+13,"FALU io_result", false,-1, 31,0);
        tracep->declBit(c+14,"FALU signBitIn1", false,-1);
        tracep->declBit(c+15,"FALU signBitIn2", false,-1);
        tracep->declBus(c+16,"FALU expBitIn1", false,-1, 7,0);
        tracep->declBus(c+17,"FALU fracBitIn1", false,-1, 22,0);
        tracep->declBus(c+18,"FALU fracBitIn2", false,-1, 22,0);
        tracep->declBus(c+1,"FALU extraRes", false,-1, 23,0);
        tracep->declBus(c+2,"FALU res_lo", false,-1, 22,0);
        tracep->declBus(c+3,"FALU res", false,-1, 23,0);
        tracep->declBus(c+4,"FALU resSignBit", false,-1, 1,0);
        tracep->declBus(c+19,"FALU expP1", false,-1, 7,0);
        tracep->declBit(c+5,"FALU io_result_hi_hi", false,-1);
        tracep->declBus(c+6,"FALU io_result_lo", false,-1, 22,0);
    }
}

void VFALU::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VFALU::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VFALU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->FALU__DOT__extraRes),24);
        tracep->fullIData(oldp+2,((0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
                                                >> 1U))),23);
        tracep->fullIData(oldp+3,(vlTOPp->FALU__DOT__res),24);
        tracep->fullCData(oldp+4,((3U & (vlTOPp->FALU__DOT__res 
                                         >> 0x16U))),2);
        tracep->fullBit(oldp+5,((1U & (vlTOPp->FALU__DOT__res 
                                       >> 0x17U))));
        tracep->fullIData(oldp+6,((0x7fffffU & vlTOPp->FALU__DOT__res)),23);
        tracep->fullBit(oldp+7,(vlTOPp->clock));
        tracep->fullBit(oldp+8,(vlTOPp->reset));
        tracep->fullIData(oldp+9,(vlTOPp->io_input1),32);
        tracep->fullIData(oldp+10,(vlTOPp->io_input2),32);
        tracep->fullCData(oldp+11,(vlTOPp->io_aluCtl),4);
        tracep->fullCData(oldp+12,(vlTOPp->io_rmm),3);
        tracep->fullIData(oldp+13,(vlTOPp->io_result),32);
        tracep->fullBit(oldp+14,((1U & (vlTOPp->io_input1 
                                        >> 0x1fU))));
        tracep->fullBit(oldp+15,((1U & (vlTOPp->io_input2 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+16,((0xffU & (vlTOPp->io_input1 
                                             >> 0x17U))),8);
        tracep->fullIData(oldp+17,((0x7fffffU & vlTOPp->io_input1)),23);
        tracep->fullIData(oldp+18,((0x7fffffU & vlTOPp->io_input2)),23);
        tracep->fullCData(oldp+19,((0xffU & ((IData)(1U) 
                                             + (vlTOPp->io_input1 
                                                >> 0x17U)))),8);
    }
}
