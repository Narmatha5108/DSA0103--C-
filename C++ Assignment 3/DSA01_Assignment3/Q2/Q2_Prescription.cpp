#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Prescription{
 int n; string* medicines;
public:
 explicit Prescription(int count):n(count),medicines(count>0?new string[count]:nullptr){if(count<0)throw invalid_argument("Negative count");}
 Prescription(const Prescription&o):n(o.n),medicines(o.n>0?new string[o.n]:nullptr){for(int i=0;i<n;++i)medicines[i]=o.medicines[i];}
 Prescription& operator=(const Prescription&o){if(this!=&o){string*p=o.n>0?new string[o.n]:nullptr;for(int i=0;i<o.n;++i)p[i]=o.medicines[i];delete[] medicines;medicines=p;n=o.n;}return *this;}
 ~Prescription(){delete[] medicines;}
 void set(int i,const string&m){if(i<0||i>=n)throw out_of_range("Index");medicines[i]=m;}
 string get(int i)const{if(i<0||i>=n)throw out_of_range("Index");return medicines[i];}
 int size()const{return n;}
};
void byValue(Prescription p){cout<<"By value: "<<p.size()<<'\n';}
void byReference(const Prescription&p){cout<<"By const reference: "<<p.size()<<'\n';}
int main(){Prescription p(2);p.set(0,"Paracetamol");p.set(1,"ORS");Prescription q=p;q.set(1,"Cetirizine");Prescription r(1);r=p;p.set(0,"Ibuprofen");cout<<p.get(0)<<' '<<p.get(1)<<" | "<<q.get(0)<<' '<<q.get(1)<<" | "<<r.get(0)<<' '<<r.get(1)<<'\n';byValue(p);byReference(p);p=p;}
