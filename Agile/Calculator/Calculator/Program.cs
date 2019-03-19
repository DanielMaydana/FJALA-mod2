using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            string args2 = "1*2*3+4-55-111(2)";
            DataAdapter _adapter = new DataAdapter(args2);
            Console.ReadKey();
        }
    }
}
