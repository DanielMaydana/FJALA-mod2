using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class RomanNumber
    {
        public string RomanString { get; private set; }
        public int RomanValue { get; private set; }

        public RomanNumber(int value)
        {
            RomanString = RomanBuilder.Build(value);
            RomanValue= value;
        }

        public RomanNumber(string value)
        {
            int.TryParse(value, out int auxValue);
            RomanString = RomanBuilder.Build(auxValue);
            RomanValue = auxValue;
        }

    }
}
