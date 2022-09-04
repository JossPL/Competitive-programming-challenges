/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejercicio notemos que el peor caso para obtener la minima cantidad de llaves necesitadas para asegurar
que se tiene la configuracion correcta es que en las primeras m-n casas se prueben todas las llaves y ningubna funcione, lo cual nos da n(m-n) intentos.
Posteriormente para las casas que si se abrira, lo peor es que suceda que en la primera casa se intenten n-1 llaves, en la segund n-2 y asi sucesivamente.

Simplificando esta expresion obtenemos el resultado solicitado. La complejidad del algoritmo es O(1) y por lo tanto el ejercicio es O(t) con t el numero de casos.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	unsigned long long m, n;
	
	while(t--){
		cin>>n>>m;
		cout<<m*n-n*(n+1)/2<<endl;
	}
	
	return 0;
}
