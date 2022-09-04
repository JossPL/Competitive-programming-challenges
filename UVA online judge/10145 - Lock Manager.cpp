/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea es asignar a cada item un set de sus transacciones que 
han sido aprobadas, e ir consultando y comparando para saber si las siguientes
peticiones deben ser ignoradas o aprobadas

Usamos otro set para guardar las transacciones que ya deben ser ignoradas

Entonces, dada una peticion, consultamos si la transaccion esta ignorada o si es la primera
transaccion de ese item, en caso de que si, se aprueba

Si no se cumple la condicion anterior, consultamos si esta ignorada y corroboramos con las transacciones 
ya aprobadas de ese item si es que la actual no entra en conflicto, si no entra, se aprueba. 
De lo contrario, se bloquea y la catalogamos como ignorada

Si la transaccion esta en el conjunto de ignorada, ignoramos y continuamos.

Asi, si t es el numero de casos, q el numero de transacciones e i el numero de items se tiene que el algoritmo es O(tqi log(q))
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic; //transaccion, locked status

void solve(){
	set<int> ignored;
	map<int, set<pic>> granted; //conjunto de peticiones aprobadas de cada item
	
	char lock; cin>>lock;
	int tran, item;
	while(lock!='#'){
		cin>>tran>>item;
		
		if(granted[item].size()==0 && ignored.count(tran)==0){
			granted[item].insert({tran, lock});
			cout<<"GRANTED\n";
		}else if(ignored.count(tran)==0){
			for(auto it : granted[item]){
				if(it.first!=tran && (lock=='X' || it.second=='X')){
					ignored.insert(tran);
					cout<<"DENIED\n";
					break;
				}
			}
			
			if(ignored.count(tran)==0){
				cout<<"GRANTED\n";
				granted[item].insert({tran, lock});
			}
		}
		else cout<<"IGNORED\n";
		cin>>lock;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
	    solve();
	    if(t!=0) cout<<endl;
	} 
	
	return 0;
}
