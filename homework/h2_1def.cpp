#include <iostream>
#define A(x) x;x;x;x;x;x;x;x;x;x;
int main(void)
{
    int n=0;
    A(A(printf("%d\n",++n)));
    return 0;
}