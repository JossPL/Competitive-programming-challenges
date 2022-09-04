/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea para solucionar este probolema es bastante sencilla. Cada fecha de nacimiento se guardo como una tupla comenzando por ano, mes y dia. 
Sabiendo que las tuplas se ordenan por la primera coordenada, luego por la segunda y ultimamente por la tecera, una vez guardadas todas solo 
hace falta ver cual es la tupla minima y cual la maxima.

Este algoritmo tiene complejidad O(n) con n la cantidad de personas que queremos comparar.

*/


#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	vector<string> names;
	vector<tuple<int, int, int>> bd;
	
	string hold;
	int d, m, y;
	for(int i=0; i<n; i++){
		cin>>hold; names.push_back(hold);
		cin>>d>>m>>y;
		tuple<int, int, int> aux=make_tuple(y, m, d);
		bd.push_back(aux);
	}
	
	string old=names[0], young=names[0];
	int oldIdx=0, youngIdx=0;
	for(int i=1; i<bd.size(); i++){
		if(bd[i]>bd[oldIdx]){
			oldIdx=i; old=names[i];
		}
		if(bd[i]<bd[youngIdx]){
			youngIdx=i; young=names[i];
		}
	}
	
	cout<<old<<endl<<young<<endl;
}

int main(){
	int n; cin>>n;
	solve(n);
	
	return 0;
}
