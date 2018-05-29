#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	struct node *left;
	struct node *right;
};

struct node* create(int num, struct node *lef, struct node *rig) {
	struct node *temp;
	temp = malloc(sizeof(struct node));

	temp->item = num;
	temp->left = lef; temp->right = rig;

	return temp;
}

void print(struct node *root) {
	printf("(%d, ", root->item);

	if(root->left) {
		print(root->left);
	} else {
		printf("(NULL, ");
	}

	if(root->right) {
		print(root->right);
	} else {
		printf("NULL)");
	}
}

int main() {
	struct node *root;

	root = create(3, NULL, NULL);
	root = create(8, root, NULL);
	root = create(7, create(5, NULL, NULL), root);

	print(root);
}

