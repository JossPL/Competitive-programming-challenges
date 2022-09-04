/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

El arguento importante para este ejercicio es ver que si la operacion se cumple en una base, entonces esta debe ser menor que 19.
Pues al momento de sumar los digitos correspondientes, el valor maximo que se obtiene es 18 (9+9). Por lo tanto, si el resultado se cumple para un 
numero mayor que 19, entonces tambien se valdra para 19. 

Una vez hecha esta observacion, solo evaluamos en cada una de las bases, para lo cual hacemos uso de la funcion eval. Impirmimos la menor para la cual se cumpla. 
Por lo tanto, la complejidad de este algoritmo es la complejidad de lo que no tome evaluar una string en cierta base, esto es O(nt) 
donde n es la longitud de cada string y t el numero de casos
*/


#include <bits/stdc++.h>
using namespace std;

int val(char c){
	return (int) c-(int) '0';
}

void eval(int b, int *len, bool *flag, string a){
	for(int j=0; j<a.size(); j++){
		if(b==1 && val(a[a.size()-1-j])!=1){
			*flag=false;
			return;
		}else if(val(a[a.size()-1-j])>=b && b>1){
			*flag=false;
			return;
		}
		*len+=val(a[a.size()-1-j])*pow(b, j);
	}
}

void solve(){
	string a, b, c;
	char aux;
	cin>>a>>aux>>b>>aux>>c;
	
	int lena, lenb, lenc;
	bool flag;
	for(int i=1; i<=19; i++){
		flag=true;
		lena=0, lenb=0, lenc=0;
		eval(i, &lena, &flag, a);
		eval(i, &lenb, &flag, b);
		eval(i, &lenc, &flag, c);
		
		if(!flag) continue;
		else if(lena+lenb==lenc){
			cout<<i<<endl;
			return;
		}
	}

	cout<<0<<endl;
}

int main(){
	int n; cin>>n;
	while(n--)
		solve();
	
	return 0;
}
