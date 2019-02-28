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
        public void TestNotEqual()
        {
            MyVector vectorA = new MyVector(5, 7);
            MyVector vectorB = new MyVector(2, 41);

            Assert.AreEqual(false, VectorMath.Equal(vectorA, vectorB));
        }

        [TestMethod]
        public void TestAdditonCorrect()
        {
            MyVector vectorA = new MyVector(1, 3);
            MyVector vectorB = new MyVector(3, 1);
            MyVector actualResult = vectorA + vectorB;
            MyVector expectedResult = new MyVector(4, 4);

            Assert.AreEqual(true, VectorMath.Equal(actualResult, expectedResult));
        }

        public void TestAdditonIncorrect()
        {
            MyVector vectorA = new MyVector(0, 6);
            MyVector vectorB = new MyVector(22, 3);
            MyVector actualResult = vectorA + vectorB;
            MyVector expectedResult = new MyVector(55, 88);

            Assert.AreEqual(false, VectorMath.Equal(actualResult, expectedResult));
        }

        [TestMethod]
        public void TestDotProductCorrect()
        {
            MyVector vectorA = new MyVector(9, 3);
            MyVector vectorB = new MyVector(5, 4);

            Assert.AreEqual(VectorMath.DotProduct(vectorA, vectorB), 57);
        }

        public void TestDotProductIncorrect()
        {
            MyVector vectorA = new MyVector(1, 7);
            MyVector vectorB = new MyVector(2, 9);

            Assert.AreNotEqual(VectorMath.DotProduct(vectorA, vectorB), 888);
        }

        [TestMethod]
        public void TestLengthCorrect()
        {
            MyVector vectorA = new MyVector(8, 6);

            Assert.AreEqual(10, VectorMath.Length(vectorA));
        }

        [TestMethod]
        public void TestLengthIncorrect()
        {
            MyVector vectorA = new MyVector(11, 22);

            Assert.AreNotEqual(34, VectorMath.Length(vectorA));
        }
    }
}
