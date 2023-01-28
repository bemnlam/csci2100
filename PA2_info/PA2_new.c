#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 150001
#define SIZEtmpString 500
#define SIZEwrong 500

//use unsigned int to make the hash table; size 10007
int i,c;
int crash = 0;
char dict[SIZE][50];


int code(char *input, int size)
{	
	int i, tmpcode, mod;
	tmpcode = 0;
	if(strlen(input)>=3)
		{	
			
			//printf("%c", input[strlen(input)-3]);
			//printf("%c", input[strlen(input)-2]);
			//printf("%c\n", input[strlen(input)-1]);
			for(i=0; i<3; i++){
				tmpcode = (input[strlen(input)-(i+1)]+tmpcode)*27;
				//printf("[%d] = %d, %d\t", i,tmpcode, (input[strlen(input)-(i+1)]));
			}
			mod = tmpcode%size;
			//printf("code= %d\n", tmpcode%size);
			
			c=0;
			while(1){
				if(strcmp(dict[mod], "#")==0){
					strcpy(dict[mod], input);
				//	printf("inserted\n");
					break;
				}
				else
				{	
					mod = (mod+1)%size;
					//printf("|CRASHED| ");
					c++;
				}
				
			}
			if(c>crash){ crash = c; };
			c=0;
		}
		else
		{
			//printf("%s\n", input);
			for(i=0; input[i]!='\0'; i++){
				tmpcode = (input[strlen(input)-(i+1)]+tmpcode)*27;
				//printf("[%d] = %d, %d\t", i,tmpcode, (input[strlen(input)-(i+1)]));
			}
			//printf("code= %d\n", tmpcode%size);
			strcpy(dict[tmpcode%size], input);
		}
}

int main(void)
{
	char tmpString[SIZEwrong];
	char wrongWord[SIZEtmpString][50];
	char *pch;
	int i,tmpcode,insert, wrong;
	char temp[51];
	
	insert = 0;
	for(i=0; i<SIZE; i++)
	{
		strcpy(dict[i],"#");
		if(i<SIZEwrong){
			strcpy(wrongWord[i],"#");
		}
	}
	//printf("HelloWorld\n");


	
	while(1){
		scanf("\n%s: ", &tmpString);
		if(strcmp(tmpString, "#")==0)
		{
			break;
		}
		for(i=0; i<strlen(tmpString); i++)
		{
			tmpString[i] = tolower(tmpString[i]);
		}
		
		code(tmpString, SIZE);		
	}

	//ptint out the dictionary
	/*
	for(i=0; i<SIZE; i++)
		{	
			//printf(">%d:\t",i);
			if(!(strcmp(dict[i],"#")==0)) {
				printf("%s\n",dict[i]);
			}
			//printf("",i);
		}
	*/
	//printf("=====================================\n");
	//printf("max. time of crash = %d\n", crash);
	//printf("dictionary end\n");
	//printf("=====================================\n");
	

	while (fgets(tmpString,sizeof(tmpString),stdin)!=NULL){
	//while(1){
		gets (tmpString);
		//printf("tmpString= %s\n", fgets(tmpString,sizeof(tmpString),stdin));
		//if(strcmp(tmpString, "#")==0)
		//{
			//printf("end by #\n");
		//break;
			
		//}
		//do the comparision here...
		printf("gets: %s\n",tmpString);
		pch = strtok (tmpString, ": ~`!@#$%^&*()_-+=|\\{[}]\';?/>.<,1234567890");
		
		while (pch != NULL)
		{
			for(c=0; c<strlen(pch); c++)
			{
				pch[c] = tolower(pch[c]);
			}
			
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
			if(!(strlen(temp)>0)){
				//printf("[%s]\n",temp);
			
		
		if(strlen(temp)>=3){
				tmpcode = 0;
				for(i=0; i<3; i++){
					tmpcode = (temp[strlen(temp)-(i+1)]+tmpcode)*27;
				}
				wrong=1;
				for(i=0; i<=crash; i++){
					if(strcmp(dict[tmpcode%SIZE+i],temp)==0){
						wrong=0;
						break;
					}
				}
				if(wrong){
					i=1;
					//printf("%d: %s\n",insert,pch);
					for(c=0; c<=insert; c++){
						if(strcmp(temp, wrongWord[c])==0){
							//printf(">repeated\n");
							i=0;
						}
					}
					if(i){
						//printf("str added.\n");
						strcpy(wrongWord[insert],temp);
						insert++;
					}
					
					i=1;
				}
			}else{
				tmpcode = 0;
				for(i=0; temp[i]!='\0'; i++){
					tmpcode = (temp[strlen(temp)-(i+1)]+tmpcode)*27;
					//printf("[%d] = %d, %d\t", i,tmpcode, (input[strlen(input)-(i+1)]));
				}
				wrong=1;
				
				
				for(i=0; i<=crash; i++){
					if(strcmp(dict[tmpcode%SIZE+i],temp)==0){
						wrong=0;
						break;
					}
				}
				
				if(wrong){
					i=1;
					//printf("%d: %s\n",insert,pch);
					for(c=0; c<=insert; c++){
						if(strcmp(temp, wrongWord[c])==0){
							//printf(">repeated\n");
							i=0;
						}
					}
					if(i){
						//printf("str added.\n");
						strcpy(wrongWord[insert],temp);
						insert++;
					}
					
					i=1;
				}
			}
		
		}
		
		
		
		
		
		
		
		
	}
			pch = strtok (NULL, ": ~`!@#$%^&*()_-+=|\\{[}]\'\";?/>.<,1234567890");
			
		}
	}
	//printf("\nList of Wrong Words\n");	
	
	//getche();strcmp(wrongWord[c],"#")!=0
	for(c=0; strcmp(wrongWord[c],"#")!=0; c++){
		if(strcmp(wrongWord[c],"\n")!=0)
			printf("%s\n",wrongWord[c]);
	}
	return 0;
}

 
