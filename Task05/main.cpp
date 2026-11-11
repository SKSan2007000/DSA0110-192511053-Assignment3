#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s){}
    Time& operator++(){++seconds;return *this;}
    Time operator++(int){Time old=*this;++seconds;return old;}
    bool operator==(const Time& t)const{return seconds==t.seconds;}
    bool operator<(const Time& t)const{return seconds<t.seconds;}
    int value()const{return seconds;}
    void show()const{int h=seconds/3600,m=(seconds/60)%60,s=seconds%60;cout<<h<<':'<<(m<10?"0":"")<<m<<':'<<(s<10?"0":"")<<s<<'\n';}
};
class Playlist {
    string tracks[3]={"Intro","Song A","Song B"};
public:
    string& operator[](int i){if(i<0||i>=3)throw out_of_range("track index");return tracks[i];}
    const string& operator[](int i)const{if(i<0||i>=3)throw out_of_range("track index");return tracks[i];}
};
int main(){
    Time t(5);Time a=t++;Time b=++t;
    cout<<a.value()<<' '<<b.value()<<' '<<t.value()<<'\n';
    Time end(3599);++end;end.show();
    Playlist p;cout<<p[1]<<'\n';
    try{cout<<p[-1]<<'\n';}catch(const out_of_range& e){cout<<"Error: "<<e.what()<<'\n';}
    try{cout<<p[3]<<'\n';}catch(const out_of_range& e){cout<<"Error: "<<e.what()<<'\n';}
}
