#include <iostream>
#include <cstring>
using namespace std;
class Text{
 char* data;
public:
 Text(const char*s=""){data=new char[strlen(s)+1];strcpy(data,s);}
 Text(const Text&o){data=new char[strlen(o.data)+1];strcpy(data,o.data);}
 Text&operator=(const Text&o){if(this!=&o){char*p=new char[strlen(o.data)+1];strcpy(p,o.data);delete[]data;data=p;}return *this;}
 Text&operator+=(const Text&o){char*p=new char[strlen(data)+strlen(o.data)+1];strcpy(p,data);strcat(p,o.data);delete[]data;data=p;return *this;}
 Text operator+(const Text&o)const{Text result(*this);result+=o;return result;}
 bool operator==(const Text&o)const{return strcmp(data,o.data)==0;}
 bool operator!=(const Text&o)const{return !(*this==o);}
 friend ostream&operator<<(ostream&out,const Text&t){return out<<t.data;}
 ~Text(){delete[]data;}
};
int main(){Text a("Hello "),b("World"),c("!");Text msg=a+b+c;cout<<msg<<'\n';Text empty;cout<<"Empty: ["<<empty<<"]\n";msg=msg;cout<<msg<<'\n';}
