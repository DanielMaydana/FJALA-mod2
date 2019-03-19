using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using MainProgram.Parts;


namespace MainProgram
{
    public class PartOperation // where T : PartBase
    {
        private List<string> PartsDB;

        public T Create<T>() where T : new()
        {
            return new T();
        }

        private void Save<T>(T _part)
        {
            Type t = _part.GetType();

            PropertyInfo prop = t.GetProperty("Items");

            object list = prop.GetValue(_part);

            //_part.;
            //string builtString = "";

            //return builtString;
        }

    }
}
