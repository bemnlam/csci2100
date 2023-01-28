#include <stdio.h>
#include <string.h>

void main(){
	typedef struct matrix_t Matrix;
	struct matrix_t{
		int x;
		int y;
		char **c;
	};
	
	int x = 0;
	int y = 0;

	Matrix M;
		M.x = 0;
		M.y = 0;
		M.c = (char*)malloc(sizeof(char *));

	while(1){
		M.c[y] = (char*)malloc(sizeof(char));
		if(!strcmp(gets(M.c[y]),"print"))
			break;
		M.y++;
		M.x = strlen(M.c[y]);
		printf("L=%d; Y=%d\n%s\n", M.x, M.y, M.c[y]);
	}

	for(y=0; y<M.y-1; y++){
		//for(x=0; x<M.x; x++)
			printf("%s\n",M.c[1]);
	}
	
	//system("pause");
	return;
}