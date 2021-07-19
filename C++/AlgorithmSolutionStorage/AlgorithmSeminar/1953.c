#include <stdio.h>
#include <stdlib.h>
typedef struct treenode {
	int key;
	struct treenode* leftchild;
	struct treenode* rightchild;
	struct treenode* parent;
}treenode;

int height(treenode* root)
{
	if (root == NULL) return -1;
	else return max(height(root->leftchild), height(root->rightchild)) + 1;
}
int  balance_check(treenode* node)
{
	int height_diff;
	int count = 0;

	height_diff = height(node->leftchild) - height(node->rightchild);
	if (height_diff < -1 || height_diff > 1) return 1;

	return 0;
}
treenode* balance_check_node(treenode* node)
{
	int height_diff;
	treenode* z = node;
	int count = 0;
	while (z != NULL)
	{
		height_diff = height(z->leftchild) - height(z->rightchild);
		if (height_diff < -1 || height_diff > 1) return z;
		z = z->parent;
	}
	return z;
}
treenode* balance(treenode* z)
{
	treenode* y;
	treenode* x;
	treenode* t2;
	treenode* t3;
	int rotate_case = 0;
	if (height(z->leftchild) > height(z->rightchild)) y = z->leftchild;
	else y = z->rightchild;

	if (height(y->leftchild) > height(y->rightchild)) x = y->leftchild;
	else x = y->rightchild;

	printf("rotate among %d %d %d \n", z->key, y->key, x->key);

	if (z->rightchild == y && y->rightchild == x) rotate_case = 1;
	if (z->leftchild == y && y->leftchild == x) rotate_case = 2;
	if (z->rightchild == y && y->leftchild == x) rotate_case = 3;
	if (z->leftchild == y && y->rightchild == x) rotate_case = 4;

	printf("rotate case %d\n", rotate_case);
	if (rotate_case == 1)
	{
		t2 = y->leftchild;
		y->leftchild = z;
		z->rightchild = t2;

		y->parent = z->parent;
		z->parent = y;
		if (t2 != NULL) t2->parent = z;
		return y;
	}
	if (rotate_case == 2)
	{
		t3 = y->rightchild;
		y->rightchild = z;
		z->leftchild = t3;

		y->parent = z->parent;
		z->parent = y;
		if (t3 != NULL) t3->parent = z;
		return y;
	}
	if (rotate_case == 3)
	{
		t2 = x->leftchild;
		t3 = x->rightchild;

		x->leftchild = z;
		x->rightchild = y;
		z->rightchild = t2;
		y->leftchild = t3;

		x->parent = z->parent;
		if (t2 != NULL) t2->parent = z;
		if (t3 != NULL) t3->parent = y;
		return x;
	}
	if (rotate_case == 4)
	{
		t2 = x->leftchild;
		t3 = x->rightchild;
		x->leftchild = y;
		x->rightchild = z;

		y->rightchild = t2;
		z->leftchild = t3;

		x->parent = z->parent;
		if (t2 != NULL) t2->parent = y;
		if (t3 != NULL) t3->parent = z;
		return x;
	}
	return z;
}
treenode* rootnode(treenode* root, int key) {
	if (root != NULL)return root;
	root = (treenode*)malloc(sizeof(treenode));
	root->key = key;
	root->leftchild = root->rightchild = NULL;
	root->parent = NULL;
	return root;
}
treenode* insertAVL(treenode* root, int key)
{
	if (root == NULL) root = rootnode(root, key);
	else
	{
		if (root->key == key) printf("already exist");
		treenode* newnode = (treenode*)malloc(sizeof(treenode));
		newnode->key = key;
		newnode->leftchild = NULL;
		newnode->rightchild = NULL;
		if (root->key > key)
		{
			if (root->leftchild == NULL)
			{
				root->leftchild = newnode;
				return root;
			}
			root->leftchild = insertAVL(root->leftchild, key);
			if (balance_check(root->leftchild) != 0)
			{
				root->leftchild = balance(root->leftchild);
			}
		}
		if (root->key < key)
		{
			if (root->rightchild == NULL)
			{
				root->rightchild = newnode;
				return root;
			}
			root->rightchild = insertAVL(root->rightchild, key);
			if (balance_check(root->rightchild) != 0)
			{
				root->rightchild = balance(root->rightchild);
			}

		}
	}
	if (balance_check(root) != 0)
	{
		root = balance(root);
	}
	return root;

}
treenode* getparent(treenode* root, int key)
{
	if (root == NULL || root->key == key) printf("not exist");
	else
	{
		if ((root->leftchild != NULL && root->leftchild->key == key) ||
			(root->rightchild != NULL && root->rightchild->key == key))
		{
			return root;
		}
		else if (root->key > key) return getparent(root->leftchild, key);
		else return getparent(root->rightchild, key);
	}
	return root;
}
treenode* leftmost(treenode* root)
{
	if (root->leftchild == NULL) return root;
	else return leftmost(root->leftchild);
}

treenode* get(treenode* root, int key)
{
	if (root == NULL || root->key == key)
	{
		if (root == NULL) printf("not exist");
		return root;
	}
	else if (root->key > key) return get(root->leftchild, key);
	else return get(root->rightchild, key);
}
treenode* deleteAVL(treenode* root, int key)
{
	treenode* deletenode = get(root, key);
	if (deletenode == NULL) return root;

	treenode* parentnode = NULL;
	if (deletenode != root) parentnode = getparent(root, key);

	if (deletenode->leftchild == NULL)
	{
		if (parentnode == NULL) root = deletenode->rightchild;
		else
		{
			if (parentnode->leftchild == deletenode) parentnode->leftchild = deletenode->rightchild;
			if (parentnode->rightchild == deletenode) parentnode->rightchild = deletenode->rightchild;
		}
		treenode* z = balance_check_node(parentnode);
		if (z != NULL)
		{
			z = balance(z);
			while (z->parent != NULL) z = z->parent;
			return z;
		}

		free(deletenode);
		return root;
	}
	else if (deletenode->rightchild == NULL)
	{
		if (parentnode == NULL) root = deletenode->leftchild;
		else
		{
			if (parentnode->leftchild == deletenode) parentnode->leftchild = deletenode->leftchild;
			if (parentnode->rightchild == deletenode) parentnode->rightchild = deletenode->leftchild;
		}
		treenode* z = balance_check_node(parentnode);
		if (z != NULL)
		{
			z = balance(z);
			while (z->parent != NULL) z = z->parent;
			return z;
		}

		free(deletenode);
		return root;
	}
	else
	{
		treenode* u = leftmost(deletenode->rightchild);
		int temp_key = u->key;
		root = deleteAVL(root, u->key);
		deletenode->key = temp_key;
		treenode* z = balance_check_node(parentnode);
		if (z != NULL)
		{
			z = balance(z);
			while (z->parent != NULL) z = z->parent;
			return z;
		}

		free(deletenode);
		return root;
	}
	return root;
}
treenode* insertBST(treenode* root, int key)
{
	if (root == NULL) root = rootnode(root, key);
	else
	{
		if (root->key == key) printf("already exist");
		treenode* newnode = (treenode*)malloc(sizeof(treenode));
		newnode->key = key;
		newnode->leftchild = NULL;
		newnode->rightchild = NULL;
		if (root->key > key)
		{
			if (root->leftchild == NULL)
			{
				root->leftchild = newnode;
				return root;
			}
			root->leftchild = insertBST(root->leftchild, key);
		}
		if (root->key < key)
		{
			if (root->rightchild == NULL)
			{
				root->rightchild = newnode;
				return root;
			}
			root->rightchild = insertBST(root->rightchild, key);
		}
	}
	return root;

}
treenode* deleteBST(treenode* root, int key)
{
	treenode* deletenode = get(root, key);
	if (deletenode == NULL) return root;

	treenode* parentnode = NULL;
	if (deletenode != root) parentnode = getparent(root, key);

	if (deletenode->leftchild == NULL)
	{
		if (parentnode == NULL) root = deletenode->rightchild;
		else
		{
			if (parentnode->leftchild == deletenode) parentnode->leftchild = deletenode->rightchild;
			if (parentnode->rightchild == deletenode) parentnode->rightchild = deletenode->rightchild;
		}
		free(deletenode);
		return root;
	}
	else if (deletenode->rightchild == NULL)
	{
		if (parentnode == NULL) root = deletenode->leftchild;
		else
		{
			if (parentnode->leftchild == deletenode) parentnode->leftchild = deletenode->leftchild;
			if (parentnode->rightchild == deletenode) parentnode->rightchild = deletenode->leftchild;
		}
		free(deletenode);
		return root;
	}
	else
	{
		treenode* u = leftmost(deletenode->rightchild);
		int temp_key = u->key;
		root = deleteBST(root, u->key);
		deletenode->key = temp_key;
		return root;
	}
	return root;
}
void print_preorder(treenode* root) {
	if (root == NULL)return;
	printf("%d ", root->key);
	print_preorder(root->leftchild);
	print_preorder(root->rightchild);
}
void print_inorder(treenode* root) {
	if (root == NULL)return;
	print_inorder(root->leftchild);
	printf("%d ", root->key);
	print_inorder(root->rightchild);
}

/*
Returns the cost of finding the node using tree's depth
*/
int search_cost(treenode* root, int depth) {	
	if (root == NULL)return 0;
	printf("cost to find %d: %d\n", root->key,depth);
	return search_cost(root->leftchild,depth+1) + search_cost(root->rightchild,depth+1)+depth;
	//Returns the costs of the left subtree and right subtree plus its own cost
}
int main() {
	treenode* AVLroot = NULL;
		treenode *BSTroot=NULL;
	AVLroot = insertAVL(AVLroot, 1);
	AVLroot = insertAVL(AVLroot, 2);
	AVLroot = insertAVL(AVLroot, 3);
	AVLroot = insertAVL(AVLroot, 4);
	AVLroot = insertAVL(AVLroot, 5);
	AVLroot = insertAVL(AVLroot, 6);
	AVLroot = insertAVL(AVLroot, 7);
	printf("preorder: ");
	print_preorder(AVLroot); printf("\n");
	printf("inorder: ");
	print_inorder(AVLroot); printf("\n");
	printf("Cost of traversing all children of AVL tree: %d\n\n",search_cost(AVLroot,0));


	BSTroot = insertBST(BSTroot, 1);
	BSTroot = insertBST(BSTroot, 2);
	BSTroot = insertBST(BSTroot, 3);
	BSTroot = insertBST(BSTroot, 4);
	BSTroot = insertBST(BSTroot, 5);
	BSTroot = insertBST(BSTroot, 6);
	BSTroot = insertBST(BSTroot, 7);
	printf("preorder: ");
	print_preorder(BSTroot); printf("\n");
	printf("inorder: ");
	print_inorder(BSTroot); printf("\n");
	printf("Cost of traversing all children of BST tree: %d\n\n", search_cost(BSTroot, 0));


	return 0;
}