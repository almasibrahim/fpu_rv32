import chisel3._
import chisel3.util._

class FALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(4.W))
    val rmm: UInt = Input(UInt(3.W))

    val result: UInt = Output(UInt(32.W))
  })

    val signBitIn1 = WireInit(io.input1(31))
    val signBitIn2 = WireInit(io.input2(31))

    val expBitIn1 = Wire(UInt(8.W))
    expBitIn1 := io.input1(30, 23)
    val expBitIn2 = Wire(UInt(8.W))
    expBitIn2 := io.input2(30, 23)

    val fracBitIn1 = Wire(UInt(23.W))
    fracBitIn1 := io.input1(22, 0)
    val fracBitIn2 = Wire(UInt(23.W))
    fracBitIn2 := io.input2(22, 0)

    val res = Wire(UInt(24.W))
    val extraRes = Wire(UInt(24.W))
    extraRes := Cat(signBitIn1, fracBitIn1) + Cat(signBitIn2, fracBitIn2)
    // res := Cat(extraRes(23), extraRes(22, 0)) >> 1.U

    res := Mux(extraRes(23) === BitPat("b0"), Cat(extraRes(23), extraRes(22, 0) >> 1.U),
                    Mux(extraRes(23) === BitPat("b1"), Cat(extraRes(23), extraRes(22, 0)) >> 1.U,
                    Cat(extraRes(23), extraRes(22, 0) >> 1.U)))

    // val resRShift1 = WireInit()
    // dontTouch(resRShift1)
    val resSignBit = Wire(UInt(2.W))
    resSignBit := res(23,22)

    // res := Mux(extraRes === BitPat("b0"), Cat(res(23), expP1, res(22,0)),
    //                 Mux(extraRes === BitPat("b1"), Cat(extraRes(23), extraRes(22, 0)) >> 1.U,
    //                 0.U))))

    val expP1 = WireInit(expBitIn1 + 1.U)

    when(expBitIn1 === expBitIn2){
        io.result := MuxCase(
            0.U,
            Array(
                (io.aluCtl === 10.U) -> (
                    Mux(resSignBit === BitPat("b00"), Cat(res(23), expP1, res(22,0)),
                    Mux(resSignBit === BitPat("b01"), Cat(res(23), expP1, res(22,0)),
                    Mux(resSignBit === BitPat("b10"), Cat(res(23), expP1, res(22,0)),
                    Mux(resSignBit === BitPat("b11"), Cat(res(23), expP1, res(22,0)),
                    0.U))))
                ),
            )    
        )}.otherwise{
        io.result := DontCare
    }

}