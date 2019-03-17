using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class KinoCart
    {
        KinoMovie Movie;
        Settings CartSettings;
        int finalPrice;

        public KinoCart(Settings settings)
        {
            CartSettings = settings;
            Movie = new KinoMovie(settings);
        }

        public int Buy(int qty, int price)
        {
            CheckExceptions(qty);
            finalPrice = qty * price;
            return finalPrice;
        }

        public List<KinoTicket> BuyManyTickets(KinoSeat start, KinoSeat finish)
        {
            List<KinoTicket> BoughtTickets = new List<KinoTicket>();
            
            return BoughtTickets;
        }

        private void CheckExceptions(int qty)
        {
            if (qty < 0) throw new ArgumentException("Quantity can't be less than 0");
        }
    }
}
