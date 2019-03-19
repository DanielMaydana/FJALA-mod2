using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    public class DataAdapter
    {
        Tuple<List<string>, List<string>> Numberator;

        public DataAdapter(string args)
        {
            Numberator = Split(args);
        }

        private Tuple<List<string>, List<string>> Split(string args)
        {
            List<string> Numbers = new List<string>();
            List<string> Symbols = new List<string>();

            Char[] tokens = new Char[] { '+', '-', '*', '/' };

            Numbers = args.Split(tokens).ToList();
            
            for(int i = 0; i < args.Length; ++i)
            {
                foreach(var c in tokens)
                {
                    if(args[i] == c)
                    {
                        Symbols.Add(args[i].ToString());
                        break;
                    }
                }
            }

            CheckParity(Numbers, Symbols, args);

            foreach (var m in Numbers) Console.WriteLine(m + " n");
            foreach (var x in Symbols) Console.WriteLine(x + " s");

            return new Tuple<List<string>, List<string>>(Numbers, Symbols);
        }

        private void CheckParity(List<string> numbers, List<string> symbols, string args)
        {
            int numbersCharCount = 0;
            int symbolsCharCount = 0;
            int originalCount = args.Length;

            foreach(var singleNumber in numbers)
            {
                numbersCharCount += singleNumber.Length;
            }

            foreach(var singleSymbol in symbols)
            {
                symbolsCharCount += singleSymbol.Length;
            }

            if(numbersCharCount + symbolsCharCount != originalCount)
            {
                throw new ArgumentException("Error");
            }
        }
    }
}
