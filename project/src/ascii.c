#include <stdarg.h>

extern void print_ascii(unsigned short *output);  // アセンブリ関数


void ascii(char *input, unsigned short *output) {
    int i = 0;
    while (input[i] != '\0') {
        output[i] = (unsigned short)(unsigned char)input[i];
        i++;
    }
    output[i] = 0; 
}

void my_printf(char *input) {
    unsigned short output[256];
    ascii(input, output); 
    print_ascii(output);   
}
