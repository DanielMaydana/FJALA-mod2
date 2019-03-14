using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class RomanBeautify
    {
        public static string ConcatAndFormat(List<string> romanArray, RomanSettings settings)
        {
            Tuple<string, string, string> ornaments = Enclosure(settings);

            string builtString = "";

            for (int i = 0; i < romanArray.Count; ++i)
            {
                if (i == 0)
                {
                    builtString = $"{builtString}{ornaments.Item1}";
                }
                if (i < romanArray.Count)
                {
                    builtString = $"{builtString}{romanArray[i]}";
                }
                if (romanArray.Count > 1 && i < (romanArray.Count - 1))
                {
                    builtString = $"{builtString}{ornaments.Item2}";
                }
                if (i == (romanArray.Count - 1))
                {
                    builtString = $"{builtString}{ornaments.Item3}";
                }

                Console.WriteLine(builtString);
            }

            return builtString;
        }
    
        private static Tuple<string, string, string> Enclosure(RomanSettings settings)
        {
            string[] splitted = settings.beautifier.Split(',');

            Tuple<string, string, string> enclosure = new Tuple<string, string, string>(splitted[0], splitted[1], splitted[2]);
            
            return enclosure;
        }
    }
}
