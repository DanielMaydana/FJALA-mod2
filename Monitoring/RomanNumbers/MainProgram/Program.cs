using System;
using Utilities;
using CustomDataTypes;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(RomanMath.Multiplication(new RomanNumber(1), new RomanNumber("III")).RomanString);
            Console.ReadKey();
        }
    }
}
