/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejercicio se calcularon los divisores de r-c que sean mayores que r. 
Para optimizar en tiempo, el algoritmo checa solamebte los divisores hasta sqrt(n) y cada que encuentra uno agrega a su complemento.

Asi, la complejidad del algoritmo es O(n^(1/2)t) donde n es el representa el rango de valores c-r y t el numero de casos por checar.
*/


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;cin>>n;
	for(int k=1;k<=n;k++){
		ll c,r;cin>>c>>r;
		cout<<"Case #"<<k<<":";
		if(r!=c){
			set<ll> div;
			for(int i=1;i<=sqrt(c-r);i++){
				if( (c-r)%i==0 ){
					if(i>r)
						div.insert(i);
					if( (c-r)/i >r )
						div.insert((c-r)/i);
				}
			}

			for(auto a:div){
				cout<<" "<<a;
			}
		}
		else
			cout<<" "<<0;
		cout<<endl;
	}
	return 0;
}
