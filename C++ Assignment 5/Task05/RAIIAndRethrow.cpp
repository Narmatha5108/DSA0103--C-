#include <iostream>
#include <string>
#include <stdexcept>
struct Guard{std::string n;Guard(std::string s):n(s){}~Guard(){std::cout<<'~'<<n<<' ';}};
void service(){Guard g("service");throw std::runtime_error("failure");}
void audit(){try{Guard g("audit");service();}catch(const std::exception&e){std::cout<<"logged "<<e.what()<<' ';throw;}}
int main(){try{Guard g("main");audit();}catch(const std::exception&e){std::cout<<"user message "<<e.what();}std::cout<<'\\n';}
