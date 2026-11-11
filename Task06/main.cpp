#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;
public:
    Text(const char* s="") { data=new char[strlen(s)+1]; strcpy(data,s); }
    Text(const Text& t) { data=new char[strlen(t.data)+1]; strcpy(data,t.data); }
    Text& operator=(const Text& t) {
        if(this!=&t){ char* fresh=new char[strlen(t.data)+1]; strcpy(fresh,t.data); delete[] data; data=fresh; }
        return *this;
    }
    ~Text(){delete[] data;}
    Text operator+(const Text& t)const{
        char* joined=new char[strlen(data)+strlen(t.data)+1];
        strcpy(joined,data); strcat(joined,t.data); Text result(joined); delete[] joined; return result;
    }
    bool operator==(const Text& t)const{return strcmp(data,t.data)==0;}
    bool operator!=(const Text& t)const{return !(*this==t);}
    friend ostream& operator<<(ostream& out,const Text& t){return out<<t.data;}
};
int main(){
    Text a("Hello "),b("C++"),c(" World");
    Text result=a+b+c; Text copy=result; copy=copy;
    cout<<result<<'\n'<<boolalpha<<(result==copy)<<'\n';
}
