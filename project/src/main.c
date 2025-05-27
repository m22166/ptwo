#include "ascii.h"

char input[] = "Hello World\n";
unsigned short output[256];
extern int my_add(int a, int b);

int main() {
    int x = 2;  // ここで変数xを2に初期化（1より大きい）
    if (x > 1) {
        x = x + 1;  // xが1より大きい場合、1を足す
    }
    my_add(1,5);
    return 0;
}