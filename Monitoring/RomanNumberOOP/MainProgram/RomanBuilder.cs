using System;
using System.Collections.Generic;

namespace MainProgram
{
    public static class RomanBuilder
    {
        public static string Build(int number)
        {
            
            string built = "";
            List<int> isolatedDigits = GetIntList(number);
            List<string> singleRomanValues = new List<string>();

            for (int position = 0; position < isolatedDigits.Count; position++)
            {
                singleRomanValues.Add(RomanParser.GetItem(isolatedDigits[position], position));
            }

            singleRomanValues.Reverse();

            foreach (var value in singleRomanValues)
            {
                built += value;
            }

            return built; 
        }

        private static List<int> GetIntList(int num)
        {
            List<int> listOfInts = new List<int>();

            while (num > 0)
            {
                listOfInts.Add(num % 10);
                num = num / 10;
            }

            return listOfInts;
        }
    }
}
