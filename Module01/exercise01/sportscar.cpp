#include <iostream>

using namespace std;

class Car{
    private:
        string make;
        string model;
        int year;
    public:
        Car();
        Car(string make, string model, int year);
        ~Car();
        Car(const Car& car);
        Car& operator=(const Car& car);
        virtual void drive();

};
Car::Car():make{""},model{""},year{0}{}
Car& Car::operator=(const Car& car){
    return *this;
}
Car::Car(string make, string model, int year)
      :make(make),model(model),year(year){}
Car::Car(const Car& car)
    :make(car.make),model(car.model),year(car.year){}
Car::~Car(){}
void Car::drive(){
    cout<<"make: "<<this->make<<" model: "<<this->model<<" year: "<<this->year<<"\n";
}

class Sportscar:public Car{
    private:
        int TopSpeed;
    public:
        Sportscar(string make, string model, int year,int TopSpeed);
        void drive() override;

};
Sportscar::Sportscar(string make, string model, int year, int TopSpeed):Car(make,model,year),TopSpeed{TopSpeed}{}
void Sportscar::drive(){
    Car::drive();
    cout<<"Top Speed: "<<TopSpeed<<"\n";
}
int main(){
    string make,model;
    int year,TopSpeed;
    cin>>make>>model>>year>>TopSpeed;
    Sportscar car1(make,model,year,TopSpeed);
    car1.drive();

}
