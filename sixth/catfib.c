#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc<2) {return 0;}
    FILE* file;
    file = fopen(argv[1],"r");
    if (!file) {return 0;}
    unsigned long long int k;
    while (fscanf(file,"%llu",&k)!=EOF) {
        printf("%llu\n",k);
    }
    return 0;
}
