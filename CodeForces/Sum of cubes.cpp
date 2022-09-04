#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void Sum_of_cubes(){
	
	long long int x;cin>>x;
	vector<long long int> cubos (int(cbrt(x)));
	int i=1;
	
	for(i=1;pow(i,3)<=x;i++){
		cubos[i-1]=pow(i,3);
	}
	
	cubos.resize(i-1);
	
	auto ptr=cubos.begin();
	while(ptr !=  cubos.end()){
		if(    binary_search( cubos.begin(), cubos.end(), x-*ptr )    ){
			cout<<"YES"<<endl;
			return;
		}
		
		ptr++;
	}
	cout<<"NO"<<endl;
}

int main(){
	
	int t;cin>>t;
	while(t--)
		Sum_of_cubes();
	
	return 0;
}
