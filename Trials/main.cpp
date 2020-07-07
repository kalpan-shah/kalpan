#include <iostream>
#include  "../DSA/List.h"
#include"myheader.h"

using namespace std;


int main()
{

    List<int> hm;
    cout << "Hello, world!\n";
    hm.prepend(6);
    cout<<hm[0];


    return 0;
}
