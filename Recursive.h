#ifndef Recursive_H
#define Recursive_H


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



#endif
