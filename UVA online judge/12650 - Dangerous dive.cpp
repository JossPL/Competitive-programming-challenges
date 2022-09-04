/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejercicio se implemento una idea bastante sencilla, esta consiste en ir marcando los elementos que si regresaron en un arreglo.
Posteriormente se imprimen los elementos que no fueron marcados.

La complejidad de este algoritmo es O(n), pues se sabe que m<=n.
*/


#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	while(cin>>n>>m){
		vector<bool> ret(n+1,false);
		for(int i=0;i<m;i++){
			int x;cin>>x;
			ret[x]=true;
		}
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(!ret[i]){
				cout<<i<<" ";
				flag=true;
			}
		}
		if(!flag)
			cout<<"*"<<endl;
		else
			cout<<endl;
	}
	
	return 0;
}
