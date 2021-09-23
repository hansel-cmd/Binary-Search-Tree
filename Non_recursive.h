#ifndef Non_recursive_H
#define Non_recursive_H


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

#endif