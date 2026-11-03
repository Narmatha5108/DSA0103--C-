#include <iostream>
#include <iomanip>
using namespace std;
class Money{
 long long paise;
public:
 Money(long long rupees=0,int p=0):paise(rupees*100+p){}
 Money operator+(const Money&o)const{return Money(0,static_cast<int>(paise+o.paise));}
 Money operator-(const Money&o)const{return Money(0,static_cast<int>(paise-o.paise));}
 Money& operator+=(const Money&o){paise+=o.paise;return *this;}
 bool operator==(const Money&o)const{return paise==o.paise;}
 bool operator<(const Money&o)const{return paise<o.paise;}
 friend ostream& operator<<(ostream&out,const Money&m){long long v=m.paise;if(v<0){out<<"-Rs ";v=-v;}else out<<"Rs ";return out<<v/100<<'.'<<setw(2)<<setfill('0')<<v%100<<setfill(' ');}
 friend istream& operator>>(istream&in,Money&m){long long r;int p;char dot;if(in>>r>>dot>>p&&dot=='.')m.paise=r*100+(r<0?-p:p);else in.setstate(ios::failbit);return in;}
};
int main(){Money a(120,75),b(79,25);Money c=a+b;cout<<c<<'\n'<<boolalpha<<(c==Money(200))<<'\n';cout<<"Carry: "<<Money(0,75)+Money(0,50)<<'\n';cout<<"Negative: "<<Money(5)-Money(7)<<'\n';}
