using System;
using CustomDataTypes;

namespace Utilities
{
    public class RomanMath
    {
        public static RomanNumber Addition(RomanNumber RomanA, RomanNumber RomanB)
        {
            return new RomanNumber(RomanStringToInt(RomanA.RomanString) + RomanStringToInt(RomanB.RomanString));
        }

        public static RomanNumber Substraction(RomanNumber RomanA, RomanNumber RomanB)
        {
            return new RomanNumber(RomanStringToInt(RomanA.RomanString) - RomanStringToInt(RomanB.RomanString));
        }

        public static RomanNumber Division(RomanNumber RomanA, RomanNumber RomanB)
        {
            if (RomanB.RomanNumeral == 0) throw new ArgumentException("Can't divide by zero");
            return new RomanNumber(RomanStringToInt(RomanA.RomanString) / RomanStringToInt(RomanB.RomanString));
        }

        public static RomanNumber Multiplication(RomanNumber RomanA, RomanNumber RomanB)
        {
            return new RomanNumber(RomanStringToInt(RomanA.RomanString) * RomanStringToInt(RomanB.RomanString));
        }

        #region Private Functions
        private static int RomanStringToInt(string romanString)
        {
            int res = 0;

            for (int i = 0; i < romanString.Length; i++)
            {
                int romanSymbolA = RomanValue(romanString[i]);

                if (i + 1 < romanString.Length)
                {
                    int romanSymbolB = RomanValue(romanString[i + 1]);

                    if (romanSymbolA >= romanSymbolB)
                    {
                        res = res + romanSymbolA;
                    }
                    else
                    {
                        res = res + romanSymbolB - romanSymbolA;
                        i++;
                    }
                }
                else
                {
                    res = res + romanSymbolA;
                    i++;
                }
            }

            return res;
        }

        private static int RomanValue(char RomanDigit)
        {
            if (RomanDigit == 'I') return 1;
            if (RomanDigit == 'V') return 5;
            if (RomanDigit == 'X') return 10;
            if (RomanDigit == 'L') return 50;
            if (RomanDigit == 'C') return 100;
            if (RomanDigit == 'D') return 500;
            if (RomanDigit == 'M') return 1000;
            return -1;
        }
        #endregion
    }
}
