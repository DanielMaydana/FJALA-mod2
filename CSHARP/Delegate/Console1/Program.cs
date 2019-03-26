using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console1
{
    public delegate void SaveHandler(string data);

    class Program
    {
        static void Main(string[] args)
        {
            //SaveHandler saver = SavetToFile;
            //saver("BRMC");

            var myStock = new Stock("$");
            myStock.Price = 20m;
            myStock.PriceChangeHander += OnPriceChange;
            myStock.Price = 50m;
        }

        static void SavetToFile(string data)
        {
            using (var file = new StreamWriter("text1.txt"))
            {
                file.Write(data);
            }
        }

        static void OnPriceChange(decimal oldOne, decimal newOne)
        {
            Console.WriteLine("Price Change Handler");
        }

        class Stock
        {
            public event OnPriceChange PriceChangeHander;
            public delegate void OnPriceChange(decimal oldValue, decimal newValue);

            public string symbol;
            public decimal price;

            public Stock(string symbol)
            {
                this.symbol = symbol;
            }

            public decimal Price
            {
                get
                {
                    return price;
                }

                set
                {
                    var oldPrice = price;
                    price = value;

                    if(PriceChangeHander != null)
                    {
                        PriceChangeHander(oldPrice, price);
                    }
                }
            }
        }
    }


}
