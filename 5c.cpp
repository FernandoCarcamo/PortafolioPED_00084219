#include <iostream>

using namespace std;

void hanoi(int, int, int, int);


int main(){
	int n;
	
	cout<<"Ingrese la cantidad de bloques: ";
	cin>>n;
	
	hanoi(n, 1, 2, 3);
	
	return 0;
}

void hanoi(int n, int a, int b, int c){
	
	if(n > 0){
		hanoi(n-1, a, c, b);
		cout<< "Se mueve el anillo desde la torre: "<< a <<" "<<"hasta la torre: "<< b << endl;
		hanoi(n-1, c, b, a);
	}
}
