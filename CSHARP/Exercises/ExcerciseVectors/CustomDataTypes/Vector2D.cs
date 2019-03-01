using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomDataTypes
{
    public class Vector2D
    {
        public int XCoordinate{ get; set; }
        public int YCoordinate{ get; set; }
        private static string ExceptionNotVector = "Not a vector";

        public Vector2D(int newXCoordinate, int newYCoordinate)
        {
            XCoordinate = newXCoordinate;
            YCoordinate = newYCoordinate;
        }

        public static Vector2D StringToVector(string vectorString)
        {
            string[] coordinates = vectorString.Split(',');

            if (!int.TryParse(coordinates[0], out int newXCoordinate) || !int.TryParse(coordinates[1], out int newYCoordinate))
            {
                throw new ArgumentException(ExceptionNotVector);
            }

            return new Vector2D(newXCoordinate, newYCoordinate);
        }

        public static Vector2D operator +(Vector2D vectorA, Vector2D vectorB)
        {
            return new Vector2D(vectorA.XCoordinate + vectorB.XCoordinate, vectorA.YCoordinate + vectorB.YCoordinate);
        }


    }
}
