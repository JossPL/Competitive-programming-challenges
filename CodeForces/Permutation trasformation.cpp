#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximo(vector<int> numeros, int inicio, int fin){
	
	int indice_max=inicio, i=0;
	
	for(int i=inicio;i<=fin;i++){
		if(numeros[i]>numeros[indice_max])
			indice_max=i;
	}
		
	return indice_max;
}

int lineas(int j, vector<int> numeros, int inicio, int fin, int nivel){
	
	int max=maximo(numeros,inicio,fin);
	
	cout<<"indice max: "<<max<<"valor max: "<<numeros[max]<<endl;
	getchar();
	
	if( numeros[max] == j)
		return nivel;
	else{
		nivel++;
		int copia_nivel=nivel;
		
		lineas(j,numeros,inicio,max-1,nivel);
		lineas(j,numeros,max+1,fin,copia_nivel);
	}
	
}
void Permutation_transormation(){
	
	int n;cin>>n;
	
	vector <int> num (n);
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	for(int i=0;i<n-1;i++)
		cout<<lineas(i,num,0,n-1,0)<<" ";
	cout<<lineas(n-1,num,0,n-1,0)<<" ";
}

int main(){

	int n;cin>>n;
	while(n--)
		Permutation_transormation();
	
	return 0;
}
