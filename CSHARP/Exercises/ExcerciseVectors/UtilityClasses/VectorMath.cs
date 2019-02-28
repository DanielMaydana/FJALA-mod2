using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CustomDataTypes;

namespace UtilityClasses
{
    public static class VectorMath
    {
        public static MyVector Addition(MyVector vectorA, MyVector vectorB)
        {
            MyVector result = new MyVector();
            result.xCoordinate = vectorA.xCoordinate + vectorB.xCoordinate;
            result.yCoordinate = vectorA.yCoordinate + vectorB.yCoordinate;
            return result;
        }

        public static int DotProduct(MyVector vectorA, MyVector vectorB)
        {
            int result = vectorA.xCoordinate*vectorB.xCoordinate + vectorA.yCoordinate*vectorB.yCoordinate;
            return result;
        }

        public static double Length(MyVector vector)
        {
            double s = Math.Sqrt(Math.Pow(vector.xCoordinate, 2) + Math.Pow(vector.yCoordinate, 2));
            return s;
        }

        public static Boolean Equal(MyVector vectorA, MyVector vectorB)
        {
            bool result = false;
            if( vectorA.xCoordinate == vectorB.xCoordinate && vectorA.yCoordinate == vectorB.yCoordinate)
            {
                result = true;
            }

            return result;
        }
    }
}
