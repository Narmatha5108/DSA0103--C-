#include <iostream>
#include <stdexcept>
struct BillingError:std::runtime_error{using runtime_error::runtime_error;};struct ClaimError:BillingError{using BillingError::BillingError;};struct NegativeCharge:BillingError{using BillingError::BillingError;};
double approve(double a,double cover){if(a<0||cover<0)throw NegativeCharge("negative amount");if(a>cover)throw ClaimError("claim exceeds cover");return a;}
int main(){for(auto p:{std::pair<double,double>{100,200},{300,200},{-1,200}}){try{std::cout<<"approved "<<approve(p.first,p.second)<<'\\n';}catch(const BillingError&e){std::cout<<"rejected "<<e.what()<<'\\n';}}}
