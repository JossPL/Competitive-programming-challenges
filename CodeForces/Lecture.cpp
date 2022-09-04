#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class palabra{
	public:
	string l1;
	string l2;
	
	bool operator < ( const palabra &p1) {
		return this->l1 < p1.l1;
	}
	
	void imprime (){
		if(l1.length()>l2.length())
			cout<<l2<<" ";
		else 
			cout<<l1<<" ";
	}
};

int bin_search(vector<palabra> V, string s){
	
	int p=0,q=V.size();
	int i=(p+q)/2;
	
	while(p<q){
		if(s>V[i].l1)
			p=i;
		if(s==V[i].l1)
			return i;
		if(s<V[i].l1)
			q=i;
	i=(p+q)/2;
	}
	return i;
}

int main(){
	
	int n,m;cin>>n>>m;
	
	vector<palabra> V(m);
	
	for(int i=0;i<m;i++)
		cin>>V[i].l1>>V[i].l2;
	
	sort(V.begin(),V.end());
	
	string palabra;
	
	for(int i=0;i<n;i++){
		cin>>palabra;
		int j=bin_search(V,palabra);
		
		V[j].imprime();
	}
	
	return 0;
}
