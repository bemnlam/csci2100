#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct P person;
struct P {
	char name[25];
	person* X;
	person* Y;
};

person* find(char* head, person* ptr){
	for(;ptr->X!=NULL;ptr=ptr->X){
		if(!(strcmp(ptr->name, head))){
			return ptr;
		}
		if(ptr->Y!=NULL){
			find(head, ptr=ptr->Y);
		}
	}
};

void hire(char* head,char* crew,person* ptr){
	person* p0,*p1;
	p0 = find(head, ptr);
	
	if(p0->Y==NULL){//for empty LL
		p0 = (person*)malloc(sizeof(person));
		strcpy(p0->name, crew);
		printf("\t[crew:%s\n]",p0->name);
	}else{
		//for non-empty LL
		while(p0->X!=NULL){
			p0 = p0->X;
		}
		p0->X = (person*)malloc(sizeof(person));
		p1 = p0->X;
		strcpy(p1->name,crew);
		printf("\t[crew:%s\n]",p1->name);
	}
	return;
};


void fire(char* crew,person* ptr){
	person* p0;
	p0 = find(crew, ptr)->Y;
	if(p0->Y==NULL){
		
	}
	return;
};



//void print(person* ptr);
/*
void insert(char head,person* ptr){
	if(ptr->Y==NULL){
		ptr->Y = malloc(sizeof(ptr));
		ptr = ptr->Y;
		strcpy(ptr->name, head);
		printf("[inserted]\n");
	}
};
*/

int main() {
	char line[60];
	char a[25];
	char b[25];
	char c[10];

	int i = 0;
	int w = -1;

	person P;
	person* p;
	person* p0;
	person* p1;

	//create a structure containing the person...
	strcpy(P.name, "#HEADER#");
	P.X = NULL;
	P.Y = NULL;
	//use a pointer to point the HEADER node...
	p = &P;
	p0 = (person*)malloc(sizeof(person));
	P.Y = p0;
	//now p0 will be the mpty boss now.
	while(gets(line)){
		w=-1;
		
		w = sscanf(line, "%s%s%s", a, b, c);
		puts(line);
		printf("w=%d\n", w);
		
		switch (w)
		{
			case 3:		puts(c);	//X hires Y;
			case 2:		puts(b);	//fire sbd;
			case 1:		puts(a);	//print;
			break;
		}
		
		if(w==1){
			if(!strcmp(a, "print")){
				printf("------------------------------------------------------------\n");
				printf("print the tree...\n");
					print(p);
				printf("------------------------------------------------------------\n");
			}
			else{
				printf("------------------------------------------------------------\n");
				printf("name inserted...\n");
					strcpy(p0->name, a);
				printf("------------------------------------------------------------\n");
			}
		}
		else if(w==2){
			printf("------------------------------------------------------------\n");
			printf("fired...\n");
				//fire(p);
			printf("------------------------------------------------------------\n");
		}
		else if(w==3){
			printf("------------------------------------------------------------\n");
			printf("hires...\n");
				hire(a,b,p);
			printf("------------------------------------------------------------\n");
		}


		printf("\n");
	}

	printf("\n");
	system("pause");
	return 0;
}
