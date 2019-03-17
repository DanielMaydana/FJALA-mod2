using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public class KinoSeat
    {
        public int Row { get; set; }
        public int Col { get; set; }
        public int AbsolutePosition { get; set; }
        public bool Availability { get; set; }

        public KinoSeat(int row, int col, bool availability, int absolute)
        {
            Row = row;
            Col = col;
            Availability = availability;
            AbsolutePosition = absolute;
        }

        public static bool operator ==(KinoSeat seatA, KinoSeat seatB)
        {
            return seatA.Row == seatB.Row && seatA.Col == seatB.Col && seatA.Availability == seatB.Availability && seatA.AbsolutePosition == seatB.AbsolutePosition;
        }

        public static bool operator !=(KinoSeat seatA, KinoSeat seatB)
        {
            return seatA.Row != seatB.Row || seatA.Col != seatB.Col || seatA.Availability != seatB.Availability || seatA.AbsolutePosition != seatB.AbsolutePosition;
        }

        public static bool CompareRelativePosition(KinoSeat seatA, KinoSeat seatB)
        {
            return seatA.Row == seatB.Row && seatA.Col == seatB.Col && seatA.Availability == seatB.Availability;
        }
    }
}
