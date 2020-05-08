#include <stdio.h>
#include <string.h>
#include <conio.h.>
#include <windows.h>
#include "header.h"
int candIdSelected;
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
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    importVoters();
    importCandidates();
    printf("\t\t\t\t\tPress any key to continue: ");
    getch();
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
    printf("                                          Press any key to continue !!!                                \n\n\n");
    Sleep(500);
    printf("________________________________________________________________________________________________________________________\n\n\n");
    Sleep(500);
    printf("                                       � Copyright Election Commission of India                                    \n\n");
    printf("\n\n                                                      ");
    Sleep(1000);

    getch();


    Sleep(200);
    int i;
    for(i=0;i<=100;i++)
    {
        printf("\r");
        printf("\t\t\t\t\t\t\tLoading : %d %%",i);
        Sleep(5);
    }
    Sleep(1000); //Delay of 1 sec= Sleep(1000).

    main_panel();


    return 0;
}

void ex()
{
    system("cls");

    printf("\n\n                                     Closing OVS in...\n");
    Sleep(1000);
    int i=4;
    while(i--)
    {
        printf("\t\t\t\t\t\t\t%d seconds",i);
        printf("\t\t\t\t\t\t\t\r");
        Sleep(1000);
    }
    Sleep(500);
}
void main_panel()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("                    \t\t\t       *** MAIN PANEL ***\n\n");
    Sleep(200);
    printf("                    \t\t\t(1) VOTE YOUR CANDIDATE ........\n\n");
    Sleep(200);
    printf("                    \t\t\t(2) ENTER ADMIN PANEL ........\n\n");
    Sleep(200);
    printf("                    \t\t\t(3) CANDIDATE IN LEAD ........\n\n");
    Sleep(200);
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
    system("cls");
    printf("\n\n\n\n\n");
    Sleep(500);
    printf("                         NOTE: Please make sure that you're registered in the electoral roll\n\n\n");
    Sleep(1000);
    printf("                          Your ID will be blocked after 3 unsuccessful attempts !!!\n\n");
    Sleep(1000);
    printf("                                       You're entering the data feeding panel\n");
    Sleep(500);
    printf("                                                       . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . \n");

    Sleep(500);
    printf("                                                 Did you know?\n\n");
    Sleep(500);
    printf("                               BIHAR: THE FIRST STATE TO WITNESS BOOTH CAPTURING\n");
    Sleep(1000);
    printf("       The first instance of booth capturing in India was recorded in 1957 in the General Elections of that\n");
    printf("                                 year in Rachiyahi of Begusarai constituency.\n");
    Sleep(1500);
    printf("                                                       . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . ");
    Sleep(500);
    printf(" . \n");
    printf("                                            Thanks for your patience.\n\n\n\n\n");
    Sleep(500);


    int timeLeft = 3;
    while (1)
    {
        system("cls");
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
                        printf("\n\n\n\n\n You have already voted. Exiting to main panel.\n\n\n\n\n\n");
                        main_panel();
                    }
                    else
                    {
                        printf("\n\n\n\n\n You have not voted.You can now view candidate list.\n\n\n\n\n\n");
                        system("cls");
                        printf("\n\n\n\n              Below is the list of all candidates: \n\n\n\n");
                        candidate *listCandidate = rootC;
                        list_all_candidates(listCandidate);
                        printf("\n\n          Enter which candidate you want to vote for by entering his ID:\n");
                        scanf("%d", &candIdSelected);
                        printf("this is just a testing printf");
                        Sleep(500);
                        printf("Ya now this vote is accounted for");
                    }
                }
                else
                {
                    if (nameTryLeft < 1)
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