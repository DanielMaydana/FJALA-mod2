using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.ModelData
{
    public class Pet
    {
        [Key]
        public Guid IdPet { get; set; }

        public string Name { get; set; }

        public Person CustomPerson { get; set; }

        public Guid IdPerson { get; set; }
    }
}
