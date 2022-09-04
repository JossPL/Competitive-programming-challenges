#include <iostream>

using namespace std;

int main(){
	
	int n;cin>>n;
	double dollars=0;
	
	for(int i=1;i<=n;i++)
		dollars+=1.0/i;
		
	cout<<dollars<<endl;
	
	return 0;
}
	
	
	
