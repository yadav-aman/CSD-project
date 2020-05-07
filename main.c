#include <stdio.h>
#include <string.h>
#include <conio.h.>
#include <windows.h>
#include "header.h"

long unsigned inputtedVoterID;
char inputtedName[30];
void main_panel();
void ex();
void admin();
void voting_screen();
void wrong_data();
void duplicate();
void lead();
void vote_bank();

int main()
{
    importVoters();
    importCandidates();
    Sleep(500);
    system("cls");

    printf("\n\n");
    printf("                                       Satyamev Jayate- Bharat Nirvachan Aayog\n\n");
    Sleep(500);
    printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
    Sleep(500);
    printf("                      **************** WELCOME TO ELECTION COMMISSION OF INDIA ***************                 \n");
    Sleep(500);
    printf("                                               Bihar Division, Patna                                           \n\n\n");
    Sleep(500);
    printf("                  BIHAR VIDHAN SABHA NIRVACHAN 2020           BIHAR LEGISLATIVE ASSEMBLY ELECTIONS 2020         \n\n");
    Sleep(500);
    printf("                                  ECI presenting the first online voting system of India.                        \n");
    printf("                                         Apologies for slow processing, if any.\n\n\n\n");
    Sleep(500);
    printf("                                          Press / to enter the main panel !!!                                \n\n\n");
    Sleep(500);
    printf("________________________________________________________________________________________________________________________\n\n\n");
    Sleep(500);
    printf("                                       � Copyright Election Commission of India                                    \n\n");
    printf("\n\n                                                      ");
    Sleep(1000);

    char ch;
    scanf("%c", &ch);

    if (ch != 47)
    {
        printf("\n           INPUT ERROR");
        Sleep(1000);
        printf("\n\n        System Failure");
        Sleep(500);

        ex();
        return 0;
    }

    else
    {
        Sleep(500);
        printf("\n\n                                                  LOADING.....                                                  \n");
        Sleep(500);
        printf("\n                                                  LOADING.....                                                  \n");
        Sleep(500);
        printf("\n                                                  LOADING.....                                                  \n");

        Sleep(1000); //Delay of 1 sec= Sleep(1000).

        main_panel();
    }

    return 0;
}

void ex()
{
    system("cls");

    printf("\n\n                                     Closing OVS in...");
    Sleep(1000);
    printf("\n\n                                           3");
    Sleep(1000);
    printf("\n\n                                           2");
    Sleep(1000);
    printf("\n\n                                           1\n\n\n\n\n\n\n\n");
    Sleep(500);
}
void main_panel()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("                    \t\t\t       *** MAIN PANEL ***\n\n");
    Sleep(500);
    printf("                    \t\t\t(1) VOTE YOUR CANDIDATE ........\n\n");
    Sleep(500);
    printf("                    \t\t\t(2) ENTER ADMIN PANEL ........\n\n");
    Sleep(500);
    printf("                    \t\t\t(3) CANDIDATE IN LEAD ........\n\n");
    Sleep(500);
    printf("                    \t\t\t(4) EXIT THE OVS........\n\n\n"); //OVS: Online Voting System

    int choice;
    printf("                                                      ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        voting_screen();
    }

    if (choice == 2)
    {
    }

    if (choice == 3)
    {
    }

    if (choice == 4)
    {
        ex(); //Exit
    }
}

void voting_screen()
{
    printf("\n\n\n\n\n");
    Sleep(500);
    printf("                         NOTE: Please make sure that you're registered in the electoral roll\n\n\n");
    Sleep(1000);
    printf("                          Your ID will be blocked after 3 unsuccessful attempts !!!\n\n");
    Sleep(1000);
    printf("                                       You're entering the data feeding panel\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                             This process may take several seconds. Kindly, be patient\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                 Did you know?\n\n");
    Sleep(500);
    printf("                               BIHAR: THE FIRST STATE TO WITNESS BOOTH CAPTURING\n");
    Sleep(1000);
    printf("       The first instance of booth capturing in India was recorded in 1957 in the General Elections of that\n");
    printf("                                 year in Rachiyahi of Begusarai constituency.\n");
    Sleep(1500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                                       .\n");
    Sleep(500);
    printf("                                            Thanks for your patience.\n\n\n\n\n");
    Sleep(500);

    system("cls");

    int timeLeft = 3;
    while (1)
    {

        printf("\n\n\n\n");
        printf("                        You have %d tries left.\n", timeLeft);
        printf("\n\n\n                      ENTER VOTER ID (as per your EPIC):   ");
        scanf("%lu", &inputtedVoterID);
        getchar();
        printf("\n\n\n\n\n\n");
        voter *tempVoter = search(root, inputtedVoterID);
        if (tempVoter)
        {
            int nameTryLeft = 3;

            printf("\n\n\n       Voter ID exists. Please enter correct name for further verification.\n\n\n");
            while (1)
            {
                printf("\n\n\n\n");
                printf("                        You have %d tries left.\n", nameTryLeft);
                printf("\n\n\n                      Enter your name as per VOTER ID:   ");
                gets(inputtedName);
                printf("\n\n\n\n\n\n");
                int res = strcmpi(tempVoter->name, inputtedName);
                if (res == 0)
                {
                    printf("\n\n\n\n\n       You are a registered voter. Congrats.\n");
                    printf("\n\n                     Here are your details.\n\n\n\n\n");
                    printf("\n\n\n\n      Your Voter ID: %lu\n", tempVoter->voterID);
                    printf("              Your Name: %s\n", tempVoter->name);
                    printf("              Your Gender: %s\n", tempVoter->sex);
                    printf("              Your date of birth: %d-%d-%d\n", tempVoter->date, tempVoter->month, tempVoter->year);
                    int toCheckIfVoted = tempVoter->voted;
                    if (toCheckIfVoted)
                    {
                        printf("\n\n\n\n\n\ You have already voted. Exiting to main panel.\n\n\n\n\n\n");
                        main_panel();
                    }
                    else
                    {
                        printf("\n\n\n\n\n\ You have not voted. To proceed to view candidate list, type YES.\n\n\n\n\n\n");
                    }
                }
                else
                {
                    if (nameTryLeft == 0)
                    {
                        printf("\n\n\n\n           You ran out of attempts. Switching to main panel.\n\n\n");
                        main_panel();
                    }
                    printf("\n\n\n            Voter Name entered was wrong. Enter correct data.\n");
                    nameTryLeft--;
                }
            }
        }
        else
        {
            if (timeLeft == 0)
            {
                printf("\n\n\n\n           You ran out of attempts. Switching to main panel.\n\n\n");
                main_panel();
            }
            printf("\n\n\n            Voter ID entered was wrong. Enter correct data.\n");
            timeLeft--;
        }
    }
}