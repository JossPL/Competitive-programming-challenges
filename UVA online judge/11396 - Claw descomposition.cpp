/*
JosueAlejandro Perez Lara
josue.perez@cimat.mx

Dadas las condiciones del problema, notemos que cada nodo debe ser centro de un claw u orilla de la misma.
Ademas, dos hojas no pueden estar conectadas ni dos centros tampoco, por lo tanto, el problema puede ser visto como determinar si la grafica dada es bipartita.
Para verificar si esto sucede, realizamos una DFS donde preguntamos si las graficas cada vez mas pequenas lo son. 
Si resulta que la grafica si es bipartita, entonces se puede dividir como se solicita. Si no lo es la respuesta sera negativa. 

La complejidad de este algoritmo es O(t(n+m)) con n el numero n de nodos, m el numero de aristas y t la cantidada de casos por evaluar.
*/


#include <bits/stdc++.h>

using namespace std;

vector<bool> check;
vector<int> color;
vector<int> ady[301];

//Pasamos el nodo que vamos a verificar y el color del que le tocaria pintarse
bool isBipartite(int node, int col){
	if(check[node]){
		if(color[node]!=col)
			return false;
		return true;
	}
	check[node]=true;
	color[node]=col;
	bool res=true;
	for(int i=0;i<ady[node].size();i++){
		res=res && isBipartite(ady[node][i],1-col);
	}
	return res;
}


int main(){
	int n;cin>>n;
	while(n!=0){
		check.assign(n+1,false);
		color.assign(n+1,-1);
		int a,b;cin>>a>>b;
		while(a!=0 || b!=0){
			ady[a].push_back(b);
			ady[b].push_back(a);
			cin>>a>>b;
		}
		bool res=true;
		for(int i=1;i<=n;i++){
			if(!check[i]){
				res=res&&isBipartite(i,1);
			}
		}
		
		res==true?cout<<"YES"<<endl:cout<<"NO"<<endl;
		
		for(int i=1;i<=n;i++)
			ady[i].clear();
		color.clear();
		check.clear();
		cin>>n;
	}
	
	
	return 0;
}
