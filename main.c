#include <stdio.h>
#include <string.h>
#include <time.h>

#define instring_limit 10
#define totalCommands 6
int numberofuser = 0;
char string_input[instring_limit];
char commandbase[9][10] = {"login","start","stop","buy","status","logout","","",""};
int login();
void start();
void stop();
void buy();
void status();
void logout();

float multiplier=0.2;

time_t timer_b;//timer_before
time_t timer_a;//timer_after

void start()
{
    timer_b = time(NULL);
    printf("Your begining code is: %ld\n",timer_b);
}

void stop()
{
    timer_a = time(NULL);
    float diff = difftime(timer_a,timer_b);
    printf("You mined %0.1f points in that time.\n",multiplier*diff);
    FILE* timelog;
    timelog = fopen("userlog.txt","a");
    fseek(timelog,0,SEEK_END);
    fprintf(timelog,"\n%0.2f",(multiplier*diff));
    fclose(timelog);
} 

void status()
{
    char buf[15];
    FILE* reading;
        reading = fopen("userlog.txt","r"); 
        fseek(reading,0,SEEK_SET);
        fgets(buf,15,reading);
        printf("user: %s \n",buf);
        fseek(reading,0,SEEK_CUR);
        fgets(buf,15,reading);
        printf("score: %s\n",buf);
        fclose(reading);
}

int login()
{
    FILE* userlog;
    char username[10];
    printf("Are you a new user? \n \t Yes?");
    scanf("%s",username);
    if (!strcmp(username,"yes"))//max number of players in one device 4
    {
        printf("What is your name?");
        scanf("%s",username);
        printf("Oh Master %s, we finally have come across you\n Welcome to the game\n\n");
        ////////////////////////////////////////////////////////////////////////////////////////
        userlog = fopen("userlog.txt","w");//pointer is at last character of the file
        
        if (userlog == NULL)//if can't open returns NULL
        {
            printf("File couldn't be opened, Try again");
            return 0;
        }
        fprintf(userlog,"%s",username);
        fclose(userlog);
    }
    else
    {
        char buf[20];
        FILE* reading;
        reading = fopen("userlog.txt","r"); 
        fseek(reading,0,SEEK_SET);
        fgets(buf,15,reading);
        printf("You are already logged in you must be %s sama, we are grateful that you have returned.\n", buf);
        fclose(reading);
    }
    return 0;
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
    printf("We are waiting for your command Sire, \n  login logout start stop status \n");
    if (scanf("%s",string_input) != 1 || !(command = validityCheck(string_input))) //if scanf shows error or input invalid(validitycheck = 0)
        {
            printf("Command out of my understanding\n");
            user_input();
        }
    else
    {
        printf("We will execute your command of \n \t");
        printf("%s, Sire\n",string_input);
    }
    return command;  //return the value    
}

int main()
{
    while(1){
        switch (user_input())
        {
            case 1:
                login();
                break;
            case 2:
                start();
                break;
            case 3:
                stop();
                break;
            case 4:
               // buy();
                break;
            case 5:
                status();
                break;
            case 6: 
                printf("thanks for logging in. Comeback before we get erased from your pc");
                return 0;
    }
    }
}

