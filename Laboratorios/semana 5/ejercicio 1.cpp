#include <iostream>
using namespace std;

struct nodo
{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *tree;

tree createTree(int x)
{
    tree p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(tree a, int unDato)
{
    if (a == NULL)
        cout << "Error: Emty tree" << endl;
    else if (a->izq != NULL)
        cout << "Error: Left subtree already exists" << endl;
    else
        a->izq = createTree(unDato);
}

void asignarDer(tree a, int unDato)
{
    if (a == NULL)
        cout << "Error: Empty tree" << endl;
    else if (a->der != NULL)
        cout << "Error: subtree already exists" << endl;
    else
        a->der = createTree(unDato);
}

void addNode(tree a)
{

    int num = 0;
    cout << "Num to add: ";
    cin >> num;

    tree p = a;

    while (true)
    {
        if (num == p->info)
        {
            cout << "Error: " << num << "Num already exists" << endl;
            return;
        }
        else if (num < p->info)
        {
            if (p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else
        {
            if (p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    if (num < p->info)
        asignarIzq(p, num);
    else
        asignarDer(p, num);
}

bool hijos(tree a)
{
    if (a->der != NULL || a->izq != NULL)
    {
        return true;
    }
}
void LevelsAmount(tree a, int &sum)
{
    if (a != NULL)
    {
        if (hijos(a))
        {
            sum+= 1;
        }
        LevelsAmount(a->izq, sum);
        LevelsAmount(a->der, sum);
    }
}

void nodesAmount(tree a, int &sum)
{
    if (a != NULL)
    {
        sum+= 1;
        nodesAmount(a->izq, sum);
        nodesAmount(a->der, sum);
    }
}

void nodesSum(tree a, int &sum)
{
    if (a != NULL)
    {
        sum+= a->info;
        nodesSum(a->izq, sum);
        nodesSum(a->der, sum);
    }
}

int main()
{
    int variable = 0;
    cout << "Initialazing...\nTree's root': ";
    cin >> variable;

    tree tree = createTree(variable);

    bool continuar = true;
    do
    {
        int sum= 0;
        int option = 0;
        cout << "Menu: \n\t1) Add\n\t2) Know amount of levels\n\t3) Know amount of nodes\n\t4) All nodes sum\n\t5) Exit"
             << "\n\toption elegida: ";
        cin >> option;
        switch (option)
        {
        case 1:
            addNode(tree);
            break;
        case 2:
            sum= 1;
            LevelsAmount(tree, sum);
            cout << "----------------------------" << endl;
            cout << "Amount of levels is: " << sum<< endl;
            cout << "----------------------------" << endl;
            break;
        case 3:
            sum= 0;
            nodesAmount(tree, sum);
            cout << "----------------------------" << endl;
            cout << "La cantidad de nodos es: " << sum<< endl;
            cout << "----------------------------" << endl;
            break;
        case 4:
            sum= 0;
            nodesSum(tree, sum);
            cout << "----------------------------" << endl;
            cout << "Node amount is: " << sum<< endl;
            cout << "----------------------------" << endl;
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "WRONG OPTION!!!!!!!!" << endl;
            break;
        }
    } while (continuar);

    return 0;
}
