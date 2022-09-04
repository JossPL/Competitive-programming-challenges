/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

En este caso la cuadricula fue vista como un grafo. Asi, donde las conexiones de cada nodo son las casillas a las que s puede llegar.
Por lo tanto partiendo del nodo inicial, se lanza una BFS y todas las caillas que alcance son a las que se puede llegar. 
Tambien tenemos un contador que nos indica cuantos pares y cuantos impares llevamos. 

La complejidad de este algoritmo es O(rct), donde r es la cantidad de filas, c la de columnas y t la cantidad de casos. 
Pues es lo que se rc es lo que tarda en leer los datos y lanzar la BFS.
*/

#include<bits/stdc++.h>

using namespace std;

int grid[100][100],pares=0, impares=0;
bool vis[100][100];
int r,c,n,m;

void BFS(){	
	queue<pair<int,int>> q;
	int dirx[]={m,m,n,n,-m,-m,-n,-n}, diry[]={n,-n,m,-m,n,-n,m,-m};
	q.push({0,0});
	vis[0][0]=true;
	
	while(!q.empty()){
		pair<int, int> curr=q.front();
		q.pop();
		int vecinos=0;
		for(int i=0;i<8;i++){
			int cx = curr.first + dirx[i], cy=curr.second+diry[i];	
			if(0<=cx && cx<r && 0<=cy && cy<c){
				if(grid[cx][cy] != -1){
					vecinos++;
					if(vis[cx][cy]==false){
						vis[cx][cy]=true;
						q.push({cx,cy});
					}
				}					
			}
		}
		if(m==n || n*m==0)
			vecinos/=2;
		
		if(vecinos%2==1)
			impares++;
		else
			pares++;
	}
}

void solve(){
	cin>>r>>c>>m>>n;
	pares=impares=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			grid[i][j]=vis[i][j]=0;
		}
		
	int w;
	cin >> w;	
	for(int i=0;i<w;i++){
		int x1,y1;cin>>x1>>y1;
		grid[x1][y1]=-1;
	}
	
	BFS();
	cout<<pares<<" "<<impares<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
