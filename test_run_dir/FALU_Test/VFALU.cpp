// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFALU.h for the primary calling header

#include "VFALU.h"             // For This
#include "VFALU__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VFALU) {
    VFALU__Syms* __restrict vlSymsp = __VlSymsp = new VFALU__Syms(this, name());
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFALU::__Vconfigure(VFALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFALU::~VFALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VFALU::eval() {
    VFALU__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VFALU::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VFALU::_eval_initial_loop(VFALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VFALU::_combo__TOP__1(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_combo__TOP__1\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
}

void VFALU::_settle__TOP__2(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_settle__TOP__2\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
}

VL_INLINE_OPT void VFALU::_combo__TOP__3(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_combo__TOP__3\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FALU__DOT___res_T_4 = ((0x800000U & vlTOPp->FALU__DOT__extraRes) 
				   | (0x3fffffU & (vlTOPp->FALU__DOT__extraRes 
						   >> 1U)));
    vlTOPp->FALU__DOT__res = ((0x800000U & vlTOPp->FALU__DOT__extraRes)
			       ? ((0x800000U & vlTOPp->FALU__DOT__extraRes)
				   ? (0x7fffffU & (vlTOPp->FALU__DOT__extraRes 
						   >> 1U))
				   : vlTOPp->FALU__DOT___res_T_4)
			       : vlTOPp->FALU__DOT___res_T_4);
}

void VFALU::_settle__TOP__4(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_settle__TOP__4\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

VL_INLINE_OPT void VFALU::_combo__TOP__5(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_combo__TOP__5\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void VFALU::_settle__TOP__6(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_settle__TOP__6\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_eval\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->_combo__TOP__5(vlSymsp);
}

void VFALU::_eval_initial(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_eval_initial\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFALU::final() {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::final\n"); );
    // Variables
    VFALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFALU::_eval_settle(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_eval_settle\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
}

VL_INLINE_OPT QData VFALU::_change_request(VFALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_change_request\n"); );
    VFALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VFALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_ctor_var_reset\n"); );
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
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VFALU::_configure_coverage(VFALU__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VFALU::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
