using PracticandoBackEnd.ModelData;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.DataAccess
{
    public class StorePet
    {
        private readonly string successMessage = " registered successfully";
        private readonly string errorMessage = " registered failed";
        public DataResult create(Pet pet)
        {
            try
            {
                using (var context = new PracticandoContext())
                {
                    context.Pets.Add(pet);
                    context.SaveChanges();
                }

                return new DataResult()
                {
                    Message = successMessage
                };
            }
            catch
            {
                return new DataResult()
                {
                    Message = errorMessage
                };
            }
        }
    }
}
