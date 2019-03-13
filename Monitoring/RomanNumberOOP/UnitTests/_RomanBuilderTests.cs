using System;
using Xunit;
using MainProgram;

namespace UnitTests
{
    public class _RomanBuilderTests
    {
        [Fact]
        public void Build_Returns_Empty_String_For_Number_0()
        {
            Assert.Equal("", RomanBuilder.Build(0, new RomanSettings()));
        }

        [Fact]
        public void Build_Returns_Empty_String_For_Negative_Numbers()
        {
            Assert.Equal("", RomanBuilder.Build(-4, new RomanSettings()));
        }

        [Fact]
        public void Build_Returns_Uppercase_String_Enclosed_In_Parenthesis_For_3459()
        {
            RomanSettings testSettings = new RomanSettings();
            testSettings.enclosure = 1;

            Assert.Equal("(MMMCDLIX)", RomanBuilder.Build(3459, testSettings));
        }

        [Fact]
        public void Build_Returns_Incorrect_String_For_3460()
        {
            Assert.NotEqual("MMMCDLIX", RomanBuilder.Build(3460, new RomanSettings()));
        }

        [Fact]
        public void Build_Cannot_Build_Numbers_Greater_Than_4999()
        {
            Assert.Throws<ArgumentException>(() => RomanBuilder.Build(5000, new RomanSettings()));
        }
    }
}
