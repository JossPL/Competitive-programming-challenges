#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n;cin>>n;
	bool flag=false;
	
	if(n<3){
		cout<<"NO"<<endl;
		return 0;
	}
		
	vector <int> longitudes (n);
	
	for(int i=0;i<n;i++)
		cin>>longitudes[i];
	
	sort(longitudes.begin(),longitudes.end());
	
	for(int i=0;i<n-2;i++)
		if(longitudes[i]+longitudes[i+1]>longitudes[i+2])
			flag=true;
	
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}
