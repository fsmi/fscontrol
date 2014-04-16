#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void debug(char* message) {

	if (getenv("FS_OPEN_DEBUG")) {
		printf("INFO: %s\n", message);
	}
}

/**
 * shell function
 */
int main(int argc, char* argv[]) {

	char* path = getenv("FS_OPEN_FILE");


	if (path == NULL) {
		printf("Filepath not set. Use 'export FS_OPEN_FILE=<path>'.\n");
		return 1;
	}
	debug(path);
	if (argc < 2) {
		FILE* open = fopen(getenv("FS_OPEN_FILE"), "r");
		
		if (open == NULL) {
			perror("open()");
			return 2;
		}
		
		if (feof(open)) {
			printf("Error in file\n");
			return 3;
		}
		char c = fgetc(open);
		fclose(open);
		
		if (c == '1') {
			printf("open\n");
		} else {
			printf("closed\n");
		}
	} else {
	
		char* input = argv[1];
		debug(input);
		
		FILE* open = fopen(getenv("FS_OPEN_FILE"), "w");
		
		if (open == NULL) {
			perror("open()");
			return 2;
		}
		
		if (strcmp(input, "open") == 0) {
			fputc('1', open);
		}
		else if (strcmp(input, "close") == 0) {
			fputc('0', open);
		} else {
			printf("Don't know what you mean: %s\n" , input);
		}
		
		fflush(open);
		fclose(open);
	}
	return 0;
}
