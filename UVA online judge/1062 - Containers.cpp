/*Josue Alejandro Perez Lara
josue.peres@cimat.mx

Por la condicion del problema, realmente solo nos interesa el tope de la pila, por lo que en vez de considerar
un vector de pilas, consideramos un vector con los topes.

Si en el orden de llegada, un contenedor posee una letra mayor al tope de la ultima pila, entonces debemos crear
una nueva pila, de lo contrario no podriamos acceder al elemento de abajo ya que se llenan alfabeticamente

Si un contenedor posee una letra menor o igual al tope de una de las pilas, entonces ese contenedor pasa a ser
el tope de dicha pila, para asi poder acceder a el
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string s){
	static int cases=1;
	vector<char> canales;
	
	canales.push_back(s[0]);
	
	for(int i=1; i<=s.size(); i++)
		for(int j=0; j<canales.size(); j++)
			if(canales[canales.size()-1]<s[i]){
				canales.push_back(s[i]); 
				break;
			}else if(canales[j]>=s[i]){
				canales[j]=s[i]; 
				break;
			}
			
	cout<<"Case "<<cases<<": "<<canales.size()<<endl; cases++;
}

int main(){
	string s; cin>>s;
	while(s.compare("end")!=0){
		solve(s); cin>>s;
	}
	
	return 0;
}
