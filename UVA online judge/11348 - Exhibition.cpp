/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Primeramente se leen todas las estmapillas junto con su dueno. 
Luego, para cada una de ellas checamos por medio de un map si hay dos personas que la tengan. En caso de que no aumentamos un contador que cada coleccionista tiene.
Una vez identificadas las estampillas unicas, solo se calculan los porcentajes corresopndientes a estas.

Este algoritmo tiene complejidad O(S log S ) donde S (con repeticiones) es la cantidad de estapillas que tienen entre todos. 
Pues en cada visita a estas estampas se accede a un map.
*/

#include <bits/stdc++.h>
using namespace std;

int cases=1;

void solve(){
	int n; cin>>n;
	vector<int> stamps[n];
	
	for(int i=0; i<n; i++){
		int hold; cin>>hold;
		for(int j=0; j<hold; j++){
			int aux; cin>>aux;
			stamps[i].push_back(aux);
		}
	}
	
	map<int, int> key;
	for(int i=0; i<n; i++)
		for(int j=0; j<stamps[i].size(); j++)
			if(key[stamps[i][j]]==0) key[stamps[i][j]]=i+1;
			else if(key[stamps[i][j]]!=i+1) key[stamps[i][j]]=-1;
	
	int tot=0;
	vector<int> ans(n+1, 0);
	map<int, int>::iterator i;
	for(i=key.begin(); i!=key.end(); i++)
		if(i->second >0){
			tot++;
			ans[i->second]++;
		}
	
	cout<<"Case "<<cases<<": ";
	for(int i=1; i<=n; i++){
		cout<<fixed<<setprecision(6)<<(double) (100*ans[i])/tot<<"%";
		if(i!=n)
			cout<<" "; 
	} cout<<endl;

	cases++;	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--) solve();
	
	return 0;
}
