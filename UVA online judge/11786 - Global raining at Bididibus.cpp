/*
Si el ultimo caracter es \
	/    +0
	_    +1/2
	\    +1

Si el ultimo caracter es _
	/    -1/2
	_    +0
	\    +1/2

Si el ultimo caracter es /
	/    -1
	_    -1/2
	\    +0
*/


#include <bits\stdc++.h>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;cin>>n;
	
	map <pair<char,char>, float> m;
	m[{'\\','/'}]=0;
	m[{'\\','_'}]=0.5;
	m[{'\\','\\'}]=1;
	m[{'_','/'}]=-0.5;
	m[{'_','_'}]=0;
	m[{'_','\\'}]=0.5;
	m[{'/','/'}]=-1;
	m[{'/','_'}]=-0.5;
	m[{'/','\\'}]=0;
	
	while(n--){
		string s,ss; cin>>ss;
		s='_'+ss;\
		float res=0, curr=0;
		float c1=0, c2=1/2, c3=1;
		for(int i=1;i<s.size();i++){
			curr+=m[{s[i-1],s[i]}];
			curr=( curr<0?0:curr );
			res+=curr;
		}
		cout<<res<<endl;
	}
	
	return 0;
}
