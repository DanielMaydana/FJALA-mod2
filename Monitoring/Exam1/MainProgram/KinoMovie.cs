using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class KinoMovie
    {
        private Settings MovieSettings;
        public  List<KinoSeat> MovieSeats;
        public double Price { get; set; }

        public KinoMovie(Settings settings)
        {
            MovieSettings = settings;
            Price = settings.moviePrice;
            MovieSeats = GenerateEmptySeatList(MovieSettings);
        }

        public List<KinoSeat> BuySeats(int row, int col, int qty = 1)
        {
            List<KinoSeat> seatsToBuy = new List<KinoSeat>();
            KinoSeat startingSeat = new KinoSeat(row, col, true, -1);
            bool operationValidity = false;

            foreach (var single in MovieSeats)
            {
                if (KinoSeat.CompareRelativePosition(startingSeat, single))
                {
                    startingSeat = single;
                    operationValidity = true;
                    break;
                }
            }

            int adaptedQty = AdaptQty(qty);
            int startPosition = startingSeat.AbsolutePosition;
            int finishPosition = startPosition + adaptedQty;

            if(operationValidity == true && finishPosition >= 0 && Math.Abs(qty) <= MovieSeats.Count)
            {
                seatsToBuy = GetFreeSeats(startPosition , finishPosition, adaptedQty);
            }

            return seatsToBuy;
        }

        private List<KinoSeat> GenerateEmptySeatList(Settings settings)
        {
            List<KinoSeat> MovieSeats = new List<KinoSeat>();

            string[] aux = settings.seatsMatrix.Split(',');
            int arrowQty = int.Parse(aux[0]);
            int colQty = int.Parse(aux[1]);
            int absolutePos = 1;

            Tuple<int, int> seatMatrix = new Tuple<int, int>(arrowQty, colQty);

            for (int i = 0; i < arrowQty; i++)
            {
                for (int j = 0; j < colQty; j++)
                {
                    MovieSeats.Add(new KinoSeat(i + 1, j + 1, true, absolutePos));
                    ++absolutePos;
                }
            }

            return MovieSeats;
        }

        private int AdaptQty(int qty)
        {
            int adapted;

            if(qty < 0)
            {
                adapted = qty + 1;
            }
            else
            {
                adapted = qty - 1;
            }

            return adapted;
        }

        private List<KinoSeat> GetFreeSeats(int startPosition, int finishPosition, int adaptedQty)
        {
            List<KinoSeat> selection = new List<KinoSeat>();

            Console.WriteLine("On And On");

            //if (adaptedQty > 0)
            //{
            //    for(int i = startPosition; i <= finishPosition; ++i)
            //    {
            //        if (MovieSeats[i - 1].Availability == true)
            //        {
            //            MovieSeats[i - 1].Availability = false;
            //            selection.Add(MovieSeats[i]);
            //        }
            //    }
            //}
            //else
            //{
            //    for (int i = startPosition; i >= finishPosition; --i)
            //    {
            //        if (MovieSeats[i - 1].Availability == true)
            //        {
            //            MovieSeats[i - 1].Availability = false;
            //            selection.Add(MovieSeats[i]);
            //        }
            //    }
            //}

            return selection;
        }
    }
}