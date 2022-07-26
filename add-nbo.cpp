
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int num, char* file[]){
    if (num != 3) {
        printf("usage: %s <file1> <file2>\n", file[0]);
        return 0;
    }
    FILE *f1 = fopen(file[1],"r");
    FILE *f2 = fopen(file[2],"r");

    uint32_t n1, n2;
    fread(&n1, sizeof(uint32_t),1,f1);
    fread(&n2, sizeof(uint32_t),1,f2);

    uint32_t add1 = ntohl(n1);
    uint32_t add2 = ntohl(n2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", add1, add1, add2, add2, add1 + add2, add1 + add2);

    fclose(f1);
    fclose(f2);

    return 0;
}
