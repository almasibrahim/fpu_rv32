// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VNFALU_H_
#define _VNFALU_H_  // guard

#include "verilated.h"

//==========

class VNFALU__Syms;
class VNFALU_VerilatedVcd;


//----------

VL_MODULE(VNFALU) {
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
    CData/*0:0*/ NFALU__DOT__xorSign;
    CData/*7:0*/ NFALU__DOT__resExp;
    CData/*7:0*/ NFALU__DOT___GEN_29;
    CData/*7:0*/ NFALU__DOT__temExp;
    IData/*22:0*/ NFALU__DOT__resFrac;
    QData/*37:0*/ NFALU__DOT___GEN_28;
    QData/*53:0*/ NFALU__DOT___GEN_48;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VNFALU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VNFALU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VNFALU(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VNFALU();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VNFALU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VNFALU__Syms* symsp, bool first);
  private:
    static QData _change_request(VNFALU__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VNFALU__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VNFALU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VNFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VNFALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VNFALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
