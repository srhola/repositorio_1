using System;
public class Demo {
   public static void Main() {
      byte[] arr = {182,218,61,66,146,157,244,194,241,251,201,67,123,13,91,190,0,0,128,63,240,142,206,67,0,0,62,66,0,0,244,194};
      Console.WriteLine("Byte Array = {0} ", BitConverter.ToString(arr));
      for (int i = 0; i < arr.Length - 4; i = i + 4) {
         float res = BitConverter.ToSingle(arr, i);
         Console.WriteLine("Value = "+arr[i]);
         Console.WriteLine("Result = "+res);
      }
   }
}
//68,65,84,65,42,20,0,0,0,182,218,61,66,146,157,244,194,241,251,201,67,123,13,91,190,0,0,128,63,240,142,206,67,0,0,62,66,0,0,244,194,
