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

            string builtString = "";
            
            List<int> isolatedDigits = GetIntList(number);
            List<string> singleRomanValues = new List<string>();

            for (int position = 0; position < isolatedDigits.Count; position++)
            {
                singleRomanValues.Add(RomanParser.GetItem(isolatedDigits[position], position, settings));
            }

            singleRomanValues.Reverse();

            foreach (var value in singleRomanValues)
            {
                builtString += value;
            }

            return RomanBeautify.Enclosure(builtString, settings);
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
