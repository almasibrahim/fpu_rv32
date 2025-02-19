module NFALU(
  input         clock,
  input         reset,
  input  [31:0] io_input1,
  input  [31:0] io_input2,
  input  [3:0]  io_aluCtl,
  input  [2:0]  io_rmm,
  output [31:0] io_result
);
  wire  signBitIn1 = io_input1[31]; // @[NFALU.scala 14:40]
  wire  signBitIn2 = io_input2[31]; // @[NFALU.scala 15:40]
  wire [7:0] expBitIn1 = io_input1[30:23]; // @[NFALU.scala 18:27]
  wire [7:0] expBitIn2 = io_input2[30:23]; // @[NFALU.scala 20:27]
  wire [22:0] fracBitIn1 = io_input1[22:0]; // @[NFALU.scala 23:28]
  wire [22:0] fracBitIn2 = io_input2[22:0]; // @[NFALU.scala 25:28]
  wire  xorSign = signBitIn1 ^ signBitIn2; // @[NFALU.scala 27:30]
  wire  andSign = signBitIn1 & signBitIn2; // @[NFALU.scala 28:30]
  wire  _T_1 = fracBitIn1 == fracBitIn2; // @[NFALU.scala 47:37]
  wire [23:0] _resFrac_T = {1'h0,fracBitIn1}; // @[Cat.scala 30:58]
  wire [23:0] _resFrac_T_1 = {1'h0,fracBitIn2}; // @[Cat.scala 30:58]
  wire [23:0] _resFrac_T_3 = _resFrac_T - _resFrac_T_1; // @[NFALU.scala 50:47]
  wire [23:0] _resFrac_T_7 = _resFrac_T_1 - _resFrac_T; // @[NFALU.scala 54:47]
  wire [23:0] _resFrac_T_11 = _resFrac_T + _resFrac_T_1; // @[NFALU.scala 61:50]
  wire [23:0] _resFrac_T_12 = {{1'd0}, _resFrac_T_11[23:1]}; // @[NFALU.scala 61:74]
  wire [23:0] _GEN_0 = _T_1 ? {{1'd0}, fracBitIn1} : _resFrac_T_12; // @[NFALU.scala 58:44 NFALU.scala 59:25 NFALU.scala 61:25]
  wire [23:0] _GEN_1 = xorSign & fracBitIn1 < fracBitIn2 ? _resFrac_T_7 : _GEN_0; // @[NFALU.scala 53:57 NFALU.scala 54:21]
  wire [23:0] _GEN_4 = xorSign & fracBitIn1 > fracBitIn2 ? _resFrac_T_3 : _GEN_1; // @[NFALU.scala 49:57 NFALU.scala 50:21]
  wire [23:0] _GEN_8 = xorSign & fracBitIn1 == fracBitIn2 ? 24'h0 : _GEN_4; // @[NFALU.scala 47:53 NFALU.scala 39:13]
  wire [7:0] diff = expBitIn1 - expBitIn2; // @[NFALU.scala 68:39]
  wire [23:0] _tmp_mant_T = {signBitIn2,fracBitIn2}; // @[Cat.scala 30:58]
  wire [23:0] _tmp_mant_T_1 = _tmp_mant_T >> diff; // @[NFALU.scala 76:52]
  wire [23:0] _GEN_22 = diff == 8'h3 ? _tmp_mant_T_1 : 24'h0; // @[NFALU.scala 105:32 NFALU.scala 112:22 NFALU.scala 43:14]
  wire [23:0] _GEN_26 = diff == 8'h2 ? _tmp_mant_T_1 : _GEN_22; // @[NFALU.scala 69:27 NFALU.scala 76:22]
  wire [23:0] _GEN_30 = expBitIn1 > expBitIn2 ? _GEN_26 : 24'h0; // @[NFALU.scala 67:37 NFALU.scala 43:14]
  wire [23:0] _GEN_37 = expBitIn1 == expBitIn2 ? 24'h0 : _GEN_30; // @[NFALU.scala 46:34 NFALU.scala 43:14]
  wire [22:0] tmp_mant = _GEN_37[22:0]; // @[NFALU.scala 37:24]
  wire [23:0] _o_mant_T_1 = {1'h0,tmp_mant}; // @[Cat.scala 30:58]
  wire [23:0] o_mant = _resFrac_T + _o_mant_T_1; // @[NFALU.scala 84:42]
  wire [22:0] o_man_lo = o_mant[22:0]; // @[NFALU.scala 87:39]
  wire [23:0] _o_man_T = {1'h0,o_man_lo}; // @[Cat.scala 30:58]
  wire [23:0] _o_man_T_1 = {{1'd0}, _o_man_T[23:1]}; // @[NFALU.scala 87:46]
  wire [1:0] o_man_hi = o_mant[22:21] + 2'h1; // @[NFALU.scala 95:47]
  wire [20:0] o_man_lo_1 = o_mant[20:0]; // @[NFALU.scala 95:59]
  wire [22:0] _o_man_T_4 = {o_man_hi,o_man_lo_1}; // @[Cat.scala 30:58]
  wire [22:0] _GEN_12 = andSign ? 23'h0 : _o_man_T_4; // @[NFALU.scala 91:59 NFALU.scala 82:18 NFALU.scala 95:26]
  wire [23:0] _GEN_13 = o_mant[23] ? _o_man_T_1 : {{1'd0}, _GEN_12}; // @[NFALU.scala 86:36 NFALU.scala 87:22]
  wire [22:0] o_man = _GEN_13[22:0]; // @[NFALU.scala 81:29]
  wire [23:0] _GEN_10 = andSign ? o_mant : {{1'd0}, o_man}; // @[NFALU.scala 91:59 NFALU.scala 92:28 NFALU.scala 97:29]
  wire [23:0] _GEN_15 = o_mant[23] ? {{1'd0}, o_man} : _GEN_10; // @[NFALU.scala 86:36 NFALU.scala 89:25]
  wire [2:0] o_man_hi_1 = o_mant[22:20] + 3'h1; // @[NFALU.scala 130:47]
  wire [19:0] o_man_lo_3 = o_mant[19:0]; // @[NFALU.scala 130:59]
  wire [22:0] _o_man_T_9 = {o_man_hi_1,o_man_lo_3}; // @[Cat.scala 30:58]
  wire [22:0] _GEN_18 = andSign ? 23'h0 : _o_man_T_9; // @[NFALU.scala 126:59 NFALU.scala 118:18 NFALU.scala 130:26]
  wire [23:0] _GEN_19 = o_mant[23] ? _o_man_T_1 : {{1'd0}, _GEN_18}; // @[NFALU.scala 122:36 NFALU.scala 123:22]
  wire [22:0] o_man_1 = _GEN_19[22:0]; // @[NFALU.scala 117:29]
  wire [22:0] _GEN_24 = diff == 8'h3 ? o_man_1 : 23'h0; // @[NFALU.scala 105:32 NFALU.scala 135:21 NFALU.scala 39:13]
  wire [23:0] _GEN_28 = diff == 8'h2 ? _GEN_15 : {{1'd0}, _GEN_24}; // @[NFALU.scala 69:27]
  wire [23:0] _GEN_32 = expBitIn1 > expBitIn2 ? _GEN_28 : 24'h0; // @[NFALU.scala 67:37 NFALU.scala 39:13]
  wire [23:0] resFrac = expBitIn1 == expBitIn2 ? _GEN_8 : _GEN_32; // @[NFALU.scala 46:34]
  wire [7:0] _resExp_T_1 = expBitIn1 + 8'h1; // @[NFALU.scala 63:33]
  wire [7:0] _GEN_2 = xorSign & fracBitIn1 < fracBitIn2 ? expBitIn1 : _resExp_T_1; // @[NFALU.scala 53:57 NFALU.scala 55:20 NFALU.scala 63:20]
  wire [7:0] _GEN_5 = xorSign & fracBitIn1 > fracBitIn2 ? expBitIn1 : _GEN_2; // @[NFALU.scala 49:57 NFALU.scala 51:20]
  wire [7:0] _GEN_9 = xorSign & fracBitIn1 == fracBitIn2 ? 8'h0 : _GEN_5; // @[NFALU.scala 47:53 NFALU.scala 40:12]
  wire [7:0] _GEN_14 = o_mant[23] ? _resExp_T_1 : expBitIn1; // @[NFALU.scala 86:36 NFALU.scala 88:23]
  wire [7:0] _GEN_23 = diff == 8'h3 ? _GEN_14 : 8'h0; // @[NFALU.scala 105:32 NFALU.scala 40:12]
  wire [7:0] _GEN_27 = diff == 8'h2 ? _GEN_14 : _GEN_23; // @[NFALU.scala 69:27]
  wire [7:0] _GEN_31 = expBitIn1 > expBitIn2 ? _GEN_27 : 8'h0; // @[NFALU.scala 67:37 NFALU.scala 40:12]
  wire [7:0] resExp = expBitIn1 == expBitIn2 ? _GEN_9 : _GEN_31; // @[NFALU.scala 46:34]
  wire [43:0] _GEN_83 = {resFrac, 20'h0}; // @[NFALU.scala 153:32]
  wire [54:0] _temFrac_T = {{11'd0}, _GEN_83}; // @[NFALU.scala 153:32]
  wire [42:0] _GEN_84 = {resFrac, 19'h0}; // @[NFALU.scala 156:32]
  wire [54:0] _temFrac_T_1 = {{12'd0}, _GEN_84}; // @[NFALU.scala 156:32]
  wire [41:0] _GEN_85 = {resFrac, 18'h0}; // @[NFALU.scala 159:32]
  wire [54:0] _temFrac_T_2 = {{13'd0}, _GEN_85}; // @[NFALU.scala 159:32]
  wire [40:0] _GEN_86 = {resFrac, 17'h0}; // @[NFALU.scala 162:32]
  wire [54:0] _temFrac_T_3 = {{14'd0}, _GEN_86}; // @[NFALU.scala 162:32]
  wire [39:0] _GEN_87 = {resFrac, 16'h0}; // @[NFALU.scala 165:32]
  wire [54:0] _temFrac_T_4 = {{15'd0}, _GEN_87}; // @[NFALU.scala 165:32]
  wire [38:0] _temFrac_T_5 = {resFrac, 15'h0}; // @[NFALU.scala 168:32]
  wire [37:0] _GEN_88 = {resFrac, 14'h0}; // @[NFALU.scala 171:32]
  wire [38:0] _temFrac_T_6 = {{1'd0}, _GEN_88}; // @[NFALU.scala 171:32]
  wire [36:0] _GEN_89 = {resFrac, 13'h0}; // @[NFALU.scala 174:32]
  wire [38:0] _temFrac_T_7 = {{2'd0}, _GEN_89}; // @[NFALU.scala 174:32]
  wire [35:0] _GEN_90 = {resFrac, 12'h0}; // @[NFALU.scala 177:32]
  wire [38:0] _temFrac_T_8 = {{3'd0}, _GEN_90}; // @[NFALU.scala 177:32]
  wire [34:0] _GEN_91 = {resFrac, 11'h0}; // @[NFALU.scala 180:32]
  wire [38:0] _temFrac_T_9 = {{4'd0}, _GEN_91}; // @[NFALU.scala 180:32]
  wire [33:0] _GEN_92 = {resFrac, 10'h0}; // @[NFALU.scala 183:32]
  wire [38:0] _temFrac_T_10 = {{5'd0}, _GEN_92}; // @[NFALU.scala 183:32]
  wire [32:0] _GEN_93 = {resFrac, 9'h0}; // @[NFALU.scala 186:32]
  wire [38:0] _temFrac_T_11 = {{6'd0}, _GEN_93}; // @[NFALU.scala 186:32]
  wire [31:0] _GEN_94 = {resFrac, 8'h0}; // @[NFALU.scala 189:32]
  wire [38:0] _temFrac_T_12 = {{7'd0}, _GEN_94}; // @[NFALU.scala 189:32]
  wire [30:0] _temFrac_T_13 = {resFrac, 7'h0}; // @[NFALU.scala 192:32]
  wire [29:0] _GEN_95 = {resFrac, 6'h0}; // @[NFALU.scala 195:32]
  wire [30:0] _temFrac_T_14 = {{1'd0}, _GEN_95}; // @[NFALU.scala 195:32]
  wire [28:0] _GEN_96 = {resFrac, 5'h0}; // @[NFALU.scala 198:32]
  wire [30:0] _temFrac_T_15 = {{2'd0}, _GEN_96}; // @[NFALU.scala 198:32]
  wire [27:0] _GEN_97 = {resFrac, 4'h0}; // @[NFALU.scala 201:32]
  wire [30:0] _temFrac_T_16 = {{3'd0}, _GEN_97}; // @[NFALU.scala 201:32]
  wire [26:0] _temFrac_T_17 = {resFrac, 3'h0}; // @[NFALU.scala 204:32]
  wire [25:0] _GEN_98 = {resFrac, 2'h0}; // @[NFALU.scala 207:32]
  wire [26:0] _temFrac_T_18 = {{1'd0}, _GEN_98}; // @[NFALU.scala 207:32]
  wire [24:0] _temFrac_T_19 = {resFrac, 1'h0}; // @[NFALU.scala 210:32]
  wire [24:0] _GEN_38 = resFrac[23:22] == 2'h1 ? _temFrac_T_19 : 25'h0; // @[NFALU.scala 209:45 NFALU.scala 210:21 NFALU.scala 214:21]
  wire [26:0] _GEN_40 = resFrac[23:21] == 3'h1 ? _temFrac_T_18 : {{2'd0}, _GEN_38}; // @[NFALU.scala 206:46 NFALU.scala 207:21]
  wire [26:0] _GEN_42 = resFrac[23:20] == 4'h1 ? _temFrac_T_17 : _GEN_40; // @[NFALU.scala 203:47 NFALU.scala 204:21]
  wire [30:0] _GEN_44 = resFrac[23:19] == 5'h1 ? _temFrac_T_16 : {{4'd0}, _GEN_42}; // @[NFALU.scala 200:48 NFALU.scala 201:21]
  wire [30:0] _GEN_46 = resFrac[23:18] == 6'h1 ? _temFrac_T_15 : _GEN_44; // @[NFALU.scala 197:49 NFALU.scala 198:21]
  wire [30:0] _GEN_48 = resFrac[23:17] == 7'h1 ? _temFrac_T_14 : _GEN_46; // @[NFALU.scala 194:50 NFALU.scala 195:21]
  wire [30:0] _GEN_50 = resFrac[23:16] == 8'h1 ? _temFrac_T_13 : _GEN_48; // @[NFALU.scala 191:51 NFALU.scala 192:21]
  wire [38:0] _GEN_52 = resFrac[23:15] == 9'h1 ? _temFrac_T_12 : {{8'd0}, _GEN_50}; // @[NFALU.scala 188:52 NFALU.scala 189:21]
  wire [38:0] _GEN_54 = resFrac[23:14] == 10'h1 ? _temFrac_T_11 : _GEN_52; // @[NFALU.scala 185:53 NFALU.scala 186:21]
  wire [38:0] _GEN_56 = resFrac[23:13] == 11'h1 ? _temFrac_T_10 : _GEN_54; // @[NFALU.scala 182:54 NFALU.scala 183:21]
  wire [38:0] _GEN_58 = resFrac[23:12] == 12'h1 ? _temFrac_T_9 : _GEN_56; // @[NFALU.scala 179:55 NFALU.scala 180:21]
  wire [38:0] _GEN_60 = resFrac[23:11] == 13'h1 ? _temFrac_T_8 : _GEN_58; // @[NFALU.scala 176:56 NFALU.scala 177:21]
  wire [38:0] _GEN_62 = resFrac[23:10] == 14'h1 ? _temFrac_T_7 : _GEN_60; // @[NFALU.scala 173:57 NFALU.scala 174:21]
  wire [38:0] _GEN_64 = resFrac[23:9] == 15'h1 ? _temFrac_T_6 : _GEN_62; // @[NFALU.scala 170:57 NFALU.scala 171:21]
  wire [38:0] _GEN_66 = resFrac[23:8] == 16'h1 ? _temFrac_T_5 : _GEN_64; // @[NFALU.scala 167:58 NFALU.scala 168:21]
  wire [54:0] _GEN_68 = resFrac[23:7] == 17'h1 ? _temFrac_T_4 : {{16'd0}, _GEN_66}; // @[NFALU.scala 164:59 NFALU.scala 165:21]
  wire [54:0] _GEN_70 = resFrac[23:6] == 18'h1 ? _temFrac_T_3 : _GEN_68; // @[NFALU.scala 161:60 NFALU.scala 162:21]
  wire [54:0] _GEN_72 = resFrac[23:5] == 19'h1 ? _temFrac_T_2 : _GEN_70; // @[NFALU.scala 158:61 NFALU.scala 159:21]
  wire [54:0] _GEN_74 = resFrac[23:4] == 20'h1 ? _temFrac_T_1 : _GEN_72; // @[NFALU.scala 155:62 NFALU.scala 156:21]
  wire [54:0] _GEN_76 = resFrac[23:3] == 21'h1 ? _temFrac_T : _GEN_74; // @[NFALU.scala 152:58 NFALU.scala 153:21]
  wire [54:0] _GEN_78 = ~resFrac[23] & resExp != 8'h0 ? _GEN_76 : {{31'd0}, resFrac}; // @[NFALU.scala 151:43 NFALU.scala 218:16]
  wire [23:0] temFrac = _GEN_78[23:0]; // @[NFALU.scala 34:23]
  wire [22:0] io_result_lo = temFrac[22:0]; // @[NFALU.scala 52:57]
  wire [7:0] _lo_T_7 = resExp - 8'h14; // @[NFALU.scala 154:30]
  wire [7:0] _lo_T_9 = resExp - 8'h13; // @[NFALU.scala 157:30]
  wire [7:0] _lo_T_11 = resExp - 8'h12; // @[NFALU.scala 160:30]
  wire [7:0] _lo_T_13 = resExp - 8'h11; // @[NFALU.scala 163:30]
  wire [7:0] _lo_T_15 = resExp - 8'h10; // @[NFALU.scala 166:30]
  wire [7:0] _lo_T_17 = resExp - 8'hf; // @[NFALU.scala 169:30]
  wire [7:0] _lo_T_19 = resExp - 8'he; // @[NFALU.scala 172:30]
  wire [7:0] _lo_T_21 = resExp - 8'hd; // @[NFALU.scala 175:30]
  wire [7:0] _lo_T_23 = resExp - 8'hc; // @[NFALU.scala 178:30]
  wire [7:0] _lo_T_25 = resExp - 8'hb; // @[NFALU.scala 181:30]
  wire [7:0] _lo_T_27 = resExp - 8'ha; // @[NFALU.scala 184:30]
  wire [7:0] _lo_T_29 = resExp - 8'h9; // @[NFALU.scala 187:30]
  wire [7:0] _lo_T_31 = resExp - 8'h8; // @[NFALU.scala 190:30]
  wire [7:0] _lo_T_33 = resExp - 8'h7; // @[NFALU.scala 193:30]
  wire [7:0] _lo_T_35 = resExp - 8'h6; // @[NFALU.scala 196:30]
  wire [7:0] _lo_T_37 = resExp - 8'h5; // @[NFALU.scala 199:30]
  wire [7:0] _lo_T_39 = resExp - 8'h4; // @[NFALU.scala 202:30]
  wire [7:0] _lo_T_41 = resExp - 8'h3; // @[NFALU.scala 205:30]
  wire [7:0] _lo_T_43 = resExp - 8'h2; // @[NFALU.scala 208:30]
  wire [7:0] _lo_T_45 = resExp - 8'h1; // @[NFALU.scala 211:30]
  wire [7:0] _GEN_39 = resFrac[23:22] == 2'h1 ? _lo_T_45 : 8'h0; // @[NFALU.scala 209:45 NFALU.scala 211:20 NFALU.scala 215:20]
  wire [7:0] _GEN_41 = resFrac[23:21] == 3'h1 ? _lo_T_43 : _GEN_39; // @[NFALU.scala 206:46 NFALU.scala 208:20]
  wire [7:0] _GEN_43 = resFrac[23:20] == 4'h1 ? _lo_T_41 : _GEN_41; // @[NFALU.scala 203:47 NFALU.scala 205:20]
  wire [7:0] _GEN_45 = resFrac[23:19] == 5'h1 ? _lo_T_39 : _GEN_43; // @[NFALU.scala 200:48 NFALU.scala 202:20]
  wire [7:0] _GEN_47 = resFrac[23:18] == 6'h1 ? _lo_T_37 : _GEN_45; // @[NFALU.scala 197:49 NFALU.scala 199:20]
  wire [7:0] _GEN_49 = resFrac[23:17] == 7'h1 ? _lo_T_35 : _GEN_47; // @[NFALU.scala 194:50 NFALU.scala 196:20]
  wire [7:0] _GEN_51 = resFrac[23:16] == 8'h1 ? _lo_T_33 : _GEN_49; // @[NFALU.scala 191:51 NFALU.scala 193:20]
  wire [7:0] _GEN_53 = resFrac[23:15] == 9'h1 ? _lo_T_31 : _GEN_51; // @[NFALU.scala 188:52 NFALU.scala 190:20]
  wire [7:0] _GEN_55 = resFrac[23:14] == 10'h1 ? _lo_T_29 : _GEN_53; // @[NFALU.scala 185:53 NFALU.scala 187:20]
  wire [7:0] _GEN_57 = resFrac[23:13] == 11'h1 ? _lo_T_27 : _GEN_55; // @[NFALU.scala 182:54 NFALU.scala 184:20]
  wire [7:0] _GEN_59 = resFrac[23:12] == 12'h1 ? _lo_T_25 : _GEN_57; // @[NFALU.scala 179:55 NFALU.scala 181:20]
  wire [7:0] _GEN_61 = resFrac[23:11] == 13'h1 ? _lo_T_23 : _GEN_59; // @[NFALU.scala 176:56 NFALU.scala 178:20]
  wire [7:0] _GEN_63 = resFrac[23:10] == 14'h1 ? _lo_T_21 : _GEN_61; // @[NFALU.scala 173:57 NFALU.scala 175:20]
  wire [7:0] _GEN_65 = resFrac[23:9] == 15'h1 ? _lo_T_19 : _GEN_63; // @[NFALU.scala 170:57 NFALU.scala 172:20]
  wire [7:0] _GEN_67 = resFrac[23:8] == 16'h1 ? _lo_T_17 : _GEN_65; // @[NFALU.scala 167:58 NFALU.scala 169:20]
  wire [7:0] _GEN_69 = resFrac[23:7] == 17'h1 ? _lo_T_15 : _GEN_67; // @[NFALU.scala 164:59 NFALU.scala 166:20]
  wire [7:0] _GEN_71 = resFrac[23:6] == 18'h1 ? _lo_T_13 : _GEN_69; // @[NFALU.scala 161:60 NFALU.scala 163:20]
  wire [7:0] _GEN_73 = resFrac[23:5] == 19'h1 ? _lo_T_11 : _GEN_71; // @[NFALU.scala 158:61 NFALU.scala 160:20]
  wire [7:0] _GEN_75 = resFrac[23:4] == 20'h1 ? _lo_T_9 : _GEN_73; // @[NFALU.scala 155:62 NFALU.scala 157:20]
  wire [7:0] _GEN_77 = resFrac[23:3] == 21'h1 ? _lo_T_7 : _GEN_75; // @[NFALU.scala 152:58 NFALU.scala 154:20]
  wire [7:0] temExp = ~resFrac[23] & resExp != 8'h0 ? _GEN_77 : resExp; // @[NFALU.scala 151:43 NFALU.scala 219:15]
  wire [31:0] _io_result_T = {signBitIn1,temExp,io_result_lo}; // @[Cat.scala 30:58]
  wire [31:0] _io_result_T_1 = {signBitIn2,temExp,io_result_lo}; // @[Cat.scala 30:58]
  wire [22:0] io_result_lo_2 = resFrac[22:0]; // @[NFALU.scala 64:54]
  wire [31:0] _io_result_T_2 = {andSign,resExp,io_result_lo_2}; // @[Cat.scala 30:58]
  wire [31:0] _GEN_3 = xorSign & fracBitIn1 < fracBitIn2 ? _io_result_T_1 : _io_result_T_2; // @[NFALU.scala 53:57 NFALU.scala 56:23 NFALU.scala 64:23]
  wire [31:0] _GEN_6 = xorSign & fracBitIn1 > fracBitIn2 ? _io_result_T : _GEN_3; // @[NFALU.scala 49:57 NFALU.scala 52:23]
  wire [31:0] _GEN_7 = xorSign & fracBitIn1 == fracBitIn2 ? 32'h0 : _GEN_6; // @[NFALU.scala 47:53 NFALU.scala 48:23]
  wire [31:0] _GEN_25 = diff == 8'h3 ? _io_result_T_2 : 32'h0; // @[NFALU.scala 105:32 NFALU.scala 137:23 NFALU.scala 141:23]
  wire [31:0] _GEN_29 = diff == 8'h2 ? _io_result_T_2 : _GEN_25; // @[NFALU.scala 69:27 NFALU.scala 103:23]
  wire [31:0] _GEN_33 = expBitIn1 > expBitIn2 ? _GEN_29 : 32'h0; // @[NFALU.scala 67:37 NFALU.scala 146:19]
  wire [1:0] shiftDiff = fracBitIn2[1:0]; // @[NFALU.scala 71:36]
  wire [2:0] shiftDiff_1 = fracBitIn2[2:0]; // @[NFALU.scala 107:36]
  assign io_result = expBitIn1 == expBitIn2 ? _GEN_7 : _GEN_33; // @[NFALU.scala 46:34]
endmodule
