#include "Integer.h"
#include "String.h"
#include "HashMap.h"

// void show(const IHashable &h, const Object &val)
// {
// }

int main()
{
    Object *obj = new Integer{5};
    Object *str = new String{"Hello World"};
    puts(str->to_string().data());
    puts(obj->to_string().data());
    delete str;
    delete obj;

    HashMap hm;
    hm.add(new Integer(10), new String("diez"));
    hm.add(new Integer(20), new String("veinte"));
    hm.add(new Integer(30), new String("treinta"));
    hm.add(new Integer(40), new String("cuarenta"));
    hm.add(new Integer(50), new String("cincuenta"));
    hm.add(new Integer(60), new String("sesenta"));
    hm.add(new Integer(70), new String("setenta"));

    //     puts(hm[Integer(20)].data());

    //     try
    //     {
    //         puts(hm[Integer(25)].data());
    //     }
    //     catch (const std::exception &e)
    //     {
    //         puts(e.what());
    //     }

    //     puts("******");

    //     hm.iterate(show);
}