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
    }
}

void VNFALU::traceFullThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VNFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
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
    }
}
