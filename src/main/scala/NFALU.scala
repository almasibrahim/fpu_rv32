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

    val resFrac = Wire(UInt(24.W))
    val resExp = Wire(UInt(8.W))


    val temFrac = Wire(UInt(24.W))
    val temExp = Wire(UInt(8.W))
    
    resFrac := 0.U
    resExp := 0.U
    temFrac := 0.U
    temExp := 0.U
    

    when(expBitIn1 === expBitIn2){
        when(xorSign && (fracBitIn1 === fracBitIn2)){
            io.result := 0.U
        }.elsewhen(xorSign && (fracBitIn1 > fracBitIn2)){
            resFrac := (Cat(0.B, fracBitIn1)) - (Cat(0.B, fracBitIn2))
            resExp := expBitIn1
            io.result := Cat(signBitIn1, temExp, temFrac(22,0))
        }.elsewhen(xorSign && (fracBitIn1 < fracBitIn2)){
            resFrac := (Cat(0.B, fracBitIn2)) - (Cat(0.B, fracBitIn1))
            resExp := expBitIn1
            io.result := Cat(signBitIn2, temExp, temFrac(22,0))
        }.otherwise{
            when(fracBitIn1 === fracBitIn2){
                resFrac := fracBitIn1
            }.otherwise{
                resFrac := (Cat(0.B, fracBitIn1) + Cat(0.B, fracBitIn2)) >> 1.U
            }
            resExp := expBitIn1 + 1.U
            io.result := Cat(andSign, resExp, resFrac(22,0))
        }
    }
    .elsewhen(expBitIn1 > expBitIn2){
        val diff = WireInit(expBitIn1 - expBitIn2)
        // val shiftDiff = Wire(Fill(8, 1.B) && dif)
        // shiftDiff := fracBitIn2(diff.asInstanceOf[Int], 0)
        val tmp_mant = WireInit(Cat(signBitIn2, fracBitIn2) >> diff)

         val o_mant = Wire(UInt(24.W))

        when(xorSign){
            o_mant := Cat(0.B, fracBitIn1) - Cat(0.B, tmp_mant)
        }.otherwise{
            o_mant := (Cat(0.B, fracBitIn1) + Cat(0.B, tmp_mant)) >> 1.U
        }

        resFrac := o_mant
        resExp := expBitIn1
        io.result := Cat(signBitIn1, temExp, temFrac(22,0))
    }
    .otherwise{
        io.result := 0.U
    }
    // .elsewhen(expBitIn1 < expBitIn2){
    //     val diff = WireInit(expBitIn2 - expBitIn1)
    //     val tmp_mant = WireInit(fracBitIn1 >> diff)

    //     when(xorSign){
    //         val o_mant = WireInit(fracBitIn2 - tmp_mant)
    //     }.otherwise{
    //         val o_mant = WireInit(fracBitIn2 + tmp_mant)
    //     }

        
    // }


   when(resFrac(23)=/=1.U && resExp=/=0.U){
        when (resFrac(23,3)==="b000000000000000000001".U){
            temFrac := resFrac <<20.U
            temExp := resExp - 20.U
        }.elsewhen(resFrac(23,4)==="b00000000000000000001".U){
            temFrac := resFrac <<19.U
            temExp := resExp - 19.U
        }.elsewhen(resFrac(23,5)==="b0000000000000000001".U){
            temFrac := resFrac <<18.U
            temExp := resExp - 18.U
        }.elsewhen(resFrac(23,6)==="b000000000000000001".U){
            temFrac := resFrac <<17.U
            temExp := resExp - 17.U
        }.elsewhen(resFrac(23,7)==="b00000000000000001".U){
            temFrac := resFrac <<16.U
            temExp := resExp - 16.U
        }.elsewhen(resFrac(23,8)==="b0000000000000001".U){
            temFrac := resFrac <<15.U
            temExp := resExp - 15.U
        }.elsewhen(resFrac(23,9)==="b000000000000001".U){
            temFrac := resFrac <<14.U
            temExp := resExp - 14.U
        }.elsewhen(resFrac(23,10)==="b00000000000001".U){
            temFrac := resFrac <<13.U
            temExp := resExp - 13.U
        }.elsewhen(resFrac(23,11)==="b0000000000001".U){
            temFrac := resFrac <<12.U
            temExp := resExp - 12.U
        }.elsewhen(resFrac(23,12)==="b000000000001".U){
            temFrac := resFrac <<11.U
            temExp := resExp - 11.U
        }.elsewhen(resFrac(23,13)==="b00000000001".U){
            temFrac := resFrac <<10.U
            temExp := resExp - 10.U
        }.elsewhen(resFrac(23,14)==="b0000000001".U){
            temFrac := resFrac <<9.U
            temExp := resExp - 9.U
        }.elsewhen(resFrac(23,15)==="b000000001".U){
            temFrac := resFrac <<8.U
            temExp := resExp - 8.U
        }.elsewhen(resFrac(23,16)==="b00000001".U){
            temFrac := resFrac <<7.U
            temExp := resExp - 7.U
        }.elsewhen(resFrac(23,17)==="b0000001".U){
            temFrac := resFrac <<6.U
            temExp := resExp - 6.U
        }.elsewhen(resFrac(23,18)==="b000001".U){
            temFrac := resFrac <<5.U
            temExp := resExp - 5.U
        }.elsewhen(resFrac(23,19)==="b00001".U){
            temFrac := resFrac <<4.U
            temExp := resExp - 4.U
        }.elsewhen(resFrac(23,20)==="b0001".U){
            temFrac := resFrac <<3.U
            temExp := resExp - 3.U
        }.elsewhen(resFrac(23,21)==="b001".U){
            temFrac := resFrac <<2.U
            temExp := resExp - 2.U
        }.elsewhen(resFrac(23,22)==="b01".U){
            temFrac := resFrac <<1.U
            temExp := resExp - 1.U
        
        }.otherwise{
            temFrac := 0.U
            temExp := 0.U
        }
    }.otherwise{
        temFrac:=resFrac
        temExp:= resExp
    }
 

}

