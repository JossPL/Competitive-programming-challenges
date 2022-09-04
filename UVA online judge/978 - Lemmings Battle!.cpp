/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Primeramente comenzamos metiendo los poderes de cada uno de los equipos en una priority queue, de esta forma podremos siempre tener al mas poderoso.
Luego, mientras ningun equipo quede vacio, se simulan las batallas. Los sobrevivientes vuelven a ser enviados a las filas de su equipo.
Este proceso continua hasta que algun equipo quede vacio. 

Este algoritmo tiene compljidad O(n log n) donde n es el numero de participantes entre los dos equipos. 
Pues cada uno de ellos se agrega al menos una vez a una priority queue cuando estos son leidos y posteriormente en las batallas hay n inserciones nuevamente.
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
	int fields, sg, sb; cin>>fields>>sg>>sb;
	priority_queue<int> green, blue;
	vector<int> dif(fields);
	
	int hold;
	for(int i=0; i<sg; i++){
		cin>>hold;
		green.push(hold);
	}
	for(int i=0; i<sb; i++){
		cin>>hold;
		blue.push(hold);
	}
	
	while(1){
		int battles=min(fields, min(green.size(), blue.size()) );
		for(int i=0; i<battles; i++){
			dif[i]=green.top()-blue.top();
			green.pop();
			blue.pop();
		}
		//hacemos la insercion hasta despues de las batallas
		for(int i=0; i<battles; i++)
			if(dif[i]>0)	green.push(dif[i]);
			else if(dif[i]<0)	blue.push(-1*dif[i]);
		
		if(green.empty() && blue.empty()){
			cout<<"green and blue died\n";
			return;
		}
		if(blue.empty()){
			cout<<"green wins\n";
			while(!green.empty()){
				cout<<green.top()<<endl;
				green.pop();
			}
			return;
		}
		if(green.empty()){
			cout<<"blue wins\n";
			while(!blue.empty()){
				cout<<blue.top()<<endl;
				blue.pop();
			}
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){
    	solve();
    	if(t) cout<<endl;
	}
	
	return 0;
}
