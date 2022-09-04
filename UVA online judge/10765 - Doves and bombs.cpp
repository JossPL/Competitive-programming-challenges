/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para este problema, lo que se solicita es encontrar los puntos de articulacion que separan en la mayor cantidad de componentes conexas al grafo dado.
a continuacion se muetra un algoritmo de como funciona nuestro algortimo para encontrar puntos de articulacion

Resumen de la busqueda de PUNTOS DE ARTICULACION

Un punto es de articulacion si se cumple una de las siguientes dos condiciones: 

	1) Si dentro del arbol generado por la DFS un nodo tiene un hijo tal que su minimo es mayor o igual al momento del descubrimiento del nodo actual, 
	entonces significa que no hay forma de regresar a los anteriores al nodo actual y al borrarlo las componentes conexas aumentarian
	
	2) Si el nodo es la raiz y tiene mas de dos hijos, entonces es un punto de articulacion.
	
La complejidad de este ejercicio es O(t(n+m)) con t la cantidad de casos, m a cantidada de aristas y n los nodos. 
Esto porque O(n+m) es la complejidad de la DFS.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int fst[10000];
int mini[10000];
int t=0;
bool visited[10000];
int AP[10000];

void clear(int n){
	for(int i=0;i<n;i++){
		fst[i]=0;
		mini[i]=0;
		adj[i].clear();
		visited[i]=false;
		AP[i]=0;
	}
	t=0;
}

void AP_dfs(int node, int padre){
	int child=0;
	visited[node]=true;
	fst[node]=mini[node]=++t;
	
	for(auto &a: adj[node]){
		if(!visited[a]){
			child++;
			AP_dfs(a,node);
			mini[node]=min(mini[node],mini[a]);
			
			// Caso 1
			if(padre!=-1 && fst[node] <= mini[a])
				AP[node]++;
				
		}else if(padre != a)
			mini[node]=min(mini[node],mini[a]);
	}
	
	//Caso 2
	if(padre==-1 && child>1)
		mini[node]=child-1;
}

int main(){
	int n,m;cin>>n>>m;
	while(n!=0 || m!=0){
		clear(n);
		int a,b;cin>>a>>b;
		while(a!=-1 || b!=-1){
			adj[a].push_back(b);
			adj[b].push_back(a);
			cin>>a>>b;
		}
		
		AP_dfs(0,-1);
		
		priority_queue<pair<int,int>> q;
		for(int i=0;i<n;i++)
			q.push({AP[i]+1,-i});
		
		for(int i=0;i<m;i++){
			cout<<-q.top().second<<" "<<q.top().first<<endl;
			q.pop();
		}
		cout<<endl;
		
		cin>>n>>m;
	}
	
	return 0;
}
