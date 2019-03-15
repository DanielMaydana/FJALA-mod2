using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            double db = 3.14;
            object ob = db;
            int n = (int)(double)ob;

            Console.WriteLine(n);
        }

    }
}
