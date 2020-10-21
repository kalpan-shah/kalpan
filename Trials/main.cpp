#include<iostream>
#include"../DSA/List.h"

int main()
{
    const int a=4,b=5,c=43,d=45;
    List<int> hm;
    hm.prepend(a);
    hm.prepend(b);
    hm.prepend(c);
    hm.prepend(d);
    hm.rever();
    std::cout<<hm[0]<<"\n"<<hm[2]<<"\n";
    return 0;
}
