//The josephus problem

#include <stdio.h>

//the define of a node
typedef struct node_s node;
struct node_s{
	int e;
	node *next;
};



int main(){
	int N=9,M=5;
	int i;
	
	node *t=malloc(sizeof(node)), *x=t;
	
	//make a cyclic link
	t->e=1;
	t->next=t;
	
	//add members
	for(i=2; i<=N; i++){
		x= (x->next = malloc(sizeof( *t)));
		x->e = i;
		x->next = t;
	}
	
	//election
	while(x!=x->next){
		for(i=1; i<M; i++){
			x=x->next;
		}
		printf("%d ", x->next->e);
		x->next = x->next->next;
		N--;
	}
	
	printf("%d\n", x->e);
	
	getchar();
	return 0;
}

//searching for the end of the linked list
for(t=x; t!=NULL; t=t->next)
	visit(t->e);
	
//List Reversal
node *reverse(node *x){
	node *t, *y=x, *r=NULL;
	while(y!=NULL){
		t=y->next;
		y->next=r;
		r=y;
		y=t;
	}
	return r;
}

//List insertion sort
node heada headb;
node *t, *u, *x, *a=&heada, *b;

//making the header node and the first linked li
for(i=0, t=a; i<N; i++){
	t->next = malloc(sizeof *t));
	t=t->next;
	t->next=NULL;
	t->e=rand()%1000;
}
b=&headb;
b->next=NULL;
for(t=a->next; t!=NULL; t=u){
	u=t->next;
	for(x=b; x->next!=NULL; x=x->next){
		if(x->next->e > t->e){
			break;
		}
	}
	
	t->next = x->next;
	x->next = t;
}
