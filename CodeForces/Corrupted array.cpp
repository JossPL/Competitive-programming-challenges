#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Corrupted_array(){
	
	int n;cin>>n;
	vector <long long int> num (n+2);
	long long int suma=0;
	
	for(int i=0;i<n+2;i++){
		cin>>num[i];
		suma+=num[i];
	}
		
	sort(num.begin(),num.end());
	
	long long int resto=suma-2*num[n+1];
	
	if (  binary_search(num.begin(),num.end()-1,resto)  ){
	 	
	 	bool flag=true; 	
	 	for(int i=0;i<n+1;i++){
	 		
	 		if(num[i]==resto && flag)
	 			flag=false;
	 		else
	 			cout<<num[i]<<" ";
		 }
	}
	else{
		if(num[n]== suma-num[n+1]-num[n])
			for(int i=0;i<n;i++)
				cout<<num[i]<<" ";
		else
			cout<<"-1";
	}
	cout<<endl;
}

int main(){
	
	int i;cin>>i;
	while(i--)
		Corrupted_array();
	
	return 0;
}
