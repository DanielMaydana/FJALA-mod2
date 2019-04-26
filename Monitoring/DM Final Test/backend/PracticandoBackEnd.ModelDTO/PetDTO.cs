using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.ModelDTO
{
    public class PetDTO
    {
        public Guid IdPet { get; set; }

        public string Name { get; set; }

        public Guid IdPerson { get; set; }
    }
}
