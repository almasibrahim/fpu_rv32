module FALU(
  input         clock,
  input         reset,
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  input  [3:0]  io_aluCtl,
  input  [2:0]  io_rmm,
  output [31:0] io_result
);
  wire  signBitIn1 = io_input1[31]; // @[FALU.scala 14:40]
  wire  signBitIn2 = io_input2[31]; // @[FALU.scala 15:40]
  wire [7:0] expBitIn1 = io_input1[30:23]; // @[FALU.scala 18:27]
  wire [22:0] fracBitIn1 = io_input1[22:0]; // @[FALU.scala 23:28]
  wire [22:0] fracBitIn2 = io_input2[22:0]; // @[FALU.scala 25:28]
  wire [23:0] _extraRes_T = {signBitIn1,fracBitIn1}; // @[Cat.scala 30:58]
  wire [23:0] _extraRes_T_1 = {signBitIn2,fracBitIn2}; // @[Cat.scala 30:58]
  wire [23:0] extraRes = _extraRes_T + _extraRes_T_1; // @[FALU.scala 29:45]
  wire [22:0] res_lo = {{1'd0}, extraRes[22:1]}; // @[FALU.scala 32:81]
  wire [23:0] _res_T_4 = {extraRes[23],res_lo}; // @[Cat.scala 30:58]
  wire [23:0] _res_T_8 = {extraRes[23],extraRes[22:0]}; // @[Cat.scala 30:58]
  wire [23:0] _res_T_9 = {{1'd0}, _res_T_8[23:1]}; // @[FALU.scala 33:91]
  wire [23:0] _res_T_12 = extraRes[23] ? _res_T_9 : _res_T_4; // @[FALU.scala 33:24]
  wire [23:0] res = ~extraRes[23] ? _res_T_4 : _res_T_12; // @[FALU.scala 32:15]
  wire [1:0] resSignBit = res[23:22]; // @[FALU.scala 39:22]
  wire [7:0] expP1 = expBitIn1 + 8'h1; // @[FALU.scala 45:36]
  wire  _io_result_T = io_aluCtl == 4'ha; // @[FALU.scala 51:28]
  wire  io_result_hi_hi = res[23]; // @[FALU.scala 52:62]
  wire [22:0] io_result_lo = res[22:0]; // @[FALU.scala 52:78]
  wire [31:0] _io_result_T_3 = {io_result_hi_hi,expP1,io_result_lo}; // @[Cat.scala 30:58]
  wire [31:0] _io_result_T_13 = 2'h3 == resSignBit ? _io_result_T_3 : 32'h0; // @[FALU.scala 55:24]
  wire [31:0] _io_result_T_14 = 2'h2 == resSignBit ? _io_result_T_3 : _io_result_T_13; // @[FALU.scala 54:24]
  wire [31:0] _io_result_T_15 = 2'h1 == resSignBit ? _io_result_T_3 : _io_result_T_14; // @[FALU.scala 53:24]
  wire [31:0] _io_result_T_16 = 2'h0 == resSignBit ? _io_result_T_3 : _io_result_T_15; // @[FALU.scala 52:24]
  assign io_result = _io_result_T ? _io_result_T_16 : 32'h0; // @[Mux.scala 98:16]
endmodule
