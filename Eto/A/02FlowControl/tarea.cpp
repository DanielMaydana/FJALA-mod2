#include <iostream>
using namespace std;

int size(int number)
{
    int count = 0;
    while(number >= 1)
    {
        number = number / 10;
        count++;
    }
    return count;
}

void unit(unsigned int number, bool space)
{
    switch (number)
    {
        case 1:
            cout << "un";
            if (space) cout << " ";
            break;

        case 2:
            cout << "dos";
            if (space) cout << " ";
            break;

        case 3:
            cout << "tres";
            if (space) cout << " ";
            break; 
        
        case 4:
            cout << "cuatro";
            if (space) cout << " ";
            break; 

        case 5:
            cout << "cinco";
            if (space) cout << " ";
            break; 

        case 6:
            cout << "seis";
            if (space) cout << " ";
            break; 

        case 7:
            cout << "siete";
            if (space) cout << " ";
            break; 

        case 8:
            cout << "ocho";
            if (space) cout << " ";
            break; 

        case 9:
            cout << "nueve";
            if (space) cout << " ";
            break; 
    }
}

void veintes()
{

}

void ten(unsigned int number, bool space)
{
    switch (number)
    {
        case 1:
            cout << "diez";
            if (space) cout << " ";
            break;

        case 2:
            cout << "veinte";
            if (space) cout << " ";
            break;

        case 3:
            cout << "treinta";
            if (space) cout << " ";
            break; 
        
        case 4:
            cout << "cuarenta";
            if (space) cout << " ";
            break; 

        case 5:
            cout << "cincuenta";
            if (space) cout << " ";
            break; 

        case 6:
            cout << "sesenta";
            if (space) cout << " ";
            break; 

        case 7:
            cout << "setenta";
            if (space) cout << " ";
            break; 

        case 8:
            cout << "ochenta";
            if (space) cout << " ";
            break; 

        case 9:
            cout << "noventa";
            if (space) cout << " ";
            break; 
    }
}

void hundred(unsigned int number, bool space)
{
    switch (number)
    {
        case 1:
            cout << "cien";
            if (space) cout << " ";
            break;

        case 2:
            cout << "doscientos";
            if (space) cout << " ";
            break;

        case 3:
            cout << "trescientos";
            if (space) cout << " ";
            break; 
        
        case 4:
            cout << "cuatrocientos";
            if (space) cout << " ";
            break; 

        case 5:
            cout << "quinientos";
            if (space) cout << " ";
            break; 

        case 6:
            cout << "seiscientos";
            if (space) cout << " ";
            break; 

        case 7:
            cout << "setecientos";
            if (space) cout << " ";
            break; 

        case 8:
            cout << "ochocientos";
            if (space) cout << " ";
            break; 

        case 9:
            cout << "novecientos";
            if (space) cout << " ";
            break; 
    }
}

void print_as_text(unsigned int num)
{
    int len = size(num);
    int aux_num;
    int aux_len;
    switch (len)
    {
        case 7: 
            aux_num = num / 1000000;
            aux_len = aux_num * 1000000;
            unit(aux_num, true);
            if(aux_num == 1)
                cout << "millon ";
            else
                cout << "millones ";
            num = num - aux_len;
            break;

        case 6: 
            aux_num = num / 100000;
            aux_len = aux_num * 100000;
            hundred(aux_num, true);
            num = num - aux_len;
            break;

        case 5: 
            aux_num = num / 10000;
            aux_len = aux_num * 10000;
            ten(aux_num, true);
            num = num - aux_len;
            break;
        
        case 4: 
            aux_num = num / 1000;
            aux_len = aux_num * 1000;
            unit(aux_num, true);
            cout << "mil ";
            num = num - aux_len;
            break;

        case 3: 
            aux_num = num / 100;
            aux_len = aux_num * 100;
            hundred(aux_num, true);
            num = num - aux_len;
            break;

        case 2: 
            aux_num = num / 10;
            aux_len = aux_num * 10;
            ten(aux_num, true);
            num = num - aux_len;
            break;
        
        case 1: 
            aux_num = num;
            aux_len = aux_num;
            unit(aux_num, true);
            num = num - aux_len;
            break;

        default:
            num = 0;
            break;
    }
    if(num >= 1)
        print_as_text(num);
    else 
        return;
}

int main()
{
    print_as_text(6946937);
    cout << "\n";
    
    print_as_text(691235);
    cout << "\n";
    
    print_as_text(64821);
    cout << "\n";

    print_as_text(3458);
    cout << "\n";

    print_as_text(937);
    cout << "\n";

    print_as_text(96);
    cout << "\n";

    print_as_text(7);
    cout << "\n";
}