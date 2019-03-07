using System;
using Xunit;
using Utilities;
using CustomDataTypes;

namespace UnitTests
{
    public class RomanNumberTest
    {
        [Fact]
        public void RomanConstructedFromAString()
        {
            Assert.Equal("XV", (new RomanNumber("XV")).RomanString);
        }

        [Fact]
        public void RomanConstructedFromANumber()
        {
            Assert.Equal(12, (new RomanNumber(12)).RomanNumeral);
        }

        [Fact]
        public void CompareIdenticalRomanNumbers()
        {
            Assert.True((new RomanNumber("XV")) == (new RomanNumber(15)));
        }

        [Fact]
        public void ConstructedFromAWrongString()
        {
            Assert.Throws<ArgumentException>(() => new RomanNumber("WV"));
        }

        [Fact]
        public void ConstructedFromOutOfRangeNumber()
        {
            Assert.Throws<ArgumentOutOfRangeException>(() => new RomanNumber(5000));
        }
    }
}
