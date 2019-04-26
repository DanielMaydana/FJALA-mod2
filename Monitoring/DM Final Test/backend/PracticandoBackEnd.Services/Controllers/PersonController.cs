using PracticandoBackEnd.BusinessLogic;
using PracticandoBackEnd.ModelDTO;
using System.Web.Http;
using System.Web.Http.Cors;

namespace PracticandoBackEnd.Services.Controllers
{
    [EnableCors(origins: "*", headers: "*", methods: "*")]
    public class PersonController : ApiController
    {
        [HttpPost]
        public ServicesDataResult<PersonDTO> create(PersonDTO personDTO)
        {
            PersonCreator personCreator = new PersonCreator();
            return personCreator.createPerson(personDTO);
        }
    }
}