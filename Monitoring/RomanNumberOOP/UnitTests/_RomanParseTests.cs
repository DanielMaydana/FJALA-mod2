using System;
using Xunit;
using MainProgram;

namespace UnitTests
{
    public class _RomanParseTests
    {
        [Fact]
        public void GetItem_Returns_Empty_String_For_Parameters_Zero()
        {
            Assert.Equal("", RomanParser.GetItem(0, 0));
        }

        [Fact]
        public void GetItem_Returns_IV_Four_For_Parameters_4_0()
        {
            Assert.Equal("IV", RomanParser.GetItem(4, 0));
        }

        [Fact]
        public void GetItem_Returns_XL_Forty_For_Parameters_4_1()
        {
            Assert.Equal("XL", RomanParser.GetItem(4, 1));
        }

        [Fact]
        public void GetItem_Returns_CD_Four_Hundred_For_Parameters_4_2()
        {
            Assert.Equal("CD", RomanParser.GetItem(4, 2));
        }

        [Fact]
        public void GetItem_Returns_MMM_Three_Thousand_For_Parameters_3_3()
        {
            Assert.Equal("MMM", RomanParser.GetItem(3, 3));
        }

        [Fact]
        public void GetItem_Works_With_Order_Less_Than_3()
        {
            Assert.NotEqual("MMMM", RomanParser.GetItem(1, 4));
        }

        [Fact]
        public void GetItem_Works_With_Numbers_Less_Than_10()
        {
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 0));
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 1));
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 2));
        }

    }
}
