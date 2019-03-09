#include "factura.h"
#include "item.h"
#include "sistema_facturacion.h"
#include <iomanip>
#include "producto.h"

factura::factura(const m_string &nombre, const m_string &nit, sistema_facturacion& sis, const fecha& f)
    :nombre{nombre},nit{nit}, descuento{0}, sis{sis}, fecha_factura{f}
{

}
void factura::agregar_item(size_t cantidad, const m_string & codigo)
{
    producto& p = sis.get_producto_por_codigo(codigo);
    if(p.get_stock() >= cantidad)
    {
        item* it = new item{cantidad,codigo, sis};
        items.add(it);
        p.reducir_stock(cantidad);
    }
    else
    {
        throw 0;
    }
}
void factura::agregar_descuento(double desc)
{

    descuento += desc;
}
void factura::mostrar() const
{
    /*cout<<nombre.get_str()<<"\t"<<nit.get_str()<<'\n';
    cout<<"ITEMS:\n\n";
    items.mostrar();*/
    cout <<"----------------------------------------------\n";
    cout<<"|Nombre: "<<setfill (' ') << setw (15)<<nombre.get_str();
    cout<<"|Nit: "<<setfill (' ') << setw (15)<<nit.get_str()<<'|'<<'\n';
    cout <<"----------------------------------------------\n";
    cout<<"|ITEMS:"<<setfill (' ') << setw (39)<<'|'<<"\n";
    cout <<"----------------------------------------------\n";
    cout <<setfill (' ') << setw (8)<< "|Cantidad|";
    cout << setfill (' ') << setw (9)<< "Marca|";
    cout << setfill (' ') << setw (9)<< "Nombre|";
    cout << setfill (' ') << setw (9)<< "Precio|";
    cout << setfill (' ') << setw (8)<< "Subtotal|"<<'\n';
    cout <<"----------------------------------------------\n";
    items.mostrar();
     cout<<"|Descuento: "<<setfill (' ') << setw (15)<<descuento;
     cout<<"|Total: "<<setfill (' ') << setw (10)<<get_precio_total()-descuento<<'|'<<'\n';
     cout <<"----------------------------------------------\n";
}

double factura::get_precio_total()const
{
    double total =0;
    for(size_t i = 0; i < items.size(); i++)
    {
        auto& p = static_cast <const item&>(items[i]);
        total += p.get_parcial();
    }
    return total;
}

const fecha& factura::get_fecha() const
{
    return fecha_factura;
}
