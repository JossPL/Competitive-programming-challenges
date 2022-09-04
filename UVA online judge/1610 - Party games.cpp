/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejercicio comenzamos letyendo las strings de los nombres y ordenandolas. posteriormente nos fijamos solo en las dos de en medio. 
Calculamos cual es rel mayor prefijo que ambas tienen en comun y comenzamos a agregar caracteres al final de esta subsecuencia para acompletar a la buscada.

La complejidada de este algoritmo es O(nm log n), donde n es la cantidad de nombres dados y m es la longitud maxima de estos nombres. 
Esta complejidad se alcanza cuando el algoritmo ordena las strings.

*/

#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;cin>>n;
	while(n!=0){
		vector<string> v;
		string aux;
		
		for(int i=0;i<n;i++){
			cin>>aux;
			v.push_back(aux);	
		}
		
		sort(v.begin(), v.end());
		string left=v[n/2-1], right=v[n/2];

		// i guarda el primer caracter que no coincide
		int i=0;
		while( i<left.size() && left[i] == right[i])
			i++;

		string n_left=left;
		n_left.push_back('A');
			
		string comun=left.substr(0,i);
		aux=comun;
		
		//Agregamos un caracter A al final de la cadena comun. Posteriormente vamos viendo a que se puede ir modificando ese ultimo caracter
		// hasta encontrar el minimo que cumpla lo solicitado
		int operation=0;
		while(  aux<left || right<=aux ){
			if(operation %2==0){
				aux=comun;
				aux.push_back(n_left [i] );
				comun.push_back(n_left[i]);
				operation++;
			}else{
				if(n_left[i] != 'Z')
					aux[i] = (char)(aux[i]+1);
				operation++;
				i++;
			}
		}
		
		cout<<aux<<endl;
		cin>>n;
	}
	return 0;
}
