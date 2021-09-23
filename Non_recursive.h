#ifndef Non_recursive_H
#define Non_recursive_H


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


#endif