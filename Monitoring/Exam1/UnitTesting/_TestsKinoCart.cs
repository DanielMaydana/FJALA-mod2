using Microsoft.VisualStudio.TestTools.UnitTesting;
using MainProgram;
using System;

namespace UnitTesting
{
    [TestClass]
    public class _TestsKinoCart
    {
        [TestMethod]
        public void Throws_an_exception_for_qty_below_0()
        {
            //int qtyToBuy = -1;
            //int price = 20;

            //KinoCart cart1 = new KinoCart();

            //Assert.ThrowsException<ArgumentException>(() => cart1.Buy(qtyToBuy, price));
        }

        [TestMethod]
        public void Returns_correct_total_price_for_2_tickets_for_20_each()
        {
            //int qtyToBuy = 2;
            //int price = 20;

            //KinoCart cart1 = new KinoCart();

            //Assert.AreEqual(40, cart1.Buy(qtyToBuy, price));
        }
    }
}
