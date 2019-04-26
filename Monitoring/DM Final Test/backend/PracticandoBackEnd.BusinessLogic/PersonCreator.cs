using PracticandoBackEnd.DataAccess;
using PracticandoBackEnd.ModelData;
using PracticandoBackEnd.ModelDTO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.BusinessLogic
{
    public class PersonCreator
    {
        public StorePerson storePerson { get; set; }

        public PersonCreator()
        {
            this.storePerson = new StorePerson();
        }

        public ServicesDataResult<PersonDTO> createPerson(PersonDTO personDTO)
        {
            Person person = new Person()
            {
                IdPerson = Guid.NewGuid(),
                Name = personDTO.Name
            };

            DataResult data = this.storePerson.create(person);

            return new ServicesDataResult<PersonDTO>(data.Message, personDTO);
        }
    }
}
