#include <iostream>
int main() {
    int size1,size2,limit1(0),limit2(0),t;
    std::cin>>size1>>size2;
    for (int i = 0; i<size1+size2; i++) {
        std::cin>>t;
        if (i<size1) { limit1+=t; } else { limit2+=t; }
    }
    std::cout<<"3 0 0 "<<limit1<<" 0 0 0 0 "<<limit2<<" 0";
}
