using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.ModelData
{
    public class Person
    {
        [Key]
        public Guid IdPerson { get; set; }

        public string Name { get; set; }

        public ICollection<Pet> Pets { get; set; }
    }
}
