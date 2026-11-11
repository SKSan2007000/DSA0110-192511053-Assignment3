#include <iostream>
using namespace std;
class SeatMap {
    int rows, cols;
    char** seats;
public:
    SeatMap(int r,int c):rows(r),cols(c),seats(nullptr){
        if(rows>0 && cols>0){seats=new char*[rows];for(int i=0;i<rows;++i){seats[i]=new char[cols];for(int j=0;j<cols;++j)seats[i][j]='O';}}
        cout<<"Event opened: "<<rows<<" x "<<cols<<'\n';
    }
    ~SeatMap(){for(int i=0;i<rows;++i)delete[] seats[i];delete[] seats;cout<<"Event closed: "<<rows*cols<<" seats checked\n";}
    bool book(int r,int c){if(r<0||r>=rows||c<0||c>=cols||seats[r][c]=='X')return false;seats[r][c]='X';return true;}
    void cancel(int r,int c){if(r>=0&&r<rows&&c>=0&&c<cols)seats[r][c]='O';}
    void show()const{for(int i=0;i<rows;++i){for(int j=0;j<cols;++j)cout<<seats[i][j]<<' ';cout<<'\n';}}
};
int main(){
    {SeatMap hall(2,3);cout<<"Book (0,1): "<<hall.book(0,1)<<'\n';cout<<"Book same seat: "<<hall.book(0,1)<<'\n';hall.show();hall.cancel(0,1);cout<<"After cancel:\n";hall.show();}
    {SeatMap empty(0,4);empty.show();}
    SeatMap* heapHall=new SeatMap(1,2);delete heapHall;
}
