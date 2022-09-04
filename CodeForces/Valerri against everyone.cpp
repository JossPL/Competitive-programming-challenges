#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Valerii_against_everyone(){
	
	int n;cin>>n;
	vector <int> potencias(n);
	
	for(int i=0;i<n;i++)
		cin>>potencias[i];
		
	sort(potencias.begin(), potencias.end());
	
	for(int i=0;i<n-1;i++)
		if(potencias[i]==potencias[i+1]){
			cout<<"YES"<<endl;
			return;
		}	
	
	cout<<"NO"<<endl;
}

int main(){
	
	int n;cin>>n;
	while(n--)
		Valerii_against_everyone();
	
	return 0;
}
