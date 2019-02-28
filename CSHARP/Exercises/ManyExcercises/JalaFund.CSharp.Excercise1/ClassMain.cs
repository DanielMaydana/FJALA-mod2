using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CustomDataTypes;
using UtilityClasses;

namespace JalaFund.CSharp.Excercise1
{
    class ClassMain
    {
        static void Main(string[] args)
        {
            List<MyVector> vectList = new List<MyVector>();
            MyVector additionResult = new MyVector();

            try
            {
                foreach (string strVect in args)
                {
                    vectList.Add(MyVector.StrToVect(strVect));
                }

                foreach (MyVector singleVector in vectList)
                {
                    additionResult = VectorMath.Addition(additionResult, singleVector);
                }

                Console.WriteLine(additionResult.xCoordinate + "," + additionResult.yCoordinate);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e);
            }

            Console.WriteLine(VectorMath.DotProduct(new MyVector(2, 2), new MyVector(1, 1)) + " midnight rambler");


            Console.ReadKey();

        }
    }
}
