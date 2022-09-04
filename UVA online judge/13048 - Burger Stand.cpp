#include <bits/stdc++.h>
using namespace std;

int cases=1;

void solve(){
	string road; cin>>road;
	int n=road.size();
	vector<int> free(n,0);
	
	for(int i=0; i<n; i++){
		switch(road[i]){
			case 'B': free[i]=-1;
					  free[max(0,i-1)]=-1;
					  free[max(0,i-2)]=-1;					  
					  break;
			case 'S': free[i]=-1;
					  free[max(0,i-1)]=-1;
					  free[min(i+1,n-1)]=-1;
					  break;
			case 'D': free[i]=-1; 
					  break;
		}
	}
	
	int ans=0;
	cout<<"Case "<<cases<<": ";
	for(int i=0; i<n; i++)
		if(free[i]==0)
			ans++;
			
	cout<<ans<<endl; cases++;
	
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
