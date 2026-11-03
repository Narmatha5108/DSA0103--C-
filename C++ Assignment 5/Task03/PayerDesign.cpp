#include <iostream>
#include <algorithm>
struct Bill{virtual ~Bill()=default;virtual double total()const=0;};struct Sample:Bill{double n;Sample(double x):n(x){}double total()const override{return n;}};
struct Payer{virtual ~Payer()=default;virtual double amountCovered(const Bill&)const=0;};struct SelfPay:Payer{double amountCovered(const Bill&b)const override{return b.total();}};
struct Insurance:Payer{double limit,copay;Insurance(double l,double c):limit(l),copay(c){}double amountCovered(const Bill&b)const override{return std::min(limit,b.total()*(1-copay/100));}};
struct Government:Payer{double rate;Government(double r):rate(r){}double amountCovered(const Bill&b)const override{return std::min(rate,b.total());}};
struct Corporate:Payer{double pct;Corporate(double p):pct(p){}double amountCovered(const Bill&b)const override{return b.total()*pct/100;}};
int main(){Sample b(50000);Insurance i(40000,10);Corporate c(75);std::cout<<i.amountCovered(b)<<' '<<c.amountCovered(b)<<'\\n';}
