using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MainProgram
{
    public abstract class PartBase
    {
        public Guid Id { get; private set; }

        public PartBase()
        {
            Id = Guid.NewGuid();
        }
    }
}
