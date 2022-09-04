#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void Maximize_the_remaining_string(){
	
	string s;getline(cin,s);
	vector<int> rep(26);
	fill(rep.begin(),rep.end(),0);
	
	for(int i=0;i<s.length();i++)
		rep[s[i]-97]++;
	
	string res;
	int mayor=97;
	
	for(int j=0;j<s.length();j++){	
		int k=j;
			
		//Quita repeticiones y guarda indice y valor mayor.
		while( rep[s[j]-97] != 1 && j!=s.length()){
			if(rep[s[j]-97] == 0)
				goto fin;
			
			rep[s[j]-97]--;		
			if((int)s[j]>mayor){
				mayor=(int)s[j];
				k=j;
			}
			fin: j++;			
		}
			
		if( j==s.length() )
			break;
		
		if((int)s[j]>mayor){
			mayor=(int)s[j];
			k=j;
		}
		printf("%c",mayor);	
			
		for(int l=k+1;l<=j;l++)
			if(rep[s[l]-97]!=0)
				rep[s[l]-97]++;
		
		rep[s[j]-97]--;	
		rep[mayor-97]=0;
	
		mayor=97;
		j=k;
	}
	cout<<endl;
}

int main(){
	long int k;cin>>k;
	getchar();
	while(k--)
		Maximize_the_remaining_string();
	return 0;
}
