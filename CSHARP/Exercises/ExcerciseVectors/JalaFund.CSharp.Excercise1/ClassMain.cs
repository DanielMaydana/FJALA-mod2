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
            List<MyVector> vectorList = new List<MyVector>();
            MyVector additionResult = new MyVector(0, 0);

            try
            {
                foreach (string vectorString in args)
                {
                    vectorList.Add(MyVector.StringToVector(vectorString));
                }

                foreach (MyVector singleVector in vectorList)
                {
                    additionResult += singleVector;
                }

                Console.WriteLine(additionResult.XCoordinate + "," + additionResult.YCoordinate);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e);
            }

            Console.ReadKey();

        }
    }
}
