#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
#define _NULL -1

typedef int BST;

typedef struct {
	int elem;
	int left;
	int right;
}Node;

typedef struct {
	Node data[MAX];
	int avail;
}VHeap;

#include "Recursive.h"
#include "Non_recursive.h"


void initVHeap(VHeap *VH)
{
	int i;
	for (i = MAX - 1; i >= 0; i--) {
		VH->data[i].left = i - 1;
		VH->data[i].right = i - 1;
	}
	VH->avail = MAX - 1;
}

int main()
{
	BST T;
	VHeap VH;
	
	initVHeap(&VH);
	T = -1;
	
	
	printf("\n========Non-Recursive=======\n");
	populate(&T, &VH);
	printf("\nInitial\n");
	printf("\nPreorder\n");
	preorder(T, VH);
	
	printf("\nInorder\n");
	inorder(T, VH);
	
	printf("\nPostorder\n");
	postorder(T, VH);
	
	int x = 12;
	printf("\n\nIs Member");
	printf("\n%d %s\n", x, isMember(T, VH, x) ? "is member" : "is not a member");
	
	
	printf("\nDelete\n");
	deleteElem(&T, &VH, x);
	printf("\nPreorder\n");
	preorder(T, VH);
	
	printf("\nInorder\n");
	inorder(T, VH);
	
	printf("\nPostorder\n");
	postorder(T, VH);
	
	
	printf("\n========Recursive=======\n");
	
	BST T1 = _NULL;
	initVHeap(&VH);
	
	populateRecursive(&T1, &VH);
	printf("\nInitial\n");
	printf("\nPreorder\n");
	preorderRecursive(T1, VH);
	
	printf("\nInorder\n");
	inorderRecursive(T1, VH);
	
	printf("\nPostorder\n");
	postorderRecursive(T1, VH);
	
	printf("\n\nIs Member");
	printf("\n%d %s\n", x, isMemberRecursive(T, VH, x) ? "is member" : "is not a member");
	
	printf("\nDelete\n");
	deleteElemRecursive(&T, &VH, x);
	printf("\nPreorder\n");
	preorderRecursive(T, VH);
	
	printf("\nInorder\n");
	inorderRecursive(T, VH);
	
	printf("\nPostorder\n");
	postorderRecursive(T, VH);
	
	return 0;
}
