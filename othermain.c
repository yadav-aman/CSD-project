#include <stdio.h>
#include <string.h>
#include <conio.h.>
#include <windows.h>
#include "header.h"

importVoters();
importCandidates();

int main()
{
    int num = 0;
    printf("enter a num, which should be the voter ID for checking\n");
    scanf("%d", &num);
    if (search(root, num))
        printf("Yes this voter ID exists\n");
    else
    {
        printf("This voter ID does not exist\n");
    }

    return 0;
}
