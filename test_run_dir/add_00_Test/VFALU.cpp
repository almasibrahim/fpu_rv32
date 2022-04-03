// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFALU.h for the primary calling header

#include "VFALU.h"
#include "VFALU__Syms.h"

//==========

VerilatedContext* VFALU::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void VFALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VFALU::eval\n"); );
    VFALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("FALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VFALU::_eval_initial_loop(VFALU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("FALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VFALU::_combo__TOP__1(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_combo__TOP__1\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FALU__DOT__extraRes = (0xffffffU & (((0x800000U 
                                                  & (vlTOPp->io_input1 
                                                     >> 8U)) 
                                                 | (0x7fffffU 
                                                    & vlTOPp->io_input1)) 
                                                + (
                                                   (0x800000U 
                                                    & (vlTOPp->io_input2 
                                                       >> 8U)) 
                                                   | (0x7fffffU 
                                                      & vlTOPp->io_input2))));
    vlTOPp->FALU__DOT___res_T_4 = ((0x800000U & vlTOPp->FALU__DOT__extraRes) 
                                   | (0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
                                                   >> 1U)));
    vlTOPp->FALU__DOT__res = ((0x800000U & vlTOPp->FALU__DOT__extraRes)
                               ? ((0x800000U & vlTOPp->FALU__DOT__extraRes)
                                   ? (0x7fffffU & (vlTOPp->FALU__DOT__extraRes 
                                                   >> 1U))
                                   : vlTOPp->FALU__DOT___res_T_4)
                               : vlTOPp->FALU__DOT___res_T_4);
    vlTOPp->FALU__DOT___io_result_T_3 = ((0x80000000U 
                                          & (vlTOPp->FALU__DOT__res 
                                             << 8U)) 
                                         | ((0x7f800000U 
                                             & (((IData)(1U) 
                                                 + 
                                                 (vlTOPp->io_input1 
                                                  >> 0x17U)) 
                                                << 0x17U)) 
                                            | (0x7fffffU 
                                               & vlTOPp->FALU__DOT__res)));
    vlTOPp->io_result = ((0xaU == (IData)(vlTOPp->io_aluCtl))
                          ? ((0U == (3U & (vlTOPp->FALU__DOT__res 
                                           >> 0x16U)))
                              ? vlTOPp->FALU__DOT___io_result_T_3
                              : ((1U == (3U & (vlTOPp->FALU__DOT__res 
                                               >> 0x16U)))
                                  ? vlTOPp->FALU__DOT___io_result_T_3
                                  : ((2U == (3U & (vlTOPp->FALU__DOT__res 
                                                   >> 0x16U)))
                                      ? vlTOPp->FALU__DOT___io_result_T_3
                                      : ((3U == (3U 
                                                 & (vlTOPp->FALU__DOT__res 
                                                    >> 0x16U)))
                                          ? vlTOPp->FALU__DOT___io_result_T_3
                                          : 0U)))) : 0U);
}

void VFALU::_eval(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_eval\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData VFALU::_change_request(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_change_request\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VFALU::_change_request_1(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_change_request_1\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VFALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_eval_debug_assertions\n"); );
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
