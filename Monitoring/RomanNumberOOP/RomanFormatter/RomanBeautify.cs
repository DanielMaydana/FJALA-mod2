using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RomanFormatter
{
    public class RomanBeautify
    {
        public static string Enclosure(string built, RomanSettings settings)
        {
            RomanOrnaments ornaments = SeparateSymbols(settings.enclosure);
            return "";
        }

        private static RomanOrnaments SeparateSymbols(string concat)
        {
            string openSymbol = "";
            string closingSymbol = "";

            int commaPosition = GetGommaPosition(concat);

            openSymbol = concat.Substring(0, commaPosition);

            return new RomanOrnaments(openSymbol, separatorSymbol, closingSymbol);
        }

        private static int GetGommaPosition(string concat)
        {
            int commaPosition = -1;

            for (int i = 0; i < concat.Length; ++i)
            {
                if (concat[i] == ',' && i != 0)
                {
                    if (concat[i - 1] != '\\')
                    {
                        commaPosition = i;
                        break;
                    }
                }
                else
                {
                    commaPosition = 0;
                    break;
                }
            }
            return commaPosition;
        }
    }
}
