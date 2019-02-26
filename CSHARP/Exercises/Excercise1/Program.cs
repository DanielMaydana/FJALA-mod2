using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Excercise1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<MyVector> vectList = new List<MyVector>();
            MyVector additionResult = new MyVector();

            foreach (string strVect in args)
            {
                vectList.Add(MyVector.atovect(strVect));
            }

            foreach(MyVector singleVector in vectList)
            {
                additionResult += singleVector;
            }

            additionResult.printVector();

            Console.ReadKey();

        }

    }
}