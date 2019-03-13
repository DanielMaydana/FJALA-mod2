using System;
using System.Collections.Generic;

namespace MainProgram
{
    public class ConversionTable
    {
        public readonly static List<string>[] RomanTableUnits = {
            new List<string>() { "i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"},
            new List<string>() { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
        };

        public readonly static List<string>[] RomanTableTens = {
            new List<string>() { "x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc" },
            new List<string>() { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }
        };

        public readonly static List<string>[] RomanTableHundreds = {
            new List<string>() { "c", "cc", "ccc", "cd", "d", "dc", "dcc", "dccc", "cm" },
            new List<string>() { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" }
        };

        public readonly static string[] RomanTableThousand = { "m", "M" };
    }
}
