/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejerccio, solamente nos fijamos en la cuarta l;inea de los numeros que nos dan, pues esta es donde difieren.
Dependiendo de en que parte se encuentre el asterisco

La complejidad de este algoritmo es O(n), con n lalongitud de la cadena, pues esta se recorre completamente.
*/


#include<bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;cin>>n;
	string s,ss;
	for(int i=0;i<4;i++)
		cin>>s;
	cin>>ss;
	for(int i=0;i<n;i++){
		if(s[4*i]=='*')
			cout<<2;
		if(s[4*i+1]=='*')
			cout<<1;
		if(s[4*i+2]=='*')
			cout<<3;
	}
	cout<<endl;
	return 0;
}
