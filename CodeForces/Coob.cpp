#include <iostream>
#include <vector>

using namespace std;

void Cobb(){
	int n,k;
	cin>>n>>k;
	
	vector <int> A(n+1);
	
	for(int i=1;i<=n;i++)
		cin>>A[i];

	long long MAX=LLONG_MIN;
	
	for(long long i=max(1LL,(long long)(n-2*k-1));i<=n;i++){
		for(int j=i+1;j<=n;j++){
			MAX=max(MAX,(long long)(i*j-k*(A[i]|A[j])));
		}
	}
	
	cout<<MAX<<endl;
	
}

int main(){
	int t;cin>>t;
	while(t--)
		Cobb();
	
	return 0;
}
