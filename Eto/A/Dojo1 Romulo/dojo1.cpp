#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class String
{
private:
    size_t len;
    char* str;
public:
    String(const char* s) 
    :len{strlen(s)}   
    { 
        str = (char*)malloc(len+1);
        memcpy(str, s, len+1);
    }

    String() : String{""}  
    {}

    String(const String& s)   //copia
    :len{s.len}, str{(char*) malloc(s.len+1)}
    {
        memcpy(str, s.str, len+1);
    }

    ~String() 
    { 
        free(str);
    }

    String& operator = (const String& s)
    {
        if(this == &s) return *this; 
        this->~String();
        
        len = s.len;
        str = (char*) malloc(len+1);
        memcpy(str, s.str, len+1);
        return *this;
    }

    const char* c_str() const  
    {
        return str;
    }

    String operator + (const String& s) const 
    {
        String aux;  
        auto nlen = len + s.len;
        aux.str = (char*)realloc(aux.str, nlen+1);
        memcpy(aux.str, str, len);
        memcpy(aux.str + len, s.str, s.len+1);
        aux.len = nlen;
        return aux;
    }

    String& operator += (const String& s)
    {
        auto nlen = len + s.len;
        str = (char*) realloc(str, nlen+1);
        memcpy(str+len, s.str, s.len+1);
        len = nlen;
        return *this;
    }

    bool operator == (const String& s) const
    {
        bool answer = true;
        if(len == s.len)
        {
            for(size_t i = 0; i < len; i++)
            {
                if(str[i] != s.str[i])
                {
                    answer = false;
                    return answer;
                }
            }
        }
        else 
        {
            answer = false;
            return answer;
        }
        return answer;
    }

    bool operator != (const String& s) const
    {
        bool answer = false;
        if(len == s.len)
        {
            for(size_t i = 0; i < len; i++)
            {
                if(str[i] != s.str[i])
                {
                    answer = true;
                    return answer;
                }
            }
        }
        else 
        {
            answer = true;
            return answer;
        }
        return answer;
    }

    void trim()
    {
        size_t finder_ini = 0;
        size_t finder_fin = len;
        size_t new_size;
        size_t cursor = 0;
        
        while(str[finder_ini] == ' ')
        {
            finder_ini++;
        }

        while(str[finder_fin] == ' ')
        {
            finder_fin--;
        }

        new_size = (finder_fin - finder_ini) + 1;

        char* aux = (char*) malloc(new_size+1);
        
        for(size_t i = finder_ini; i <= finder_fin; i++)
        {
            aux[cursor] = str[i];
            cursor++;
        }
        aux[cursor] = 0;
        free(str); 
        str = aux;
    }

    int index_of(const String& s) const
    {
        size_t len_new = 0;
        size_t cont_first = 0;
        size_t len_finded = s.len;
        for(size_t i = 0; i < len; i++)
        {
            if(str[i] == s.str[len_new])
            {
                len_new++;
            }
            else 
            {
                len_new = 0;
                cont_first++;
            }

            if(len_new == len_finded)
            {
                return cont_first;
            }
        }   
        return -1;
    }

    String substring(size_t init, size_t len) const
    {
        size_t new_len = len - init;
        size_t init_new = 0;
        String new_string;    
        new_string.str = (char*) realloc(new_string.str, new_len+1);
        for(size_t i = init; i < len; i++)
        {
            new_string.str[init_new] = str[i];  
            init_new++;
        } 
        
        return new_string;
    }

    // String substring(size_t init) const
    // {}
};






// ---------------------------------class----------------------------
// ---------------------------------class----------------------------
enum class TipoCuenta
{
    Efectivo = 1,
    Corriente = 2
    
};

class ICuenta;





// ---------------------------------class----------------------------
// ---------------------------------class----------------------------
class IContacto
{
private:
    
public:
    IContacto() { }

    virtual ~IContacto() { }

    virtual String Get_name() const = 0;
};

// ---------------------------------class----------------------------

class Contacto : public IContacto
{
private:
    String nombre_c;
    String apellido_c;
    double saldo;
public:
    Contacto(const String& nombre_c, const String& apellido_c) 
    :nombre_c{nombre_c}, apellido_c{apellido_c}, saldo{0}
    { }

    Contacto() 
    :nombre_c{""}, apellido_c{""}, saldo{0}
    { }

    ~Contacto() { }

    String Get_name() const
    {
        return nombre_c;   
    }
};

// ---------------------------------class----------------------------
// ---------------------------------class----------------------------
class ITransaccion
{
private:
    
public:
    ITransaccion() { }
    
    virtual ~ITransaccion() { }

    virtual ICuenta& Get_cuenta() const = 0;

    virtual double get_monto() const = 0;

};

// ---------------------------------class----------------------------
class Retiro : public ITransaccion, public Contacto
{
private:
    ICuenta& cuenta;
    double monto;
    IContacto& contacto;
public:
    Retiro(ICuenta& cuenta, double monto) 
    :cuenta{cuenta}, monto{monto}, contacto{*(new Contacto{" "," "})}
    { 
        // contacto = Contacto{"",""};
    }

    Retiro(ICuenta& cuenta, double monto, IContacto& contacto) 
    :cuenta{cuenta}, monto{monto}, contacto{contacto}
    { }
    
    ~Retiro() { }

    ICuenta& Get_cuenta() const
    {
        return cuenta;
    }

    double get_monto() const
    {
        return monto;
    }
};

// ---------------------------------class----------------------------
// ---------------------------------class----------------------------
class ICuenta
{
private:
    
public:
    ICuenta() { }

    virtual ~ICuenta() { }

    virtual double Saldo() const = 0;

    virtual TipoCuenta Get_tipo() const = 0;

    virtual void set_saldo(double monto) = 0;
};

// ---------------------------------class----------------------------

class Cuenta : public ICuenta
{
private:
    TipoCuenta tipo;
    String descripcion;
    double saldo;
public:
    Cuenta(TipoCuenta tipo, String concepto, double saldo) 
    :tipo{tipo}, descripcion{concepto} , saldo{saldo}
    { }
    
    ~Cuenta() { }

    double Saldo() const
    {
        return saldo;
    }

    TipoCuenta Get_tipo() const
    {
        return tipo;
    }

    void set_saldo(double p_monto) override
    {
        saldo = saldo - p_monto;
    } 

};

// ---------------------------------class----------------------------
// ---------------------------------class----------------------------
class IBilletera
{
private:
    
public:
    IBilletera() { }

    virtual~IBilletera() { }

    virtual ICuenta* CrearCuenta(TipoCuenta tipo, const String& concepto, double monto) = 0;

    virtual void RealizarTransaccion(ITransaccion&) = 0;

    virtual double BalanceGeneral() const = 0;

    virtual IContacto* CrearContacto(const String& nombre_c, const String& apellido_c) = 0;

    virtual vector<IContacto> Contactos() const = 0; 

    virtual const double TotalEntregadoAContacto(IContacto& contacto) const = 0;
};

// ---------------------------------class----------------------------
class BilleteraPersonal : public IBilletera
{
private:
    String nombre;
    String apellido;
    vector<ICuenta*> cuentas;
    vector<IContacto*> contactos;
public:
    BilleteraPersonal(String nombre, String apellido)
    :nombre{nombre}, apellido{apellido} 
    { }
    
    ~BilleteraPersonal() { }

    ICuenta* CrearCuenta(TipoCuenta tipo, const String& concepto, double monto) override
    {
        Cuenta *nueva_cuenta = new Cuenta(tipo, concepto, monto);
        cuentas.push_back(nueva_cuenta);
        return nueva_cuenta;
    }

    void RealizarTransaccion(ITransaccion& transaccion)
    {
        transaccion.Get_cuenta().set_saldo(transaccion.get_monto());
        // transaccion.
    }

    double BalanceGeneral() const override
    {
        return cuentas[0]->Saldo();
    }

    IContacto* CrearContacto(const String& nombre_c, const String& apellido_c) override
    {
        IContacto* nuevo_contacto = new Contacto{nombre_c, apellido_c};
        contactos.push_back(nuevo_contacto);
        return nuevo_contacto;
    }

    vector<IContacto> Contactos() const override
    {
        vector<IContacto> aux_retorno;
        for(int i = 0; i < contactos.size(); i++)
        {
            aux_retorno[i] = *contactos[i];
        }
        
        return aux_retorno;
    }

    const double TotalEntregadoAContacto(IContacto& contacto) const override
    {
        double resultado = 0;
        // for 
        return resultado;
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
    // return false;
    
    IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");
    ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    ITransaccion *transaccion = new Retiro(*efectivo, 20);
    billetera->RealizarTransaccion(*transaccion);

    bool assertion = (billetera->BalanceGeneral() == 80);

    delete billetera;
    delete transaccion;

    return assertion;
}

bool test3()
{
    // return false;
    
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

}

bool test4()
{
    return false;
    
    // IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");

    // IContacto *contacto = billetera->CrearContacto("Juan", "Peralta");

    // ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    // ICuenta *deudas = billetera->CrearCuenta(TipoCuenta::Deuda, "deudas", 0); // 0 es el saldo inicial
    // //a la derecha
    // ITransaccion *transferencia = new Transferencia(*deudas, *efectivo, 50, *contacto); // sacamos 50 de deudas y los metemos a efectivo, ademas registramos al contacto en esas operaciones
    // billetera->RealizarTransaccion(*transferencia);

    // vector<IContacto> contactos = billetera->Contactos();
    // int montoAdeudadoAJuan = deudas->Saldo(contactos[0]); // la cuenta deudas deberia tener un valor -50 registrado a nombre de Juan Peralta, si hubiesen mas transacciones registradas a nombre de Juan Peralta en esta cuenta, la funcion Saldo recibiendo el parametro de tipo IContacto deberia contabilizar el total de esas transacciones registradas con ese contacto

    // bool assertion =
    //     (
    //         billetera->BalanceGeneral() == 100 &&
    //         montoAdeudadoAJuan == -50
    //     );

    // delete billetera;
    // delete transferencia;

    // return assertion;

}

bool test5()
{
    return false;
    
    // IBilletera *billetera = new BilleteraPersonal("Romulo", "Rojas");

    // IContacto *juan = billetera->CrearContacto("Juan", "Peralta");
    // IContacto *pedro = billetera->CrearContacto("Pedro", "Lima");

    // ICuenta *efectivo = billetera->CrearCuenta(TipoCuenta::Efectivo, "efectivo", 100); // 100 es el saldo inicial
    // ICuenta *deudas = billetera->CrearCuenta(TipoCuenta::Deuda, "deudas", 0); // 0 es el saldo inicial

    // ITransaccion *deposito = new Deposito(*efectivo, 30, *juan);
    // billetera->RealizarTransaccion(*deposito);

    // ITransaccion *transferencia = new Transferencia(*deudas, *efectivo, 20, *pedro);
    // billetera->RealizarTransaccion(*transferencia);

    // ITransaccion *retiro = new Retiro(*efectivo, 10);
    // billetera->RealizarTransaccion(*transaccion2);

    // bool assertion =
    //     (
    //         billetera->ImprimirTransacciones().compare(
    //             "tipo de transaccion,nombre de cuenta origen,nombre de cuenta destino,contacto,monto\n"
    //             "apertura de cuenta,,efectivo,,100\n"
    //             "apertura de cuenta,,deudas,,0\n"
    //             "deposito,,efectivo,Juan Peralta,30\n"
    //             "transferencia,deudas,efectivo,Pedro Lima,20\n"
    //             "retiro,efectivo,,,10\n"
    //         ) == 0
    //     );

    // delete billetera;
    // delete deposito;
    // delete transferencia;
    // delete retiro;

    // return assertion;

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