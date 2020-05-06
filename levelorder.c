// Recursive C program for level order traversal of Binary Tree 
#include <stdio.h> 
#include <stdlib.h> 
#include"header.h"

/* Function protoypes */
void printGivenLevel(struct voter* root, int level); 
int height(struct voter* voter); 
struct voter* newvoter(int data); 

/* Function to print level order traversal a tree*/
void printLevelOrder(struct voter* root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(root, i); 
} 

/* Print voters at a given level */
void printGivenLevel(struct voter* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
    {
    printf("%lu ",root->voterID);
    }
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 

/* Compute the "height" of a tree -- the number of 
	voters along the longest path from the root voter 
	down to the farthest leaf voter.*/
int height(struct voter* voter) 
{ 
	if (voter==NULL) 
		return 0; 
	else
	{ 
		/* compute the height of each subtree */
		int lheight = height(voter->left); 
		int rheight = height(voter->right); 

		/* use the larger one */
		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
} 

/* Helper function that allocates a new voter with the 
given data and NULL left and right pointers. */
struct voter* newvoter(int data) 
{ 
	struct voter* voter = (struct voter*) 
						malloc(sizeof(struct voter)); 
	voter->voterID = data; 
	voter->left = NULL; 
	voter->right = NULL; 

	return(voter); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	root = NULL;
    importData();
	printf("Level Order traversal of binary tree is \n"); 
	printLevelOrder(root); 

	return 0; 
} 
