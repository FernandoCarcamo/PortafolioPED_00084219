#include <iostream>
#include <string>

using namespace std;

struct nodo{
    string Titulo;
    int numPaginas;
    nodo *sig;
};

void menu(void){
    cout<<"---------------------------Library/Libreria------------------------"<<endl;
    cout<<"1) Add book/Agregar un Libro"<<endl;
    cout<<"2) View Catalog/Revisar Catalogo"<<endl;
    cout<<"3) Serch/Buscar"<<endl;
    cout<<"0) Exit/Salir "<<endl;
}

void mostrarDatos(nodo *pInicio){
    if(!pInicio){
        return;
    }
    else{
        cout<<"Book/Libro: "<<pInicio->Titulo<<endl;
        cout<<"Pages number/Numero de paginas: "<<pInicio->numPaginas<<endl;
        mostrarDatos(pInicio->sig);
    }
}

void BuscarDato(nodo *pInicio, string libro){
    if(!pInicio){
        return;
    }
    else{
        if(libro == pInicio->Titulo){
        	cout<<"****Available/Disponible****\n";
            cout<<"This book has/El librio contiene "<<pInicio->numPaginas<<" pages/paginas"<<endl;
            cout<<endl;
        }else if(libro != pInicio->Titulo){
    	cout<<"Book not available/libro no disponible\n";
	}
        BuscarDato(pInicio->sig, libro);
    }
}

int main() {
    nodo *pInicio = NULL;
    nodo *nuevo = NULL;

    int opcion=0;
    string libro;

    do{
        menu();
        cin>>opcion;
        switch(opcion){
            case 1:
                nuevo = new nodo;
                cout<<"Title/Titulo: "<<endl;
                cin>>nuevo->Titulo;
                cout<<"Amount of pages/Cantidad de paginas: "<<endl;
                cin>>nuevo->numPaginas;

                if(pInicio == NULL){
                    pInicio = nuevo;
                    nuevo->sig=NULL;
                }
                else{
                    nuevo->sig = pInicio;
                    pInicio = nuevo;
                }

                break;
            case 2:
                mostrarDatos(pInicio);
                break;
            case 3:
                cout<<"Which book would you like to search?/Que libro desea buscar?: "<<endl;
                cin>>libro;
                BuscarDato(pInicio,libro);
                break;
            case 0:
                break;
        }
    }
    while(opcion !=0);


    return 0;
}


