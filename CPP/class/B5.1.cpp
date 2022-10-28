#include<iostream>
#include<cmath>
using namespace std;

class Ctriangle{
	
	private:
		double a,b,c;
		
	public:
	void setCtriangle(double s1,double s2,double s3){
		if( s1>0 && s2>0 && s3>0 && s1+s2>s3 && s1+s3>s2 && s2+s3>s1){
			a=s1; b=s2; c=s3;
		}
	}
	
	void showPerimeter(){
		double s = a+b+c;
		cout<<"Perimeter="<<s<<endl;
	} 
	
	void showArea(){
		double p=(a+b+c)/2;	
		double area = sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<"area="<<area<<endl;
	}
};

int main()
{
	Ctriangle A;
	A.setCtriangle(3,3,3);
	A.showPerimeter();
	A.showArea(); 
}


