/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea para este problema fue precalcular todos los numeros que serian parte del conjunto next23.
Posteriormente para cada entrada solo se hace una binary search en el conjunto para encontrar la solucion.
El llenado del arreglo tiene una complejidad constante de 32^2.

Asi, la complejidad del algoritmo es O(m), con m la cantidad de preguntas a realizar.
*/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> next23;

void fill_next23(){
	vector<ll> pow2(32,1);
	vector<ll> pow3(32,1);
	for(int i=1;i<32;i++){
		pow2[i]=2*pow2[i-1];
		pow3[i]=3*pow3[i-1];
	}
	
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			if(i+j<32)
				next23.push_back(pow2[i]*pow3[j]);	
		}
	}
	sort(next23.begin(),next23.end());
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	fill_next23();
	
	int m;cin>>m;
	while(m!=0){
		auto i=lower_bound(next23.begin(), next23.end(),m);
		cout<<*i<<endl;
		cin>>m;
	}
	
	return 0;
}
