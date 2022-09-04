#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;cin>>t;
	
	while(t--){
		
		int n;cin>>n;
		getchar();
		
		string s;
		getline(cin,s);
	
		int p=0,cambios=0;
	
		for(int i=0;i<n;i++){
			if(s[i]=='(')
				p++;
			else
				p--;
			
			if(p<0){
				cambios++;
				p++;
			}
		}
	cout<<cambios<<endl;
	}
	return 0;
}
