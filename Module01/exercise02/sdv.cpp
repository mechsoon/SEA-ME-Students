#include <iostream>
#include <string>
#include <vector>
using namespace std;

// abstract

class Car{
    private:
        std::string FamousModel;
        int price;
        std::string Ceo;

    public:
        Car();
        Car(std::string FamousModel,int price, std::string Ceo);
        Car(const Car& car);
        Car& operator=(const Car& car);
        ~Car();
        
        virtual void info();
        std::string getFamousModel();
        int getPrice();
        std::string getCeo();

};

// Constructor
Car::Car():FamousModel(""),price(0),Ceo(""){}
// argument constructor
Car::Car(std::string FamousModel,int price, std::string Ceo)
    :FamousModel(FamousModel),price(price),Ceo(Ceo){}
// copy constructor
Car::Car(const Car& car)
    :FamousModel(car.FamousModel),price(car.price),Ceo(car.Ceo){}
//Copy assignment constructor 
Car& Car::operator=(const Car& car)
{
    return *this;
}
// Destructor
Car::~Car(){}

void Car::info(){cout<<"Mom car\n";}

// encapsulation
std::string Car::getFamousModel(){
    return FamousModel;
}

int Car::getPrice(){
    return price;
}

string Car::getCeo(){
    return Ceo;
}

class Volkswagen:public Car{
    public:
        Volkswagen();
        Volkswagen(const Volkswagen& volkswagen);
        Volkswagen& operator=(const Volkswagen& volkswagen);
        Volkswagen(std::string FamousModel,int price, std::string Ceo);
        void info() override;
        ~Volkswagen();
};

// inheritance
Volkswagen::Volkswagen():Car(){}
Volkswagen::Volkswagen(const Volkswagen& volkswagen):Car(volkswagen){}
Volkswagen& Volkswagen::operator=(const Volkswagen& volkswagen)
{
    if(this!=&volkswagen)
    {
        Car::operator=(volkswagen);
    }
    return *this;
    }

Volkswagen::Volkswagen(std::string FamousModel,int price, std::string Ceo):Car(FamousModel,price,Ceo){}
void Volkswagen::info(){
    cout<<"VolkswagenFamousModel: "<<getFamousModel()<<" price: "<<getPrice()<<" Ceo: "<<getCeo()<<"\n";
}
Volkswagen::~Volkswagen(){}

// inheritance

class Audi:public Car{
    public:
        
        Audi(std::string FamousModel,int price, std::string Ceo);
        void info() override;
};

Audi::Audi(std::string FamousModel,int price, std::string Ceo):Car(FamousModel,price,Ceo){}
void Audi::info(){
    cout<<"AudiFamousModel: "<<getFamousModel()<<" price: "<<getPrice()<<" Ceo: "<<getCeo()<<"\n";
}


void checkPolymorphism(Car* car){
    car->info();
}

int main(){
    // polymorphism
    vector<Car*> car;
    car.emplace_back(new Volkswagen("Beetle",200000,"Till Scheer"));
    car.emplace_back(new Audi("A7",500000,"Steve Cloete"));

    for(auto brand:car){
        checkPolymorphism(brand);
        delete brand;
    }
    
}