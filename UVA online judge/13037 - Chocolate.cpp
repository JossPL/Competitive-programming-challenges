/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Utilizaremos un arreglo de longitud maxima que pueda almacenar los tipos de chocolate de cada persona, el arreglo
sera de tuplas de chars, donde 'x' representa que una persona lo tiene y ' ' no lo tiene

las posiciones de la tupla son la de las tres personas respectivamente

al leer el input, llenamos en nuestro arreglo los chocolates que tiene la primera persona, de la misma forma con
la segunda y la tercera

luego, recorremos el arreglo, y para cada tupla, verificamos si es que exactamente una persona posee el chocolate
o no lo posee. Lo anterior lo guardamos en una matriz de respuesta, que almacena cuantos chocolate tiene una
persona en exclusivo y cuantos no tiene que los demas si.

La complejidad de este algoritmo es O(tn), donde n es la cantidad de tipos de chocolate y t el numero de casos.
*/

#include <bits/stdc++.h>
using namespace std;

typedef tuple<char, char, char> ccc;

void solve(int cases){
	ccc aux=make_tuple(' ', ' ', ' ');
	vector<ccc> key(100000, aux);
	
	int l, r, s; cin>>l>>r>>s;
	
	int hold;
	for(int i=0; i<l; i++){
		cin>>hold;
		get<0>(key[hold])='x';
	}
	for(int i=0; i<r; i++){
		cin>>hold;
		get<1>(key[hold])='x';
	}
	for(int i=0; i<s; i++){
		cin>>hold;
		get<2>(key[hold])='x';
	}
	
	int ans[3][2];
	for(int i=0; i<3; i++)
		for(int j=0; j<2; j++)
			ans[i][j]=0;
			
	for(int i=0; i<100000; i++){
		if(get<0>(key[i])=='x' && get<1>(key[i])=='x' && get<2>(key[i])==' ')
			ans[2][1]++;
		else if(get<0>(key[i])=='x' && get<1>(key[i])==' ' && get<2>(key[i])==' ')
			ans[0][0]++;
		else if(get<0>(key[i])=='x' && get<1>(key[i])==' ' && get<2>(key[i])=='x')
			ans[1][1]++;
		else if(get<0>(key[i])==' ' && get<1>(key[i])==' ' && get<2>(key[i])=='x')
			ans[2][0]++;
		else if(get<0>(key[i])==' ' && get<1>(key[i])=='x' && get<2>(key[i])==' ')
			ans[1][0]++;
		else if(get<0>(key[i])==' ' && get<1>(key[i])=='x' && get<2>(key[i])=='x')
			ans[0][1]++;
	}
	
	cout<<"Case #"<<cases<<":\n";
	for(int i=0; i<3; i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, cases=1; cin>>t;
    while(t--){
    	solve(cases);
    	cases++;
	}

	return 0;
}
