#include <iostream>
using namespace std;
struct Complejo
{
    int parteReal = 0;
    int parteImaginaria = 0;
    char sgnPI;
};
Complejo suma(Complejo, Complejo);
int main()
{
    Complejo complejo;
    Complejo complejo2;
    Complejo resultado;

    cout << "Digite la parte Real del primer complejo: " << endl;
    cin >> complejo.parteReal;
    cout << "Digite la parte imaginaria del primer complejo: " << endl;
    cin >> complejo.parteImaginaria;

    cout << "Digite la parte imaginaria del segundo complejo: " << endl;
    cin >> complejo2.parteReal;
    cout << "Digite la parte imaginaria del segundo complejo: " << endl;
    cin >> complejo2.parteImaginaria;

    resultado = suma(complejo, complejo2);
    cout << "El resultado de la suma de los complejos es: " << resultado.parteReal << resultado.sgnPI << resultado.parteImaginaria << 'i' << endl;
    return 0;
}

Complejo suma(Complejo a, Complejo b)
{
    Complejo res;
    res.parteReal = a.parteReal + b.parteReal;
    res.parteImaginaria = a.parteImaginaria + b.parteImaginaria;
    res.sgnPI = (res.parteImaginaria > 0) ? ' +' : ' ';
    return res;
}
