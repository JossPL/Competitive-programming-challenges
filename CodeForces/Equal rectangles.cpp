#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Equal_rectangles(){
	
	int n;cin>>n;
	vector <int> medidas (4*n);
	
	for(int i=0;i<4*n;i++)
		cin>>medidas[i];
	
	sort(medidas.begin(),medidas.end());
	bool res=true;
	int area=0;

	
	for(int i=0 ; i<n ; i++){
		
		if( medidas[2*i] != medidas [2*i+1] ){
			res=false;
			break;
		}
			
		if( medidas[ (4*n-1)-2*i ] != medidas [ (4*n-1)-2*i-1 ] ){
			res=false;
			break;
		}
		
		if(i==0)
			area=medidas[0] * medidas [ 4*n-1 ];
			
		if(area != medidas[2*i] * medidas[ (4*n-1)-2*i ] ){
			res= false;
			break;
		}
	}
	
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
}

int main(){
	
	int c;cin>>c;
	while(c--)
		Equal_rectangles();

	return 0;
}
