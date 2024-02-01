#include <stdio.h>
#include <string.h>
#include <time.h>


#define instring_limit 10
#define totalCommands 6
char string_input[instring_limit];
char commandbase[9][10] = {"login","start","stop","buy","status","logout","","",""};
void login()
{
    char username[10];
    scanf("Are you a new user? %s",username);
}


int validityCheck(char* ptr_command)//returns 1 if it is invalid 
{
    for (int i = 0; i<totalCommands; i++)
    {
        if (!strcmp(ptr_command,commandbase[i]))//strcmp returns 0 if the two strings are equal
        {
            return i+1;//can't return 0 if we accept login
        }
    }
    return 0;
}
//switch 

int user_input()
{
    int command=0;
    printf("We are waiting for your command Sire\n");
    if (scanf("%s",string_input) != 1 || !(command = validityCheck(string_input))) //if scanf shows error or input invalid(validitycheck = 0)
        {
            printf("Command out of my understanding\n");
            user_input();
        }
    printf("We will execute your command of \n");
    printf("%s, Sire",string_input);
    return command;  //return the value    
}

int main()
{
    switch (user_input())
    {
        case 1:
            login();
        // case 2:

        // case 3:

        // case 4:

        // case 5:

        // case 6: 

        default:
            printf("thanks for logging in");
            return 0;
    }

}

