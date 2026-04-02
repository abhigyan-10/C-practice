#include <stdio.h>
void str_rev(char *src);

int main()
{
    char src[50];
    printf("Enter String ");
    scanf("%s",src);
    str_rev(src);
    
    return 0;
}

void str_rev(char *src){
    int p=0,q=0;
    char *s1 = src;
    while (*src != '\0') {
        q++;
        src++;
    }
    char t;
    q--; //since last value is null....so taking the index to the value prev to null
    while(p<q){
        t=*(s1 + p);
        *(s1 + p) = *(s1 + q);
        *(s1 + q) = t;
        
        p++;
        q--;
    }
    printf("\n %s",s1);
    
}
