#include <iostream>

using namespace std;

int main(){
	int k;cin>>k;
	while(k--){
		long long n;cin>>n;
		long long s=0;
		if(n <= 6){
			s=15;
		}else{
			if(n%2==0)
				s=2.5*n;
			else
				s=2.5*(n+1);
		}
		cout<<s<<endl;
	}
	return 0;
}
