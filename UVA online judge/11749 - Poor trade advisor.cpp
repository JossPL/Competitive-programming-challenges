/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea para este problema fue guardar las ciudades que tienen algun camino con ppa maximo. 
Posteriormente sobre estas ciudades se hace una busqueda BFS para saber si hay mas ciudades conectadas a ella que tengan el mismo peso. 
En caso de que si estas se agregan y continamos el proceso. Si no solo vamos guardando la cantidad maxima de ciudades que llevamos.

Asi, la complejidad del algoritmo es O(n(c+r)), con n la cantidad de casos, c la cantidad de ciudades en el imperio y r la cantidad de caminos.
Pues esta es la complejidad tanto de leer los datos de entrada como de las BFS que se realizan.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<int,int>> adj[501];
bool visited[501];

int BFS(int n, int max_ppa){
	queue<int> q;
	q.push(n);
	visited[n]=true;
	int res=0;;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		res++;
		for(auto &a:adj[curr])
			if(a.second==max_ppa && !visited[a.first]){
				visited[a.first]=true;
				q.push(a.first);
			}
				
	}
	return res;
}

void solve(int n,int m){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int max_ppa=INT_MIN;
	vector<int> rep;
	for(int i=0;i<m;i++){
		int a,b,ppa;cin>>a>>b>>ppa;
		adj[a].push_back({b,ppa});
		adj[b].push_back({a,ppa});
		if(max_ppa<ppa){
			max_ppa=ppa;
			rep.clear();
			rep.push_back(a);
		}else if(max_ppa==ppa)
			rep.push_back(a);
	}
	
	int res=INT_MIN;
	for(auto a:rep){
		if(!visited[a])
			res=max(res,BFS(a,max_ppa));
	}
	cout<<res<<endl;
}

void initialize(int n){
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<=n;i++)
		adj[i].clear();
}

int main(){
	int n,m;cin>>n>>m;
	while(m!=0 || m!=0){
		initialize(n);
		solve(n,m);
		cin>>n>>m;
	}
	return 0;
}
