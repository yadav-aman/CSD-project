#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct voter //structure for soring the details of the voter
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
}voter;
voter *root;
long int TotalVoters = 0;

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
	return (a > b)? a : b;
}

voter* rightRotate(struct voter *y)//utility function to right rotate subtree rooted with y
{
	voter *x = y->left;
	voter *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = maximum(getheight(y->left), getheight(y->right))+1;
	x->height = maximum(getheight(x->left), getheight(x->right))+1;

	// Return new root
	return x;
}

// Function to left rotate subtree rooted with x
voter* leftRotate(voter*x)
{
	voter*y = x->right;
	voter*T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = maximum(getheight(x->left), getheight(x->right))+1;
	y->height = maximum(getheight(y->left), getheight(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(voter *N)
{
	if (N == NULL)
		return 0;
	return getheight(N->left) - getheight(N->right);
}

voter* insertvoter(voter* node, voter *temp)
{
	/* 1. Perform the normal BST insertvoterion */
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

voter* search(voter* root, long unsigned int key) 
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

int importData()
{
    root = NULL; // Initialising tree
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
            voter *temp = (voter *)malloc(sizeof(voter));

            char *data = strtok(line,","); // parsing the line upto "," using strtok function present in string.h library
            temp->voterID = atoi(data); // atoi function used to convert string into integer

            data = strtok(NULL,","); // updating data pointer to point to next value
            strcpy(temp->name,data);

            data = strtok(NULL,","); // updating data pointer to point to next value
            strcpy(temp->sex,data);

            data = strtok(NULL,","); // updating data pointer to point to next value
            strcpy(temp->address,data);
		
	    	data = strtok(NULL,","); // updating data pointer to point to next value
            temp->date = atoi(data);
		
	    	data = strtok(NULL,","); // updating data pointer to point to next value
            temp->month = atoi(data);
		
			data = strtok(NULL,","); // updating data pointer to point to next value
            temp->year = atoi(data);

            data = strtok(NULL,","); // updating data pointer to point to next value
            temp->voted = atoi(data);

            data = strtok(NULL,","); // updating data pointer to point to next value
            temp->NoOfAttempt = atoi(data);

			temp->left = NULL;
            temp->right = NULL;
            temp->height = 1;

            root = insertvoter(root, temp);
	    TotalVoters++;
        }
        printf("Message: Data Successfully Loaded\n");
        fclose(FilePointer); // closing file
    }
    return 0;
}
