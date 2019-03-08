using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class ConversionTable
    {
        public static List<string> RomanTableUnits = new List<string> { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        public static List<string> RomanTableTens = new List<string>() { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        public static List<string> RomanTableHundreds = new List<string>() { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        public static string RomanTableThousand = "M";
    }
}
