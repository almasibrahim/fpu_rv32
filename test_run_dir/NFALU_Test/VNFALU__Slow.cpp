// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNFALU.h for the primary calling header

#include "VNFALU.h"
#include "VNFALU__Syms.h"

//==========

VNFALU::VNFALU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    VNFALU__Syms* __restrict vlSymsp = __VlSymsp = new VNFALU__Syms(_vcontextp__, this, name());
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VNFALU::__Vconfigure(VNFALU__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

VNFALU::~VNFALU() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VNFALU::_eval_initial(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_initial\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNFALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::final\n"); );
    // Variables
    VNFALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNFALU::_eval_settle(VNFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_eval_settle\n"); );
    VNFALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VNFALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNFALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_input1 = VL_RAND_RESET_I(32);
    io_input2 = VL_RAND_RESET_I(32);
    io_aluCtl = VL_RAND_RESET_I(4);
    io_rmm = VL_RAND_RESET_I(3);
    io_result = VL_RAND_RESET_I(32);
    NFALU__DOT__xorSign = VL_RAND_RESET_I(1);
    NFALU__DOT__resFrac = VL_RAND_RESET_I(24);
    NFALU__DOT__resExp = VL_RAND_RESET_I(8);
    NFALU__DOT___GEN_28 = VL_RAND_RESET_Q(39);
    NFALU__DOT___GEN_48 = VL_RAND_RESET_Q(55);
    NFALU__DOT___GEN_50 = VL_RAND_RESET_Q(55);
    NFALU__DOT___GEN_29 = VL_RAND_RESET_I(8);
    NFALU__DOT__temExp = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
