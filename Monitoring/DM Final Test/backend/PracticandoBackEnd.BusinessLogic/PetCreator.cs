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
    public class PetCreator
    {
        public StorePet storePet { get; set; }

        public PetCreator()
        {
            this.storePet = new StorePet();
        }
        public ServicesDataResult<PetDTO> createPet(PetDTO petDTO)
        {
            Pet pet = new Pet()
            {
                IdPet = Guid.NewGuid(),
                Name = petDTO.Name,
                IdPerson = petDTO.IdPerson
                
            };

            DataResult data = this.storePet.create(pet);

            return new ServicesDataResult<PetDTO>(data.Message, petDTO);
        }
    }
}
