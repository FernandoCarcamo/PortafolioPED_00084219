#include <iostream>
using namespace std;

int main()
{
    int matriz[5][5];

    for (int i = 0; i < 5; i++)
    {
    for (int j = 0; j < 5; j++)
    {
    matriz[i][j] = 0;
    }
    }

    cout << "Digite los datos para crear una matriz diagonal superior" << endl;
    for (int i = 0; i < 5; i++)
    {
    for (int j = i; j < 5; j++)
    {
    cout << "Digite la posicion : " << j << ", " << i << endl;
    cin >> matriz[i][j];
    }
    }

    for (int i = 0; i < 5; i++)
    {
    for (int j = 0; j < 5; j++)
    {
    cout << matriz[i][j] << "\t";
    }
    cout << endl;
    }

    return 0;
}
