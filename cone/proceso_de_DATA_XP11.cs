using System;
public class Demo {
   public static void Main() {
    byte[] array={68,65,84,65,42,20,0,0,0,182,218,61,66,146,157,244,194,241,251,201,67,123,13,91,190,0,0,128,63,240,142,206,67,0,0,62,66,0,0,244,194}; 
      byte[] arr = {182,218,61,66,146,157,244,194,241,251,201,67,123,13,91,190,0,0,128,63,240,142,206,67,0,0,62,66,0,0,244,194};
      string segmento=BitConverter.ToString(array) ;
      Console.WriteLine("Byte Array = {0} ", segmento);
      Console.WriteLine("Value 1 = "+array[0]);
      //for (int i = 0; i <= 8; i = i + 1) {
      //   Console.WriteLine("Value 1 = "+array[i]);
      //}
      Console.Write("Result: [");
      for (int i = 9; i < array.Length; i = i + 4) {
         float res = BitConverter.ToSingle(array, i);
         //Console.WriteLine("Value = "+arr[i]);
         Console.Write("  "+res);
      }
      Console.WriteLine("  ]");
   }
}
//68,65,84,65,42, 20,0,0,0, 182,218,61,66, 146,157,244,194, 241,251,201,67, 123,13,91,190, 0,0,128,63, 240,142,206,67, 0,0,62,66, 0,0,244,194,
//                              1               2                   3          4                 5           6             7           8          
