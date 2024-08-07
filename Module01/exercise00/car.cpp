#include <iostream>

class Car{
    private:
        std::string name;
        double speed;
    public:
        Car();
        Car(const Car& car);
        Car& operator=(const Car& car);
        ~Car();
};

Car::Car(){
    std::cout<<"Constructor\n";
}

Car::Car(const Car& car){
    std::cout<<"Copy constructor\n";
}

Car& Car::operator=(const Car& car){
    std::cout<<"Copy assignment constructor\n";
    return *this;
}

Car::~Car(){
    std::cout<<"Destructor\n";
}

int main(){
    // Constructor
    Car wolve1;
    // Copy constructor
    Car wolve2(wolve1);
    // Copy assignment constructor
    Car wolve3;
    wolve3=wolve1;

}