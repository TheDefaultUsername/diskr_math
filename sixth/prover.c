#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc<2) {
        printf("No file to prove\n");
        return 1;
    }
    FILE* file;
    file = fopen(argv[1],"r");
    if (!file) {
        printf("Incorrect filename to prove\n");
        return 1;
    }
    if (argc<3) {
        printf("No mod to prove\n");
        return 1;
    }
    int mod;
    if (!sscanf(argv[2],"%d",&mod)) {
        printf("Not number mod\n");
        return 1;
    }
    printf("current mod is %d. if it is correct type RUN\n",mod);
    {
        char yes[4];
        scanf("%3s",&yes);
        if (
            (yes[0]!='R') ||
            (yes[1]!='U') ||
            (yes[2]!='N')
            ) {return 0;}
    }
    unsigned int a,b,c;
    if (fscanf(file,"%u%u",&a,&b)==EOF) {
        printf("too short file");
        return 0;
    }
    while (fscanf(file,"%u",&c)!=EOF) {
        if ((a+b)%mod!=c) {
            printf("mistake. \n%u + %u != %u\n in mod %d it == %u\n",a,b,c,mod,(a+b)%mod);
            return 0;
        }
        a=b;
        b=c;
    }
    printf("no errors\n");
    return 0;
}
