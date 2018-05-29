#include <stdio.h>
#include <stdlib.h>

int main() {
	// char buf[1024];
	//
	// FILE *f;
	// f = fopen("postal.txt", "r");
	//
	// while(1) {
	// 	int d = fscanf(f, "%s", buf);
	// 	if(d == EOF) break;
	// 	printf("%s\n", buf);
	// }

	char tmp[32];
	scanf("%s", tmp);
	printf("%s\n", tmp);
	printf("%ld\n", strtol(tmp, NULL, 10));
}
