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
		ListaSimple(void);
		void InsertarInicioLista(int);
		void MostrarLista(void);
		void MostrarLista(nodo *);
		int EliminarNodo(int);
		void eliminarNodo(int dato);
};

	ListaSimple::ListaSimple (void){
	pInicio =  NULL;
	}
	
    void ListaSimple::InsertarInicioLista(int dato){
    	
    nodo *nuevo;
    
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;    
    
	}
	
void ListaSimple::MostrarLista(void){
	
	MostrarLista(pInicio);
	
}

void ListaSimple::MostrarLista(nodo *s){
	if (s != NULL){
	cout<< s->dato << " ";
	MostrarLista(s->sig);
		
	}
	
}

void ListaSimple::eliminarNodo(int dato)
{
    nodo *p = pInicio, *q = NULL;

    while(p != NULL && p->dato != dato){
        q = p;
        p = p->sig;
    }
    if(p != NULL){
        if(q != NULL){
            q->sig = p->sig;
            
        }else if(q == NULL){
         	pInicio = pInicio->sig;
        	delete q;
    }
        else{
            pInicio->sig = p->sig;
            delete p;
        }
    }else{
        cout << "Dato a borrar NO existe" << endl;
    }

}


int main(){
	ListaSimple miLista;
	char resp;
	int dato;
	
	cout<< "Desea meter un dato (s/n)?";
	cin>>resp;
	
	while (resp == 's'){
	cout << "Digite el dato: ";
    cin >> dato;
    miLista.InsertarInicioLista(dato);
    cout << "Desea meter un dato (s/n)?";
    cin>> resp;

    }    
    
    cout << "\nMostrar lista: " << endl;
    miLista.MostrarLista();
    
    cout<<endl;
    
    cout << "\Cual elemento desea eliminar?: " << endl;
    cin >> dato;
    miLista.eliminarNodo(dato);
	
	cout << "\nMostrar lista:" << endl;
    miLista.MostrarLista();
    cout<<endl;
    
    cout<<"Desea eliminar otro nodo(s/n)? ";
    cin>>resp;
    while(resp == 's'){
	cout<<endl;
   	cout << "\Cual elemento desea eliminar? ";
    cin >> dato;
    miLista.eliminarNodo(dato);	
    cout<<endl;
    cout << "\nMostrar lista:" << endl;
    miLista.MostrarLista();
    cout<<endl;
    cout<<"Desea eliminar otro nodo(s/n)? ";
    cin>>resp;
    cout<<endl;
	}
	
	return 0;
}
