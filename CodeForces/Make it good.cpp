#include <iostream>
#include <vector>

using namespace std;

void Make_it_good(){
	
	long long n;cin>>n;
	vector <long long> number (n);
	
	for(int i=0;i<n;i++)
		cin>>number[i];
		
	long long k=n;
	int cambios=0;
		
	if(n==1){
		cout<<"0"<<endl;
		return;
	}
		
	while(k != 1 && cambios < 2){
		
		if(number[k-1] > number [k-2] && cambios==0)
			cambios++;
		
		if(number[k-1] < number [k-2] && cambios==1)
			cambios++;
		
		if(cambios != 2)
			k--;
	}
	
	cout<<k-1<<endl;
}

int main(){
	
	int n;cin>>n;
	while(n--)
		Make_it_good();
	
	return 0;
}
