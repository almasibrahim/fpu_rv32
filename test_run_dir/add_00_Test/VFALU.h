// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VFALU_H_
#define VERILATED_VFALU_H_  // guard

#include "verilated_heavy.h"

//==========

class VFALU__Syms;
class VFALU_VerilatedVcd;


//----------

VL_MODULE(VFALU) {
  public:
    
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
    IData/*23:0*/ FALU__DOT__extraRes;
    IData/*23:0*/ FALU__DOT___res_T_4;
    IData/*23:0*/ FALU__DOT__res;
    IData/*31:0*/ FALU__DOT___io_result_T_3;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFALU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VFALU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VFALU(VerilatedContext* contextp, const char* name = "TOP");
    VFALU(const char* name = "TOP")
      : VFALU(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~VFALU();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(VFALU__Syms* __restrict vlSymsp);
    void __Vconfigure(VFALU__Syms* symsp, bool first);
  private:
    static QData _change_request(VFALU__Syms* __restrict vlSymsp);
    static QData _change_request_1(VFALU__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VFALU__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VFALU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
