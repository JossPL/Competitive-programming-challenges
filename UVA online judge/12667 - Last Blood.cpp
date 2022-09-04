/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea del problema es tener dos matrices, la matriz que almacena los valores lastBlood de cada problema y su equipo
Tambien se tiene una matriz auxiliar para saber si un equipo X ya ha resuelto el problema Y, y saber si debemos ignorar
su submission

La complejidad de este algoritmo O(pe+s) con p la cantida de problemas, e la cantidad de equipos y s la cantidad de submisions
*/

#include <bits/stdc++.h>
using namespace std;

int val(char x){
	return (int) x-'A';
}

char trans(int x){
	int p=(int) 'A';
	p+=x;
	return (char) p;
}

void solve(int p, int e, int s){
	int score[p][2], check[e][p];
	/*score es la matriz de salida, check una tabla de equiposXproblema,
	 para saber si un equipo ya resolvio el problema e ignorar las submissions despues*/
	 
	//score , almacena el tiempo final y el id del equipo last blood
	
	for(int i=0; i<p; i++)
		for(int j=0; j<2; j++)
			score[i][j]=-1;

	for(int i=0; i<e; i++)
		for(int j=0; j<p; j++)
			check[i][j]=0;
	
	int time, team;
	char prob;
	string verdict;
	for(int i=0; i<s; i++){
		cin>>time>>team>>prob>>verdict;
		if(verdict.compare("Yes")==0){
			if(check[team-1][val(prob)]==0){ //Checamos si ya ha resuelto ese problema
				check[team-1][val(prob)]=1;
				if(time>=score[val(prob)][0]){ //Checamos si la submission no es mas reciente que las demas
					score[val(prob)][0]=time;
					score[val(prob)][1]=team;
				}
			}
		}
	}
	
	for(int i=0; i<p; i++){
		cout<<trans(i)<<" ";
		if(score[i][0]==-1) cout<<"- -\n";
		else  cout<<score[i][0]<<" "<<score[i][1]<<endl;
	}
}

int main(){
	int p, e, s; cin>>p>>e>>s;
	solve(p,e,s);
	
	return 0;
}
