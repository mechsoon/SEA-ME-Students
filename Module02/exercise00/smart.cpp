#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
        // virtual void info()=0; pure virtual 

        // getter
        std::string getFamousModel();
        int getPrice();
        std::string getCeo();

};

// Constructor
Car::Car():FamousModel(""),price(0),Ceo(""){
    cout<<"constructor\n";
}
// parameterized constructor
Car::Car(std::string FamousModel,int price, std::string Ceo)
    :FamousModel(FamousModel),price(price),Ceo(Ceo)
    {
        cout<<"constructor\n";
    }
// copy constructor
Car::Car(const Car& car)
    :FamousModel(car.FamousModel),price(car.price),Ceo(car.Ceo){}
//Copy assignment constructor 
Car& Car::operator=(const Car& car)
{
    if(this!=&car){
        FamousModel=car.FamousModel;
        price=car.price;
        Ceo=car.Ceo;
    }
    return *this;
}
// Destructor
Car::~Car(){
    cout<<"destructor\n";
}

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
Volkswagen::Volkswagen():Car(){cout<<"derived constructor\n";}
Volkswagen::Volkswagen(const Volkswagen& volkswagen):Car(volkswagen){}
Volkswagen& Volkswagen::operator=(const Volkswagen& volkswagen)
{
    if(this!=&volkswagen)
    {
        Car::operator=(volkswagen);
    }
    return *this;
    }

Volkswagen::Volkswagen(std::string FamousModel,int price, std::string Ceo):Car(FamousModel,price,Ceo){cout<<"derive constructor\n";}
void Volkswagen::info(){
    cout<<"VolkswagenFamousModel: "<<getFamousModel()<<" price: "<<getPrice()<<" Ceo: "<<getCeo()<<"\n";
}
Volkswagen::~Volkswagen(){cout<<"derived destructor\n";}

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


void checkPolymorphism(std::unique_ptr<Car>& car){
    car->info();
}

int main(){
    // polymorphism
    vector<std::unique_ptr<Car>> car;

    // uniquesmart pointer practice
    std::unique_ptr<Car> car1=std::make_unique<Volkswagen>("Beetle",200000,"Till Scheer");
    std::unique_ptr<Car> car2=std::make_unique<Audi>("A7",500000,"Steve Cloete");
    car.emplace_back(std::move(car1));
    car.emplace_back(std::move(car2));
    for(std::unique_ptr<Car> & brand:car){
        checkPolymorphism(brand);
    }        

    // shared smartpointer

    std::shared_ptr<Volkswagen> car3=std::make_shared<Volkswagen>("BEEE",2000030,"Till scheer");
    cout<<car3.use_count()<<"\n";
    {
        std::shared_ptr<Volkswagen> car4{car3};
        cout<<car3.use_count()<<"\n";

    }
    cout<<car3.use_count()<<"\n";


    //To check memory lear, we can use valgrind --leak-check ./{programName} 

    // car.emplace_back(new Volkswagen("Beetle",200000,"Till Scheer"));
    // car.emplace_back(new Audi("A7",500000,"Steve Cloete"));
    // for(auto brand:car){
    //     checkPolymorphism(brand);
    //     delete brand;                       if not use Smartpointer, must use delete.
    // }
    
}