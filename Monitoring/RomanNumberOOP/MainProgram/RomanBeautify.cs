using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class RomanBeautify
    {
        public static string Enclosure(string built, RomanSettings settings)
        {
            return $"{RomanOrnaments.Enclosing[settings.enclosure].Open}{built}{RomanOrnaments.Enclosing[settings.enclosure].Closing}";
        }
    }
}
