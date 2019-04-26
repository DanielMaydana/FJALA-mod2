using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.ModelDTO
{
    public class ServicesDataResult<T>
    {
        public ServicesDataResult(string Message, T obj)
        {
            this.Message = Message;
            this.obj = obj;
        }
        public string Message { get; set; }

        public T obj { get; set; }
    }
}
