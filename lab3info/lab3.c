#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

typedef struct P person;
struct P {
        char name[26];
        int Xnext;
        int Xprev;
        int Ynext;
        int Yprev;
};
//the company tree...
person A[N];
int i = 0;
int j = 0;
//stack...
int S[N];
int si = N;

int find(char* p){
    int l = 0;
    //assume must find
    for(l=0;l<N;l++){
        if(!strcmp(A[l].name,p)){
            break;
        }
    }
    return l;
}

int fire(char* crew){
        int l = find(crew);
        if(A[l].Ynext<0 && A[l].Xnext<0){
                strcpy(A[l].name, "~");
                S[si++] = l;
                if(A[l].Yprev>=0){
                        A[A[l].Yprev].Ynext = -1;
                }else{
                        A[A[l].Xprev].Xnext = -1;
                }
                A[l].Xnext = -1;
                A[l].Xprev = -1;
                A[l].Ynext = -1;
                A[l].Yprev = -1;
                return 0;
        }
        while(A[l].Ynext>0){
                strcpy(A[l].name, A[A[l].Ynext].name);
                l=A[l].Ynext;
        }
		S[si++] = l;		
        if(A[l].Xnext>0){
                if(A[l].Yprev<0){
                    A[A[l].Xprev].Xnext = A[l].Xnext;
                    A[A[l].Xnext].Xprev = A[l].Xprev;
                }else{
					A[A[l].Yprev].Ynext = A[l].Xnext;
					A[A[l].Xnext].Yprev = A[l].Yprev;
					A[A[l].Xnext].Xprev = -1;
				}

        }else{
			A[A[l].Yprev].Ynext = -1;
		}
		strcpy(A[l].name, "~");
        A[l].Xnext = -1;
        A[l].Xprev = -1;
        A[l].Ynext = -1;
        A[l].Yprev = -1;
        return 0;
}
int hires(char* head, char* crew, int j){
        int l,m;
        strcpy(A[j].name, crew);
        if(!strcmp(head," ")){
				A[j].Xnext = -1;
				A[j].Xprev = -1;
				A[j].Ynext = -1;
				A[j].Yprev = -1;
                return 0;
        }
        l=find(head);
        m=A[l].Ynext;
        if(m>0){
                while(A[m].Xnext>0)
                    m=A[m].Xnext;
                A[m].Xnext = j;
                A[j].Xprev = m;
        }else{
                A[j].Yprev = l;
                A[l].Ynext = j;
                A[j].Xprev = -1;
        }
        return 0;
}
int print(int i, int lvl){
        int j;
        int l;
        l=lvl+1;
        if(strcmp(A[i].name,"~"))
                puts(A[i].name);
        if(A[i].Ynext>0){
                for(j=0;j<=lvl;j++){
					printf("+");
                }
                print(A[i].Ynext,l);
        }
        if(A[i].Xnext>0){
                for(j=0;j<lvl;j++){
					printf("+");
                }
                print(A[i].Xnext,lvl);
        }
        return 0;
}

int main(){
        char line[80];
        char a[26];
        char b[26];
        char c[26];
        int w = -1;

        //initializing A[] and S[]
        for(i=0;i<N;i++){
                strcpy(A[i].name,"~");
                A[i].Xnext = A[i].Xprev = A[i].Ynext = A[i].Yprev = -21101;
                S[i] = N-1-i;
        }
        //loop for input
        while(gets(line)){
                w = -1;
                w = sscanf(line, "%s%s%s", a, b, c);
                if(w==1){
                        if(!strcmp(a, "print")){
                                print(0,0);
                                printf("------------------------------------------------------------\n");
                        }
                        else{
                                hires(" ", a, S[--si]);
                        }
                }
                else if(w==2){
					fire(b);
                }
                else if(w==3){
					hires(a,c,S[--si]);
                }

        }
        return 0;
}
