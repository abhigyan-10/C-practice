#include <stdio.h>
int strcomp(char *src, char *dest);

int main()
{
    char src[50],dest[50];
    printf("Enter String 1");
    scanf("%s",src);
    printf("Enter String 2");
    scanf("%s",dest);
    int k = strcomp(src,dest);
    if(k==1)
        printf("\n Success!!!");
    else
        printf("\nFailure!!");
    return 0;
}

int strcomp(char *src, char *dest) {
    while (*src == *dest && *src != '\0') {
        src++;
        dest++;
    }
    
    return (*src == *dest); // If both are same,it return 1
}
