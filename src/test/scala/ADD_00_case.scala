import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class ADD_00_case extends FreeSpec with ChiselScalatestTester {

  "add 00 Test" in {
    test(new FALU()).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>
    //pass
    //   c.io.input1.poke("h47afc800".U)
    //   c.io.input2.poke("h47afc800".U)
    //   c.io.aluCtl.poke(10.U)
    //   c.clock.step(100)


      //fail
    //   c.io.input1.poke("h47afc800".U)    //4e4
    //   c.io.input2.poke("h471c4000".U)    //9e4   
    //   c.io.aluCtl.poke(10.U)           // expected output (47fde800)
    //   c.clock.step(100)
      

      //pass
    //   c.io.input1.poke("h72977617".U)    //6e30
    //   c.io.input2.poke("h72c9f2ca".U)    //8e30
    //   c.io.aluCtl.poke(10.U)             //expected output(7330b470)
    //   c.clock.step(100)



      //fail
    //   c.io.input1.poke("h42a76148".U)    //83.69
    //   c.io.input2.poke("h4203eb85".U)    //32.98
    //   c.io.aluCtl.poke(10.U)             //expected output(42e9570a)
    //   c.clock.step(100)

      

      //fail
      // c.io.input1.poke("hc7afc800".U)    //-9e4
      // c.io.input2.poke("hc7afc800".U)    //-9e4
      // c.io.aluCtl.poke(10.U)             //expected output(c82fc800)
      // c.clock.step(100)
    }
  }
}
