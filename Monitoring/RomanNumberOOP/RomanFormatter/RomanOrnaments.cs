using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RomanFormatter
{
    public class RomanOrnaments
    {
        public readonly string Open = "";
        public readonly string Closing = "";

        public RomanOrnaments(string Open, string Separator, string Closing)
        {
            this.Open = Open;
            this.Separator = Separator;
            this.Closing = Closing;
        }
    }

}
