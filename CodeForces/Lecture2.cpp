#include <iostream>
#include <map>

using namespace std;

int main(){
	
	int n,m;cin>>n>>m;
	
	map<string, string> lista;
	
	for(int i=0;i<m;i++){
		string p1,p2;cin>>p1>>p2;
		lista[p1]= p1.length()<=p2.length() ? p1:p2;	
	}
	
	for(int i=0;i<n;i++){
		string p;cin>>p;
		cout<<lista[p]<<" ";
	}
	
	return 0;
}
