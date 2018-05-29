#include <stdio.h>
#include <stdlib.h>

struct cell {
	int item;
	struct cell *next;
};

struct cell* next(struct cell *ptr) {
	return ptr->next;
}

void printList(struct cell *ptr) {
	if(ptr == NULL) {
		printf("\n");
		return;
	}

	printf("%d ", ptr->item);
		// if(ptr->next) {
		 	printList(ptr->next);
		// }
}

struct cell* push(int data, struct cell *ptr) {
	struct cell *p;
	p = malloc(sizeof(struct cell));

	p->item = data;
	p->next = ptr;

	return p;
}

struct cell* pop(struct cell *ptr) {
	struct cell *p;
	p = ptr->next;

	free(ptr);

	return p;
}

struct cell* nconc(struct cell *ptr1, struct cell *ptr2) {
	while(ptr1->next) {
		next(ptr1->next);
	}

	ptr1->next = ptr2;

	return ptr1;
}

struct cell* reverse(struct cell *ptr) {
	struct cell *p;
	p = NULL;

	while(ptr) {
		p = push(ptr->item, p);
		ptr = ptr->next;
	}

	return p;
}

int main() {
	struct cell *pl, *res;

	pl = NULL;
	pl = push(3,pl);
	pl = push(2,pl);
	pl = push(1,pl);

	printList(pl);

	res = reverse(pl);
	printList(res);
}
