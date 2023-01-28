#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Mx, My, _x, _y, MIN;
//int **S = (int**) malloc(sizeof(int*)); //to store the temp shortest path
int cnt;
typedef struct location L;
struct location {
	int x;
	int y;
};
void print(char **M){
	
	int i;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(i=1; i<=My; i++){
		puts(M[i]);
	}
	return;
}

int findNode(char** Mat,int prevX, int prevY, int posX, int posY, char dir, int psum,L* Que){
	int waySum, wayN, wayS, wayE, wayW,i;
	waySum = wayN = wayS = wayE = wayW = 0;
	//psum++;
	if(dir=='N' || dir=='S'){
			waySum++;
		if(Mat[posY][posX+1]!='#')
			waySum++;
		if(Mat[posY][posX-1]!='#')
			waySum++;
	}
	if(dir=='W' || dir=='E'){
			waySum++;
		if(Mat[posY+1][posX]!='#')
			waySum++;
		if(Mat[posY-1][posX]!='#')
			waySum++;
	}
	/*if(Mat[posY+1][posX]!='#')
		waySum++;
	if(Mat[posY-1][posX]!='#')
		waySum++;
	if(Mat[posY][posX+1]!='#')
		waySum++;
	if(Mat[posY][posX-1]!='#')
		waySum++;
	//
	if(Mat[posY-1][posX]!='#' && Mat[posY+1][posX]!='#' && (Mat[posY][posX-1]=='#' && Mat[posY][posX+1]=='#'))
		waySum--;
	if(Mat[posY+1][posX]!='#' && Mat[posY-1][posX]!='#' && (Mat[posY][posX-1]=='#' && Mat[posY][posX+1]=='#'))
		waySum--;
	if(Mat[posY][posX-1]!='#' && Mat[posY][posX+1]!='#' && (Mat[posY-1][posX]=='#' && Mat[posY+1][posX]=='#'))
		waySum--;
	if(Mat[posY][posX+1]!='#' && Mat[posY][posX-1]!='#' && (Mat[posY-1][posX]=='#' && Mat[posY+1][posX]=='#'))
		waySum--;
	*/
	if(waySum>=2){
		if(Mat[posY][posX]=='O'){
			printf("Neo :(%d,%d);\n", posX, posY-1);
		}else{
			printf("node:(%d,%d);\n", posX, posY-1);
			psum +=  abs(prevX-posX)+abs(prevY-posY);
			printf("\t>plen: %d\n",abs(prevX-posX)+abs(prevY-posY));
			printf("\t>prev(%d,%d)\n", prevX,prevY-1);
			if(MIN<psum){
				//cnt=1;
				return 0;
			}
			prevX = posX;
			prevY = posY;
		}
		printf("\t>psum: %d\n", psum);
	}
	if(Mat[posY][posX]=='X'){		
		printf("exit:(%d,%d)\n", posX, posY-1);
		psum +=  abs(prevX-posX)+abs(prevY-posY);
		printf("\t>plen: %d\n", abs(prevX-posX)+abs(prevY-posY));
		printf("\t>prev(%d,%d)\n", prevX,prevY-1);
		printf("\t>paum: %d\n", psum);
		if(MIN>psum){
			MIN = psum;
			cnt = 1;
			Que[cnt].x = posX;
			Que[cnt].y = posY-1;
			cnt++;
			return 1;
		}else{
			return 0;
		}
	}/*else if(waySum==0 && Mat[posY][posX]!='O'){
		printf("deadend:(%d,%d)\n", posX, posY-1);
		printf("\t>psum: %d\n", psum);
		//cnt = 1;
		return 0;
	}*/
	//
	if(dir!='N' && Mat[posY+1][posX]!='#'){
		wayS = findNode(Mat, prevX, prevY, posX, posY+1,'S',psum,Que);
	}
	if(dir!='S' && Mat[posY-1][posX]!='#'){
		wayN = findNode(Mat, prevX, prevY, posX, posY-1,'N',psum,Que);
	}
	if(dir!='E' && Mat[posY][posX-1]!='#'){
		wayW = findNode(Mat, prevX, prevY, posX-1, posY,'W',psum,Que);
	}
	if(dir!='W' && Mat[posY][posX+1]!='#'){
		wayE = findNode(Mat, prevX, prevY, posX+1, posY,'E',psum,Que);
	}
	//
	if(wayE||wayS||wayN||wayW){
		if(cnt!=1 && (Que[cnt-1].x!=prevX || Que[cnt-1].y!=prevY-1)){
		Que[cnt].x = prevX;
		Que[cnt].y = prevY-1;
		cnt++;
		for(i=0;i<cnt;i++)
			printf("x:%d,y:%d\n", Que[i].x, Que[i].y);
		}
		return 1;
	}/*
	if(wayW){
		if(Que[cnt-1].x!=prevX || Que[cnt-1].y!=prevY-1){
		Que[cnt].x = prevX;
		Que[cnt].y = prevY-1;
		cnt++;
		}
		return 1;
	}if(wayN){
		if(Que[cnt-1].x!=prevX || Que[cnt-1].y!=prevY-1){
		Que[cnt].x = prevX;
		Que[cnt].y = prevY-1;
		cnt++;
		}
		return 1;
	}if(wayS){
		if(Que[cnt-1].x!=prevX || Que[cnt-1].y!=prevY-1){
			Que[cnt].x = prevX;
		Que[cnt].y = prevY-1;
		cnt++;
		}
		return 1;
	}
	*/
	return 0;
}

void draw(char** Mat, L* Que){
	int i,j;
	j = -1;
	for(i=1;i<cnt-1;i++){
		if(Que[i].x>Que[i+1].x){
			j=Que[i].x;
			while(j>=Que[i+1].x){
				if(Mat[Que[i].y+1][j]!='X' && Mat[Que[i].y+1][j]!='O')
					Mat[Que[i].y+1][j] = '.';
				j--;
			}
		}else
		if(Que[i].x<Que[i+1].x){
			j=Que[i].x;
			while(j<=Que[i+1].x){
				if(Mat[Que[i].y+1][j]!='O' && Mat[Que[i].y+1][j]!='X')
					Mat[Que[i].y+1][j] = '.';
				j++;
			}
		}else
		if(Que[i].y>Que[i+1].y){
			j=Que[i].y;
			while(j>=Que[i+1].y){
				if(Mat[j+1][Que[i].x]!='O' && Mat[j+1][Que[i].x]!='X')
					Mat[j+1][Que[i].x] = '.';
				j--;
			}
		}else
		if(Que[i].y<Que[i+1].y){
			j=Que[i].y;
			while(j<=Que[i+1].y){
				if(Mat[j+1][Que[i].x]!='O' && Mat[j+1][Que[i].x]!='X')
					Mat[j+1][Que[i].x] = '.';
				j++;
			}
		}
	}
	return;
}

void main(){
	// matrix
	int i,j;
	char **M =  (char**) malloc(sizeof(char*));
	L *Q = (L*) malloc(sizeof(L*));

	cnt = 1;
	i=j=0;
	scanf("%d", &Mx);
	scanf("%d", &My);
	MIN = Mx*Mx;
	for(j=0; j<=My; j++){
		
		gets(M[j]=(char*) malloc(sizeof(char)));
		if(j>0)
			for(i=0; i<Mx-1; i++)
				if(M[j][i]=='O'){
					_x = i;
					_y = j-1;
					break;
				}
	}

	printf("\n X=%d ; Y=%d \nNEO: (%d, %d)\n",Mx,My,_x,_y);
	
	print(M);
	
	findNode(M,_x, _y+1 ,_x,_y+1,'Q',0,Q);
	//Q[MIN].x = _x;
	//Q[MIN].y = _y;
	//cnt++;
	printf("\nshortest: %d\n", MIN);
	draw(M,Q);
	print(M);

	for(i=0;i<MIN;i++)
		printf("x:%d,y:%d\n", Q[i].x, Q[i].y);

	//findNode(M,_x,_y+1,'E');
	//findNode(M,_x,_y+1,'S');
	//findNode(M,_x,_y+1,'W');
	
	free(M);
	free(Q);
	system("pause");
	return;
}
