#include <stdio.h>
#include <string.h>
#include <time.h>


#define instring_limit 10

char string_input[instring_limit];

int validityCheck(char* ptr_command)//returns 1 if it is invalid 
{
    if (!strcmp(ptr_command,"area"))//strcmp returns 0 if the two strings are equal
    {
        return 0;
    }
    return 1;
}
//switch 



static char* commandbase[3][3] = [["login","start","stop"],["buy","status","logout"],[]];

char* user_input()
{
    printf("We are waiting for your command Sire\n");
    if (scanf("%s",string_input) != 1 || validityCheck(string_input)) //if scanf shows error or input invalid 
        {
            printf("Command out of my understanding\n");
            user_input();
        }
    return string_input;     
}

int main()
{
    char* pointer = user_input();
    printf("We will execute your command of \n");
    printf("%s, Sire",&(*pointer));
}

