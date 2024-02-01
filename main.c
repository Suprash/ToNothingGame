#include <stdio.h>
#include <string.h>
#include <time.h>


#define instring_limit 10
char string_input[instring_limit];
char commandbase[9][10] = {"login","start","stop","buy","status","logout","","",""};

int validityCheck(char* ptr_command)//returns 1 if it is invalid 
{
    if (!strcmp(ptr_command,commandbase[0]))//strcmp returns 0 if the two strings are equal
    {
        return 0;
    }
    return 1;
}
//switch 

char* user_input()
{
    printf("We are waiting for your command Sire\n");
    if (scanf("%s",string_input) != 1 || validityCheck(string_input)) //if scanf shows error or input invalid 
        {
            printf("Command out of my understanding\n");
            user_input();
        }
    return string_input;  //return the value    
}

int main()
{
    char* pointer = user_input();
    printf("We will execute your command of \n");
    printf("%s, Sire",&(*pointer));
}

