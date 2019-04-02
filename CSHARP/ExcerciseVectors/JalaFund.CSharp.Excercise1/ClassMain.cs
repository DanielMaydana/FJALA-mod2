using System;
using System.Collections.Generic;
using CustomDataTypes;
using UtilityClasses;

namespace JalaFund.CSharp.Excercise1
{
    class ClassMain
    {
        static void Main(string[] args)
        {
            List<Vector2D> vectorList = new List<Vector2D>();
            Vector2D additionResult = new Vector2D(0, 0);

            try
            {
                foreach (string vectorString in args)
                {
                    vectorList.Add(Vector2D.StringToVector(vectorString));
                }

                foreach (Vector2D singleVector in vectorList)
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