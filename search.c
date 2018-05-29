#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HSIZE 17

struct cell {
	char *pcode;
	char *addr;
	struct cell *p_next;
	struct cell *a_next;
};

struct cell *p_hstab[HSIZE];
struct cell *a_hstab[HSIZE];

int p_hash(char *pcode) {
    	int num = atoi(pcode) % HSIZE;
	return num;
}

//int a_hash(char *addr) {
//
//}

//void search(char *x) {
//
//}

void show(struct cell *hstab){
	if(hstab == NULL) {
		printf("\n");
		return;
	}

	printf("%s %s\n", hstab->pcode, hstab->addr);
	show(hstab->p_next);
}

struct cell* add(struct cell *hstab, char *p, char *a) {
	struct cell *tmp;
	tmp = malloc (sizeof(struct cell));

	tmp -> pcode = p;
	tmp -> addr = a;
	tmp -> p_next = hstab;

	return tmp;
}

int main() {
	for(int i=0; i<HSIZE; i++) {
		p_hstab[i] = NULL;
	}

	FILE *f;
	f = fopen("postal.txt", "r");

	while(1) {
		char *p_buf = malloc(sizeof(char)*128);
		char *a_buf = malloc(sizeof(char)*128);
		
		int d = fscanf(f, "%s %s", p_buf, a_buf);
		if(d == EOF) break;
		
		int p_val = p_hash(p_buf);
		p_hstab[p_val] = add(p_hstab[p_val], &p_buf[0], &a_buf[0]);
		
		printf("%d\n", p_val);
		show(p_hstab[p_val]);
		usleep(200000);
	}
}

