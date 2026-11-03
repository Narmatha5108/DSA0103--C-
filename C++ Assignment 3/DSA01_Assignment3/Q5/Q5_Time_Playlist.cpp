#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
class Time{
 int seconds;
public:
 Time(int h=0,int m=0,int s=0):seconds(h*3600+m*60+s){if(h<0||m<0||m>=60||s<0||s>=60)throw invalid_argument("Invalid time");}
 Time&operator++(){++seconds;return *this;}
 Time operator++(int){Time old=*this;++seconds;return old;}
 bool operator==(const Time&o)const{return seconds==o.seconds;}
 bool operator<(const Time&o)const{return seconds<o.seconds;}
 friend ostream&operator<<(ostream&out,const Time&t){int h=t.seconds/3600,m=t.seconds%3600/60,s=t.seconds%60;return out<<h<<':'<<(m<10?"0":"")<<m<<':'<<(s<10?"0":"")<<s;}
};
class Playlist{
 vector<string> tracks;
public:
 Playlist(initializer_list<string>x):tracks(x){}
 string&operator[](int i){if(i<0||i>=static_cast<int>(tracks.size()))throw out_of_range("Playlist index out of range");return tracks[i];}
 const string&operator[](int i)const{if(i<0||i>=static_cast<int>(tracks.size()))throw out_of_range("Playlist index out of range");return tracks[i];}
 int size()const{return static_cast<int>(tracks.size());}
};
int main(){Time t(0,0,5);Time a=t++;Time b=++t;cout<<a<<' '<<b<<' '<<t<<'\n';Time x(0,59,59);++x;cout<<"Roll-over: "<<x<<'\n';Playlist p{"Song A","Song B","Song C"};cout<<p[1]<<'\n';try{cout<<p[p.size()]<<'\n';}catch(const exception&e){cout<<e.what()<<'\n';}}
