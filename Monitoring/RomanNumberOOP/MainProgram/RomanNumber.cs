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

        public RomanNumber(int value, RomanSettings settings)
        {
            RomanString = RomanBuilder.Build(value, settings);
            RomanValue = Math.Abs(value);
        }

        public RomanNumber(string value, RomanSettings settings)
        {
            int.TryParse(value, out int auxValue);

            RomanString = RomanBuilder.Build(auxValue, settings);
            RomanValue = Math.Abs(auxValue);
        }
    }
}
