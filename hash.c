#include <stdio.h>

struct cell {
	int num;
	char *name;
	struct cell *next;
};

struct cell* table[26];

int hash(char *na) {
	int temp = (int)*na - 65;
	return temp;
}

void push(int no, char *na) {
	int hsh = hash(na);

	struct cell *temp;
	temp = malloc(sizeof(cell));
	temp->num = no; temp->name = na;

	table[hsh]->next = temp;
}

int main() {
	push(100000, "Aozora");
}
