using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomDataTypes
{
    public class MyVector
    {
        public int xCoordinate { get; set; }
        public int yCoordinate { get; set; }

        public MyVector(int newXCoordinate, int newYCoordinate)
        {
            xCoordinate = newXCoordinate;
            yCoordinate = newYCoordinate;
        }
        public MyVector()
        {
        }

        public static MyVector StrToVect(string vectorAsStr)
        {
            MyVector converted = new MyVector();
            string[] coordinates = vectorAsStr.Split(',');

            if (!int.TryParse(coordinates[0], out int newXCoordinate) || !int.TryParse(coordinates[1], out int newYCoordinate))
            {
                throw new ArgumentException("Not a vector");
            }
            converted.xCoordinate = newXCoordinate;
            converted.yCoordinate = newYCoordinate;

            return converted;
        }

    }
}
