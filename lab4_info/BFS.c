void graph_bfs(graph G){
	int i;

	pre = malloc(sizeof(int) *G->V);
	st = malloc(sizeof(int) *G->V);
	cnt = 0;
	for(i=0;  i< G->V; i++){
		pre[i] = -1;
		st[i] = -1;
	}
	queue_init(G->V);

	bfs_visit(G, new_edge(0,0));

	queue_free();
	free(pre);
	free(st);
}

void bfs_visit(Graph G, edge_t e){
	int w;
	node *t;
	queue_enq(e);
	pre[e.w] = cnt++;
	while (!queue_is_wnpty()){
		e = queue_deq();
		w = e.w;
		st[w] = e.v;
		for(t = G->adj[w]; t!=NULL; t = t->next)
			if(pre[t->v] == -1){
				queue_enq(new_edge(w, t->v));
				pre[t->v] = cnt++;
			}
	}
}
