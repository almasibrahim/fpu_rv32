import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class exp_not_eql_Test extends FreeSpec with ChiselScalatestTester {

  "Exp not equal Test" in {
    test(new NFALU()).withAnnotations(Seq(VerilatorBackendAnnotation)){ c =>

    //   c.io.input1.poke("h418FD70A".U)     // sign bit (0) , manteesa (00011111101011100001010) , exp (10000011) , float(17.98)
    //   c.io.input2.poke("h4098F5C3".U)     //sign bit (0) , manteesa (00110001111010111000011) , exp (10000001) , float(4.78)
    //   c.io.aluCtl.poke(10.U)              //expected output (41B6147B), sign bit (0) , manteesa (01101100001010001111011) , exp (10000011) , float(22.76)
    //   c.clock.step(100)


    //   c.io.input1.poke("hC227EB85".U)     // sign bit (1) , manteesa (01001111110101110000101) , exp (10000100) , float(-41.98)
    //   c.io.input2.poke("hC17C7AE1".U)     //sign bit (1) , manteesa (11111000111101011100001) , exp (10000010) , float(-15.78)
    //   c.io.aluCtl.poke(10.U)              //expected output (C2670A3D), sign bit (1) , manteesa (11001110000101000111101) , exp (10000100) , float(-57.76)
    //   c.clock.step(100)


    //   c.io.input1.poke("h372251CF".U)     // sign bit (0) , manteesa (01000100101000111001111) , exp (01101110) , float(9.675E-6)
    //   c.io.input2.poke("h367D001B".U)     //sign bit (0) , manteesa (11111010000000000011011) , exp (01101100) , float(0.00000377)
    //   c.io.aluCtl.poke(10.U)              //expected output (376191D6), sign bit (0) , manteesa (11000011001000111010110) , exp (01101110) , float(1.3445E-5)
    //   c.clock.step(100)


    //   c.io.input1.poke("h4248676D".U)     // sign bit (0) , manteesa (10010000110011101101101) , exp (10000100) , float(50.101)
    //   c.io.input2.poke("h40B67EFA".U)     //sign bit (0) , manteesa (01101100111111011111010) , exp (10000001) , float(5.703)
    //   c.io.aluCtl.poke(10.U)              //expected output (425F374C), sign bit (0) , manteesa (10111110011011101001100) , exp (10000100) , float(55.804)
    //   c.clock.step(100)


    //   c.io.input1.poke("h35C29D9F".U)     // sign bit (1) , manteesa (10000101001110110011111) , exp (01101011) , float(0.00000145)
    //   c.io.input2.poke("h34B6893F".U)     //sign bit (1) , manteesa (01101101000100100111111) , exp (01101001) , float(0.00000034)
    //   c.io.aluCtl.poke(10.U)              //expected output (35F03FEF), sign bit (1) , manteesa (11100000011111111101111) , exp (01101011) , float(0.00000179)
    //   c.clock.step(100)


      

    }
  }
}










