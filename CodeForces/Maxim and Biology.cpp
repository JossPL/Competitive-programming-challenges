#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int n;cin>>n;
	string s;cin>>s;
	string genome = "ACTG";
	int h=1000;
	
	for(int i=0;i<n-3;i++){
		int k=0;
		for(int j=0;j<4;j++){
			int dist = abs( genome[j]-s[j+i] );			
			k+=min (dist, 26-dist);
		}
		h=min(h,k);
	}
	
	cout<<h<<endl;
	
	return 0;
	
}
