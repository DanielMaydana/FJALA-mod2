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

            Assert.Equal("MMMCDLIX", RomanBuilder.Build(3459, testSettings));
        }

        [Fact]
        public void Build_Returns_Lowercase_With_Separation_Four_Thousand_For_3333()
        {
            RomanSettings testSettings = new RomanSettings();
            testSettings.beautifier = ", ,";
            testSettings.casing = 0;

            Assert.Equal("mmm ccc xxx iii", RomanBuilder.Build(3333, testSettings));
        }

        [Fact]
        public void Build_Returns_Enclosed_Lowercase_Four_Thousand_With_Separation_For_4999()
        {
            RomanSettings testSettings = new RomanSettings();
            testSettings.beautifier = "[,_,]";
            testSettings.casing = 0;

            Assert.Equal("[mmmm_cm_xc_ix]", RomanBuilder.Build(4999, testSettings));
        }

        [Fact]
        public void Build_Returns_Enclosed_Lowercase_Four_Thousand_With_Separation_For_3000()
        {
            RomanSettings testSettings = new RomanSettings();
            testSettings.beautifier = "{,_,}";
            testSettings.casing = 0;

            Assert.Equal("{mmm}", RomanBuilder.Build(3000, testSettings));
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
