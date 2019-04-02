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
            Vector2D vectorA = new Vector2D(1, 7);
            Vector2D vectorB = new Vector2D(1, 7);

            Assert.AreEqual(true, VectorMath.Equal(vectorA, vectorB));
        }

        [TestMethod]
        public void TestNotEqual()
        {
            Vector2D vectorA = new Vector2D(5, 7);
            Vector2D vectorB = new Vector2D(2, 41);

            Assert.AreEqual(false, VectorMath.Equal(vectorA, vectorB));
        }

        [TestMethod]
        public void TestAdditonCorrect()
        {
            Vector2D vectorA = new Vector2D(1, 3);
            Vector2D vectorB = new Vector2D(3, 1);
            Vector2D actualResult = vectorA + vectorB;
            Vector2D expectedResult = new Vector2D(4, 4);

            Assert.AreEqual(true, VectorMath.Equal(actualResult, expectedResult));
        }

        public void TestAdditonIncorrect()
        {
            Vector2D vectorA = new Vector2D(0, 6);
            Vector2D vectorB = new Vector2D(22, 3);
            Vector2D actualResult = vectorA + vectorB;
            Vector2D expectedResult = new Vector2D(55, 88);

            Assert.AreEqual(false, VectorMath.Equal(actualResult, expectedResult));
        }

        [TestMethod]
        public void TestDotProductCorrect()
        {
            Vector2D vectorA = new Vector2D(9, 3);
            Vector2D vectorB = new Vector2D(5, 4);

            Assert.AreEqual(VectorMath.DotProduct(vectorA, vectorB), 57);
        }

        public void TestDotProductIncorrect()
        {
            Vector2D vectorA = new Vector2D(1, 7);
            Vector2D vectorB = new Vector2D(2, 9);

            Assert.AreNotEqual(VectorMath.DotProduct(vectorA, vectorB), 888);
        }

        [TestMethod]
        public void TestLengthCorrect()
        {
            Vector2D vectorA = new Vector2D(8, 6);

            Assert.AreEqual(10, VectorMath.Length(vectorA));
        }

        [TestMethod]
        public void TestLengthIncorrect()
        {
            Vector2D vectorA = new Vector2D(11, 22);

            Assert.AreNotEqual(34, VectorMath.Length(vectorA));
        }
    }
}
