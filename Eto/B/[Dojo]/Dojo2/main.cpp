#include "Integer.h"
#include "String.h"
#include "HashMap.h"
#include <cstdio>
#include <ctime>

void show(const IHashable &h, const Object &val)
{
    printf("%s %s\n", h.to_string().data(), val.to_string().data());
}

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

    HashMap hm2;
    for (size_t i = 0; i < 10'000'000; i++)
    {
        hm2.add(new String(std::to_string(i)), new Integer(i));
    }
    //hm2.iterate(show);
    puts("************");
    auto t0 = clock();
    puts(hm2[String("9999999")].to_string().data());
    auto t1 = clock();
    printf("%ld\n", (t1 - t0) / CLOCKS_PER_SEC);

    // puts(hm[Integer(20)].to_string().data());

    // try
    // {
    //     puts(hm[Integer(25)].to_string().data());
    // }
    // catch (const std::exception &e)
    // {
    //     puts(e.what());
    // }

    //     puts("******");

    // hm.iterate(show);
}