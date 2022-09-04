/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este ejrcicio comenzamos guardando las posiciones de las camas guardadas y posteriormente analizamos cuales son las mas separadas.
Deespues de esto solo resta compara con los espacios que quedaron a las orillas de la fila, pues ahi podria estar tambien nuestra solucion. 

La complejidad de este algortimo es O(n) con n la cantidad de camas.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string &beds){
	vector<int> used;
	for(int i=0; i<beds.size(); i++)
		if(beds[i]=='X')
			used.push_back(i);
	
	int maxb=0, dif;
	for(int i=1; i<used.size(); i++){
		dif=used[i]-used[i-1]-1;
		if(dif%2==0)
			dif--;
		dif/=2;
		
		if(dif>maxb)
			maxb=dif;
	}
	dif=used[0]-1;
	if(dif>maxb)
		maxb=dif;
	
	dif=beds.size()-1-used.back()-1;
	if(dif>maxb)
		maxb=dif;
		
	cout<<maxb<<endl;
}

int main(){
	string s;
	while(cin>>s)
		solve(s);
	
	return 0;
}
