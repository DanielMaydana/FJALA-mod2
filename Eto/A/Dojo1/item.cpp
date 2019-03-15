#include"item.h"
#include "sistema_facturacion.h"
#include "producto.h"
#include <iomanip>
item::item(size_t cantidad, const m_string& codigo, sistema_facturacion& sis)
:cant{cantidad}, codigo{codigo}, sis{sis}
{

}

/*void item::mostrar()const
{
    const producto& p = sis.get_producto_por_codigo(codigo);
    cout << cant << "\t" << codigo.get_str() << "\n";
    cout << p.get_name().get_str() << "\n";
    cout << p.get_marca().get_str() << "\n";
    cout << p.get_precio() << "\n";
}*/

void item::mostrar()const
{
    const producto& p = sis.get_producto_por_codigo(codigo);
    cout << setw (0);
    cout <<'|';
    cout << setfill (' ') << setw (8);
    cout <<cant<<'|';
    cout << setfill (' ') << setw (8);
    cout << p.get_marca().get_str()<<'|';
    cout << setfill (' ') << setw (8);
    cout << p.get_name().get_str()<<'|';
    cout << setfill (' ') << setw (8);
    cout << p.get_precio()<<'|';
    cout << setfill (' ') << setw (8);
    cout << cant*p.get_precio()<<'|'<< "\n";
    cout <<"----------------------------------------------\n";
}

double item::get_parcial()const
{
    const producto& p = sis.get_producto_por_codigo(codigo);
    return p.get_precio()*cant;

}