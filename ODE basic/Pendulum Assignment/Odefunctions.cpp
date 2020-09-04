#include "Odefunctions.h"
 
 
 void Euler_predictor(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double* parameters)
{

/* Function that uses Euler-Predictor-Trapezoidal algorithm
   **Inputs**
   theta = a vector with initial value in theta[0] (double)
   omega = a vector with initial value in omega[0] (double)
   n = number of steps (int)
   deltat = the step size (double)
   *func() = the function representing the RHS of the ODE

   **Returns**
   It returns nothing but modifies the pointer to arrays of theta and omega
*/


double h = deltat;

for(int i=0;i<=n;i++)
{

double omega_predic = omega[i] + h * (*fun)(i*deltat,theta[i],omega[i],parameters);
double theta_predic = theta[i] + h * omega[i];

theta[i+1] = theta[i] + (h/2) * (omega[i] + omega_predic);
omega[i+1] = omega[i] + (h/2) * ( (*fun)(i*deltat,theta[i],omega[i],parameters) + (*fun)((i+1)*deltat ,theta_predic,omega_predic,parameters) );

}
}

void Taylor_series(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double (*funderiv)(double t,double theta,double omega,double* param),double* parameters)
{

/* Function that uses Taylor-Series method to solve the ODE

   **Inputs**
   theta = a vector with initial value in theta[0] (double)
   omega = a vector with initial value in omega[0] (double)
   n = number of steps (int)
   deltat = the step size (double)
   *func() = the function representing the RHS of the ODE
   *funcderiv = the double derivative of the RHS of the ODE

   **Returns**
   It returns nothing but modifies the pointer to arrays of theta and omega
*/

double h = deltat;

for(int i=0;i<=n;i++)
{

theta[i+1] = theta[i] + h * omega[i] + (h*h)/2 * (*fun)(i*deltat,theta[i],omega[i],parameters);

omega[i+1] = omega[i] + h * (*fun)(i*deltat,theta[i],omega[i],parameters) + (h*h)/2 * (*funderiv)(i*deltat,theta[i],omega[i],parameters);

}
}

void RK2(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double* parameters)
{

/* Function that uses Runge-Kutta 2 method to solve the ODE

   **Inputs**
   theta = a vector with initial value in theta[0] (double)
   omega = a vector with initial value in omega[0] (double)
   n = number of steps (int)
   deltat = the step size (double)
   *func() = the function representing the RHS of the ODE


   **Returns**
   It returns nothing but modifies the pointer to arrays of theta and omega
*/

   double h = deltat;

   for(int i=0;i<=n;i++)
   {

   double k1_theta = omega[i];
   double k1_omega = (*fun)(i*deltat,theta[i],omega[i],parameters);

   double k2_theta = omega[i] + (h/2) * k1_omega;
   double k2_omega = (*fun)(i*deltat + (h/2) ,theta[i] + (h/2) * k1_theta,omega[i] + (h/2) * k1_omega,parameters);   
   
   omega[i+1] = omega[i] + h * k2_omega;
   theta[i+1] = theta[i] + h * k2_theta;

   }  


}

void RK4(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double* parameters)
{
   /* Function that uses Runge Kutta 4 method to solve the ODE

   **Inputs**
   theta = a vector with initial value in theta[0] (double)
   omega = a vector with initial value in omega[0] (double)
   n = number of steps (int)
   deltat = the step size (double)
   *func() = the function representing the RHS of the ODE
  

   **Returns**
   It returns nothing but modifies the pointer to arrays of theta and omega
*/

   double h = deltat;

   for(int i=0;i<=n;i++)
   {

   double k1_theta = omega[i];
   double k1_omega = (*fun)(i*deltat,theta[i],omega[i],parameters);

   double k2_theta = omega[i] + (h/2) * k1_omega;
   double k2_omega = (*fun)(i*deltat + (h/2) ,theta[i] + (h/2) * k1_theta,omega[i] + (h/2) * k1_omega,parameters);  

   double k3_theta = omega[i] + (h/2) * k2_omega;
   double k3_omega = (*fun)(i*deltat + (h/2) ,theta[i] + (h/2) * k2_theta,omega[i] + (h/2) * k2_omega,parameters);

   double k4_theta = omega[i] + h * k3_omega;
   double k4_omega = (*fun)(i*deltat + h ,theta[i] + h * k3_theta,omega[i] + h * k3_omega,parameters);

   omega[i+1] = omega[i] + (h/6) * (k1_omega + 2 * k2_omega + 2 * k3_omega + k4_omega);
   theta[i+1] = theta[i] + (h/6) * (k1_theta + 2 * k2_theta + 2 * k3_theta + k4_theta);

   }  

}
