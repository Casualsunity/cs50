//segmentation fault if user typed more than 16 charakters

#include <stdio.h>

int main(void)
{
    char s[16];
    printf("String please: ");
    scanf("%s",s);
    printf("Thanks for the %s!\n",s);
}