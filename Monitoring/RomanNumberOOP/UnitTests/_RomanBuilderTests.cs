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
            Assert.Equal("", RomanBuilder.Build(0));
        }

        [Fact]
        public void Build_Returns_Roman_Absolute_Value()
        {
            Assert.Equal("IV", RomanBuilder.Build(-4));
        }

        [Fact]
        public void Build_Returns_Correct_String_For_3459()
        {
            Assert.Equal("MMMCDLIX", RomanBuilder.Build(3459));
        }

        [Fact]
        public void Build_Returns_Incorrect_String_For_3460()
        {
            Assert.NotEqual("MMMCDLIX", RomanBuilder.Build(3460));
        }

        [Fact]
        public void Build_Cannot_Build_Numbers_Greater_Than_4999()
        {
            Assert.Throws<ArgumentException>(() => RomanBuilder.Build(5000));
        }
    }
}
