#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------- VOTER STRUCTURE -------------------------------------------------------
typedef struct voter //structure for storing the details of the voter
{
	long unsigned int voterID;
	char name[30];
	char sex[2];
	char address[30];
	int date;
	int month;
	int year;
	int voted;
	int NoOfAttempt;
	struct voter *left;
	struct voter *right;
	int height;

} voter;
voter *root;
long int TotalVoters = 0;
int candidateCounter = 0;
//-------------------------------- CANDIDATE STRUCTURE -------------------------------------------------------
typedef struct candidate // structure to store the list of candidates
{
	int candID;
	char name[30];
	char partyName[45];
	char partySymbol[20];
	char sex[2];
	long int numOfVotes;
	struct candidate *next;
} candidate;
candidate *rootC;

//--------------------------------------- INPUT FUNCTION FOR CANDIDATE ----------------------------------------------------------
void insertCandidate(candidate **h, int candidID, char name[30], char partyName[50], char partySymbol[20], char sex[2], long int numOfVotes)
{
	candidate *newC = (candidate *)malloc(sizeof(candidate));
	newC->candID = candidID;
	strcpy(newC->name, name);
	strcpy(newC->partyName, partyName);
	strcpy(newC->partySymbol, partySymbol);
	strcpy(newC->sex, sex);
	newC->numOfVotes = numOfVotes;
	newC->next = *h;
	*h = newC;
	candidateCounter++;
}

//--------------------------------FUNCTION FOR PRINTING CANDIDATES------------------------------------------------------------------
void list_all_candidates(candidate *cand)
{
	if (cand == NULL)
	{
		printf("\n\n\n\nNo candidates.\n\n\n\n\n");
	}
	else
	{
		while (cand != NULL)
		{
			printf("\n\nCandidateID: %d || Name: %s || Party Name: %s || Party Symbol: %s || Gender: %s\n", cand->candID, cand->name, cand->partyName, cand->partySymbol, cand->sex);
			cand = cand->next;
		}

		printf("\n\n");
	}
}

//---------------------------------FUNCTION FOR UPDATING CANDIDATE VOTES-------------------------------------------------------
void candidateVoteUpdate(candidate **c, int id)
{
	candidate *temp = *c;
	if (temp == NULL)
	{
		printf("\n\nERROR\n\nNo candidates.\n\n\n\n\n");
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->candID == id)
				temp->numOfVotes++;
			temp = temp->next;
		}

		printf("\n\n");
	}
}

//----------------------------------------------- AVL TREE CODE ------------------------------------------------------------------
// Function to get the height of the tree
int getheight(voter *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

// Function to get maximum of two integers
int maximum(int a, int b)
{
	return (a > b) ? a : b;
}

voter *rightRotate(struct voter *y) // Function to right rotate subtree rooted with y
{
	voter *x = y->left;
	voter *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = maximum(getheight(y->left), getheight(y->right)) + 1;
	x->height = maximum(getheight(x->left), getheight(x->right)) + 1;

	// Return new root
	return x;
}

// Function to left rotate subtree rooted with x
voter *leftRotate(voter *x)
{
	voter *y = x->right;
	voter *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = maximum(getheight(x->left), getheight(x->right)) + 1;
	y->height = maximum(getheight(y->left), getheight(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(voter *node)
{
	if (node == NULL)
		return 0;
	return getheight(node->left) - getheight(node->right);
}

voter *insertvoter(voter *node, voter *temp)
{
	/* 1. Normal BST insertion */
	if (node == NULL)
		return temp;
	else if (temp->voterID < node->voterID)
		node->left = insertvoter(node->left, temp);
	else
		node->right = insertvoter(node->right, temp);

	/* 2. Update height of this ancestor node */
	node->height = 1 + maximum(getheight(node->left),
							   getheight(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && temp->voterID < node->left->voterID)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && temp->voterID > node->right->voterID)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && temp->voterID > node->left->voterID)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && temp->voterID < node->right->voterID)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

voter *search(voter *root, long unsigned int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->voterID == key)
		return root;

	// Key is greater than root's key
	if (root->voterID < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

//------------------------------------------- CODE TO IMPORT DATA FROM DATABASE -------------------------------------------
void importVoters()
{
	root = NULL; // Initialising tree
	// Initialising a pointer to file
	FILE *FilePointer;

	// Opening file in read-only mode and pointing the FilePointer to the start of the file
	FilePointer = fopen("VoterList.csv", "r");
	char line[150];

	if (FilePointer == NULL)
	{
		printf("\t\t\t\t\tERROR: Failed to open file.\nMake sure the required file is in current directory.\n");
		return;
	}
	else
	{
		printf("\t\t\t\t\tMessage: Voters Database Opened\n\t\t\t\t\tLoading Data...\n");
		fgets(line, 150, FilePointer); // storing first line in string 'line' from file to skip it

		while (fgets(line, 150, FilePointer)) // storing each line(one at a time) from the file in the string 'line'
		{
			voter *temp = (voter *)malloc(sizeof(voter));

			char *data = strtok(line, ","); // parsing the line upto "," using strtok function present in string.h library
			temp->voterID = atoi(data);		// atoi function used to convert string into integer

			data = strtok(NULL, ","); // updating data pointer to point to next value
			strcpy(temp->name, data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			strcpy(temp->sex, data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			strcpy(temp->address, data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			temp->date = atoi(data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			temp->month = atoi(data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			temp->year = atoi(data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			temp->voted = atoi(data);

			data = strtok(NULL, ","); // updating data pointer to point to next value
			temp->NoOfAttempt = atoi(data);

			temp->left = NULL;
			temp->right = NULL;
			temp->height = 1;

			root = insertvoter(root, temp);
			TotalVoters++;
		}
		printf("\t\t\t\t\tMessage: Voters Data Successfully Loaded\n\n");
		fclose(FilePointer); // closing file
	}
}

void importCandidates()
{
	rootC = NULL; // Initialising Linked List
	// Initialising a pointer to file
	FILE *FilePointer;

	// Opening file in read-only mode and pointing the FilePointer to the start of the file
	FilePointer = fopen("CandidateList.csv", "r");
	char line[150];

	if (FilePointer == NULL)
	{
		printf("\t\t\t\t\tERROR: Failed to open file.\n\t\t\t\t\tMake sure the required file is in current directory.\n");
		return;
	}
	else
	{
		printf("\t\t\t\t\tMessage: Candidates Database Opened\n\t\t\t\t\tLoading Data...\n");
		fgets(line, 150, FilePointer); // skip first line

		while (fgets(line, 150, FilePointer))
		{
			char *data = strtok(line, ",");
			int candid = atoi(data);

			data = strtok(NULL, ",");
			char *name = data;

			data = strtok(NULL, ",");
			char *partyname = data;

			data = strtok(NULL, ",");
			char *partysymbol = data;

			data = strtok(NULL, ",");
			char *sex = data;

			data = strtok(NULL, ",");
			int noofvotes = atoi(data);

			insertCandidate(&rootC, candid, name, partyname, partysymbol, sex, noofvotes);
		}
		printf("\t\t\t\t\tMessage: Candidates Successfully Loaded\n\n");
		fclose(FilePointer); // closing file
	}
}

//-------------------------------- FINAL RESULTS OF THE ELECTION AND OTHER IMPORTANT STATS ---------------------------------
void electionStatistics(candidate **list, long int totalVotesCasted)
{
	FILE *FilePointer;
	FilePointer = fopen("Result.txt", "w");

	candidate *crt = *list;
	if (*list == NULL)
	{
		printf("\nERROR: Candidate List not found");
		fprintf(FilePointer, "\nERROR: Candidate List not found"); // print to file
		fclose(FilePointer);
		return;
	}
	else if (totalVotesCasted == 0)
	{
		printf("\nERROR\nNo Vote Casted");
		fprintf(FilePointer, "\nERROR: No Vote Casted");
		fclose(FilePointer);
		return;
	}
	else
	{
		printf("\n\nELECTION STATISTICS:\n\n");
		fprintf(FilePointer, "\n\nELECTION STATISTICS:\n\n");

		printf("Total Number of Voters on the Electoral roll: %ld\n", TotalVoters);
		fprintf(FilePointer, "Total Number of Voters on the Electoral roll: %ld\n", TotalVoters);

		printf("Votes Casted: %ld\n", totalVotesCasted);
		fprintf(FilePointer, "Votes Casted: %ld\n", totalVotesCasted);

		float turnout = ((totalVotesCasted * 100) / TotalVoters);

		printf("Voter Turnout: %.2f%%\n\n", turnout);
		fprintf(FilePointer, "Voter Turnout: %.2f%%\n\n", turnout);

		// to store the maximum number of votes won by a candidate/s
		// i.e. if more than one candidate have got the same number of highest votes
		int maxVotes=0, maxCounter = 0;
		candidate *winner;
		printf("\n");
		while (crt != NULL)
		{
			printf("%s has got %ld votes\n", crt->name, crt->numOfVotes);
			fprintf(FilePointer, "%s has got %ld votes\n", crt->name, crt->numOfVotes);

			if (crt->numOfVotes > maxVotes)
			{
				maxVotes = crt->numOfVotes;
				maxCounter = 1;
				winner = crt;
			}
			else if (crt->numOfVotes == maxVotes)
				maxCounter++; //if more than one candidate has gotten the highest votes
			else
				;
			crt = crt->next;
		}
		if (maxCounter == 1) // if there is only one winner
		{
			float votePer = (float)((winner->numOfVotes * 100 / totalVotesCasted));
			printf("\nWinner of the Elections is: \n\nName: %s\nParty: %s\nLogo: %s\nVotes: %ld\nVote Percentage: %.2f%%\n", winner->name, winner->partyName, winner->partySymbol, winner->numOfVotes, votePer);
			fprintf(FilePointer, "\nWinner of the Elections is: \n\nName: %s\nParty: %s\nLogo: %s\nVotes: %ld\nVote Percentage: %.2f%%\n", winner->name, winner->partyName, winner->partySymbol, winner->numOfVotes, votePer);
		}
		else //in case there is a tie
		{
			crt = *list;
			printf("\n\nThe Election has been tied between the following %d candidates:\n\n", maxCounter);
			fprintf(FilePointer, "\n\nThe Election has been tied between the following %d candidates:\n\n", maxCounter);

			int counter = 1;
			while (crt != NULL)
			{

				if (crt->numOfVotes == maxVotes)
				{
					float votePer = (float)((crt->numOfVotes * 100 / totalVotesCasted));
					printf("Candidate %d:\nName: %s\nParty: %s\nLogo: %s\nVotes: %ld\nVote Percentage: %.2f%%\n\n", counter, crt->name, crt->partyName, crt->partySymbol, crt->numOfVotes, votePer);
					fprintf(FilePointer, "Candidate %d:\nName: %s\nParty: %s\nLogo: %s\nVotes: %ld\nVote Percentage: %.2f%%\n\n", counter, crt->name, crt->partyName, crt->partySymbol, crt->numOfVotes, votePer);
					counter++;
				}
				crt = crt->next;
			}
		}
	}
	printf("MESSAGE: Results Saved\n");
	fclose(FilePointer);
}

//--------------------------------------- ELECTION COMMISSION LOGO ----------------------------------------

void logo()
{
	printf("\n");
	printf("	                                .::::-`                          \n");
	printf("	                           `  `::::::::`                         \n");
	printf("	                        `+mN+``::::::::.                         \n");
	printf("	                      `oNNhhMm+.::::::-                          \n");
	printf("	                    .yNNy++++dMm/`..`                            \n");
	printf("	                  :hMms+++++++odMd-        `..``                 \n");
	printf("	                /dMdo++++++++++hMNo`     `::::::-`               \n");
	printf("	             `oNMho+++++++++odMm+`  .o.  :::::::::               \n");
	printf("	           .sNNh++++++++++smMd:   :hMNNo`-:::::::-               \n");
	printf("	         -yMmy++++++++++yNMy-   /dMh-`+NN+--:::-.                \n");
	printf("	       /dMms++++++++++hNNs.  `omNs.    `sNm/                     \n");
	printf("	    `+mMdo+++++++++ohMm+`  .sNmo`        .dMd.       `.--.`      \n");
	printf("	   `dMNo+++++++++sdMd/   -yMd/          /dMy-       -:::::::     \n");
	printf("	    `+NNy++++++smMh:   /dMh:         `oNNs.   -yy. .::::::::.    \n");
	printf("	      `sNNy++yNNs.  `+mMy-         .sNmo`   :hMNNMs.::::::::`    \n");
	printf("	        .yMNNNo`  .oNNo`         -yMd/    /dMmhyydNNo.----.      \n");
	printf("	          -y/`  -yMm+`         /dMh:   `oNMmyyyyyyydMN+          \n");
	printf("	              :hMd:         `+mNy.   .sNNdyyyyyyyyyydMMy         \n");
	printf("	              /mMs`       .sNNo`   :hMNdyyyyyyyyyydNMy-          \n");
	printf("	                +NNo`   -yMm+`   /dMmhyyyyyyyyyydMNs.            \n");
	printf("	                 `oNN+:dMh:   `+mMmhyyyyyyyyyhmMm+`              \n");
	printf("	                   `sMMy-   .sNNdyyyyyyyyyyhmMd/                 \n");
	printf("	                     ..   -yMNdyyyyyyyyyydNMh-                   \n");
	printf("	                        .dMNhyyyyyyyyyydNNs.                     \n");
	printf("	                         :dMmyyyyyyyymMNo`                       \n");
	printf("	                           /mMmyyyhmMd/                          \n");
	printf("	                             +NMmNMh:                            \n");
	printf("	                              `oNy-                              \n");
	printf("\n\n           	  ELECTION COMMISSION OF INDIA\n");
	printf("	   	   MERA VOTE MERA ADHIKAAR\n");
	
	int i;
    for (i = 0; i <= 100; i ++)
    {
        printf("\r");
        printf("\t\t\t\t\t\tLoading : %d %%", i);
        Sleep(10);
    }
}
