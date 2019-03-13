using System;

namespace MainProgram
{
    public class RomanParser
    {
        public static string GetItem(int number, int order, RomanSettings settings)
        {
            if (number == 0)
            {
                return "";
            }
            else
            {
                number -= 1;
                int caseSelect = settings.casing;

                switch (order)
                {
                    case 0:
                        {
                            return ConversionTable.RomanTableUnits[caseSelect][number];
                        }
                    case 1:
                        {
                            return ConversionTable.RomanTableTens[caseSelect][number];
                        }
                    case 2:
                        {
                            return ConversionTable.RomanTableHundreds[caseSelect][number];
                        }
                    case 3:
                        {
                            string thousandsString = "";

                            for (int i = 0; i <= number; i++)
                            {
                                thousandsString += ConversionTable.RomanTableThousand[caseSelect];
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
}
