#include <iomanip>
#include <iostream>
using namespace std;
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    Money operator+(const Money& other)const{Money m;m.paise=paise+other.paise;return m;}
    Money operator-(const Money& other)const{Money m;m.paise=paise-other.paise;return m;}
    Money& operator+=(const Money& other){paise+=other.paise;return *this;}
    bool operator==(const Money& other)const{return paise==other.paise;}
    bool operator<(const Money& other)const{return paise<other.paise;}
    friend ostream& operator<<(ostream& out,const Money& m){
        long long v=m.paise;if(v<0)out<<"-Rs "<<-v/100<<'.'<<setw(2)<<setfill('0')<<-v%100;
        else out<<"Rs "<<v/100<<'.'<<setw(2)<<setfill('0')<<v%100;
        out<<setfill(' ');return out;
    }
    friend istream& operator>>(istream& in,Money& m){long long r;int p;if(in>>r>>p)m.paise=r*100+p;return in;}
};
int main(){
    Money a(120,75),b(79,25),c=a+b;
    cout<<c<<'\n'<<boolalpha<<(c==Money(200))<<'\n';
    cout<<Money(0,75)+Money(0,50)<<'\n';
    cout<<"Negative subtraction: "<<Money(1,0)-Money(2,0)<<'\n';
}
