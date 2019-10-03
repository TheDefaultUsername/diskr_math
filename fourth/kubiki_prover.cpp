#include <iostream>
#include <fstream>

int main() {
    int n;
    std::cin>>n;
    int m;
    std::FILE* file;
    file = std::fopen("this_file_is_always_temp_for.savthe_com_pp_kubiki","r");
    std::fscanf(file,"%d",&m);
    std::fclose(file);
    if (m>n) {
        std::cout<<"NO"<<std::endl;
    } else std::cout<<"YES"<<std::endl;
    std::remove("this_file_is_always_temp_for.savthe_com_pp_kubiki");
}
