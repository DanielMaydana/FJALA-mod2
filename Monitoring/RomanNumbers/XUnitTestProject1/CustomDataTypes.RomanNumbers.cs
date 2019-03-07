using System;
using Xunit;
using CustomDataTypes;

namespace UnitTests.RomanNumbers
{
    public class RomanNumbers
    {
        [Fact]
        public void ConstructedFromStringIsOK()
        {
            Assert.Equals(true, (new RomanNumber(22)) == (new RomanNumber(22)));
        }
    }
}
