#include<iostream>
#include<math.h>
#include<fstream>
#include<assert.h>
using namespace std;


//* The Baseball Trajectory program utilises three different algorithms to solve basic ODES*//
int main()
{

//Initial conditions for the position and velocity of the baseball

double r0[2],v0[2],r[2],v[2],a[2];
double y1,speed,theta;

cout<<"Enter initial height(meters):";
cin>>y1;

r0[0] = 0;
r0[1] = y1;

cout<<"Enter initial speed(m/s):";
cin>>speed;
cout<<"Enter initial angle(degrees):";
cin>>theta;

const double pi = 3.141592654;

v0[0] = speed*cos(theta*pi/180); //Initial velocity(x)
v0[1] = speed*sin(theta*pi/180); //Initial velovity(y)

r[0] = r0[0];
r[1] = r0[1];

v[0] = v0[0];
v[1] = v0[1];

//*Physical parameters

double Cd = 0.35; //Drag coefficient
double area = 4.3e-3; //cross sectional area of the ball (m^2)
double grav = 9.81; //Acc. due to gravity (m/s^2)
double mass = 0.145; //Mass of projectile (kg)
double airFlag,rho;

cout<<"Air resistance?(Yess:1,No:0):";
cin>>airFlag;

if(airFlag == 0)
	rho=0; //no air resistance
else
	rho=1.2; //Densit of air (kg/m^3)

double airconst = -0.5*Cd*rho*area/mass;
//*loop until ball hits ground or max steps completed
double tau;
cout<<"Enter timestep, tau(sec):";
cin>>tau;

int istep,maxstep =1000; //maximum number of steps;

double *xplot, *yplot, *xnoair, *ynoair;

xplot = new double[maxstep];
yplot = new double[maxstep];

xnoair = new double[maxstep];
ynoair = new double[maxstep];

for(istep=0; istep<=maxstep; istep++){

	//Record  position(computed and theoretical)

	xplot[istep] = r[0];
	yplot[istep] = r[1];
	
	cout<<xplot[istep]<<yplot[istep]<<endl;

	double t = istep*tau;
	cout<<t;

	xnoair[istep] = r0[0] + v0[0] * t;
	ynoair[istep] = r0[1] + v0[1] *t -0.5*grav*t*t;

	cout<<xnoair[istep]<<ynoair[istep];
	//*accelaration of ball
	double normV = sqrt(v[0]*v[0] + v[1]*v[1]);
	a[0] = airconst*normV*v[0];
	a[1] = airconst*normV*v[1];
	a[1] -= grav;

	//*Euler's method

	r[0] += tau*v[0];
	r[1] += tau*v[1];
	v[0] += tau*a[0];
	v[1] += tau*a[1];


	/*Euler-Cromer Method

	v[0] += tau*a[0];
	v[1] += tau*a[1];
	r[0] += tau*v[0];
	r[1] += tau*v[1];
        
        */

	
	/*Midpoint Method

	v[0] += tau*a[0];
	v[1] += tau*a[1];

	r[0] += tau*v[0]+0.5*tau*tau*a[0];
	r[1] += tau*v[1]+0.5*tau*tau*a[1];
        
        */
	
	cout<<r[0]<<r[1]<<v[0]<<v[1];

	//*If ball reaches ground(y<0), break out of the loop

	if( r[1] < 0) {
	break;
	}
}

cout<<"Maximum range is "<<r[0]<<"meters"<<endl;
cout<<"Time of flight is"<<istep*tau<<"seconds"<<endl;

ofstream plotOut("plot.txt"),noairOut("noair.txt");

for(int i=0;i<=istep;i++){
plotOut<<xplot[i]<<"\t"<<yplot[i]<<endl;
}

for(int i=0;i<=istep;i++){
noairOut<<xnoair[i]<<"\t"<<ynoair[i]<<endl;
}

delete [] xplot,yplot,xnoair,ynoair;

return 0;
}



