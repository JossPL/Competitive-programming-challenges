/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Primeramente vemos todos los elementos de la lilsta como nodos de un grafo y las condiciones dadas como aristas que los unen. 
Si tenemos a<b entonces trazamos una arista que va de a a b. Asui el problema se convierte en encontrar todos los ordenes topologicos que hay en este grafo.

Para resolver este ejrcicio se hizo uso del algoritmo del algoritmo de Khans de manera recursiva. Es decir, partimos de un nodo y lo fijamos. 
Vamos sobre todos los nodos que son adyacentes a el y agregamos alguno de ellos. Lo marcamos como visitado y hacemos una llamada recursiva. 
Asi, depues de iterar sobre las listas de nodos adyacentes de cada uno de ellos habremos obtenido la totalidad de ordenes topologicos en el grafo.

La complejidad de este algoritmo es O(n!) donde n es la cantidaad de elementos que podemos ordenar. Pues por cada uno hay a lo mas n-1,n-1,n-3,...
conexiones en el grafo y por cada unaa de ellas debemos verificar si es un orden topologico valido.
*/


#include <bits/stdc++.h>
using namespace std;
int k=0;

struct graph{
	vector<vector<int>> adj;
	vector<int> in_degree;
	vector<int> discovered;
	int n;
	
	graph(int nn, vector<pair<int,int>>& edges){
		adj.resize(nn);
		in_degree.assign(nn,0);
		discovered.assign(nn,false);
		n=nn;
		
		for(auto a:edges){
			adj[a.first].push_back(a.second);
			in_degree[a.second]++;
		}
		
	}
};


void print(list<int> q, vector<char> &letter){
	if(k)
		cout<<endl;
	while(!q.empty()){
		cout<<letter[q.front()];
		if(q.size()>1)
			cout<<" ";
		q.pop_front();
	}
	k++;
}


/*
path -> el orden topologico que se va formando hasta el momento
discovered -> cuales nodos ya fueron explorados en el orden topologico que estamos checando actualmente
gr -> grafica sobre la cual se esta buscando el orden topoogico
*/

bool top_sort(list<int> &path, vector<bool> &discovered, graph& gr, vector<char> &letter){
	bool flag=false;
	for(int i=0;i<gr.n;i++){
		if(gr.in_degree[i]==0 && !discovered[i]){
			discovered[i]=true;
			for(auto a:(gr.adj)[i])
				gr.in_degree[a]--;
			path.push_back(i);
			
			flag=top_sort(path,discovered,gr,letter) || flag;
			
			discovered[i]=false;
			for(auto a:gr.adj[i])
				gr.in_degree[a]++;
			path.pop_back();
		}
	}
	
	if(path.size()==gr.n){
		print(path,letter);
		flag=true;
	}
	return flag;
}

void solve(){
	string s;
	k=0;
	getline(cin,s);
	map <char,int> node;
	vector<char> letter;
	int n=0;
	
	for(auto c:s){
		if(c!=' '){
			letter.push_back(c);
			n++;
		}	
	}
	
	sort(letter.begin(),letter.end());
	for(int i=0;i<n;i++){
		//cout<<letter[i]<<" -> "<<i<<endl;
		node[letter[i]]=i;
	}
		
	
	vector<pair<int,int>> edges;
	
	getline(cin,s);
	for(int i=0,j=2;i<s.size();i+=4,j+=4){
		edges.push_back( {node[s[i]],node[s[j]]} );
	}	
		
	graph g(n,edges);
	list<int> path;
	vector<bool> discovered(n,false);
	
	if( !top_sort(path,discovered,g,letter))
		cout<<"NO"<<endl;
	else
		cout<<endl;
}

int main(){
	int t;cin>>t;getchar();
	while(t--){
		string s;
		getline(cin,s);
		solve();
		if(t!=0)
			cout<<endl;
	}
		
	return 0;
}
