// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFALU__Syms.h"


void VFALU::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VFALU::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->FALU__DOT__extraRes),24);
            tracep->chgIData(oldp+1,((0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
                                                   >> 1U))),23);
            tracep->chgIData(oldp+2,(vlTOPp->FALU__DOT__res),24);
            tracep->chgCData(oldp+3,((3U & (vlTOPp->FALU__DOT__res 
                                            >> 0x16U))),2);
            tracep->chgBit(oldp+4,((1U & (vlTOPp->FALU__DOT__res 
                                          >> 0x17U))));
            tracep->chgIData(oldp+5,((0x7fffffU & vlTOPp->FALU__DOT__res)),23);
        }
        tracep->chgBit(oldp+6,(vlTOPp->clock));
        tracep->chgBit(oldp+7,(vlTOPp->reset));
        tracep->chgIData(oldp+8,(vlTOPp->io_input1),32);
        tracep->chgIData(oldp+9,(vlTOPp->io_input2),32);
        tracep->chgCData(oldp+10,(vlTOPp->io_aluCtl),4);
        tracep->chgCData(oldp+11,(vlTOPp->io_rmm),3);
        tracep->chgIData(oldp+12,(vlTOPp->io_result),32);
        tracep->chgBit(oldp+13,((1U & (vlTOPp->io_input1 
                                       >> 0x1fU))));
        tracep->chgBit(oldp+14,((1U & (vlTOPp->io_input2 
                                       >> 0x1fU))));
        tracep->chgCData(oldp+15,((0xffU & (vlTOPp->io_input1 
                                            >> 0x17U))),8);
        tracep->chgIData(oldp+16,((0x7fffffU & vlTOPp->io_input1)),23);
        tracep->chgIData(oldp+17,((0x7fffffU & vlTOPp->io_input2)),23);
        tracep->chgCData(oldp+18,((0xffU & ((IData)(1U) 
                                            + (vlTOPp->io_input1 
                                               >> 0x17U)))),8);
    }
}

void VFALU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VFALU__Syms* __restrict vlSymsp = static_cast<VFALU__Syms*>(userp);
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
