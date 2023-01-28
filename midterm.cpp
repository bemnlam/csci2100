//a sample of the node in linked list
typeof struct node_s node;
struct node_s{
	int e;
	node *next;
};

//create a new node
node *x = malloc(sizeof(node));
free(x);

//The josephus problem
int main(int argc, char *argv[]){
	int i, N=atoi(argv[1]), M=atoi(argv[2]);
	node *t=malloc(sizeof(node)), *x=t;
	
	t->e=1;
	t->next=t;
	
	for(i=2; i<=N; i++){
		x= (x->next = malloc(sizeof( *t)));
		x->e = i;
		x->next = t;
	}
	
	while(x!=x->next){
		for(i=1; i<M; i++){
			x=x->next;
		}
		printf("%d ", x->next->e);
		x->next = x->next->next;
		N--;
	}
	
	printf("%d\n", x->e);
	
	return 0;
}
