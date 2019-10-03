#include <iostream>
#include <vector>
int main() {
    int n,m,temp;
    std::cin>>n>>m;
    std::vector<int> a,b;
    a.clear();
    b.clear();
    for (int i=0; i<n; i++) {
        std::cin>>temp;
        a.push_back(temp);
    }
    for (int i=0; i<m; i++) {
        std::cin>>temp;
        b.push_back(temp);
    }
    temp=0;
    for (int i=0; i<n; i++) {
        temp+=a.at(i);
    }
    m = (m>n ? m : n) + 2;
    std::cout<<m<<std::endl<<"0 0 ";
    for (int i=0; i<a.size(); i++) {
        std::cout<<a.at(i)<<" ";
    }
    if (a.size()<m-2)
    for (int i=0; i<m-a.size()-2; i++) {
        std::cout<<"0 ";
    }
    std::cout<<std::endl;
    for (int i=0; i<m; i++) {
        std::cout<<"0 ";
    }
    std::cout<<std::endl;
    for (int i=0; i<b.size(); i++) {
        std::cout<<"0 "<<b.at(i)<<" ";
        for (int j=2; j<m; j++) {
            std::cout<<temp<<" ";
        }
        std::cout<<std::endl;
    }
    if (b.size()<m-2)
    for (int i=0; i<m-b.size()-2; i++) {
        std::cout<<"0 0 ";
        for (int j=2; j<m; j++) {
            std::cout<<temp<<" ";
        }
        std::cout<<std::endl;
    }
}