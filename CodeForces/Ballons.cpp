#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n;cin>>n;
	int suma=0, indice_min=0;
	
	vector <int> numero(n);
	
	for(int i=0;i<n;i++)
		cin>>numero[i];
	
	int min=numero[0];
	
	for(int i=0;i<n;i++){
		if(numero[i]<min){
			min=numero[i];
			indice_min=i;
		}
		suma+=numero[i];
	}
		
	if(suma-min==min || n==1)
		cout<<"-1"<<endl;
	else{
		cout<<"1"<<endl;
		cout<<indice_min+1<<endl;
	}
	return 0;
}
