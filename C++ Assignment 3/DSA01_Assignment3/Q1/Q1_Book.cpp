#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Book {
 string title, author; int copies;
 static int check(int n){ if(n<0) throw invalid_argument("Copies cannot be negative"); return n; }
public:
 Book():Book("Not entered","Not entered",0){}
 explicit Book(const string& t):Book(t,"Donated book",1){}
 Book(const string& t,const string& a,int n):title(t),author(a),copies(check(n)){}
 void show()const{cout<<title<<" | "<<author<<" | Copies: "<<copies<<'\n';}
 void setDetails(const string&t,const string&a,int n){title=t;author=a;copies=check(n);}
};
int main(){try{Book a;Book b("Wings of Fire");Book c("The Guide","R. K. Narayan",5);a.show();b.show();c.show();Book d;d.setDetails("Ponniyin Selvan","Kalki",3);d.show();Book bad("Invalid","Test",-2);}catch(const exception&e){cout<<"Error: "<<e.what()<<'\n';}}
