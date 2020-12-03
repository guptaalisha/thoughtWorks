#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Car{
    private:
        string type;
        int base_fare;
        int base_km;
        int rate_for_next_15_km;
        int additional_dist_charge;
        int total_limit;
        int additional_charge_for_exceeding_limit;
    public:
        Car(){};
        Car(string type, int base_fare, int base_km, int rate_for_next_15_km, int additional_dist_charge, int total_limit=-1, int additional_charge_for_exceeding_limit=-1)
            {
                this->type = type;
                this->base_fare = base_fare;
                this->base_km = base_km;
                this->rate_for_next_15_km = rate_for_next_15_km;
                this->additional_dist_charge = additional_dist_charge;
                this->total_limit = total_limit;
                this->additional_charge_for_exceeding_limit = additional_charge_for_exceeding_limit;
            }
        string getType(){
            return this->type;
        }
        int getBaseFare(){
            return this->base_fare;
        }
        int getBaseKm(){
            return this->base_km;
        }
        int getRateFor15Km(){
            return this->rate_for_next_15_km;
        }
        int getAdditionalDistanceCharge(){
            return this->additional_dist_charge;
        }
        int getTotalLimit(){
            return this->total_limit;
        }
        int getAdditionalChargeForExtraLimit(){
            return this->additional_charge_for_exceeding_limit;
        }
        void getType(string type){
             this->type = type;
        }
        void getBaseFare(int base_fare){
             this->base_fare = base_fare;
        }
        void getBaseKm(int base_km){
             this->base_km = base_km;
        }
        void getRateFor15Km(int rate_for_next_15_km){
             this->rate_for_next_15_km = rate_for_next_15_km;
        }
        void getAdditionalDistanceCharge(int additional_dist_charge){
             this->additional_dist_charge = additional_dist_charge;
        }
        void getTotalLimit(int total_limit){
             this->total_limit = total_limit;
        }
        void getAdditionalChargeForExtraLimit(int additional_charge_for_exceeding_limit){
             this->additional_charge_for_exceeding_limit = additional_charge_for_exceeding_limit;
        }
        
        //function to calculate the estimated fare for all types of cars
        
        double calculateEstimatedFare(int km)
            {
                if(this->total_limit != -1 && this->additional_charge_for_exceeding_limit != -1 && km>this->total_limit){
                double total;
                total = km*this->additional_charge_for_exceeding_limit;
                return total;
                }
                double total = this->base_fare;
                int extra_km = km-this->base_km;
                if(extra_km>0){
                    if(extra_km<=15){
                        total+= (km-this->base_km)*this->rate_for_next_15_km;
                    }
                    else{
                        total+=15*rate_for_next_15_km;
                        total+=(extra_km-15)*this->additional_dist_charge;
            
                    }
                }
                return total;
    
            }
        
    
};

class Manage{
    private:
        vector<Car> cars;
    public:
        Manage(){};
        void createCars(){
            Car car1("Mini",50,3,10,8,75,8);
            Car car2("Sedan",80,5,12,10,100,10);
            Car car3("SUV",100,5,15,12);
            cars.push_back(car1);
            cars.push_back(car2);
            cars.push_back(car3);
        }
        void displayFare(Car obj, double calculatedFare){
            cout<<"THE ESTIMATED FARES ARE"<<endl;
            cout<<"CAR TYPE:"<<obj.getType()<<endl;
            cout<<"ESTIMATED FARE: RS"<<calculatedFare<<endl;
        }
        void calculateEstimatedFareForAllCars(int km){
            for(int i=0;i<cars.size();i++)
            {
                displayFare(cars.at(i),cars.at(i).calculateEstimatedFare(km));
            }
        }
};




int main() {
	// your code goes here
	Manage manage;
	manage.createCars();
	int km;
	cout<<"ENTER THE APPROXIMATE KILOMETERS THAT YOU WANT TO TRAVEL"<<endl;
	cin>>km;
	manage.calculateEstimatedFareForAllCars(km);
	return 0;
}
