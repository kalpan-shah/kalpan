#include"myheader.h"
#include<iostream>
#include<cmath>


//for printing hello world
void hello()
{
    println('/');
    std::cout<<"\nHello, world!\n";
    println('#');
}
// to print a line of length 34
void println(char ch)
{
    int i = 0;
    do{
        std::cout<<((i==34||i==0)?'\n':ch);
        i++;
    }while(i<35);
}
//calculate distance of two coordinates
int dxy(int x1,int x2,int y1,int y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) +  std::pow(y2 - y1, 2) * 1.0);
}

//This space include various shapes variable
namespace sh
{
    //calculate and return volume of cube
    double Cube::getVolume() {
      return length_ * length_ * length_;
    }
    //calculate and return surface area of cube
    double Cube::getSurfaceArea() {
      return 6 * length_ * length_;
    }
    //getting the value of variable
    void Cube::setLength(double l) {
      length_ = l;
    }
    //destructor
    Cube::~Cube()
    {
        //for stack memory alloted will be called automatically when the function ends
        //while for heap memory when we use delete keyword
        std::cout<<"destructor called\n";
    }
    //default cube constructor
    Cube::Cube()
    {
        length_ = 1;
        std::cout<<"default constructor is invoked\n";
    }
    //custom constructor
    Cube::Cube(double l)
    {
        length_ = l;
        std::cout<<"constructor invoked with a pre specified value: "<<l<<"\n";
    }
    //copy constructor
    Cube::Cube(const Cube&cp)
    {
        length_ = cp.length_;
        std::cout<<"Copy constructor invoked\n";
    }
    //assignment operator
    Cube & Cube::operator=(const Cube  & cp)
    {
        length_ = cp.length_;
        std::cout<<"assignment operator invoked\n";
        return *this;
    }
}
//
