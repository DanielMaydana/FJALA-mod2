using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using CustomDataTypes;
using UtilityClasses;

namespace UnitTests
{
    [TestClass]
    public class UnitTestsMyVector
    {
        [TestMethod]
        public void TestMyVectorEmptyConstructor()
        {
            MyVector vectorA = new MyVector();

            Assert.AreEqual(0, vectorA.xCoordinate);
            Assert.AreEqual(0, vectorA.yCoordinate);
        }
        [TestMethod]
        public void TestMyVector()
        {
            MyVector vectorA = new MyVector(1, -1);
            MyVector vectorB = MyVector.StrToVect("1, -1");

            Assert.AreEqual(true, VectorMath.Equal(vectorA, vectorB));

        }
    }
}
