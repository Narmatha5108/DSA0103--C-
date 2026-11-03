#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Vehicle {
protected: string registration; double dailyRate; bool rented=false;
public:
 Vehicle(string r,double d):registration(r),dailyRate(d){}
 virtual double rentalCharge(int days) const=0;
 virtual string type() const=0;
 virtual void showDetails() const{
  cout<<type()<<" | "<<registration<<" | Daily rate: "<<dailyRate
      <<" | Status: "<<(rented?"Rented":"Available")<<'\n';
 }
 void rent(){if(!rented){rented=true;cout<<registration<<" rented successfully.\n";}
  else cout<<registration<<" is already rented.\n";}
 void returnVehicle(int lateDays){
  if(rented){double fee=lateDays>0?lateDays*dailyRate*0.5:0;
   cout<<registration<<" returned. Late charge: "<<fee<<'\n';rented=false;}
  else cout<<registration<<" was not rented.\n";
 }
 virtual ~Vehicle()=default;
};
class Bicycle:public Vehicle {
public: Bicycle(string r,double d):Vehicle(r,d){}
 double rentalCharge(int days) const override{return dailyRate*days;}
 string type() const override{return "Bicycle";}
};
class MotorVehicle:public Vehicle {
protected: double fuelOrChargeLevel; string serviceDueDate;
public:
 MotorVehicle(string r,double d,double level,string date)
 :Vehicle(r,d),fuelOrChargeLevel(level),serviceDueDate(date){}
};
class TwoWheeler:public MotorVehicle {
public: TwoWheeler(string r,double d,double f,string date):MotorVehicle(r,d,f,date){}
 double rentalCharge(int days) const override{return dailyRate*days+20*days;}
 string type() const override{return "Two-wheeler";}
};
class Car:public MotorVehicle {
protected: int seats;
public:
 Car(string r,double d,double f,string date,int s):MotorVehicle(r,d,f,date),seats(s){}
 double rentalCharge(int days) const override{return dailyRate*days+50*days+seats*10;}
 string type() const override{return "Car";}
};
class ElectricCar:public Car {
 double batteryCapacity, pricePerKWh;
public:
 ElectricCar(string r,double d,double level,string date,int s,double cap,double price)
 :Car(r,d,level,date,s),batteryCapacity(cap),pricePerKWh(price){}
 double rentalCharge(int days) const override{return dailyRate*days+batteryCapacity*pricePerKWh;}
 string type() const override{return "Electric car";}
};
class ElectricBus:public MotorVehicle {
 int passengers; double batteryCapacity, pricePerKWh;
public:
 ElectricBus(string r,double d,double level,string date,int p,double cap,double price)
 :MotorVehicle(r,d,level,date),passengers(p),batteryCapacity(cap),pricePerKWh(price){}
 double rentalCharge(int days) const override{return dailyRate*days+batteryCapacity*pricePerKWh+passengers*2;}
 string type() const override{return "Electric bus";}
};
int main(){
 cout<<fixed<<setprecision(2);
 Bicycle bike("BIKE101",100);
 TwoWheeler two("TW202",250,80,"2026-12-10");
 Car car("CAR303",1200,70,"2026-12-15",5);
 ElectricCar ev("EV404",1500,90,"2026-12-20",5,60,8);
 ElectricBus bus("BUS505",3000,85,"2026-12-25",40,150,9);
 Vehicle* fleet[]={&bike,&two,&car,&ev,&bus};
 int count=sizeof(fleet)/sizeof(fleet[0]);
 cout<<"VEHICLE FLEET\n";
 for(int i=0;i<count;++i){
  fleet[i]->showDetails();
  cout<<"Rental charge for 2 days: "<<fleet[i]->rentalCharge(2)<<'\n';
 }
 cout<<"\nRENT AND RETURN DEMONSTRATION\n";
 car.rent();car.returnVehicle(2);bus.rent();bus.returnVehicle(0);
}
