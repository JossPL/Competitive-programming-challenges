#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Bogosort(){
	
	int n;cin>>n;
	vector <int> numeros(n);
	
	for(int i=0;i<n;i++)
		cin>>numeros[i];
	
	sort(numeros.begin(),numeros.end());
	
	for(int i=n-1;i>0;i--)
		cout<<numeros[i]<<" ";
	cout<<numeros[0]<<endl;
	
}

int main(){
	
	int n;cin>>n;
	while(n--)
		Bogosort();
	
	return 0;
}
