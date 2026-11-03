#include <iostream>
#include <stdexcept>
using namespace std;
class Auditorium{
 int rows,cols,booked; bool** seats;
public:
 Auditorium(int r,int c):rows(r),cols(c),booked(0),seats(nullptr){
 if(r<0||c<0)throw invalid_argument("Negative dimensions");
 if(rows){seats=new bool*[rows];int made=0;try{for(;made<rows;++made)seats[made]=new bool[cols]{};}catch(...){for(int i=0;i<made;++i)delete[]seats[i];delete[]seats;throw;}}
 cout<<"Created "<<rows<<" x "<<cols<<'\n';}
 bool book(int r,int c){if(r<0||r>=rows||c<0||c>=cols)throw out_of_range("Invalid seat");if(seats[r][c])return false;seats[r][c]=true;++booked;return true;}
 bool cancel(int r,int c){if(r<0||r>=rows||c<0||c>=cols)throw out_of_range("Invalid seat");if(!seats[r][c])return false;seats[r][c]=false;--booked;return true;}
 ~Auditorium(){for(int i=0;i<rows;++i)delete[]seats[i];delete[]seats;cout<<"Closed. Booked: "<<booked<<'\n';}
};
int main(){Auditorium morning(2,3);morning.book(0,1);{Auditorium special(1,2);special.book(0,0);}Auditorium* evening=new Auditorium(3,4);evening->book(2,3);delete evening;Auditorium empty(0,5);}
