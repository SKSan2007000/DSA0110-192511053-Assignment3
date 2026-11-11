#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex():real(0),imag(0){}
    Complex(double r):real(r),imag(0){}
    Complex(double r,double i):real(r),imag(i){}
    Complex operator+(const Complex& z)const{return Complex(real+z.real,imag+z.imag);}
    Complex operator-(const Complex& z)const{return Complex(real-z.real,imag-z.imag);}
    Complex operator*(const Complex& z)const{return Complex(real*z.real-imag*z.imag,real*z.imag+imag*z.real);}
    Complex operator/(const Complex& z)const{
        double d=z.real*z.real+z.imag*z.imag;
        if(d==0) throw runtime_error("division by zero impedance");
        return Complex((real*z.real+imag*z.imag)/d,(imag*z.real-real*z.imag)/d);
    }
    double magnitude()const{return sqrt(real*real+imag*imag);}
    bool operator==(const Complex& z)const{return fabs(real-z.real)<1e-9&&fabs(imag-z.imag)<1e-9;}
    friend ostream& operator<<(ostream& out,const Complex& z){return out<<z.real<<(z.imag<0?" - ":" + ")<<fabs(z.imag)<<"j";}
};
int main(){
    Complex r(10), l(0,5), c(0,-2);
    Complex series=r+l+c;
    Complex parallel=(r*l)/(r+l);
    cout<<"Series impedance: "<<series<<" (|Z|="<<series.magnitude()<<")\n";
    cout<<"Parallel impedance: "<<parallel<<" (|Z|="<<parallel.magnitude()<<")\n";
    try{Complex zero; cout<<r/zero<<'\n';}catch(const runtime_error& e){cout<<"Error: "<<e.what()<<'\n';}
}
