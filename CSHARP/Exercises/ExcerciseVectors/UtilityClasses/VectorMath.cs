using System;
using CustomDataTypes;

namespace UtilityClasses
{
    public static class VectorMath
    {
        public static int DotProduct(MyVector vectorA, MyVector vectorB)
        {
            int result = vectorA.XCoordinate*vectorB.XCoordinate + vectorA.YCoordinate*vectorB.YCoordinate;
            return result;
        }

        public static double Length(MyVector vector)
        {
            double s = Math.Sqrt(Math.Pow(vector.XCoordinate, 2) + Math.Pow(vector.YCoordinate, 2));
            return s;
        }

        public static Boolean Equal(MyVector vectorA, MyVector vectorB)
        {
            bool result = false;
            if( vectorA.XCoordinate == vectorB.XCoordinate && vectorA.YCoordinate == vectorB.YCoordinate)
            {
                result = true;
            }

            return result;
        }
    }
}
