using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomDataTypes
{
    public class RomanNumber
    {
        // An instance contains a string as well as a number representing the same quantity.
        // They both can be accessed through the dot operator, however they can't be modified on their own.
        public string RomanString { private set; get; }
        public double RomanNumeral { private set; get; } = 0.0D;

        List<char> upperCaseNumerals = new List<char>(new char[] { 'I', 'V', 'X', 'L', 'C', 'D', 'M' });

        // A RomanNumber can be constructed from a string like "XXII",
        // checking first that the string doesn't have illegal characters.
        public RomanNumber(string numberProspect)
        {
            CheckStringValidity(numberProspect);    
            RomanString = numberProspect;
        }

        // A RomanNumber can be constructed from a number.
        public RomanNumber(double number)
        {
            RomanString = ToRoman(number);
            RomanNumeral = number;
        }

        // The actual conversion method allows positive numbers ranging from 1 to 3999
        // due to range constraints caused by the use of recursivity.
        private static string ToRoman(double number)
        {
            if ((number < 0) || (number > 3999)) throw new ArgumentOutOfRangeException("Insert value betwheen 1 and 3999");
            if (number < 1) return string.Empty;
            if (number >= 1000) return "M" + ToRoman(number - 1000);
            if (number >= 900) return "CM" + ToRoman(number - 900);
            if (number >= 500) return "D" + ToRoman(number - 500);
            if (number >= 400) return "CD" + ToRoman(number - 400);
            if (number >= 100) return "C" + ToRoman(number - 100);
            if (number >= 90) return "XC" + ToRoman(number - 90);
            if (number >= 50) return "L" + ToRoman(number - 50);
            if (number >= 40) return "XL" + ToRoman(number - 40);
            if (number >= 10) return "X" + ToRoman(number - 10);
            if (number >= 9) return "IX" + ToRoman(number - 9);
            if (number >= 5) return "V" + ToRoman(number - 5);
            if (number >= 4) return "IV" + ToRoman(number - 4);
            if (number >= 1) return "I" + ToRoman(number - 1);
            throw new ArgumentOutOfRangeException("Something bad happened");
        }

        public static bool operator ==(RomanNumber RomanA, RomanNumber RomanB)
        {
            return RomanA.RomanNumeral == RomanB.RomanNumeral;
        }

        public static bool operator !=(RomanNumber RomanA, RomanNumber RomanB)  
        {
            return RomanA.RomanNumeral != RomanB.RomanNumeral;
        }

        // For a string to be validated it has to prove that it doesn't
        // contain nothing but uppercase roman numerals. Otherwise, an exception is throwed.
        #region CheckStringValidity
        private void CheckStringValidity(string numberProspect)
        {
            if(!upperCaseNumerals.Any(romanChar => numberProspect.Contains(romanChar)))
            {
                throw new ArgumentException("Not a valid string");
            }
        }
        #endregion
    }
}
