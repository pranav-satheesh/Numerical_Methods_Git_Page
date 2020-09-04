
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

double f(double x){return x;}

int main()
{
	int N;
	double f_0,x_0,h;
	cout<<"step(h):"; cin>>h;
	cout<<"# of solution points:"; cin>>N;
	cout<<"IC(f0 x0):"; cin>>f_0>>x_0;
	
	double sol[N];
	sol[0]=f_0;
	
	ofstream solution;
	solution.open("solution.txt");
	solution<<"f(x)"<<"\t"<<"x"<<endl;

	for(int i=0;i<N;i++)
	{
		sol[i+1]=sol[i]+(h*f(x_0+(i*h)));
		cout<<sol[i]<<endl;
		solution<<sol[i]<<"\t"<<x_0+(i*h)<<endl;
	}
	solution.close();
	
	return 0;
}
