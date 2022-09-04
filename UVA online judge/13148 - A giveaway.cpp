/*
Josue Alejandro Perez Lara 
josue.perez@cimat.mx

Notemos que los unicos numeros que son potencias de 2 y de 3 son las sextas potencias. 
Primeramente se realizo un precalculo de estas potencias y luego para cada pregunta solo se consulta el set para saber si el numero esta o no presente.

Para llenar el set la complejidad es O(n^(1/6)) donde n el rango de los valores. Por lo tanto la complejidad final del algoritmo sera O(n^(1/6) + q), 
con q el numero de preguntas.
*/

#include<bits/stdc++.h>
using namespace std;

set<int> s;

void fill(){
	s.insert(1);
	int aux=2,p;
	while(p<100000000){
		p=pow(aux++,6);
		s.insert(p);
	}
}

void solve(int n){
	if(s.count(n)>0)
		cout<<"Special"<<endl;
	else
		cout<<"Ordinary"<<endl;
}

int main(){
	fill();
	int n;
	while(1){
		cin>>n;
		if(n==0)
			return 0;
		solve(n);
	}
	return 0;
}
