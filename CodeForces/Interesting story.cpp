#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int diferencia(char c, string s){
	int res=0;
	for(int i=0;i<s.size();i++)
		if(s[i]==c)
			res++;
	return 2*res-s.size();
}

struct funcion{
	
	char param;
	
	funcion(char param){
		this->param=param;
	}

	bool operator ()(string s1,string s2){
		if(diferencia(param,s1)<diferencia(param,s2))
			return true;
		return false;
	}
};

void Interesting_story(){
	
	int n;cin>>n;getchar();
	string V[n];
	
	for(int i=0;i<n;i++)
		getline(cin,V[i]);
	
	long res=0;
	
	for(int i=0;i<5;i++){
		long dif=0, palabras=0,k=n-1;
		sort(V,V+n,funcion('a'+i));
		
		do{
			dif+=diferencia('a'+i,V[k]);
			palabras++;
			k--;
		}while(dif>0 && k>=0);
		
		if(dif<=0)
			palabras--;

		res=max(res,palabras);
	}
	
	cout<<res<<endl;
}


int main(){
	int t;cin>>t;
	while(t--)
		Interesting_story();
	return 0;
}
