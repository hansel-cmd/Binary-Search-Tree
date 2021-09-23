#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cell {
	int data;
	struct cell *LC;
	struct cell *RC;
}nodeType, *BSTree;

/** Non-Recursive style */
void preorder(BSTree T);
void inorder(BSTree T);
void postorder(BSTree T);
BSTree populate(int arr[], int size);
void insert(BSTree *T, int x);
int isMember(BSTree T, int x);
void deleteElem(BSTree *T, int x);
int getPredecessor(BSTree *T);
int getSuccessor(BSTree *T);

/** Recursive Style */
void preorderRecursive(BSTree T);
void inorderRecursive(BSTree T);
void postorderRecursive(BSTree T);
BSTree populateRecursive(int arr[], int size);
void insertRecursive(BSTree *T, int x);
int isMemberRecursive(BSTree T, int x);
void deleteElemRecursive(BSTree *T, int x);
int getPredecessorRecursive(BSTree *T);
int getSuccessorRecursive(BSTree *T);


BSTree populate(int arr[], int size)
{
	int i;
	BSTree T;
	T = NULL;
	
	for (i = 0; i < size; i++) {
		insert(&T, arr[i]);
	}
	
	return T;
}

void insert(BSTree *T, int x)
{
	BSTree *trav;
	trav = T;
	
	while (*trav != NULL && (*trav)->data != x) {
		trav = ((*trav)->data < x) ? &(*trav)->RC : &(*trav)->LC;
	}
	
	if (*trav == NULL) {
		*trav = (BSTree) calloc (1, sizeof(nodeType));
		if (*trav != NULL) {
			(*trav)->data = x;
		}
	}
}

void preorder(BSTree T)
{
	BSTree stack[10000], temp;
	int top = -1;
	
	if (T != NULL) {
		stack[++top] = T;
	}
	
	while (top >= 0) {
		temp = stack[top];
		
		printf("%d ", temp->data);
		
		top--;
		
		if (temp->RC != NULL) {
			stack[++top] = temp->RC;
		}
		
		if (temp->LC != NULL) {
			stack[++top] = temp->LC;
		}
	}
	printf("\n");
}

void inorder(BSTree T)
{
	BSTree stack[10000];
	BSTree trav;
	int top = -1;
	
	trav = T;
	while (1) {
		if (trav != NULL) {
			stack[++top] = trav;
			trav = trav->LC;
		} else {
			if (top == -1) {
				break;
			}
			
			trav = stack[top];
			--top;
			
			printf("%d ", trav->data);
			
			if (trav->RC != NULL) {
				trav = trav->RC;
			} else {
				trav = NULL;
			}
		}
	}
	printf("\n");
}

void postorder(BSTree T)
{
	BSTree stack[10000], trav;
	int top = -1;
	
	trav = T;
	while (1) {
		if (trav != NULL) {
			stack[++top] = trav;
			trav = trav->LC;
		} else {
			if (top == -1) {
				break;
			}
			
			
			if (stack[top]->RC == NULL) {
				trav = stack[top];
				top--;
				printf("%d ", trav->data);
				
				while (top >= 0 && stack[top]->RC == trav) {
					printf("%2d ", stack[top]->data);
					trav = stack[top--];
				}
			}
			
			if (top != -1) {
				trav = stack[top]->RC;
			} else {
				trav = NULL;
			}
		}
	}
	printf("\n");
}

int isMember(BSTree T, int x)
{
	BSTree trav;
	
	trav = T;
	while (trav != NULL && trav->data != x) {
		trav = (trav->data < x) ? trav->RC : trav->LC;
	}
	
	return (trav != NULL) ? 1 : 0;
}

void deleteElem(BSTree *T, int x)
{
	BSTree *trav, *trav2, temp;
	
	trav = T;
	while (*trav != NULL && (*trav)->data != x) {
		trav = ((*trav)->data < x) ? &(*trav)->RC : &(*trav)->LC;
	}
	
	if (*trav != NULL) {
		temp = *trav;
		if (temp->LC == NULL) {
			*trav = temp->RC;
			free(temp);
		} else if (temp->RC == NULL) {
			*trav = temp->LC;
			free(temp);
		} else {
			(*trav)->data = getPredecessor(&(*trav)->LC);
		}
	}
}

int getPredecessor(BSTree *T)
{
	int retval;
	BSTree *trav, temp;
	trav = T;
	while ((*trav)->RC != NULL) {
		trav = &(*trav)->RC;
	}
	
	temp = *trav;
	retval = temp->data;
	*trav = (*trav)->LC;
	free(temp);
	return retval;
}

int getSuccessor(BSTree *T)
{
	int retval;
	BSTree *trav, temp;
	trav = T;
	while ((*trav)->LC != NULL) {
		trav = &(*trav)->LC;
	}
	
	temp = *trav;
	retval = temp->data;
	*trav = (*trav)->RC;
	free(temp);
	return retval;
}


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


/** Recursive Style */


void preorderRecursive(BSTree T)
{
	if (T != NULL) {
		printf("%d ", T->data);
		preorderRecursive(T->LC);
		preorderRecursive(T->RC);
	}
}

void inorderRecursive(BSTree T)
{
	if (T != NULL) {
		inorderRecursive(T->LC);
		printf("%d ", T->data);
		inorderRecursive(T->RC);
	}
}

void postorderRecursive(BSTree T)
{
	if (T != NULL) {
		postorderRecursive(T->LC);
		postorderRecursive(T->RC);
		printf("%d ", T->data);
	}
}

BSTree populateRecursive(int arr[], int size)
{
	BSTree T;
	T = NULL;
	
	int i;
	for (i = 0; i < size; i++) {
		insertRecursive(&T, arr[i]);
	}
	
	return T;
}

void insertRecursive(BSTree *T, int x)
{
	if (*T == NULL) {
		*T = (BSTree) calloc (1, sizeof(nodeType));
		if (*T != NULL) {
			(*T)->data = x;
		}
		return;
	}
	
	if ((*T)->data == x) return;
	
	return ((*T)->data < x) ? insertRecursive(&(*T)->RC, x) : insertRecursive(&(*T)->LC, x);
}

int isMemberRecursive(BSTree T, int x)
{
	if (T == NULL) return 0;
	if (T->data == x) return 1;
	return (T->data < x) ? isMemberRecursive(T->RC, x) : isMemberRecursive(T->LC, x);
}

void deleteElemRecursive(BSTree *T, int x)
{
	if (*T == NULL) return;
	
	if ((*T)->data == x) {
		BSTree *trav, temp;
		temp = *T;
		if (temp->RC == NULL) {
			*T = temp->LC;
			free(temp);
		} else if (temp->LC == NULL) {
			*T = temp->RC;
			free(temp);
		} else {
			(*T)->data = getPredecessorRecursive(&(*T)->LC);
		}
		return;
	}
	
	return ((*T)->data < x) ? deleteElemRecursive(&(*T)->RC, x) : deleteElemRecursive(&(*T)->LC, x);
}

int getPredecessorRecursive(BSTree *T)
{
	if ((*T)->RC == NULL) {
		BSTree temp;
		int retval;
		
		temp = *T;
		retval = temp->data;
		*T = temp->LC;
		free(temp);
		return retval;
	}
	
	return getPredecessorRecursive(&(*T)->RC);
}

int getSuccessorRecursive(BSTree *T)
{
	if ((*T)->LC == NULL) {
		BSTree temp;
		int retval;
		
		temp = *T;
		retval = temp->data;
		*T = (*T)->RC;
		free(temp);
		return retval;
	}
	
	return getSuccessorRecursive(&(*T)->LC);
}

