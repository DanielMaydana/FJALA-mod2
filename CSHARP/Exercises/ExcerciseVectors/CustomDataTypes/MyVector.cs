using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomDataTypes
{
    public class MyVector
    {
        public int XCoordinate{ get; set; }
        public int YCoordinate{ get; set; }
        private static string ExceptionNotVector = "Not a vector";

        public MyVector(int newXCoordinate, int newYCoordinate)
        {
            XCoordinate = newXCoordinate;
            YCoordinate = newYCoordinate;
        }

        public static MyVector StringToVector(string vectorString)
        {
            string[] coordinates = vectorString.Split(',');

            if (!int.TryParse(coordinates[0], out int newXCoordinate) || !int.TryParse(coordinates[1], out int newYCoordinate))
            {
                throw new ArgumentException(ExceptionNotVector);
            }

            return new MyVector(newXCoordinate, newYCoordinate);
        }

        public static MyVector operator +(MyVector vectorA, MyVector vectorB)
        {
            return new MyVector(vectorA.XCoordinate + vectorB.XCoordinate, vectorA.YCoordinate + vectorB.YCoordinate);
        }


    }
}
