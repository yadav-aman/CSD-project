#include <stdio.h>
#include <string.h>
#include <conio.h.>
#include <windows.h>
#include <stdbool.h>
#include "header.h"

#define ADMINID 123456

bool isVotingOpen = true;
int candIdSelected;
long unsigned inputtedVoterID;
long int numOfVotesCasted = 0;
char inputtedName[30];
void main_panel();
void ex();
void admin();
void voting_screen();
void adminPanel();

int main() //completed
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\tFOR BETTER EXPERIENCE PLEASE OPEN TERMINAL IN FULL SCREEN MODE\n\n\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE\n\t\t\t\t\t\t");
    getch();
    system("cls");
    logo();
    Sleep(1000);
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    importVoters();
    importCandidates();
    printf("\t\t\t\t\tPress any key to continue: ");
    getch();
    system("cls");
    Sleep(1000); //Delay of 1 sec= Sleep(1000).

    main_panel();

    return 0;
}

void ex() //completed
{
    system("cls");

    printf("\n\n                                     Closing OVS in...\n");
    Sleep(1000);
    int i = 4;
    while (i--)
    {
        printf("\t\t\t\t\t\t\t%d seconds", i);
        printf("\t\t\t\t\t\t\t\r");
        Sleep(500);
    }
    Sleep(500);
    main_panel();
}

void main_panel() //completed
{
    if (isVotingOpen)
    {
        system("cls");
        printf("\n\n");
        printf("                                       Satyamev Jayate- Bharat Nirvachan Aayog\n\n");
        Sleep(200);
        printf("-----------------------------------------------------------------------------------------------------------------------\n\n");
        Sleep(200);
        printf("                      **************** WELCOME TO ELECTION COMMISSION OF INDIA ***************                 \n");
        Sleep(200);
        printf("                                               Bihar Division, Patna                                           \n\n\n");
        Sleep(200);
        printf("                  BIHAR VIDHAN SABHA NIRVACHAN 2020           BIHAR LEGISLATIVE ASSEMBLY ELECTIONS 2020         \n\n");
        Sleep(200);
        printf("                                  ECI presenting the first online voting system of India.                        \n");
        printf("\n                                             Live Vote count %d / %d\n\n\n\n", numOfVotesCasted, TotalVoters);
        Sleep(200);
        printf("                                       � Copyright Election Commission of India                                    \n\n");
        Sleep(200);
        printf("________________________________________________________________________________________________________________________\n\n\n");
        Sleep(200);
        printf("                                          Press any key to continue !!!                                \n\n\n");
        printf("\n\n                                                      ");
        Sleep(1000);

        getch();
        Sleep(1000); //Delay of 1 sec= Sleep(1000).

        while (1)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            printf("                    \t\t\t       *** MAIN PANEL ***\n\n");
            Sleep(200);
            printf("                    \t\t\t(1) VOTE YOUR CANDIDATE ........\n\n");
            Sleep(200);
            printf("                    \t\t\t(2) ENTER ADMIN PANEL ........\n\n");
            Sleep(200);
            printf("                    \t\t\t(3) EXIT THE OVS........\n\n\n"); //OVS: Online Voting System

            int choice;
            printf("                                                      ");
            scanf("%d", &choice);
            getchar();

            switch (choice)
            {

            case 1:
                voting_screen();
                break;

            case 2:
                adminPanel();
                break;

            case 3:
                ex();
                break;

            default:
                printf("\n\n\n\n\t\t\t\tInvalid Choice\n\t\t\t\tEnter Again");
                Sleep(1000);
                break;
            }
        }
    }
    else // finally exiting the system after the voting is complete
    {
        system("cls");
        printf("Voting has been closed\nEnter Admin id to close the system\n");
        int id;
        while (1)
        {
            printf("\nID: ");
            scanf("%d", &id);
            getchar();
            if (id == ADMINID)
            {
                system("cls");
                printf("\n\n                                          ID Verified              \n ");
                printf("\n                                   Thank You for using our System    \n");
                printf("\n\n                                     Closing System in...\n");
                Sleep(1000);
                int i = 4;
                while (i--)
                {
                    printf("\t\t\t\t\t\t\t%d seconds", i);
                    printf("\t\t\t\t\t\t\t\r");
                    Sleep(1000);
                }
                Sleep(500);
                exit(0);
            }
            else
                printf("Invalid ID\nEnter again");
        }
    }
}

void adminPanel() //completed
{
    int id, ch;
    while (1)
    {
        system("cls");
        printf("\n\nEnter Admin Id: ");
        scanf("%d", &id);
        getchar();
        if (id == ADMINID)
        {
            printf("\n\t\t\t\t\tID Matched\n\t\t\t\t\tYou have entered the Admin Panel\n");
            while (1)
            {
                printf("\n\n\t\t\t\t\tEnter: \n\t\t\t\t\t1.To close voting\n\t\t\t\t\t2.To view Results\n\t\t\t\t\t3.Go back to the main panel\n\t\t\t\t\t");
                scanf("%d", &ch);
                getchar();
                switch (ch)
                {
                case 1:
                    if (isVotingOpen)
                    {
                        printf("\n\t\t\t\t\tVoting is now closed\n");
                        isVotingOpen = false;
                    }
                    else
                        printf("\n\t\t\t\t\tVoting has already been closed\n");
                    break;

                case 2:
                    if (isVotingOpen)
                    {
                        printf("\n\t\t\t\t\tVoting is still open\n\t\t\t\t\tClose Voting to watch the Results\n");
                        break;
                    }
                    else
                        electionStatistics(&rootC, numOfVotesCasted);
                    break;

                case 3:
                    ex();
                    break;

                default:
                    printf("\n\t\t\t\t\tInvalid Choice\n\t\t\t\t\tTry Again");
                    break;
                }
            }
        }
        else
            printf("Invalid ID\nEnter again");
    }
}

void voting_screen() //completed
{
    system("cls");
    printf("\n\n");
    Sleep(200);
    printf("                         NOTE: Please make sure that you're registered in the electoral roll\n\n\n");
    Sleep(500);
    printf("                          Your ID will be blocked after 3 unsuccessful attempts !!!\n\n");
    Sleep(200);
    printf("                                    You're entering the data in the feeding panel\n");
    Sleep(200);
    printf("                                                     . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . \n");

    Sleep(200);
    printf("                                                 Did you know?\n\n");
    Sleep(200);
    printf("                              BIHAR: THE FIRST STATE TO WITNESS BOOTH CAPTURING\n");
    Sleep(500);
    printf("               The first instance of booth capturing in India was recorded in 1957 in the General Elections of that\n");
    printf("                                 year in Rachiyahi of Begusarai constituency.\n");
    Sleep(500);
    printf("                                              . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . ");
    Sleep(200);
    printf(" . \n");
    printf("                                            Thanks for your patience.\n\n\n\n\n");
    Sleep(500);

    while (1)
    {
        system("cls");
        printf("\n\n\n                      ENTER VOTER ID (as per your EPIC):   ");
        scanf("%lu", &inputtedVoterID);
        getchar();
        printf("\n\n\n\n\n\n");
        voter *tempVoter = search(root, inputtedVoterID);

        if(tempVoter)
        {
            system("cls");
            if( ! tempVoter->voted )
            {
                while(1)
                {
                    if (tempVoter->NoOfAttempt == 0)
                    {
                        printf("\n\n\n\n\t\t\t\tYou ran out of attempts.\n\t\t\t\tYour ID has been blocked\n\t\t\t\tSwitching to main panel.\n\n\n");
                        Sleep(3000);
                        ex();
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n         Voter ID exists. Please enter correct name for further verification.\n\n\n");
                        printf("\n\n");
                        printf("                        You have %d tries left.", tempVoter->NoOfAttempt);
                        printf("\n\n                       Enter your full name as per VOTER ID:   ");
                        fflush(stdin);
                        gets(inputtedName);
                        printf("\n\n\n");
                        if( ! strcmpi(tempVoter->name, inputtedName) )
                        {
                            system("cls");
                            printf("\n\n             You are a registered voter. Congrats.\n");
                            printf("\n\n                     Here are your details.\n");
                            printf("\n              Your Voter ID: %lu\n", tempVoter->voterID);
                            printf("              Your Name: %s\n", tempVoter->name);
                            printf("              Your Gender: %s\n", tempVoter->sex);
                            printf("              Your date of birth: %d-%d-%d\n", tempVoter->date, tempVoter->month, tempVoter->year);
                            printf("              Your Address: %s\n", tempVoter->address);
                            printf("\n\n\t\t\t Press any key to continue!!\n\t\t\t");
                            getch();
                            system("cls");
                            printf("\n\n\t\t\t You have not voted.You can now view candidate list.\n");
                            printf("\n               Below is the list of all candidates: \n\n");
                            candidate *listCandidate = rootC;
                            list_all_candidates(listCandidate);
                            while (1)
                            {
                                printf("\n\n          Enter which candidate you want to vote for by entering his ID:  ");
                                scanf("%d", &candIdSelected);
                                if (candIdSelected > 0 && candIdSelected <= candidateCounter)
                                {
                                    candidateVoteUpdate(&listCandidate, candIdSelected);
                                    numOfVotesCasted++;
                                    tempVoter->voted++;
                                    Sleep(1000);
                                    system("cls");
                                    printf("\n\n\t\t\t\t\tYour Vote had been casted\n\t\t\t\t\tThank You for Voting\n\n\n\t\t\t\t\tExiting to Home Screen");
                                    Sleep(2000);
                                    ex();
                                }
                                else
                                    printf("\n\n\t\t\t\t\tInvalid Choice\n\t\t\t\t\tEnter Again\n");
                            }
                        }
                        else
                        {
                            printf("\n\n\n\t\tVoter Name entered was wrong.\n\t\tPress 1 to try again.\n\t\tPress 2 to exit to the Home Screen\n\n\t\t");
                            tempVoter->NoOfAttempt--;
                            int c;
                            scanf("%d", &c);
                            getchar();
                            switch(c)
                            {
                                case 1 :
                                    break;
                                case 2 :
                                    ex();
                                    break;
                                default :
                                    printf("Enter a valid choice: ");
                                    Sleep(1000);
                            }   
                        }
                    }
                }
            }
            else
            {                        
                printf("\n\n\t\t\tYou have already voted. Exiting to main panel.");
                Sleep(2000);
                main_panel();
            }

        }
        else
        {
            printf("\n\n\n\t\t\tVoter ID entered was wrong OR does not exist.\n\t\t\tEnter correct data.\n\t\t\tPlease try again. Exiting to main Panel\n\n");
            Sleep(3000);
            ex();
        }
    }
}