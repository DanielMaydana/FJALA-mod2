#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
//prototipos
class ITransaccion
{
private:
    
public:
    ITransaccion() { }
    virtual ~ITransaccion() { }
    virtual void ejecutar()=0;
};

enum class TipoCuenta
{
    Efectivo = 1
};

class ICuenta
{
  private:
  public:
    virtual double Saldo() const = 0;
    virtual ~ICuenta() {}
    virtual void restarMonto(const double m)=0;
};

class Cuenta : public ICuenta
{
  private:
    TipoCuenta tipo;
    char *value;
    double monto;

  public:
    double Saldo() const
    {
        return monto;
    }
    Cuenta(TipoCuenta tipo, const char *value, double monto)
        : tipo{tipo}, monto{monto}
    {
        size_t len = strlen(value);
        this->value = (char *)malloc(len + 1);
        memcpy(this->value, value, len + 1);
    }
    ~Cuenta()
    {}
    void restarMonto(const double m){
        monto -= m;
    }
};

class IBilletera
{
  private:
    /* data */
  public:
    IBilletera(/* args */) {}
    virtual ~IBilletera() {}

    virtual ICuenta *CrearCuenta(TipoCuenta tipo, const char *value, double monto)= 0;
    virtual void RealizarTransaccion(ITransaccion& trans)=0;
    
    virtual double BalanceGeneral() const=0;
};



class BilleteraPersonal : public IBilletera
{
  private:
    char *nombre;
    char *apellido;
    Cuenta *cuentas;
  public:
    BilleteraPersonal(const char *nombre, const char *apellido)
    {
        size_t len = strlen(nombre);
        this->nombre = (char *)malloc(len + 1);
        memcpy(this->nombre, nombre, len + 1);
        size_t len2 = strlen(apellido);
        this->apellido = (char *)malloc(len2 + 1);
        memcpy(this->apellido, apellido, len2 + 1);
    }
    ~BilleteraPersonal() {}

    ICuenta *CrearCuenta(TipoCuenta tipo, const char *value, double monto)
    {
        Cuenta *c = new Cuenta(tipo, value, monto);
        cuentas = c;
        return c;
    }
    void RealizarTransaccion(ITransaccion& trans){
        trans.ejecutar();
    }
    double BalanceGeneral() const{
        return cuentas->Saldo();
    }
};






class Retiro : public ITransaccion
{
private:
    ICuenta& cuenta;
    double monto;
public:
    Retiro(ICuenta& cu, double tr)
    : cuenta { cu}, monto {tr}
    {

    }
    ~Retiro() { }
    void ejecutar(){
        cuenta.restarMonto(monto);
    }
};

bool test1()
{
    // return false;

    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");
    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial

    bool assertion = (efectivo->Saldo() == 100);

    delete billetera;

    return assertion;
}

bool test2()
{
    
    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");
    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    ITransaccion *transaccion = new Retiro(*efectivo, 20);
    billetera->RealizarTransaccion(*transaccion);

    bool assertion = (billetera->BalanceGeneral() == 80);

    delete billetera;
    delete transaccion;

    return assertion;
    return false;
}

bool test3()
{
    
    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");

    IContacto *contacto = billetera->CrearContacto("Juan", "Peralta");

    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    ICuenta *corriente = billetera->CrearCuenta(TipoCuenta::Corriente, "corriente", 200); // 200 es el saldo inicial

    ITransaccion *transaccion1 = new Retiro(*efectivo, 10, *contacto);
    billetera->RealizarTransaccion(*transaccion1);

    ITransaccion *transaccion2 = new Retiro(*corriente, 30, *contacto);
    billetera->RealizarTransaccion(*transaccion2);// emtregar a otro, sobrecargar este metodo

    vector<IContacto> contactos = billetera->Contactos();
    int montoTotalEntregadoAJuan = billetera->TotalEntregadoAContacto(contactos[0]);

    bool assertion =
        (
            billetera->BalanceGeneral() == 260 &&
            montoTotalEntregadoAJuan == 40
        );

    delete billetera;
    delete transaccion1;
    delete transaccion2;

    return assertion;
    return false;

}

bool test4()
{
    return false;
    
    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");

    IContacto *contacto = billetera->CrearContacto("Juan", "Peralta");

    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    ICuenta *deudas = billetera->CrearCuenta(TipoCuenta::Deuda, "deudas", 0); // 0 es el saldo inicial
    //a la derecha
    ITransaccion *transferencia = new Transferencia(*deudas, *efectivo, 50, *contacto); // sacamos 50 de deudas y los metemos a efectivo, ademas registramos al contacto en esas operaciones
    billetera->RealizarTransaccion(*transferencia);

    vector<IContacto> contactos = billetera->Contactos();
    int montoAdeudadoAJuan = deudas->Saldo(contactos[0]); // la cuenta deudas deberia tener un valor -50 registrado a nombre de Juan Peralta, si hubiesen mas transacciones registradas a nombre de Juan Peralta en esta cuenta, la funcion Saldo recibiendo el parametro de tipo IContacto deberia contabilizar el total de esas transacciones registradas con ese contacto

    bool assertion =
        (
            billetera->BalanceGeneral() == 100 &&
            montoAdeudadoAJuan == -50
        );

    delete billetera;
    delete transferencia;

    return assertion;

}

bool test5()
{
    return false;
    
    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");

    IContacto *juan = billetera->CrearContacto("Juan", "Peralta");
    IContacto *pedro = billetera->CrearContacto("Pedro", "Lima");

    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    ICuenta *deudas = billetera->CrearCuenta(TipoCuenta::Deuda, "deudas", 0); // 0 es el saldo inicial

    ITransaccion *deposito = new Deposito(*efectivo, 30, *juan);
    billetera->RealizarTransaccion(*deposito);

    ITransaccion *transferencia = new Transferencia(*deudas, *efectivo, 20, *pedro);
    billetera->RealizarTransaccion(*transferencia);

    ITransaccion *retiro = new Retiro(*efectivo, 10);
    billetera->RealizarTransaccion(*transaccion2);

    bool assertion =
        (
            billetera->ImprimirTransacciones().compare(
                "tipo de transaccion,nombre de cuenta origen,nombre de cuenta destino,contacto,monto\n"
                "apertura de cuenta,,efectivo,,100\n"
                "apertura de cuenta,,deudas,,0\n"
                "deposito,,efectivo,Juan Peralta,30\n"
                "transferencia,deudas,efectivo,Pedro Lima,20\n"
                "retiro,efectivo,,,10\n"
            ) == 0
        );

    delete billetera;
    delete deposito;
    delete transferencia;
    delete retiro;

    return assertion;

}

class TestSuite
{
    unsigned int passed;
    unsigned int executed;

  public:
    TestSuite() : passed(0), executed(0)
    {
    }

    void run(bool (*test)())
    {
        bool r = test();
        passed += (unsigned int)r;
        executed++;
        string result = r ? "PASSED" : "FAILED";
        printf("Test #%d %s\n", executed, result.c_str());
    }

    unsigned int getPassed() const
    {
        return passed;
    }

    unsigned int getExecuted() const
    {
        return executed;
    }
};

int main()
{
    TestSuite testSuite;

    testSuite.run(test1);
    testSuite.run(test2);
    testSuite.run(test3);
    testSuite.run(test4);
    testSuite.run(test5);

    printf("FINAL SCORE: %d / %d\n", testSuite.getPassed() * 20, testSuite.getExecuted() * 20);
}