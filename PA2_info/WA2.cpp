typedef struct node_s node;
struct node_s {
	int e;
	node *prev;
	node *next;	
}

void dll_sort(node *list) {
	node *x, *t, *m;
	
	for (x=list->next; x!=list; x=m->next) {
		for (m=t=x; t!=list; t->next) {
			if (m->e >= t->e) {
				m=t;
			}
		}
		
		swap (x, m);
	}
	
}
