#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _Node {
		int word_end:1;
		struct _Node* branch[26];
} Node;


int i,j,k;
Node root;
Node* cnp;
char temp[81];


void outputText(Node* pointer, int depth) {
    int i;
    static Node* printed = NULL;

    for (i=0; i<26; i++) {
        Node* next = pointer->branch[i];
        if (next==NULL) {
            continue;
        }
            
        if (printed!=NULL && printed->word_end) {
            for (k = 0; k < depth; k++) {
                printf(" ");
            }
        }

        printf("%c", (char) i + 'a');
        printed = next;

        if (next->word_end) {
            printf("\n");
        }

        outputText(next, depth+1);
    }        
}

int main() {
	printf("Type only letters and empty spaces, finished by #:\n");
	//initializing the root to all NULL
	for (i=0; i<26; i++) {
		root.branch[i] = NULL;
		//root.word_end = 0;
	}
	//accept the inout one by one
	while(1){
		//get word one by one
		scanf("%s", &temp);
		//convert all to lowercase
		for(i=0; i<strlen(temp); i++) {
			temp[i] = toupper(temp[i]);
		}
		//end when input BYE
		if(strcmp(temp,"#")==0) {
			break;
		}
		//make the poiner point to the root
		cnp = &root;
		//looping and store the word
		for(i=0; i<strlen(temp); i++) {
			
			if(!cnp->branch[temp[i]-'a']) {	
				cnp->branch[temp[i]-'a'] = (Node*) malloc(sizeof(Node));
				cnp->branch[temp[i]-'a'] -> word_end = 0;
				for(j=0; j<26; j++) {
					cnp->branch[temp[i]-'a']->branch[j]=NULL;
					cnp->branch[temp[i]-'a']->word_end = 0;
				}
				
			}
			
			cnp = cnp->branch[temp[i]-'a'];
		}
		cnp->word_end = 1;
	}
	
	cnp = &root;
	outputText(cnp, 0);
	printf("\n");
	return 0;

}
 
