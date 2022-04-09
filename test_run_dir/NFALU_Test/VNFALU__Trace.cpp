// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VNFALU__Syms.h"


void VNFALU::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VNFALU::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->NFALU__DOT__xorSign));
            tracep->chgIData(oldp+1,(vlTOPp->NFALU__DOT__resFrac),24);
            tracep->chgCData(oldp+2,(vlTOPp->NFALU__DOT__resExp),8);
            tracep->chgIData(oldp+3,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_50))),24);
            tracep->chgIData(oldp+4,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_50))),23);
            tracep->chgCData(oldp+5,(vlTOPp->NFALU__DOT__temExp),8);
            tracep->chgIData(oldp+6,((0x7fffffU & vlTOPp->NFALU__DOT__resFrac)),23);
        }
        tracep->chgBit(oldp+7,(vlTOPp->clock));
        tracep->chgBit(oldp+8,(vlTOPp->reset));
        tracep->chgIData(oldp+9,(vlTOPp->io_input1),32);
        tracep->chgIData(oldp+10,(vlTOPp->io_input2),32);
        tracep->chgCData(oldp+11,(vlTOPp->io_aluCtl),4);
        tracep->chgCData(oldp+12,(vlTOPp->io_rmm),3);
        tracep->chgIData(oldp+13,(vlTOPp->io_result),32);
        tracep->chgBit(oldp+14,((1U & (vlTOPp->io_input1 
                                       >> 0x1fU))));
        tracep->chgBit(oldp+15,((1U & (vlTOPp->io_input2 
                                       >> 0x1fU))));
        tracep->chgCData(oldp+16,((0xffU & (vlTOPp->io_input1 
                                            >> 0x17U))),8);
        tracep->chgIData(oldp+17,((0x7fffffU & vlTOPp->io_input1)),23);
        tracep->chgIData(oldp+18,((0x7fffffU & vlTOPp->io_input2)),23);
        tracep->chgBit(oldp+19,((1U & ((vlTOPp->io_input1 
                                        & vlTOPp->io_input2) 
                                       >> 0x1fU))));
    }
}

void VNFALU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
