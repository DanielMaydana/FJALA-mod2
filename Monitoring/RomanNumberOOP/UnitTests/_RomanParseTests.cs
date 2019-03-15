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
            RomanSettings testSetting = new RomanSettings();

            Assert.Equal("", RomanParser.GetItem(0, 0, testSetting));
        }

        [Fact]
        public void GetItem_Returns_Uppercase_Four_For_Digit_4_Order_0()
        {
            RomanSettings testSetting = new RomanSettings();

            Assert.Equal("IV", RomanParser.GetItem(4, 0, testSetting));
        }

        [Fact]
        public void GetItem_Returns_Lowercase_Forty_For_Digit_4_Order_1()
        {
            //.AppSettings["bracketSwitch"] = { x};
            RomanSettings testSetting = new RomanSettings();
            testSetting.casing = 0;

            Assert.Equal("xl", RomanParser.GetItem(4, 1, testSetting));
        }

        [Fact]
        public void GetItem_Returns_Uppercase_Four_Hundred_For_Digit_4_Order_2()
        {
            RomanSettings testSetting = new RomanSettings();

            Assert.Equal("CD", RomanParser.GetItem(4, 2, testSetting));
        }

        [Fact]
        public void GetItem_Returns_Uppercase_Three_Thousand_For_Digit_3_Order_3()
        {
            RomanSettings testSetting = new RomanSettings();

            Assert.Equal("MMM", RomanParser.GetItem(3, 3, testSetting));
        }

        [Fact]
        public void GetItem_Works_With_Order_Less_Than_3()
        {
            Assert.NotEqual("MMMM", RomanParser.GetItem(1, 4, new RomanSettings()));
        }

        [Fact]
        public void GetItem_Works_With_Numbers_Less_Than_10()
        {
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 0, new RomanSettings()));
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 1, new RomanSettings()));
            Assert.Throws<ArgumentOutOfRangeException>(() => RomanParser.GetItem(11, 2, new RomanSettings()));
        }
    }
}
