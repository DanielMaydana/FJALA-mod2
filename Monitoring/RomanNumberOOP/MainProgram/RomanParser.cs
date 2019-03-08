using System;

namespace MainProgram
{
    public class RomanParser
    {
        public static string GetItem(int number, int order)
        {
            if (number == 0)
            {
                return "";
            }
            else
            {
                number -= 1;
            }

            switch (order)
            {
                case 0:
                    {
                        return ConversionTable.RomanTableUnits[number];
                    }
                case 1:
                    {
                        return ConversionTable.RomanTableTens[number];
                    }
                case 2:
                    {
                        return ConversionTable.RomanTableHundreds[number];
                    }
                case 3:
                    {
                        string thousandsString = "";

                        for (int i = 0; i <= number; i++)
                        {
                            thousandsString += ConversionTable.RomanTableThousand;
                        }

                        return thousandsString;
                    }
                default:
                    {
                        return "";
                    }
            }
        }
    }
}
