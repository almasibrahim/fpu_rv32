// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFALU_H_
#define _VFALU_H_

#include "verilated.h"
class VFALU__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VFALU) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_aluCtl,3,0);
    VL_IN8(io_rmm,2,0);
    VL_IN(io_input1,31,0);
    VL_IN(io_input2,31,0);
    VL_OUT(io_result,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(FALU__DOT__extraRes,23,0);
    VL_SIG(FALU__DOT___res_T_4,23,0);
    VL_SIG(FALU__DOT__res,23,0);
    VL_SIG(FALU__DOT___io_result_T_3,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFALU__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VFALU& operator= (const VFALU&);	///< Copying not allowed
    VFALU(const VFALU&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VFALU(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFALU();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFALU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFALU__Syms* symsp, bool first);
  private:
    static QData	_change_request(VFALU__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(VFALU__Syms* __restrict vlSymsp);
    static void	_combo__TOP__3(VFALU__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(VFALU__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VFALU__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VFALU__Syms* __restrict vlSymsp);
    static void	_eval_initial(VFALU__Syms* __restrict vlSymsp);
    static void	_eval_settle(VFALU__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VFALU__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VFALU__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(VFALU__Syms* __restrict vlSymsp);
    static void	traceChgThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
