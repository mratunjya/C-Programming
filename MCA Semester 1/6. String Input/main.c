#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char s[100];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    fgets(s, sizeof(s), stdin);
    printf("Hello, World!\n%s", s);
    return 0;
}