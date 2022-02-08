// INCLUDE LIBRARIES
#include<iostream>
#include<cmath>
using namespace std;

// DECLARE GLOBAL VARIABLES
double a=0.,b=0.,c=0., initial=0., initial2=0.; 


/* DECLARE FUNCTIONS
	1.- Square
	2.- Newton
		- 2.1 function
		- 2.2 derfuction
		- 2.3 iterations
		- 2.4 newton
*/

// 1) Square
int square (double a1, double b1,  double c1)
{
	 double d1;
	d1 = (b1*b1) - (4.*a1*c1);
	if (d1>=0.)
	{
		cout<<"\n The solution using GENERAL FORMULA is:\n";
		cout<<"x="<<((-b1 + sqrt(d1))/(2.*a1))<<"\n";
		cout<<"x="<<((-b1 - sqrt(d1))/(2.*a1))<<"\n";
	}
	else
	{
		// the answer if 0.5 + 34i (i=complex number)
		cout<<"\n The solution using GENERAL FORMULA is:\n";
		cout<<"x="<<((-b1 + sqrt(-d1))/(2.*a1))<<"i"<<"\n";
		cout<<"x="<<((-b1 - sqrt(-d1))/(2.*a1))<<"i"<<"\n";
		}
return 0;
}

// 2 Newton 

// 2.1 function
double function(double a2,double b2,double c2,double x)
{
	return((a2*(x*x))+(b2*x)+ (c2));
}

// 2.2 derfunction
double derfunction(double a3,double b3,double x)
{
	return((2.*a3*x)+(b3));
}

// 2.3 iteractions
double ite(double func, double der, double x)
{
	return (x-(func/der));
}
// 2.4 Newton
double newton (double x0)
{	
	double x0old, max=100000,tol=1.e-6; 
	
	int n;
	for (n=0; n<max; n++)
	{
	x0old = x0;			 
	x0=ite(function(a,b,c,x0),derfunction(a,b,x0),x0);
	if (abs((x0 -x0old))<= tol) break;
	}
	
	if (n>(max-1.))
		{
		cout<<"x= there is no root in real number \n";
		x0=0.;
		}
	else
		{
	cout<<"x="<<x0<<"\n";
		}
	return(0);
}


// MAIN

int main()
{
	
	cout<<"WELCOME \n Input a:\n";
		cin>> a;
	cout<<"Input b:\n";
		cin>> b;
	cout<<"Input c:\n";
		cin>>c;

	cout<<"your equation is:";
	cout<<a<<"x^2 + "<<b<<"x + "<<c<<"\n";
	cout<<"\n";

	//cout<<"Input initial value for newton iteractions:\n";
		//cin>>initial;
	cout<<"\n";
//Call the functions
 square(a,b,c);
		cout<<"\n";
		cout<<"\n";

//Determine initial values
initial = (-b/(2.*a))-1;
initial2 = (-b/(2.*a))+1;

cout<<"The solution using NEWTON METHOD is:\n";
newton(initial);
newton(initial2);
cout<<"\n";
main();

}