
#include <iostream>
using namespace std;
int main()
{
    int array[10] = {};
    int i = 0;
    int enter = 0;
    float suma = 0;
    float promedio = 0.0;
    while (i < 10)
    {
        cout << "Ingrese el numero: " << i + 1 << endl;
        cin >> array[i];
        suma += array[i];
        i++;
    }
    promedio = suma / 10;
    for (int j = 0; j < 10; j++)
    {
        cout << array[j] << endl;
    }
    cout << "Sumatoria = " << suma << endl;
    cout << "Promedio = " << promedio << endl;

    return 0;
}
