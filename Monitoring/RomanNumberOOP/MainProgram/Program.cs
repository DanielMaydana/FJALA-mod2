using System;
using System.Configuration;
using System.Collections.Generic;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine((new RomanNumber(22)).RomanString);

            //List<string> RomanTableUnits = new List<string> { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

            //var test = ConfigurationManager.AppSettings["caseSelector"].ToString();

            //Console.WriteLine(test);

            //Console.WriteLine(Settings.Instance.CaseSelector.CaseSelection);

            Console.WriteLine($"{RomanBuilder.Build(3459)} | {"MMMCDLIX"}");

            Console.ReadKey();
        }
    }
}
