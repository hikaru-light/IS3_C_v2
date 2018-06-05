#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define HSIZE 997

struct cell {
	char *pcode;
	char *addr;
	struct cell *p_next;
	struct cell *a_next;
};

struct cell *p_hstab[HSIZE];
struct cell *a_hstab[HSIZE];

int sum(char *x) {
	int sum = 0;
	while(*x) {
		sum += (int)(*x);
		x++;
	}

	return sum;
}

int p_hash(char *pcode) {
    	return atoi(pcode) % HSIZE;
}

int a_hash(char *addr) {
	return -(sum(addr) % HSIZE);
}

void p_search(struct cell *p_hstab, char *x) {
	if(p_hstab == NULL) {
		printf("No Data\n");
		return;
	}

	if(strcmp(p_hstab->pcode, x) == 0){
		printf("%s\n", p_hstab->addr);
	} else {
		p_search(p_hstab->p_next, x);
	}
}

void a_search(struct cell *a_hstab, char *x) {
	if(a_hstab == NULL) {
		printf("No Data\n");
		return;
	}

	if(strcmp(a_hstab->addr, x) == 0){
		printf("%s\n", a_hstab->pcode);
	} else {
		a_search(a_hstab->a_next, x);
	}
}

void show(struct cell *hstab) {
	if(hstab == NULL) {
		printf("\n");
		return;
	}

	printf("%s %s\n", hstab->pcode, hstab->addr);
	show(hstab->a_next);
}

struct cell* p_add(struct cell *p_hstab, char *p, char *a) {
	struct cell *tmp;
	tmp = malloc (sizeof(struct cell));

	tmp -> pcode = p;
	tmp -> addr = a;
	tmp -> p_next = p_hstab;

	return tmp;
}

struct cell* a_add(struct cell *a_hstab, char *p, char *a) {
	struct cell *tmp;
	tmp = malloc (sizeof(struct cell));

	tmp -> pcode = p;
	tmp -> addr = a;
	tmp -> a_next = a_hstab;

	return tmp;
}

int main(int argc , char **argv) {
	for(int i=0; i<HSIZE; i++) {
		p_hstab[i] = NULL;
		a_hstab[i] = NULL;
	}

	FILE *f;
	f = fopen("postal.txt", "r");

	while(1) {
		char *p_buf = malloc(sizeof(char)*128);
		char *a_buf = malloc(sizeof(char)*128);

		int d = fscanf(f, "%s %s", p_buf, a_buf);
		if(d == EOF) break;

		int p_val = p_hash(p_buf);
		p_hstab[p_val] = p_add(p_hstab[p_val], &p_buf[0], &a_buf[0]);

		int a_val = a_hash(a_buf);
		a_hstab[a_val] = a_add(a_hstab[a_val], &p_buf[0], &a_buf[0]);

		//printf("%d\n", a_val);
		//show(a_hstab[a_val]);

		//usleep(100000);
	}

	// int i, length;
	// struct cell *p;
	//
	// for(i=0; i< HSIZE; i++){
	// 		length = 0;
	// 		p = p_hstab[i];
	// 		while(p!=NULL){
	// 				length++;
	// 				p = p->p_next;
	// 		}
	// 		printf("%d\n\n",length);
	// }

	while(1) {
			char *tmp = malloc(sizeof(char)*128);
			int d = scanf("%s", tmp);
			if(d == EOF) break;

			if(sum(tmp) < 0) {
				int a_val = a_hash(tmp);
				a_search(a_hstab[a_val], tmp);
			} else {
				int p_val = p_hash(tmp);
				p_search(p_hstab[p_val], tmp);
			}

			printf("\n");
	}
}
