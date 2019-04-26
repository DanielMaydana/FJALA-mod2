using PracticandoBackEnd.BusinessLogic;
using PracticandoBackEnd.ModelDTO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Http.Cors;

namespace PracticandoBackEnd.Services.Controllers
{
    [EnableCors(origins: "*", headers: "*", methods: "*")]    
    public class PetController : ApiController
    {
        [HttpPost]
        public ServicesDataResult<PetDTO> create(PetDTO petDTO)
        {
            PetCreator petCreator = new PetCreator();
            return petCreator.createPet(petDTO);
        }
    }
}
