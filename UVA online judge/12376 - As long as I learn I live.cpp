/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejerficio se utiliza una tecnica basenate sencilla. 
Solo es lanzar una BFS desde el nodo inicial (0) y seguir por su hijo por el cual tendremos mayor aprendizaje.
A lo  largo de este recorrido se guarda el aprendizaje total que se tiene. 

La complejidad total del algortimo es O(m+n) con n y m la cantidad de nodo y aristas respectivamente.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> learn;
vector<int> ady[100];
int ep;

int BFS(int node){
	int max=-1, max_node=-1;
	for(int i=0;i<ady[node].size();i++){
		int v=ady[node][i];
		if(learn[v]>max){
			max=learn[v];
			max_node=v;
		}	
	}
	if(max_node==-1)
		ep=node;
	return max_node!=-1?learn[node]+BFS(max_node):learn[node];
}

int solve(){
	int n,m;cin>>n>>m;
	learn.assign(n,0);
	for(int i=0;i<n;i++)
		cin>>learn[i];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		ady[a].push_back(b);
	}
	int res=BFS(0);
	for(int i=0;i<n;i++)
		ady[i].clear();
	return res;
}

int main(){
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		int k=solve();
		cout<<"Case "<<i<<": "<<k<<" "<<ep<<'\n';
	}	
	return 0;
}
