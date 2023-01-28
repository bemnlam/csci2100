#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 18959 //a primeE
#define WORD_SIZE 51

int i,j,k; //the counters
int boolean; //act as boolean

//a linklist node



typedef struct TABLE {
		char word[51];
		struct Hash* next;
} Hash;

typedef struct DICT {
		//int index[HASH_SIZE];
		struct Hash* index[HASH_SIZE];
} Dict;


Dict dictionary;

Hash table;
Hash *dict;

dict = (Hash*)malloc(sizeof(struct TABLE)*HASH_SIZE);

void hash_func(char* input) {
	int tmpcode;
	Hash *ptr;
	printf("%s\t", input);
	if(strlen(input)>=3){
		//for(i=0; i<3; i++){
			tmpcode = ((input[strlen(input)-1]-96)*(input[strlen(input)-2]-96)*(input[strlen(input)-3]-96))%HASH_SIZE;
			printf("%d\t", input[strlen(input)-1]-96);
			printf("%d\t", input[strlen(input)-2]-96);
			printf("%d\t", input[strlen(input)-3]-96);
			printf("%d\t", tmpcode);
			
			//add item
			//ptr = (Hash*)malloc(sizeof(table));
			if(dictionary.index[tmpcode]==NULL){
				dictionary.index[tmpcode].next = (Hash*)malloc(sizeof(table));
			}
				
			//printf("\n");
		//}
	}
}



int main() {	
	char c;
	char temp[51];
	
	//hash table[HASH_SIZE];
	
	//dictionary...
	
	//Initializing the Dict.
	for(i=0; i<HASH_SIZE; i++){	
		dictionary.index[i] = NULL;
	}
	
	//input the words
	while(1){
		scanf("\n%s: ", &temp);
		if(strcmp(temp, "#")==0)
		{
			break;
		}
		for(i=0; i<strlen(temp); i++)
		{
			temp[i] = tolower(temp[i]);
		}		
		hash_func(temp);
		//printf("%s\n", temp);	
	}
	
	
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////

	//input...
	while(1){
		i=-1;
		if(scanf("%c",&c)==EOF){ break;	}
			while( (c>=65&&c<=90) || (c>=97&&c<=122) ){
				c=tolower(c);
				if(c>96&&c<123){
					temp[++i] = c;
					scanf("%c",&c);
				}else{
					break;
				}
			}
			temp[++i]='\0';
			//i=-1;
			if(strlen(temp)>0){
				printf("[%s]\n",temp);
				//checking the vaildity of te word...
			}
	}

	return 0;
}
