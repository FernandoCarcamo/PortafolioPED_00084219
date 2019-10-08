#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class ListaSimple{
private:
    nodo *pInicio;
    
public:
	
    ListaSimple(void) {
    pInicio = NULL;
    
}

void insertarInicioLista(int dato) {
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}
void sumPar(nodo *s, int val){
	int acc = val;
	if(s != NULL){
		if(s->dato %2 == 0){
			cout<< s->dato << ", ";
			acc += s->dato;
		}
		sumPar(s->sig, acc);
	}
	else{
		cout<< " \nSuma total: " << acc << endl;
	}
}

void mostrarListaPar(void)
{
	nodo *s = pInicio;
	int acum = 0;
	sumPar(s, 0);
}

void sumImpar(nodo *s, int val){
	int acc = val;
	if(s != NULL){
		if(s->dato %2 != 0){
			cout<< s->dato << ", ";
			acc += s->dato;
		}
		sumImpar(s->sig, acc);
	}
	else{
		cout<< " \nSuma total: " << acc << endl;
	}
}

void mostrarListaImpar(void)
{
	nodo *s = pInicio;
	int acum = 0;
	sumImpar(s, 0);
}


};

int main(void)
{
    ListaSimple miLista;
    char resp;
    int dato, datoRef, datoBuscar;
    
    cout << "Desea meter un dato (s/n)?";
    cin>> resp;
    while(resp == 's'){
        cout << "Digite el dato: ";
        cin >> dato;
        miLista.insertarInicioLista(dato); //insertarInicioLista(dato);
        cout << "Desea meter un dato (s/n)?";
        cin>> resp;
    }    
    
    cout << "\nMostrar lista Par: " << endl;
    miLista.mostrarListaPar();
    cout<<endl;
    
    cout << "\nMostrar lista Impar: " << endl;
    miLista.mostrarListaImpar();
    cout<<endl;
    

    
    cout<<endl;

    return 0;
}
