// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNFALU.h for the primary calling header

#include "VNFALU.h"
#include "VNFALU__Syms.h"

//==========

VerilatedContext* VNFALU::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void VNFALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VNFALU::eval\n"); );
    VNFALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("NFALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VNFALU::_eval_initial_loop(VNFALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("NFALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VNFALU::_combo__TOP__1(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_combo__TOP__1\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->NFALU__DOT__xorSign = (1U & ((vlTOPp->io_input1 
                                          ^ vlTOPp->io_input2) 
                                         >> 0x1fU));
    if (((IData)(vlTOPp->NFALU__DOT__xorSign) & ((0x7fffffU 
                                                  & vlTOPp->io_input1) 
                                                 == 
                                                 (0x7fffffU 
                                                  & vlTOPp->io_input2)))) {
        vlTOPp->NFALU__DOT__resExp = 0U;
        vlTOPp->NFALU__DOT__resFrac = 0U;
    } else {
        vlTOPp->NFALU__DOT__resExp = (0xffU & (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                                & ((0x7fffffU 
                                                    & vlTOPp->io_input1) 
                                                   > 
                                                   (0x7fffffU 
                                                    & vlTOPp->io_input2)))
                                                ? (vlTOPp->io_input1 
                                                   >> 0x17U)
                                                : (
                                                   ((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                                    & ((0x7fffffU 
                                                        & vlTOPp->io_input1) 
                                                       < 
                                                       (0x7fffffU 
                                                        & vlTOPp->io_input2)))
                                                    ? 
                                                   (vlTOPp->io_input1 
                                                    >> 0x17U)
                                                    : 
                                                   ((IData)(1U) 
                                                    + 
                                                    (vlTOPp->io_input1 
                                                     >> 0x17U)))));
        vlTOPp->NFALU__DOT__resFrac = (0xffffffU & 
                                       (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                         & ((0x7fffffU 
                                             & vlTOPp->io_input1) 
                                            > (0x7fffffU 
                                               & vlTOPp->io_input2)))
                                         ? ((0x7fffffU 
                                             & vlTOPp->io_input1) 
                                            - (0x7fffffU 
                                               & vlTOPp->io_input2))
                                         : (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                             & ((0x7fffffU 
                                                 & vlTOPp->io_input1) 
                                                < (0x7fffffU 
                                                   & vlTOPp->io_input2)))
                                             ? ((0x7fffffU 
                                                 & vlTOPp->io_input2) 
                                                - (0x7fffffU 
                                                   & vlTOPp->io_input1))
                                             : (((0x7fffffU 
                                                  & vlTOPp->io_input1) 
                                                 == 
                                                 (0x7fffffU 
                                                  & vlTOPp->io_input2))
                                                 ? 
                                                (0x7fffffU 
                                                 & vlTOPp->io_input1)
                                                 : 
                                                (0x7fffffU 
                                                 & (((0x7fffffU 
                                                      & vlTOPp->io_input1) 
                                                     + 
                                                     (0x7fffffU 
                                                      & vlTOPp->io_input2)) 
                                                    >> 1U))))));
    }
    if ((1U == (0x7ffU & (vlTOPp->NFALU__DOT__resFrac 
                          >> 0xdU)))) {
        vlTOPp->NFALU__DOT___GEN_29 = (0xffU & ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                - (IData)(0xaU)));
        vlTOPp->NFALU__DOT___GEN_28 = ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                       << 0xaU);
    } else {
        vlTOPp->NFALU__DOT___GEN_29 = (0xffU & ((1U 
                                                 == 
                                                 (0x3ffU 
                                                  & (vlTOPp->NFALU__DOT__resFrac 
                                                     >> 0xeU)))
                                                 ? 
                                                ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                 - (IData)(9U))
                                                 : 
                                                ((1U 
                                                  == 
                                                  (0x1ffU 
                                                   & (vlTOPp->NFALU__DOT__resFrac 
                                                      >> 0xfU)))
                                                  ? 
                                                 ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                  - (IData)(8U))
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (0xffU 
                                                    & (vlTOPp->NFALU__DOT__resFrac 
                                                       >> 0x10U)))
                                                   ? 
                                                  ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                   - (IData)(7U))
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x7fU 
                                                     & (vlTOPp->NFALU__DOT__resFrac 
                                                        >> 0x11U)))
                                                    ? 
                                                   ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                    - (IData)(6U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x3fU 
                                                      & (vlTOPp->NFALU__DOT__resFrac 
                                                         >> 0x12U)))
                                                     ? 
                                                    ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                     - (IData)(5U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlTOPp->NFALU__DOT__resFrac 
                                                          >> 0x13U)))
                                                      ? 
                                                     ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                      - (IData)(4U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0xfU 
                                                        & (vlTOPp->NFALU__DOT__resFrac 
                                                           >> 0x14U)))
                                                       ? 
                                                      ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                       - (IData)(3U))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->NFALU__DOT__resFrac 
                                                            >> 0x15U)))
                                                        ? 
                                                       ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                        - (IData)(2U))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlTOPp->NFALU__DOT__resFrac 
                                                             >> 0x16U)))
                                                         ? 
                                                        ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                         - (IData)(1U))
                                                         : 0U))))))))));
        vlTOPp->NFALU__DOT___GEN_28 = ((1U == (0x3ffU 
                                               & (vlTOPp->NFALU__DOT__resFrac 
                                                  >> 0xeU)))
                                        ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                           << 9U) : 
                                       ((1U == (0x1ffU 
                                                & (vlTOPp->NFALU__DOT__resFrac 
                                                   >> 0xfU)))
                                         ? (QData)((IData)(
                                                           (vlTOPp->NFALU__DOT__resFrac 
                                                            << 8U)))
                                         : (QData)((IData)(
                                                           ((1U 
                                                             == 
                                                             (0xffU 
                                                              & (vlTOPp->NFALU__DOT__resFrac 
                                                                 >> 0x10U)))
                                                             ? 
                                                            (vlTOPp->NFALU__DOT__resFrac 
                                                             << 7U)
                                                             : 
                                                            ((1U 
                                                              == 
                                                              (0x7fU 
                                                               & (vlTOPp->NFALU__DOT__resFrac 
                                                                  >> 0x11U)))
                                                              ? 
                                                             (vlTOPp->NFALU__DOT__resFrac 
                                                              << 6U)
                                                              : 
                                                             ((1U 
                                                               == 
                                                               (0x3fU 
                                                                & (vlTOPp->NFALU__DOT__resFrac 
                                                                   >> 0x12U)))
                                                               ? 
                                                              (vlTOPp->NFALU__DOT__resFrac 
                                                               << 5U)
                                                               : 
                                                              ((1U 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlTOPp->NFALU__DOT__resFrac 
                                                                    >> 0x13U)))
                                                                ? 
                                                               (vlTOPp->NFALU__DOT__resFrac 
                                                                << 4U)
                                                                : 
                                                               ((1U 
                                                                 == 
                                                                 (0xfU 
                                                                  & (vlTOPp->NFALU__DOT__resFrac 
                                                                     >> 0x14U)))
                                                                 ? 
                                                                (vlTOPp->NFALU__DOT__resFrac 
                                                                 << 3U)
                                                                 : 
                                                                ((1U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlTOPp->NFALU__DOT__resFrac 
                                                                      >> 0x15U)))
                                                                  ? 
                                                                 (vlTOPp->NFALU__DOT__resFrac 
                                                                  << 2U)
                                                                  : 
                                                                 ((1U 
                                                                   == 
                                                                   (3U 
                                                                    & (vlTOPp->NFALU__DOT__resFrac 
                                                                       >> 0x16U)))
                                                                   ? 
                                                                  (vlTOPp->NFALU__DOT__resFrac 
                                                                   << 1U)
                                                                   : 0U)))))))))));
    }
    vlTOPp->NFALU__DOT__temExp = (0xffU & (((~ (vlTOPp->NFALU__DOT__resFrac 
                                                >> 0x17U)) 
                                            & (0U != (IData)(vlTOPp->NFALU__DOT__resExp)))
                                            ? ((1U 
                                                == 
                                                (0x1fffffU 
                                                 & (vlTOPp->NFALU__DOT__resFrac 
                                                    >> 3U)))
                                                ? ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                   - (IData)(0x14U))
                                                : (
                                                   (1U 
                                                    == 
                                                    (0xfffffU 
                                                     & (vlTOPp->NFALU__DOT__resFrac 
                                                        >> 4U)))
                                                    ? 
                                                   ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                    - (IData)(0x13U))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x7ffffU 
                                                      & (vlTOPp->NFALU__DOT__resFrac 
                                                         >> 5U)))
                                                     ? 
                                                    ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                     - (IData)(0x12U))
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0x3ffffU 
                                                       & (vlTOPp->NFALU__DOT__resFrac 
                                                          >> 6U)))
                                                      ? 
                                                     ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                      - (IData)(0x11U))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (0x1ffffU 
                                                        & (vlTOPp->NFALU__DOT__resFrac 
                                                           >> 7U)))
                                                       ? 
                                                      ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                       - (IData)(0x10U))
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (0xffffU 
                                                         & (vlTOPp->NFALU__DOT__resFrac 
                                                            >> 8U)))
                                                        ? 
                                                       ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                        - (IData)(0xfU))
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (0x7fffU 
                                                          & (vlTOPp->NFALU__DOT__resFrac 
                                                             >> 9U)))
                                                         ? 
                                                        ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                         - (IData)(0xeU))
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (0x3fffU 
                                                           & (vlTOPp->NFALU__DOT__resFrac 
                                                              >> 0xaU)))
                                                          ? 
                                                         ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                          - (IData)(0xdU))
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (0x1fffU 
                                                            & (vlTOPp->NFALU__DOT__resFrac 
                                                               >> 0xbU)))
                                                           ? 
                                                          ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                           - (IData)(0xcU))
                                                           : 
                                                          ((1U 
                                                            == 
                                                            (0xfffU 
                                                             & (vlTOPp->NFALU__DOT__resFrac 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((IData)(vlTOPp->NFALU__DOT__resExp) 
                                                            - (IData)(0xbU))
                                                            : (IData)(vlTOPp->NFALU__DOT___GEN_29)))))))))))
                                            : (IData)(vlTOPp->NFALU__DOT__resExp)));
    vlTOPp->NFALU__DOT___GEN_48 = ((1U == (0x1fffffU 
                                           & (vlTOPp->NFALU__DOT__resFrac 
                                              >> 3U)))
                                    ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                       << 0x14U) : 
                                   ((1U == (0xfffffU 
                                            & (vlTOPp->NFALU__DOT__resFrac 
                                               >> 4U)))
                                     ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                        << 0x13U) : 
                                    ((1U == (0x7ffffU 
                                             & (vlTOPp->NFALU__DOT__resFrac 
                                                >> 5U)))
                                      ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                         << 0x12U) : 
                                     ((1U == (0x3ffffU 
                                              & (vlTOPp->NFALU__DOT__resFrac 
                                                 >> 6U)))
                                       ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                          << 0x11U)
                                       : ((1U == (0x1ffffU 
                                                  & (vlTOPp->NFALU__DOT__resFrac 
                                                     >> 7U)))
                                           ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                              << 0x10U)
                                           : ((1U == 
                                               (0xffffU 
                                                & (vlTOPp->NFALU__DOT__resFrac 
                                                   >> 8U)))
                                               ? ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                                  << 0xfU)
                                               : ((1U 
                                                   == 
                                                   (0x7fffU 
                                                    & (vlTOPp->NFALU__DOT__resFrac 
                                                       >> 9U)))
                                                   ? 
                                                  ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                                   << 0xeU)
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (0x3fffU 
                                                     & (vlTOPp->NFALU__DOT__resFrac 
                                                        >> 0xaU)))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                                    << 0xdU)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (0x1fffU 
                                                      & (vlTOPp->NFALU__DOT__resFrac 
                                                         >> 0xbU)))
                                                     ? 
                                                    ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                                     << 0xcU)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (0xfffU 
                                                       & (vlTOPp->NFALU__DOT__resFrac 
                                                          >> 0xcU)))
                                                      ? 
                                                     ((QData)((IData)(vlTOPp->NFALU__DOT__resFrac)) 
                                                      << 0xbU)
                                                      : vlTOPp->NFALU__DOT___GEN_28))))))))));
    vlTOPp->NFALU__DOT___GEN_50 = (((~ (vlTOPp->NFALU__DOT__resFrac 
                                        >> 0x17U)) 
                                    & (0U != (IData)(vlTOPp->NFALU__DOT__resExp)))
                                    ? vlTOPp->NFALU__DOT___GEN_48
                                    : (QData)((IData)(vlTOPp->NFALU__DOT__resFrac)));
    vlTOPp->io_result = (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                          & ((0x7fffffU & vlTOPp->io_input1) 
                             == (0x7fffffU & vlTOPp->io_input2)))
                          ? 0U : (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                   & ((0x7fffffU & vlTOPp->io_input1) 
                                      > (0x7fffffU 
                                         & vlTOPp->io_input2)))
                                   ? ((0x80000000U 
                                       & vlTOPp->io_input1) 
                                      | (((IData)(vlTOPp->NFALU__DOT__temExp) 
                                          << 0x17U) 
                                         | (0x7fffffU 
                                            & (IData)(vlTOPp->NFALU__DOT___GEN_50))))
                                   : (((IData)(vlTOPp->NFALU__DOT__xorSign) 
                                       & ((0x7fffffU 
                                           & vlTOPp->io_input1) 
                                          < (0x7fffffU 
                                             & vlTOPp->io_input2)))
                                       ? ((0x80000000U 
                                           & vlTOPp->io_input2) 
                                          | (((IData)(vlTOPp->NFALU__DOT__temExp) 
                                              << 0x17U) 
                                             | (0x7fffffU 
                                                & (IData)(vlTOPp->NFALU__DOT___GEN_50))))
                                       : ((0x80000000U 
                                           & (vlTOPp->io_input1 
                                              & vlTOPp->io_input2)) 
                                          | (((IData)(vlTOPp->NFALU__DOT__resExp) 
                                              << 0x17U) 
                                             | (0x7fffffU 
                                                & vlTOPp->NFALU__DOT__resFrac))))));
}

void VNFALU::_eval(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData VNFALU::_change_request(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_change_request\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VNFALU::_change_request_1(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_change_request_1\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VNFALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_aluCtl & 0xf0U))) {
        Verilated::overWidthError("io_aluCtl");}
    if (VL_UNLIKELY((io_rmm & 0xf8U))) {
        Verilated::overWidthError("io_rmm");}
}
#endif  // VL_DEBUG
