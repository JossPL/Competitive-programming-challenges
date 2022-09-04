/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea para reslolver este problem,a consiste en lo siguiente:
Se tendra una cola de prioridad donde almacenaremos las medicinas por medio de tuplas como se describe a continuacion
	<siguiente momento en que toca la medicina, prioridad, nombre>
Una vez que se toma una medicina, sacamos esta de la cola, actualizamos el tiempo de cuando tocaria la siguiente dosis y posteriormente la vovemos a meter.
De esta forma, por como son ordenadas las tuplas, la medicina que mas pronto este es la que se tomara.

Este algoritmo tiene compljidad O(n log n) pues cada insecion en la cola de prioridad nos toma tiempo logaritmico.
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, doses, time;
    cin>>m>>doses;
    string med;
    map<string, int> tiempo;
	
	priority_queue<tuple<int, int, string>> pq;			//tiempo de dosis, prioridad, nombre
    tuple<int, int, string> hold;
    for(int i=0; i<m; i++){
        cin>>med>>time;
        hold=make_tuple(-1*time, m-i, med);				//Se guardan como negativos para siempre obtener el menor
        pq.push(hold);
        tiempo[med]=time;
    }
    
    for(int i=0; i<doses; i++){
        hold=pq.top(); pq.pop();
        cout<<-1*get<0>(hold)<<" "<<get<2>(hold)<<endl;
		get<0>(hold)-=tiempo[get<2>(hold)];
        pq.push(hold);
    }

}

int main(){
	int t; cin>>t;
    while(t--) 
		solve();
    return 0;
}
