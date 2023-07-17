#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");


    uint32_t num1, num2;
    size_t bytesRead1 = fread(&num1, sizeof(uint32_t), 1, file1);
    size_t bytesRead2 = fread(&num2, sizeof(uint32_t), 1, file2);
    
    fclose(file1);
    fclose(file2);

    uint32_t hostNum1 = ntohl(num1);
    uint32_t hostNum2 = ntohl(num2);
    uint32_t sum = hostNum1 + hostNum2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", hostNum1, hostNum1, hostNum2, hostNum2, sum, sum);

    return 0;
}

