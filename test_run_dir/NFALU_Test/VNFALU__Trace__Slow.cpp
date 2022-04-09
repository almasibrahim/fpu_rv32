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
<<<<<<< HEAD
        vcdp->declBit(c+137,"clock", false,-1);
        vcdp->declBit(c+145,"reset", false,-1);
        vcdp->declBus(c+153,"io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+177,"io_rmm", false,-1, 2,0);
        vcdp->declBus(c+185,"io_result", false,-1, 31,0);
        vcdp->declBit(c+137,"NFALU clock", false,-1);
        vcdp->declBit(c+145,"NFALU reset", false,-1);
        vcdp->declBus(c+153,"NFALU io_input1", false,-1, 31,0);
        vcdp->declBus(c+161,"NFALU io_input2", false,-1, 31,0);
        vcdp->declBus(c+169,"NFALU io_aluCtl", false,-1, 3,0);
        vcdp->declBus(c+177,"NFALU io_rmm", false,-1, 2,0);
        vcdp->declBus(c+185,"NFALU io_result", false,-1, 31,0);
        vcdp->declBit(c+193,"NFALU signBitIn1", false,-1);
        vcdp->declBit(c+201,"NFALU signBitIn2", false,-1);
        vcdp->declBus(c+209,"NFALU expBitIn1", false,-1, 7,0);
        vcdp->declBus(c+217,"NFALU expBitIn2", false,-1, 7,0);
        vcdp->declBus(c+225,"NFALU fracBitIn1", false,-1, 22,0);
        vcdp->declBus(c+233,"NFALU fracBitIn2", false,-1, 22,0);
        vcdp->declBit(c+1,"NFALU xorSign", false,-1);
        vcdp->declBit(c+9,"NFALU andSign", false,-1);
        vcdp->declBus(c+17,"NFALU diff", false,-1, 7,0);
        vcdp->declBus(c+241,"NFALU tmp_mant", false,-1, 22,0);
        vcdp->declBus(c+25,"NFALU o_mant", false,-1, 23,0);
        vcdp->declBus(c+33,"NFALU o_man_lo", false,-1, 22,0);
        vcdp->declBus(c+41,"NFALU o_man_hi", false,-1, 1,0);
        vcdp->declBus(c+49,"NFALU o_man_lo_1", false,-1, 20,0);
        vcdp->declBus(c+57,"NFALU o_man", false,-1, 22,0);
        vcdp->declBus(c+65,"NFALU o_man_hi_1", false,-1, 2,0);
        vcdp->declBus(c+73,"NFALU o_man_lo_3", false,-1, 19,0);
        vcdp->declBus(c+81,"NFALU o_man_1", false,-1, 22,0);
        vcdp->declBus(c+89,"NFALU resFrac", false,-1, 23,0);
        vcdp->declBus(c+97,"NFALU resExp", false,-1, 7,0);
        vcdp->declBus(c+105,"NFALU temFrac", false,-1, 23,0);
        vcdp->declBus(c+113,"NFALU io_result_lo", false,-1, 22,0);
        vcdp->declBus(c+121,"NFALU temExp", false,-1, 7,0);
        vcdp->declBus(c+129,"NFALU io_result_lo_2", false,-1, 22,0);
        vcdp->declBus(c+249,"NFALU shiftDiff", false,-1, 1,0);
        vcdp->declBus(c+257,"NFALU shiftDiff_1", false,-1, 2,0);
=======
        vlTOPp->traceFullSub0(userp, tracep);
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5
    }
}

void VNFALU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VNFALU__Syms* __restrict vlSymsp = static_cast<VNFALU__Syms*>(userp);
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
<<<<<<< HEAD
        vcdp->fullBit(c+1,(vlTOPp->NFALU__DOT__xorSign));
        vcdp->fullBit(c+9,(vlTOPp->NFALU__DOT__andSign));
        vcdp->fullBus(c+17,(vlTOPp->NFALU__DOT__diff),8);
        vcdp->fullBus(c+25,(vlTOPp->NFALU__DOT__o_mant),24);
        vcdp->fullBus(c+33,((0x7fffffU & vlTOPp->NFALU__DOT__o_mant)),23);
        vcdp->fullBus(c+41,((3U & ((IData)(1U) + (vlTOPp->NFALU__DOT__o_mant 
                                                  >> 0x15U)))),2);
        vcdp->fullBus(c+49,((0x1fffffU & vlTOPp->NFALU__DOT__o_mant)),21);
        vcdp->fullBus(c+57,((0x7fffffU & vlTOPp->NFALU__DOT___GEN_13)),23);
        vcdp->fullBus(c+65,((7U & ((IData)(1U) + (vlTOPp->NFALU__DOT__o_mant 
                                                  >> 0x14U)))),3);
        vcdp->fullBus(c+73,((0xfffffU & vlTOPp->NFALU__DOT__o_mant)),20);
        vcdp->fullBus(c+81,((0x7fffffU & ((0x800000U 
                                           & vlTOPp->NFALU__DOT__o_mant)
                                           ? (0x3fffffU 
                                              & (vlTOPp->NFALU__DOT__o_mant 
                                                 >> 1U))
                                           : ((IData)(vlTOPp->NFALU__DOT__andSign)
                                               ? 0U
                                               : ((0x700000U 
                                                   & (((IData)(1U) 
                                                       + 
                                                       (vlTOPp->NFALU__DOT__o_mant 
                                                        >> 0x14U)) 
                                                      << 0x14U)) 
                                                  | (0xfffffU 
                                                     & vlTOPp->NFALU__DOT__o_mant)))))),23);
        vcdp->fullBus(c+89,(vlTOPp->NFALU__DOT__resFrac),24);
        vcdp->fullBus(c+97,(vlTOPp->NFALU__DOT__resExp),8);
        vcdp->fullBus(c+105,((0xffffffU & (IData)(vlTOPp->NFALU__DOT___GEN_78))),24);
        vcdp->fullBus(c+113,((0x7fffffU & (IData)(vlTOPp->NFALU__DOT___GEN_78))),23);
        vcdp->fullBus(c+121,(vlTOPp->NFALU__DOT__temExp),8);
        vcdp->fullBus(c+129,((0x7fffffU & vlTOPp->NFALU__DOT__resFrac)),23);
        vcdp->fullBit(c+137,(vlTOPp->clock));
        vcdp->fullBit(c+145,(vlTOPp->reset));
        vcdp->fullBus(c+153,(vlTOPp->io_input1),32);
        vcdp->fullBus(c+161,(vlTOPp->io_input2),32);
        vcdp->fullBus(c+169,(vlTOPp->io_aluCtl),4);
        vcdp->fullBus(c+177,(vlTOPp->io_rmm),3);
        vcdp->fullBus(c+185,(vlTOPp->io_result),32);
        vcdp->fullBit(c+193,((1U & (vlTOPp->io_input1 
                                    >> 0x1fU))));
        vcdp->fullBit(c+201,((1U & (vlTOPp->io_input2 
                                    >> 0x1fU))));
        vcdp->fullBus(c+209,((0xffU & (vlTOPp->io_input1 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+217,((0xffU & (vlTOPp->io_input2 
                                       >> 0x17U))),8);
        vcdp->fullBus(c+225,((0x7fffffU & vlTOPp->io_input1)),23);
        vcdp->fullBus(c+233,((0x7fffffU & vlTOPp->io_input2)),23);
        vcdp->fullBus(c+241,((((0xffU & (vlTOPp->io_input1 
                                         >> 0x17U)) 
                               == (0xffU & (vlTOPp->io_input2 
                                            >> 0x17U)))
                               ? 0U : (((0xffU & (vlTOPp->io_input1 
                                                  >> 0x17U)) 
                                        > (0xffU & 
                                           (vlTOPp->io_input2 
                                            >> 0x17U)))
                                        ? (0x7fffffU 
                                           & ((2U == (IData)(vlTOPp->NFALU__DOT__diff))
                                               ? vlTOPp->NFALU__DOT___tmp_mant_T_1
                                               : ((3U 
                                                   == (IData)(vlTOPp->NFALU__DOT__diff))
                                                   ? vlTOPp->NFALU__DOT___tmp_mant_T_1
                                                   : 0U)))
                                        : 0U))),23);
        vcdp->fullBus(c+249,((3U & vlTOPp->io_input2)),2);
        vcdp->fullBus(c+257,((7U & vlTOPp->io_input2)),3);
=======
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
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5
    }
}
