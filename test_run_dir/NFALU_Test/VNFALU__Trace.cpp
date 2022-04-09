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
    }
}

void VNFALU::traceChgThis__3(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
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
    }
}
