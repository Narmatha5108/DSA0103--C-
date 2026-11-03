#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class Account {
public:
 double rate() const{return 3.5;}
 virtual double vrate() const{return 3.5;}
 virtual ~Account(){cout<<"Account destructor\n";}
};
class SeniorAccount:public Account {
 double* history;
public:
 SeniorAccount():history(new double[100]{}){}
 double rate() const{return 4.0;}
 double vrate() const override{return 4.0;}
 ~SeniorAccount() override{delete[] history;cout<<"SeniorAccount destructor\n";}
};
int main(){
 SeniorAccount s; Account* p=&s; Account copy=s;
 cout<<p->rate()<<' '<<p->vrate()<<' '<<copy.vrate()<<'\n';
 vector<unique_ptr<Account>> accounts;
 accounts.push_back(make_unique<Account>());
 accounts.push_back(make_unique<SeniorAccount>());
 cout<<"POLYMORPHIC STORAGE\n";
 for(const auto& a:accounts) cout<<a->vrate()<<'\n';
}
