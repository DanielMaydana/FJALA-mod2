using System;
using System.Collections.Generic;

namespace MainProgram
{
    public class ConversionTable
    {
        public static List<string> RomanTableUnits = new List<string> { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix" };
        public static List<string> RomanTableTens = new List<string>() { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc" };
        public static List<string> RomanTableHundreds = new List<string>() { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm" };
        public static string RomanTableThousand = "M";
    }
}
