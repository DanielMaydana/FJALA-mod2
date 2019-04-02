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
        public void TestStringToVector()
        {
            Vector2D vectorA = new Vector2D(1, -1);
            Vector2D vectorB = Vector2D.StringToVector("1, -1");

            Assert.AreEqual(true, VectorMath.Equal(vectorA, vectorB));

        }
    }
}
