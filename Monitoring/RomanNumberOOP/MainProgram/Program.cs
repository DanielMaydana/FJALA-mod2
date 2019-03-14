using System;
using System.Configuration;
using System.Collections.Generic;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            //RomanSettings settings = new RomanSettings();
            //settings.casing = int.Parse(ConfigurationManager.AppSettings["caseSwitch"]);
            //settings.enclosure = int.Parse(ConfigurationManager.AppSettings["bracketSwitch"]);

            RomanSettings settings = new RomanSettings();
            settings.beautifier = "[,_,]";
            settings.casing = 0;
            Console.WriteLine((new RomanNumber(3000, settings)).RomanString);

            Console.ReadKey();
        }
    }
}
