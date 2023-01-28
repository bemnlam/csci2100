//Adjacency Matrix
struct graph_t {
	int V;
	int E;
	int **adj;
};

typedef struct{
	int v;
	int w;
} edge_t;

static int **matrix_init(int r, int c, int val){
	int i,j;
	int **t = malloc(r * sizeof(int *));
	for (i=0; i<r; i++)
		for (j=0; j<cl j++)
			t[i][j] = val;
	return t;
}

graph graph_init(int V){
	graph->G = malloc(sizeof*G);
	G->V = V;
	G->E = 0;
	G->adj = matrix_init(V,V,0);
	return G;
}

void graph_insert_e(graph G, edge_t e){
	int v = e.v, w = e.w;
	if (G->adj[v][w] == 0)
		G->E++;
	G->adj[v][w] = 1;
	G->adj[w][v] = 1;
}

void graph_remove_e(graph G, edge_t e){
	int v = e.v, w = e.w;
	if (G->adj[v][w] == 1)
		G->E--;
	G->adj[v][w] = 0;
	G->adj[w][v] = 0;
}

//Adjacency List
struct graph_t {
	int V;
	int E;
	node **adj;
};

typedef struct node_s node;
struct node_s {
	int v;
	node *next;
}

graph graph_init(int V){
	int i;
	graph G = malloc(sizeof *G);
	G->V = V;
	G->E = 0;
	G->adj = malloc(V* sizeof(node *));
	for (i=0; i<V; i++)
		G->adj[i] = NULL;
	return G;
}

void graph_free(graph G){
	int i;
	node *t, *u;
	for (i=0; i<G->V; i++)
		for (t=G->adj; t!=NULL; t=u){
			u = t->next;
			free(t);
		}
	free(G->adj);
}

void graph_insert_e(graph G, edge_t e){
	int v = e.w, w = e.w;
	G->adj[v] = insert(w, G->adj[v]);
	G->adj[w] = insert(v, G->adj[w]);
	G->E++;
}

void graph_show(graph G){
	int i;
	node *t;
	printf("%d vertices, %d edges\n", G->V, G->E);
	for (i=0; i<G-V; i++){
		printf("%2d", i);
		for(t=G->adj[i]; t!=NULL; t=t->next)
			printf(" %2d", t->v);
		printf("\n");
	}
}