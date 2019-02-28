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
            MyVector vectorA = new MyVector(1, -1);
            MyVector vectorB = MyVector.StringToVector("1, -1");

            Assert.AreEqual(true, VectorMath.Equal(vectorA, vectorB));

        }
    }
}
