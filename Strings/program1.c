//get a string of nos of upto 50 digits and remove all the leading 0s

#include <stdio.h>
void strmodify(char *src);

int main()
{
    char src[50];
    printf("Enter String ");
    scanf("%s",src);
    strmodify(src);
    
    return 0;
}

void strmodify(char *src){
    while (*src != '\0') {
        if((*src - '0') != 0){
            printf("Modified String: %s",src); 
            break;
        }
        src++;
    }
}
