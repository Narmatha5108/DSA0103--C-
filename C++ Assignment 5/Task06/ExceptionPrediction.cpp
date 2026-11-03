#include <iostream>
#include <stdexcept>
void validate(double a){if(a<0)throw std::invalid_argument("negative");if(a>1e6)throw std::out_of_range("too large");std::cout<<"ok ";}
void process(double a){try{validate(a);}catch(const std::out_of_range&e){std::cout<<"[log "<<e.what()<<"] ";throw;}}
int main(){for(double a:{100.0,-5.0,2e6}){try{process(a);std::cout<<"done ";}catch(const std::exception&e){std::cout<<"caught "<<e.what()<<' ';}}std::cout<<'\\n';}
