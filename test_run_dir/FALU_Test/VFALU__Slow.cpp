// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFALU.h for the primary calling header

#include "VFALU.h"
#include "VFALU__Syms.h"

//==========

VFALU::VFALU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    VFALU__Syms* __restrict vlSymsp = __VlSymsp = new VFALU__Syms(_vcontextp__, this, name());
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFALU::__Vconfigure(VFALU__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

VFALU::~VFALU() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VFALU::_eval_initial(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_eval_initial\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::final\n"); );
    // Variables
    VFALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFALU::_eval_settle(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_eval_settle\n"); );
    VFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VFALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VFALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input1 = VL_RAND_RESET_I(32);
    io_input2 = VL_RAND_RESET_I(32);
    io_aluCtl = VL_RAND_RESET_I(4);
    io_rmm = VL_RAND_RESET_I(3);
    io_result = VL_RAND_RESET_I(32);
    FALU__DOT__extraRes = VL_RAND_RESET_I(24);
    FALU__DOT___res_T_4 = VL_RAND_RESET_I(24);
    FALU__DOT__res = VL_RAND_RESET_I(24);
    FALU__DOT___io_result_T_3 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
