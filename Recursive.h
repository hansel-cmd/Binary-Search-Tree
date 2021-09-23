#ifndef Recursive_H
#define Recursive_H


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


#endif