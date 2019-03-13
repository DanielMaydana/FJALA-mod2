using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class RomanOrnaments
    {
        //public static readonly List<Dictionary<string, string>> Enclosing = new List<Dictionary<string, string>>();

        //static RomanOrnaments()
        //{
        //    Enclosing.Add(new Dictionary<string, string>() { { "open", "" }, { "closing", "" } });
        //    Enclosing.Add(new Dictionary<string, string>() { { "open", "[" }, { "closing", "]" } });
        //    Enclosing.Add(new Dictionary<string, string>() { { "open", "{" }, { "closing", "}" } });

        //}

        public static readonly List< EnclosingSymbols > Enclosing = new List< EnclosingSymbols >();

        static RomanOrnaments()
        {
            Enclosing.Add(new EnclosingSymbols());
            Enclosing.Add(new EnclosingSymbols("(", ")"));
            Enclosing.Add(new EnclosingSymbols("[", "]"));
            Enclosing.Add(new EnclosingSymbols("{", "}"));
        }


        public class EnclosingSymbols
        {
            public readonly string Open = "";
            public readonly string Closing = "";

            public EnclosingSymbols(string Open, string Closing)
            {
                this.Open = Open;
                this.Closing = Closing;
            }
            public EnclosingSymbols()
            { }

        }
    }

}
