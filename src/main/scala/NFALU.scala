import chisel3._
import chisel3.util._

class NFALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(4.W))
    val rmm: UInt = Input(UInt(3.W))

    val result: UInt = Output(UInt(32.W))
  })

    val signBitIn1 = WireInit(io.input1(31))    //sign bit
    val signBitIn2 = WireInit(io.input2(31))

    val expBitIn1 = Wire(UInt(8.W))             //exp bits
    expBitIn1 := io.input1(30, 23)
    val expBitIn2 = Wire(UInt(8.W))
    expBitIn2 := io.input2(30, 23)

    val fracBitIn1 = Wire(UInt(23.W))           //manteesa bits
    fracBitIn1 := io.input1(22, 0)
    val fracBitIn2 = Wire(UInt(23.W))
    fracBitIn2 := io.input2(22, 0)

    val xorSign = signBitIn1 ^ signBitIn2
    val andSign = signBitIn1 & signBitIn2 

    val resFrac = Wire(UInt(23.W))
    val resExp = Wire(UInt(8.W))
    resFrac := 0.U

    resExp := expBitIn1 + 1.U

    when(xorSign && (fracBitIn1 === fracBitIn2)){
        io.result := 0.U
    }
    .elsewhen(xorSign && (fracBitIn1 > fracBitIn2)){
        resFrac := (fracBitIn1 + fracBitIn2) >> 1.U
        io.result := Cat(signBitIn1, resExp, resFrac)
    }
    .elsewhen(xorSign && (fracBitIn1 < fracBitIn2)){
        resFrac := (fracBitIn1 + fracBitIn2) >> 1.U
        io.result := Cat(signBitIn2, resExp, resFrac)
    }
    .otherwise{
        when(fracBitIn1 === fracBitIn2){
            resFrac := fracBitIn1
        }.otherwise{
            resFrac := (fracBitIn1 + fracBitIn2) >> 1.U
        }
        io.result := Cat(andSign, resExp, resFrac)
    }

}
