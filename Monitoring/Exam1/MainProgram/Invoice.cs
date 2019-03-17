using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class Invoice
    {
        string code { get; set; }
        string name { get; set; }
        double balance { get; set; }

        Invoice(string code, string name, double balance)
        {
            this.code = code;
            this.name = name;
            this.balance = balance;
        }
    }
}
