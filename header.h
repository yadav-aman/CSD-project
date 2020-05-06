#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int importData()
{
    // Initialising a pointer to file
    FILE *FilePointer;
    
    // Opening file in read-only mode and pointing the FilePointer to the start of the file
    FilePointer = fopen("VoterList.csv","r");  
    char line[100];

    if( FilePointer == NULL )
    {
        printf("ERROR: Failed to open file.\nMake sure the required file is in current directory.\n");
        return -1;
    }
    else
    {
        printf("Message: File Opened\nLoading Data...\n");
        fgets(line,100,FilePointer); // storing first line in string 'line' from file to skip it
        
        while( fgets(line,100,FilePointer) ) // storing each line(one at a time) from the file in the string 'line'
        {
            char *data = strtok(line,","); // parsing the line upto "," using strtok function present in string.h library

            unsigned int voterID = atoi(data); // atoi function used to convert string into integer
            printf("%u\n",voterID);

            data = strtok(NULL,","); // updating data pointer to point to next value 
            char name[30];
            strcpy(name,data);
            puts(name);

            data = strtok(NULL,","); // updating data pointer to point to next value
            char sex[2];
            strcpy(sex,data);
            puts(sex);

            data = strtok(NULL,","); // updating data pointer to point to next value
            char address[50];
            strcpy(address,data);
            puts(address);

            data = strtok(NULL,","); // updating data pointer to point to next value
            bool voted = atoi(data);
            printf("%d\n",voted);

            data = strtok(NULL,","); // updating data pointer to point to next value
            unsigned int NoOfAttempt = atoi(data);
            printf("%u\n",NoOfAttempt);

            printf("\n");
        }
        printf("Message: Data Successfully Loaded\n");
        fclose(FilePointer); // closing file
    }
    return 0;
}
