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
            int qtyToBuy = 3;
            int price = 20;

            Settings settings = new Settings();
            settings.seatsMatrix = "5,2";

            KinoMovie movie = new KinoMovie(settings);
            List<KinoSeat> boughtSeats = movie.BuySeats(1, 1, 10);

            //foreach (var seat in movie.MovieSeats)
            //{
            //    Console.WriteLine($"{seat.AbsolutePosition} => {seat.Col} x {seat.Row}");
            //}

            Console.ReadKey();
        }
    }
}
