using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using CustomDataTypes;
using UtilityClasses;

namespace UnitTests
{
    [TestClass]
    public class UnitTestsVectorMath
    {
        [TestMethod]
        public void TestEqual()
        {
            MyVector vectorA = new MyVector(1, 7);
            MyVector vectorB = new MyVector(1, 7);

            Assert.AreEqual(true, VectorMath.Equal(vectorA, vectorB));
        }

        [TestMethod]
        public void TestAdditon()
        {
            MyVector vectorA = new MyVector(1, 3);
            MyVector vectorB = new MyVector(3, 1);
            MyVector actualResult = VectorMath.Addition(vectorA, vectorB);
            MyVector expectedResult = new MyVector(4, 4);

            Assert.AreEqual(true, VectorMath.Equal(actualResult, expectedResult));
        }

        [TestMethod]
        public void TestDotProduct()
        {
            MyVector vectorA = new MyVector(9, 3);
            MyVector vectorB = new MyVector(5, 4);

            Assert.AreEqual(VectorMath.DotProduct(vectorA, vectorB), 57);
        }

        [TestMethod]
        public void TestLength()
        {
            MyVector vectorA = new MyVector(8, 6);

            Assert.AreEqual(10, VectorMath.Length(vectorA));
        }
    }
}
