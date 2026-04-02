#include <stdio.h>
void strconcat(char *src1,char *src2,char *dest);

int main()
{
    char src1[50],src2[50],dest[100];
    printf("Enter String 1");
    scanf("%s",src1);
    printf("Enter String 2");
    scanf("%s",src2);
    strconcat(src1,src2,dest);
    
    return 0;
}

void strconcat(char *src1,char *src2,char *dest){
    
    char *t = dest; //because by the end 'dest' will itself be pointing to null
    while (*src1 != '\0') {
        *dest = *src1;
        src1++;
        dest++;
    }
    while (*src2 != '\0') {
        *dest = *src2;
        src2++;
        dest++;
    }
    *dest ='\0';
    
    printf("%s",t); 
}
