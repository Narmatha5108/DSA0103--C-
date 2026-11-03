#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cart {
 string items[10]; double prices[10]; int n=0; double discount=0;
public:
 Cart& add(const string& item,double price){if(n<10&&price>=0){items[n]=item;prices[n]=price;++n;}return *this;}
 Cart& setDiscount(double discount){if(discount>=0&&discount<=100)this->discount=discount;return *this;}
 double total() const{double t=0;for(int i=0;i<n;++i)t+=prices[i];return t*(100-discount)/100;}
};
int main(){
 Cart c;c.add("Rice",60).add("Dal",120).setDiscount(10);Cart* p=&c;p->add("Oil",180);
 cout<<fixed<<setprecision(2)<<p->total()<<'\n';
 Cart direct;direct.add("Book",50);Cart* ptr=&direct;ptr->add("Pen",10);
 Cart& ref=direct;ref.add("Pencil",5);
 Cart* dynamicCart=new Cart;dynamicCart->add("Bag",500);
 cout<<"Direct/reference total: "<<direct.total()<<'\n';
 cout<<"Dynamic total: "<<dynamicCart->total()<<'\n';delete dynamicCart;
}
