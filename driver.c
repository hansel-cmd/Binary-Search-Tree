#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cell {
	int data;
	struct cell *LC;
	struct cell *RC;
}nodeType, *BSTree;

#include "Recursive.h"
#include "Non_recursive.h"


int main()
{
	int arr[] = {50, 12, 67, 43, 23, 83, 76, 78, 95, 58, 68};
	int size = 11;
	
	BSTree T;
	T = populate(arr, size);
	printf("\n=======Non-Recursive Style=======\n");
	printf("Initial\n");
	
	printf("\nPreorder\n");
	preorder(T);
	
	printf("\nInorder\n");
	inorder(T);
	
	printf("\nPostorder\n");
	postorder(T);
	
	int z = 89;
	insert(&T, z);
	printf("\nAfter Insert\n");
	
	printf("\nPreorder\n");
	preorder(T);
	
	printf("\nInorder\n");
	inorder(T);
	
	printf("\nPostorder\n");
	postorder(T);
	
	
	int x = 50;
	printf("\n%d %s\n", x, isMember(T, x) ? "is a member" : "is not a member");
	
	deleteElem(&T, x);
	printf("\nAfter Delete\n");
	
	printf("\nPreorder\n");
	preorder(T);
	
	printf("\nInorder\n");
	inorder(T);
	
	printf("\nPostorder\n");
	postorder(T);
	
	
	printf("\n\n=======Recursive Style=======\n");
		
	int arr1[] = {50, 12, 67, 43, 23, 83, 76, 78, 95, 58, 68};
	int size1 = 11;
	
	BSTree T1;
	T1 = populateRecursive(arr1, size1);
	
	printf("Initial\n");
	
	printf("\nPreorder Recursive\n");
	preorderRecursive(T1);
	
	printf("\nInorder Recursive\n");
	inorderRecursive(T1);
	
	printf("\nPostorder Recursive\n");
	postorderRecursive(T1);
	
	insertRecursive(&T1, z);
	printf("\nAfter Insert\n");
	
	printf("\nPreorder\n");
	preorderRecursive(T1);
	
	printf("\nInorder\n");
	inorderRecursive(T1);
	
	printf("\nPostorder\n");
	postorderRecursive(T1);
	
	printf("\n%d %s\n", x, isMemberRecursive(T1, x) ? "is a member" : "is not a member");
	
	deleteElemRecursive(&T1, x);
	printf("\nAfter Delete\n");
	
	printf("\nPreorder\n");
	preorderRecursive(T1);
	
	printf("\nInorder\n");
	inorderRecursive(T1);
	
	printf("\nPostorder\n");
	postorderRecursive(T1);
	
	
	
	return 0;
}
