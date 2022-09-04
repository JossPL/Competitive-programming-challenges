#include <iostream>

using namespace std;

struct point{
	int x;
	int y;
};

int main(){
	
	point p1,p2,p3;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
	
	point P1,P2,P3;
	P1.x=p3.x+p2.x-p1.x;	
	P1.y=p3.y+p2.y-p1.y;
	P2.x=p3.x+p1.x-p2.x;	
	P2.y=p3.y+p1.y-p2.y;
	P3.x=p2.x+p1.x-p3.x;	
	P3.y=p2.y+p1.y-p3.y;
	
	cout<<"3"<<endl;
	cout<<P1.x<<" "<<P1.y<<endl;
	cout<<P2.x<<" "<<P2.y<<endl;
	cout<<P3.x<<" "<<P3.y<<endl;
	
	return 0;
}
