using System;
using System.Collections.Generic;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine((new RomanNumber(22)).RomanString);

            //List<string> RomanTableUnits = new List<string> { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

            RomanParser.GetItem(11, 3);

            Console.ReadKey();
        }
    }
}
