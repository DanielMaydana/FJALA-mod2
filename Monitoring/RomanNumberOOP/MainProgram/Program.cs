using System;
using System.Configuration;
using System.Collections.Generic;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            RomanSettings settings = new RomanSettings();
            //settings.casing = int.Parse(ConfigurationManager.AppSettings["caseSwitch"]);
            //settings.enclosure = int.Parse(ConfigurationManager.AppSettings["bracketSwitch"]);

            Console.WriteLine((new RomanNumber(222, settings)).RomanString);

            //Console.WriteLine($"{RomanBuilder.Build(3459, new RomanSettings())} | {"MMMCDLIX"}");

            Console.ReadKey();
        }
    }
}
