#include <iostream>
#include <cmath>

using namespace std;

void invert(int);
int main (){
	int n;
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	invert(n);	
	
	return 0;
}

void invert (int a){
	if(a>0){
		int i = a % 10;
		cout<< i;
		invert(a/10);
	}
	return;

}
