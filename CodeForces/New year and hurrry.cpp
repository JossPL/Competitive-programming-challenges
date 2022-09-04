#include <iostream>

using namespace std;

void New_year_and_hurry(){
	
	int n,k;cin>>n>>k;
	
	int time=0,i=0;
	
	while( ((time+=(i+1)*5) <= 240-k) && i<n)
		i++;
	
	cout<<i<<endl;
}

int main(){
	
	New_year_and_hurry();
	
	return 0;
}
