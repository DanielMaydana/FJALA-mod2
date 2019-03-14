using System;
using System.Collections.Generic;

namespace MainProgram
{
    public static class RomanBuilder
    {
        public static string Build(int number, RomanSettings settings)
        {
            if (number > 4999)
            {
                throw new ArgumentException("Numbers above 4999 not supported");
            }

            List<int> splittedDigits = GetIntList(number);
            List<string> splittedRomanDigits = new List<string>();
            string singleRoman;

            for (int position = 0; position < splittedDigits.Count; position++)
            {
                singleRoman = RomanParser.GetItem(splittedDigits[position], position, settings);

                if (singleRoman != "")
                {
                    splittedRomanDigits.Add(singleRoman);
                }
            }

            splittedRomanDigits.Reverse();

            return RomanBeautify.ConcatAndFormat(splittedRomanDigits, settings);
        }

        private static List<int> GetIntList(int num)
        {
            List<int> listOfInts = new List<int>();

            while (num > 0)
            {
                listOfInts.Add(num % 10);
                num /= 10;
            }

            return listOfInts;
        }
    }
}
