#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char * argv[]){

	int f1 = 1;
	int f2 = 1;
	int f = 0;
	int i = 0;

	if(argc != 2){
		printf("ERROR! requires user to input one arg\n");
		exit(1);
	}

	int input = atoi(argv[1]);
	const int SIZE = 4096;
	const char *name = "Fibonacci";
	int shm_fd;
	void *ptr;
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	int sizeofint = sizeof(int)*3+2;
	char a[sizeofint];
	sprintf(a,"%d",f1);
	sprintf(ptr,"%s",a);
	ptr += strlen(a);
	sprintf(ptr,",");
	ptr += strlen(",");
	char b[sizeofint];
	sprintf(b, "%d", f2);
	sprintf(ptr, "%s", b);
	ptr += strlen(b);
	sprintf(ptr, ",");
	ptr += strlen(",");

	for(i = 0; i < input; i++){
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		char xy[sizeofint];
		sprintf(xy, "%d", f);
		sprintf(ptr, "%s", xy);
		ptr += strlen(xy);

		if(i == input-1){
			sprintf(ptr,"\n");
			return 0;	
		}
	sprintf(ptr, ",");
	ptr += strlen(",");
	}
	return 0;
}




