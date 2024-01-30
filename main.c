#include <stdio.h>
#include <string.h>

#define instring_limit 10

char string_input[instring_limit];

char* user_input()
{
    printf("We are waiting for your command Sire");
    if (scanf("%s",string_input) != 1)
        {
            user_input();
        }
    return &string_input[0];     
}

int main()
{
    char* pointer = user_input();
    printf("We will execute your command of \n");
    printf("%s, Sire",&(*pointer));
}
