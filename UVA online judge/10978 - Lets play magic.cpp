/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resoolver este ejercicio comenzamos con todas las cartas marcadas como 0, lo cual indica que hasta ahora no sabemos que valor ira en esa posicion.
Posteriormente leemos cada palabra y avanzamos las casillas correspondientes, solo contando las casillas cero (que son ls que no se han quitado del circulo)
Mientras realizamos lo anterior vamos guardando el orden de las cartas. Posteriormente solo se imprime el orden

El peor caso es cuando ya tenemos todas las caillas ocupadas y debemos llenar la ultima. 
Porque en el ciclo tendra n-1 caillas cero las cuales no contaran para disminuir la cantidad de saltos que debe dar. Entonces la complejidad sera O(n^2l), 
donde n es la cantidad de cartas, l la longitud de las palabras de cada carta.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;cin>>n;
	while(n!= 0){
		int disp=n,pos=0;
		vector<string> str;
		str.assign(n,"0");
		for(int i=0;i<n;i++){
			string card, word;
			cin>>card>>word;
			int avanza=( word.size()%disp == 0? word.size() :  word.size()%disp );
			//Solo va contando las posiciones que aun tienen 0
			while(avanza != 0){
				if(str[pos] == "0"){
					avanza--;
				}
				pos=(pos+1)%n;
			}
			disp--;
			str[(n+pos-1)%n]=card;
		}
		
		//Imprime el orden resultante
		for(int i=0;i<n;i++){
			cout<<str[i];
			if(i != n-1)
				cout<<" ";
		}
		cout<<endl;
		cin>>n;
	}
	
	
	return 0;
}
