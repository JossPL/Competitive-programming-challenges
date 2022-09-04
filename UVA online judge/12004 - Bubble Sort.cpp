/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx


Se observo que el numero promedio de cambios es n(n-1)/4, con n la cantidad de elementos a ordenar. 
Por lo tanto, solo debemos buscar la forma de escribir el resultado ya sea como entero o como fraccion irreducible. Eso es lo que hace la funcion solve.
La complejidad de este algoritmo es O(t) donde t es el numero de casos  a resolver

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, int cases){
	cout<<"Case "<<cases<<": ";
	long long num=n;
	num=num*(num-1);
	
	if(num%4==0){
		cout<<num/4<<endl; 
	}else if(num%4==2){
		cout<<num/2<<"/"<<2<<endl;
	}else{
		cout<<num<<"/"<<4<<endl;
	}
}

int main(){
	int t; cin>>t;
	int n;
	for(int i=1; i<=t; i++){
		cin>>n;
		solve(n, i);
	}
	
	return 0;
}
