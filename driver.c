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

/** Non-Recursive */
void initVHeap(VHeap *VH);
void preorder(BST T, VHeap VH);
void inorder(BST T, VHeap VH);
void postorder(BST T, VHeap VH);
void populate(BST *T, VHeap *VH);
void insert(BST *T, VHeap *VH, int x);
int isMember(BST T, VHeap VH, int x);
void deleteElem(BST *T, VHeap *VH, int x);


/** Recursive */
void preorderRecursive(BST T, VHeap VH);
void inorderRecursive(BST T, VHeap VH);
void postorderRecursive(BST T, VHeap VH);
void populateRecursive(BST *T, VHeap *VH);
void insertRecursive(BST *T, VHeap *VH, int x);
int isMemberRecursive(BST T, VHeap VH, int x);
void deleteElemRecursive(BST *T, VHeap *VH, int x);


void initVHeap(VHeap *VH)
{
	int i;
	for (i = MAX - 1; i >= 0; i--) {
		VH->data[i].left = i - 1;
		VH->data[i].right = i - 1;
	}
	VH->avail = MAX - 1;
}

void preorder(BST T, VHeap VH)
{
	BST stack[10000], temp;
	int top = -1;
	
	if (T != _NULL) {
		stack[++top] = T;
	}
	
	while (top >= 0) {
		temp = stack[top];
		
		printf("%d ", VH.data[temp].elem);
		
		--top;
		
		if (VH.data[temp].right != _NULL) {
			stack[++top] = VH.data[temp].right;
		}
		
		if (VH.data[temp].left != _NULL) {
			stack[++top] = VH.data[temp].left;
		}
	}
}

void inorder(BST T, VHeap VH)
{
	BST stack[10000], temp;
	int top = -1;
	
	while (1) {
		if (T != _NULL) {
			stack[++top] = T;
			T = VH.data[T].left;
		} else {
			if (top == -1) {
				break;
			}
			
			temp = stack[top];
			--top;
			
			printf("%d ", VH.data[temp].elem);
			
			if (VH.data[temp].right != _NULL) {
				T = VH.data[temp].right;
			}
		}
	}
}

void postorder(BST T, VHeap VH)
{
	BST stack[10000], temp;
	int top = -1;
	
	while (1) {
		if (T != _NULL) {
			stack[++top] = T;
			T = VH.data[T].left;
		} else {
			if (top == -1) {
				break;
			}
			
			
			if (VH.data[stack[top]].right == _NULL) {
				temp = stack[top];
				--top;
				printf("%d ", VH.data[temp].elem);
				
				while (top >= 0 && temp == VH.data[stack[top]].right) {
					printf("%d ", VH.data[stack[top]].elem);
					
					temp = stack[top];
					top--;
				}
			}
			
			if (top != _NULL) {
				T = VH.data[stack[top]].right;
			} else {
				T = _NULL;
			}
		}
	}
}

void populate(BST *T, VHeap *VH)
{
	int arr[] = {50, 12, 67, 43, 23, 83, 76, 78, 95, 58, 68};
	int size = 11;
	int i;
	
	for (i = 0; i < size; i++) {
		insert(T, VH, arr[i]);
	}
}

void insert(BST *T, VHeap *VH, int x)
{
	while (*T != _NULL && VH->data[*T].elem != x) {
		T = (VH->data[*T].elem < x) ? &VH->data[*T].right : &VH->data[*T].left;
	}
	
	if (*T == _NULL) {
		*T = VH->avail;
		if (*T != _NULL) {
			VH->avail = VH->data[*T].left;
			
			VH->data[*T].elem = x;
			VH->data[*T].left = _NULL;
			VH->data[*T].right = _NULL;
		}
	}
}

int isMember(BST T, VHeap VH, int x)
{
	while (T != _NULL && VH.data[T].elem != x) {
		T = (VH.data[T].elem < x) ? VH.data[T].right : VH.data[T].left;
	}
	
	return T != _NULL ? 1 : 0;
}


void deleteElem(BST *T, VHeap *VH, int x)
{
	BST *trav, temp, *trav2;
	trav = T;
	while (*trav != _NULL && VH->data[*trav].elem != x) {
		trav = (VH->data[*trav].elem < x) ? &VH->data[*trav].right : &VH->data[*trav].left;
	}
	
	if (*trav != _NULL) {
		temp = *trav;
		if (VH->data[temp].right == _NULL) {
			*trav = VH->data[temp].left;
			
			VH->data[temp].right = VH->avail;
			VH->data[temp].left = VH->avail;
			VH->avail = temp;
		} else if (VH->data[temp].left == _NULL) {
			*trav = VH->data[temp].right;
			
			VH->data[temp].left = VH->avail;
			VH->data[temp].right = VH->avail;
			VH->avail = temp;
		} else {
			trav2 = &VH->data[*trav].right;
			
			while (VH->data[*trav2].left != _NULL) {
				trav2 = &VH->data[*trav2].left;
			}
			
			temp = *trav2;
			VH->data[*trav].elem = VH->data[temp].elem;
			
			*trav2 = VH->data[temp].right;
			VH->data[temp].left = VH->avail;
			VH->data[temp].right = VH->avail;
			VH->avail = temp;
			
		}
	}
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

void preorderRecursive(BST T, VHeap VH)
{
	if (T != _NULL)	{
		printf("%d ", VH.data[T].elem);
		
		preorderRecursive(VH.data[T].left, VH);
		preorderRecursive(VH.data[T].right, VH);
	}
}

void inorderRecursive(BST T, VHeap VH)
{
	if (T != _NULL) {
		inorderRecursive(VH.data[T].left, VH);
		printf("%d ", VH.data[T].elem);
		inorderRecursive(VH.data[T].right, VH);
	}
}

void postorderRecursive(BST T, VHeap VH)
{
	if (T != _NULL) {
		postorderRecursive(VH.data[T].left, VH);
		postorderRecursive(VH.data[T].right, VH);
		printf("%d ", VH.data[T].elem);
	}
}

void populateRecursive(BST *T, VHeap *VH)
{
	int arr[] = {50, 12, 67, 43, 23, 83, 76, 78, 95, 58, 68};
	int size = 11;
	int i;
	
	for (i = 0; i < size; i++) {
		insertRecursive(T, VH, arr[i]);
	}
}

void insertRecursive(BST *T, VHeap *VH, int x)
{
	if (*T == _NULL) {
		*T = VH->avail;
		if (*T != _NULL) {
			VH->avail = VH->data[*T].left;
			
			VH->data[*T].elem = x;
			VH->data[*T].left = _NULL;
			VH->data[*T].right = _NULL;
		}
	}
	
	if (VH->data[*T].elem == x) return;
	
	return (VH->data[*T].elem < x) ? insertRecursive(&VH->data[*T].right, VH, x) : insertRecursive(&VH->data[*T].left, VH, x);
}

int isMemberRecursive(BST T, VHeap VH, int x)
{
	if (T == _NULL) return 0;
	if (VH.data[T].elem == x) return 1;
	return (VH.data[T].elem < x) ? isMemberRecursive(VH.data[T].right, VH, x) : isMemberRecursive(VH.data[T].left, VH, x);
}

void deleteElemRecursive(BST *T, VHeap *VH, int x)
{
	if (*T == _NULL) return;
	if (VH->data[*T].elem == x) {
		BST *trav, temp;
		temp = *T;
		if (VH->data[temp].right == _NULL) {
			*T = VH->data[temp].left;
			VH->data[temp].left = VH->avail;
			VH->data[temp].right = VH->avail;
			VH->avail = temp;
		} else if (VH->data[temp].left == _NULL) {
			*T = VH->data[temp].right;
			VH->data[temp].left = VH->avail;
			VH->data[temp].right = VH->avail;
			VH->avail = temp;
		} else {
			trav = &VH->data[*T].right;
			while (VH->data[*trav].left != _NULL) {
				trav = &VH->data[*trav].left;
			}
			
			temp = *trav;
			VH->data[*T].elem = VH->data[temp].elem;
			
			*trav = VH->data[temp].right;
			VH->data[temp].left = VH->avail;
			VH->data[temp].right = VH->avail;
			VH->avail = temp;
		}
		return;
	}
	return (VH->data[*T].elem < x) ? deleteElemRecursive(&VH->data[*T].right, VH, x) : deleteElemRecursive(&VH->data[*T].left, VH, x);
}
