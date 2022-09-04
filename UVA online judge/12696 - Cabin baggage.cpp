/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejercicio la parte principal solo es una condicion con las caracteristicas que da el problema. 
Ademas se cuentan las veces que las maletas cumplen las condiciones

La complejidad de este algoritmo es O(n), con n el numero de maletas a estudiar.
*/


#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int tot=0,n;
	cin>>n;
	while(n--){
		float m1,m2,m3,w; cin>>m1>>m2>>m3>>w;
		if( ((m1<=56 && m2<=45 && m3<=25) || m1+m2+m3<=125) && w<=7   ){
			cout<<1<<endl;
			tot++;
			continue;
		}
		else
			cout<<0<<endl;
		
	}
	cout<<tot<<endl;
	
	
	return 0;
}
