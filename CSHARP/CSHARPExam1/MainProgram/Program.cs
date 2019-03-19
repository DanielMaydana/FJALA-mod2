using System;
using System.Collections.Generic;
using MainProgram.Parts;

namespace MainProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            PartOperation operation = new PartOperation();

            var window1 = operation.Create<Window>();
            var wheel1 = operation.Create<Wheel>();

            window1.GlassType = "Darkened";
            wheel1.Radius = 22;

            Console.WriteLine(window1.Id);
            Console.WriteLine(wheel1.Id);

            operation.Save<PartBase>(window1);
            operation.Save<PartBase>(wheel1);

        }
    }
}
