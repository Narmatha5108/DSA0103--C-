#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
class Complex{
 double re,im;
public:
 Complex():re(0),im(0){}
 Complex(double r):re(r),im(0){}
 Complex(double r,double i):re(r),im(i){}
 Complex operator+(const Complex&z)const{return {re+z.re,im+z.im};}
 Complex operator-(const Complex&z)const{return {re-z.re,im-z.im};}
 Complex operator*(const Complex&z)const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
 Complex operator/(const Complex&z)const{double d=z.re*z.re+z.im*z.im;if(d==0)throw domain_error("Division by zero impedance");return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};}
 bool operator==(const Complex&z)const{return fabs(re-z.re)<1e-9&&fabs(im-z.im)<1e-9;}
 double magnitude()const{return sqrt(re*re+im*im);}
 friend ostream&operator<<(ostream&out,const Complex&z){out<<z.re<<(z.im>=0?" + j":" - j")<<fabs(z.im);return out;}
};
int main(){try{const double pi=acos(-1.0),f=50,w=2*pi*f,R=10,L=.01,C=100e-6;Complex zr(R,0),zl(0,w*L),zc(0,-1/(w*C));Complex series=zr+zl+zc;Complex parallel=(zr*zl)/(zr+zl);cout<<"ZR: "<<zr<<"\nZL: "<<zl<<"\nZC: "<<zc<<"\nSeries: "<<series<<"\nMagnitude: "<<series.magnitude()<<" ohms\nParallel R-L: "<<parallel<<'\n';Complex zero;cout<<Complex(5,2)/zero<<'\n';}catch(const exception&e){cout<<"Error: "<<e.what()<<'\n';}}
