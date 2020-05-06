#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include"header.h"

int isBSTUtil(struct voter* voter, int min, int max); 

/* Returns true if the given tree is a binary search tree 
(efficient version). */
int isBST(struct voter* voter) 
{ 
return(isBSTUtil(voter, INT_MIN, INT_MAX)); 
} 

/* Returns true if the given tree is a BST and its 
values are >= min and <= max. */
int isBSTUtil(struct voter* voter, int min, int max) 
{ 
/* an empty tree is BST */
if (voter==NULL) 
	return 1; 
		
/* false if this voter violates the min/max constraint */
if (voter->voterID < min || voter->voterID > max) 
	return 0; 

/* otherwise check the subtrees recursively, 
tightening the min or max constraint */
return
	isBSTUtil(voter->left, min, voter->voterID-1) && // Allow only distinct values 
	isBSTUtil(voter->right, voter->voterID+1, max); // Allow only distinct values 
} 

/* Helper function that allocates a new voter with the 
given voterID and NULL left and right pointers. */
struct voter* newvoter(int voterID) 
{ 
struct voter* voter = (struct voter*) 
					malloc(sizeof(struct voter)); 
voter->voterID = voterID; 
voter->left = NULL; 
voter->right = NULL; 

return(voter); 
} 

/* Driver program to test above functions*/
int main() 
{ 
root = NULL;
importData();
if(isBST(root)) 
	printf("Is BST\n"); 
else
	printf("Not a BST\n"); 
	
return 0; 
} 
