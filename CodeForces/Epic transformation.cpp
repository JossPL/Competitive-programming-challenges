#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Epic_transformation(){
	
	long long n;cin>>n;
	vector <long long> num (n);
	
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	sort(num.begin(),num.end());
	long long max=1,rep=0;
	
	for(long long j=0;j<n;j++){
		
		if(j==0){
			rep++;
			continue;
		}
			
		if(num[j]==num[j-1])
			rep++;
		
		if(num[j] != num[j-1] || j==n-1){
			if(max<rep){
				max=rep;
				rep=1;
			}
		}
	}
	
	if(2*max < n){
		if (n % 2==0)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	else
		cout<<2*max-n<<endl;
}

int main(){
	
	int t;cin>>t;
	while(t--)
		Epic_transformation();
	
	return 0;
}

