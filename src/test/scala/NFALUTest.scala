import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class NFALUTest extends FreeSpec with ChiselScalatestTester {

  "NFALU Test" in {
    test(new NFALU()).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>

      //pass
      // c.io.input1.poke("hC0200000".U)     // (-2.5)
      // c.io.input2.poke("h40333333".U)     //(2.8)  
      // c.io.aluCtl.poke(10.U)              //expected output (3E999998)
      // c.clock.step(100)


      //pass
      // c.io.input1.poke("h43168000".U)     // (150.5)
      // c.io.input2.poke("h43118000".U)     //(145.5)  
      // c.io.aluCtl.poke(10.U)              //expected output (43940000)
      // c.clock.step(100)



        //pass
        // c.io.input1.poke("h47435000".U)    //5e4
        // c.io.input2.poke("h476A6000".U)    //6e4   
        // c.io.aluCtl.poke(10.U)           // expected output (47D6D800)
        // c.clock.step(100)



        //pass
        // c.io.input1.poke("h385A1A93".U)    //0.000052
        // c.io.input2.poke("h381B3073".U)    //0.000037   
        // c.io.aluCtl.poke(10.U)           // expected output (38BAA583)
        // c.clock.step(100)




        //pass
        // c.io.input1.poke("hC53B8000".U)    //-3e4
        // c.io.input2.poke("hC53B8000".U)    //-3e4   
        // c.io.aluCtl.poke(10.U)           // expected output (C5BB8000)
        // c.clock.step(100)


        //pass
        // c.io.input1.poke("h4A989680".U)    //5e6
        // c.io.input2.poke("h4AB71B00".U)    //6e6   
        // c.io.aluCtl.poke(10.U)           // expected output (4B27D8C0)       passsss
        // c.clock.step(100)




        //pass
        // c.io.input1.poke("hC024538F".U)    //-2.5676
        // c.io.input2.poke("h4024538F".U)    //2.5676 
        // c.io.aluCtl.poke(10.U)           // expected output (00000000)
        // c.clock.step(100)



        //fail
        // c.io.input1.poke("h407F3B64".U)    //3.988
        // c.io.input2.poke("h403F1AA0".U)    //2.986
        // c.io.aluCtl.poke(10.U)           // expected output (40DF2B02)         passsss
        // c.clock.step(100)


        //pass
        // c.io.input1.poke("h407F3B64".U)    //3.988
        // c.io.input2.poke("hC03F1AA0".U)    //-2.986
        // c.io.aluCtl.poke(10.U)           // expected output (3F804188)
        // c.clock.step(100)



        //pass
        // c.io.input1.poke("hC07F3B64".U)    //-3.988
        // c.io.input2.poke("h403F1AA0".U)    //2.986
        // c.io.aluCtl.poke(10.U)           // expected output (BF804188)
        // c.clock.step(100)

    }
  }
}













// Working
    //   c.io.instIn.poke("h952E9426".U)
    //   c.io.pcIn.poke(12.U)
    //   c.clock.step(1)
    // //   c.io.pcIn.poke(c.io.pcOut.peek)
    // //   c.clock.step(1)
    //   c.io.pcIn.poke(c.io.pcOut.peek)
    //   c.io.instIn.poke("h00940433".U)
    //   c.clock.step(1)
    //   c.io.pcIn.poke(c.io.pcOut.peek)
    //   c.clock.step(1)
    //   c.io.instIn.poke("h952E9426".U)
    //   c.io.pcIn.poke(c.io.pcOut.peek)
    //   c.clock.step(1)
    //   c.io.pcIn.poke(c.io.pcOut.peek)
    //   c.clock.step(1)
    //   c.io.pcIn.poke(c.io.pcOut.peek)
    //   c.io.instIn.poke("h00940433".U)