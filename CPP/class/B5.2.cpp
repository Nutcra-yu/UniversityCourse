#include<iostream>
#include<cmath>
using namespace std;

class Point{
	
	private:
		double x,y;
		
	public:
		
		Point(double X,double Y){
			x = X;
			y = Y;
		}
		
		double Distance(Point &a){
			double d = sqrt( (a.x - x)*(a.x - x) + (a.y - y)*(a.y - y) );
			return d;
		}
		
};


int main(){
	Point A(0,0);
	Point B(10,1);
	cout<<A.Distance(B);
}



