#include <stdio.h>
void strcopy(char *src,char *dest);

int main()
{
    char src[50],dest[50];
    printf("Enter String ");
    scanf("%s",src);
    strcopy(src,dest);
    
    return 0;
}

void strcopy(char *src,char *dest){
    
    char *t = dest; //because by the end 'dest' will itself be pointing to null
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest ='\0';
    
    printf("Copied String: %s",t); 
}
