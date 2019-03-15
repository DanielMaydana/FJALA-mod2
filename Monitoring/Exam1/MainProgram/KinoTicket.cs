using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class KinoTicket
    {
        public KinoSeat Seat { get; private set; }
        public Invoice Bill { get; private set; }

        public KinoTicket(KinoSeat seat, Invoice bill)
        {
            Seat = seat;
            Bill = bill;
        }
    }
}
