#include <iostream>

class Point{
    private:
        int x,y;
    public:
        Point():x(0),y(0){}
        Point(int x,int y):x(x),y(y){}
        Point(const Point& point):x(point.x),y(point.y){}
        Point& operator=(const Point& point){
            if(this!=&point){
                x=point.x;
                y=point.y;
            }
            return *this;
        }
        ~Point(){}

};

class Smartp{
    Point* ptr;
    public:
        Smartp(Point* p):ptr(p){}
        ~Smartp(){
            delete ptr;
        }
        Point* operator->() const{
            return ptr;
        }
};

int main(){

    Smartp p1=new Point(2,3);
    Smartp p2=new Point(3,5);
}