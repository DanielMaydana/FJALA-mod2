using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Excercise1
{
    class MyVector
    {
        private int m_x;
        private int m_y;

        public MyVector(int p_x, int p_y)
        {
            this.m_x = p_x;
            this.m_x = p_y;
        }
        public MyVector()
        {
        }

        public void printVector()
        {
            Console.WriteLine("[" + m_x + "," + m_y + "]");
        }

        public void setX(int p_x)
        {
            m_x = p_x;
        }

        public void setY(int p_y)
        {
            m_y = p_y;
        }

        public static MyVector operator +(MyVector p_va, MyVector p_vb)
        {
            MyVector result = new MyVector();
            result.m_x = p_va.m_x + p_vb.m_x;
            result.m_y = p_va.m_y + p_vb.m_y;
            return result;
        }

        public static MyVector atovect(string p_str)
        {
            int x, y;
            MyVector converted = new MyVector();
            string[] coordinates = p_str.Split(',');
            bool xConversion = Int32.TryParse(coordinates[0], out x);
            bool yConversion = Int32.TryParse(coordinates[1], out y);

            if (!xConversion || !yConversion)
            {
                Console.Write("ERRROOOOOOOR");
                return converted;
            }
            converted.setX(x);
            converted.setY(y);

            return converted;
        }

    }
}
