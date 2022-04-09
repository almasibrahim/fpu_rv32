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
<<<<<<< HEAD
        vcdp->chgBit(c+1,(vlTOPp->NFALU__DOT__xorSign));
        vcdp->chgBit(c+9,(vlTOPp->NFALU__DOT__andSign));
        vcdp->chgBus(c+17,(vlTOPp->NFALU__DOT__diff),8);
        vcdp->chgBus(c+25,(vlTOPp->NFALU__DOT__o_mant),24);
        vcdp->chgBus(c+33,((0x7fffffU & vlTOPp->NFALU__DOT__o_mant)),23);
        vcdp->chgBus(c+41,((3U & ((IData)(1U) + (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 0x15U)))),2);
        vcdp->chgBus(c+49,((0x1fffffU & vlTOPp->NFALU__DOT__o_mant)),21);
        vcdp->chgBus(c+57,((0x7fffffU & vlTOPp->NFALU__DOT___GEN_13)),23);
        vcdp->chgBus(c+65,((7U & ((IData)(1U) + (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 0x14U)))),3);
        vcdp->chgBus(c+73,((0xfffffU & vlTOPp->NFALU__DOT__o_mant)),20);
        vcdp->chgBus(c+81,((0x7fffffU & ((0x800000U 
                                          & vlTOPp->NFALU__DOT__o_mant)
                                          ? (0x3fffffU 
                                             & (vlTOPp->NFALU__DOT__o_mant 
                                                >> 1U))
                                          : ((IData)(vlTOPp->NFALU__DOT__andSign)
                                              ? 0U : 
                                             ((0x700000U 
                                               & (((IData)(1U) 
                                                   + 
                                                   (vlTOPp->NFALU__DOT__o_mant 
                                                    >> 0x14U)) 
                                                  << 0x14U)) 
                                              | (0xfffffU 
                                                 & vlTOPp->NFALU__DOT__o_mant)))))),23);
        vcdp->chgBus(c+89,(vlTOPp->NFALU__DOT__resFrac),24);
        vcdp->chgBus(c+97,(vlTOPp->NFALU__DOT__resExp),8);
        vcdp->chgBus(c+105,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_78))),24);
        vcdp->chgBus(c+113,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_78))),23);
        vcdp->chgBus(c+121,(vlTOPp->NFALU__DOT__temExp),8);
        vcdp->chgBus(c+129,((0x7fffffU & vlTOPp->NFALU__DOT__resFrac)),23);
=======
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
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5
    }
}

void VNFALU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
<<<<<<< HEAD
        vcdp->chgBit(c+137,(vlTOPp->clock));
        vcdp->chgBit(c+145,(vlTOPp->reset));
        vcdp->chgBus(c+153,(vlTOPp->io_input1),32);
        vcdp->chgBus(c+161,(vlTOPp->io_input2),32);
        vcdp->chgBus(c+169,(vlTOPp->io_aluCtl),4);
        vcdp->chgBus(c+177,(vlTOPp->io_rmm),3);
        vcdp->chgBus(c+185,(vlTOPp->io_result),32);
        vcdp->chgBit(c+193,((1U & (vlTOPp->io_input1 
                                   >> 0x1fU))));
        vcdp->chgBit(c+201,((1U & (vlTOPp->io_input2 
                                   >> 0x1fU))));
        vcdp->chgBus(c+209,((0xffU & (vlTOPp->io_input1 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+217,((0xffU & (vlTOPp->io_input2 
                                      >> 0x17U))),8);
        vcdp->chgBus(c+225,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->chgBus(c+233,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->chgBus(c+241,((((0xffU & (vlTOPp->io_input1 
                                        >> 0x17U)) 
                              == (0xffU & (vlTOPp->io_input2 
                                           >> 0x17U)))
                              ? 0U : (((0xffU & (vlTOPp->io_input1 
                                                 >> 0x17U)) 
                                       > (0xffU & (vlTOPp->io_input2 
                                                   >> 0x17U)))
                                       ? (0x7fffffU 
                                          & ((2U == (IData)(vlTOPp->NFALU__DOT__diff))
                                              ? vlTOPp->NFALU__DOT___tmp_mant_T_1
                                              : ((3U 
                                                  == (IData)(vlTOPp->NFALU__DOT__diff))
                                                  ? vlTOPp->NFALU__DOT___tmp_mant_T_1
                                                  : 0U)))
                                       : 0U))),23);
        vcdp->chgBus(c+249,((3U & vlTOPp->io_input2)),2);
        vcdp->chgBus(c+257,((7U & vlTOPp->io_input2)),3);
=======
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5
    }
}
