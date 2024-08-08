#include <iostream>

using namespace std;

class Part{
    public:
        virtual void PrintINfo()=0;
};

class Engine:public Part{
    private:
        int piston;
    public:
        Engine(int piston=4){}
        ~Engine(){}
        int getPiston(){
            return piston;
        }
        void PrintINfo() override{
            std::cout<<"Piston Number: "<<getPiston()<<"\n";
        }
};

class Wheel:public Part{
    private:
        int wheelcount;
    public:
        Wheel(int wheelcount=4):wheelcount(wheelcount){}
        ~Wheel(){}
        int getCount(){
            return wheelcount;
        }
        void PrintINfo() override{
            std::cout<<"wheelNumber: "<<getCount()<<std::endl;
        }
};

template <typename T>
class Hardware:public Part{
    private:
        std::string color;
        T price;
    public:
        Hardware(std::string color="yellow",T price=0):color(color),price(price){}
        ~Hardware(){}
        T getPrice(){
            return price;
        }
        void setPrice(T price_){
            price=price_;
        }
        std::string getColor(){
            return color;
        }
        void PrintINfo() override{
            std::cout<<"price: "<<getPrice()<<" color: "<<color<<"\n";
        }
};
template <typename T1>
class Car{
    private:
        std::string name;
        std::string version;
        Engine* engine;
        Wheel* wheel;
        Hardware<T1>* hardware;
    public:
        std::string getName(){
            return name;
        }
        std::string getVersion(){
            return version;
        }

        Car(std::string name="URUS", std::string version=""):name("URUS"),version(version){
            if(version=="Normal"){
                engine=new Engine();
                wheel=new Wheel();
                hardware=new Hardware<T1>("yellow",2.999);

                engine->PrintINfo();
                wheel->PrintINfo();
                hardware->PrintINfo();
                cout<<"NAME: "<<getName()<<" VERSION: "<<getVersion()<<endl;
            }else if(version=="S"){
                engine=new Engine();
                wheel=new Wheel();
                hardware=new Hardware<T1>("yellow",4);

                engine->PrintINfo();
                wheel->PrintINfo();
                hardware->PrintINfo();
                cout<<"NAME: "<<getName()<<" VERSION: "<<getVersion()<<endl;
            }
            cout<<"constructor\n";
        }
        ~Car(){
            delete engine;
            delete wheel;
            delete hardware;
            cout<<"destructor\n";
        }

};

int main(){
    std::string a,b;
    cout<<"enter the URUS version that you want to get more details.\n 1. Noraml, 2. S\n";
    std::cin>>a;
    Car<double> car1("URUS",a);
    std::cin>>b;

    Car<int> car2("URUS",b);

}