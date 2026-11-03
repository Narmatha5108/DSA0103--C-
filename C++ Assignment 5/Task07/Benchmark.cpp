#include <iostream>
#include <vector>
#include <memory>
#include <variant>
#include <chrono>
using namespace std;
struct Base{virtual ~Base()=default;virtual double total()const=0;};struct OP:Base{double a,b;OP(double x,double y):a(x),b(y){}double total()const override{return a+b;}};struct IP:Base{double d,r,p;IP(double x,double y,double z):d(x),r(y),p(z){}double total()const override{return d*r+p;}};
struct Tagged{int type;double x,y,z;};double sw(const Tagged&b){return b.type?b.x*b.y+b.z:b.x+b.y;}using V=variant<OP,IP>;double vv(const V&v){return visit([](const auto&x){return x.total();},v);}
template<class F>double timeit(F f){auto a=chrono::steady_clock::now();volatile double x=f();(void)x;return chrono::duration<double>(chrono::steady_clock::now()-a).count();}
int main(){for(size_t n:{1000u,1000000u,10000000u}){vector<unique_ptr<Base>>v;vector<Tagged>s;vector<V>w;v.reserve(n);s.reserve(n);w.reserve(n);for(size_t i=0;i<n;i++)if(i%2){v.push_back(make_unique<IP>(3,2500,40000));s.push_back({1,3,2500,40000});w.emplace_back(IP(3,2500,40000));}else{v.push_back(make_unique<OP>(500,1200));s.push_back({0,500,1200,0});w.emplace_back(OP(500,1200));}double a=0,b=0,c=0;auto tv=timeit([&]{for(auto&p:v)a+=p->total();return a;});auto ts=timeit([&]{for(auto&p:s)b+=sw(p);return b;});auto tw=timeit([&]{for(auto&p:w)c+=vv(p);return c;});cout<<n<<" virtual="<<tv<<" switch="<<ts<<" variant="<<tw<<" equal="<<(a==b&&b==c)<<'\\n';}}
