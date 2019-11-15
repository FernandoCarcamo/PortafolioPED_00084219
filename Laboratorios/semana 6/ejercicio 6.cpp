#include <iostream>
#include <cstdlib>
using namespace std;

struct List{
    int data;
    List *next;
};

struct Tree{
    int data;
    Tree *left;
    Tree *right;
};

List *createNodeList(int value){
    List *newNode = new List();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void ShowList(List *pInicio){
    if(pInicio!=NULL){
        cout<<pInicio->data<<", ";
        ShowList(pInicio->next);
    }else{
        cout<<"NULL";
    }
}
void deleteList(List *&pInicio)
{
    List *s = pInicio;

    while(pInicio != NULL){
        s = pInicio;
        pInicio = pInicio->next;
        delete(s);
    }
}
void insertarList(List *&pInicio, List *&nuevo){
    if(pInicio==NULL){
        pInicio=nuevo;
    }else{
        insertarList(pInicio->next, nuevo);
    }
}
void ShowTreePreOrright(Tree *root){
    if(root!=NULL){
        cout<<root->data<<", ";
        ShowTreePreOrright(root->left);
        ShowTreePreOrright(root->right);
    }
}

Tree *createNodeTree(int value){
    Tree *nuevo = new Tree();
    nuevo->data = value;
    nuevo->left = nuevo->right = NULL;
    return nuevo;
}

void fillTree(Tree *&root, Tree *&nuevo){
    if(root==NULL){
        root = nuevo;
    }
    else if (nuevo->data < root->data){
        if(root->left != NULL){
            fillTree(root->left, nuevo);
        }else{
            root->left = nuevo;
        }
    }
    else if (nuevo->data > root->data){
        if(root->right != NULL){
            fillTree(root->right, nuevo);
        }else{
            root->right = nuevo;
        }
    }
}
void fillTreeWithList(List *&pInicio, Tree *&root){
    if(pInicio != NULL){
        Tree *nuevo = createNodeTree(pInicio->data);
        fillTree(root, nuevo);
        fillTreeWithList(pInicio->next,root);
        
    }
}

int main() {
   
    int array[] = {-3,-2,-1,0,1,2,3}; //Numeros de la lista
    List *pInicio = NULL;
    List *aux = NULL;

    Tree *root = NULL;

    for (int i = 0; i < sizeof(array)/ sizeof(*array); ++i) {
        aux = createNodeList(array[i]);
        insertarList(pInicio,aux);
    }
    cout<<"List inserted ";
    ShowList(pInicio);

    fillTreeWithList(pInicio,root);
    cout<<endl<<"tree with the list: ";
    ShowTreePreOrright(root);
    
    cout<<endl<<"tree with the list: ";
    ShowTreePreOrright(root);
    
    cout<<endl<<"List inserted: ";
    deleteList(pInicio);
    ShowList(pInicio);
    
    return 0;
}
