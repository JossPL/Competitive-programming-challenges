/*
Josue Alejanmdro Perez Lara
josue.perez@cimat.mx

La idea para resolver este problema consiste en dos busquedas binarias anidadas. 
Es decir, primero hacemos una busqueda binaria para saber cuantodeberia pagar el que gasto menos. 
Una vez fijo este valor buscamos si existe un valor mayor a el que cumpla las condiciones que solicita el problema. 
Si dicho numero no existe entonces cambiamos el primer valor y nuevamente buscamos en la segunda busqueda binaria. 
Este proceso se repite hasta dar con la parja que cumple las condiciones.

La complejidad de este algoritmo es O(t log^2 n) donde n es el rango de los valores que puede tomar la deuda de la luz y t la cantidad de casos.

*/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a,b;

ll pay(ll x){
	if(x<=100)
		return 2*x;
	if(101<=x && x<=10000)
		return 200+3*(x-100);
	if(10001<=x && x<=1000000)
		return 200+3*9900+(x-10000)*5;
	return 200+3*9900+990000*5+(x-1000000)*7;
}

//x represneta la cantidad de watts que gaste yo y [l,r] el rango donde se encuentra la cantidad de luz que gasto el vecino
//Esta funcion regresa el entero mas grande que 
ll busca_pareja(ll x, ll l, ll r){
	if(pay(2*x)>a)
		return -2;
		
	if(l==r){
		int y=l-1;
		int dif=max(pay(x),pay(y))-min(pay(x),pay(y));
		if(pay(x+y)==a){
			if(dif<b)
				return -2;
			if(dif>b)
				return -1;
			return y;
		}
		if(dif<b)
			return -2;
		if(dif>=b)
			return -1;
	}
	ll p=(l+r)/2;
	if(pay(p+x)<=a)
		return busca_pareja(x,p+1,r);
	return busca_pareja(x,l,p);
}

ll solve(ll l, ll r){
	ll p=(l+r)/2;
	ll aux=busca_pareja(p,p,(ll)1e9);	
	if(aux>0)
		return p;
	if(aux==-2)
		return solve(l,p);
	if(aux==-1)
		return solve(p+1,r);
}

int main(){
	cin>>a>>b;
	while(a!=0 || b!=0){
		cout<<pay(solve(1,(ll)1e9))<<endl;
		cin>>a>>b;
	}
	return 0;
}
