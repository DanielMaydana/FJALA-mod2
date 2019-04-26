using PracticandoBackEnd.ModelData;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.DataAccess
{
    public class StorePerson
    {
        private readonly string successMessage = " registered successfully";
        private readonly string errorMessage = " registered failed";

        public DataResult create(Person person)
        {
            try
            {
                using (var context = new PracticandoContext())
                {
                    context.People.Add(person);
                    context.SaveChanges();
                }

                return new DataResult()
                {
                    Message = $"{successMessage}"
                };
            }
            catch (Exception e)
            {
                return new DataResult()
                {
                    Message = $"{errorMessage}"
                };
            }
        }
    }
}
