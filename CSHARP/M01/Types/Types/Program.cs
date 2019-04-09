using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Types
{
    class Program
    {

        [Flags]
        public enum COLOR
        {
            red,
            blue,
            black
        }

        static void Main(string[] args)
        {
            COLOR c = COLOR.black| COLOR.blue;
            Console.WriteLine(c);
        }
    }
}
