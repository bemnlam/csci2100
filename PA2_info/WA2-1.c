swap(node *x, node *m)
{

	node* tmp;
	
	tmp->next = x->next;
	tmp->prev = x->prev;
	
	x->next = m->next;
	x->prev = m->prev;
	
	m->next = tmp->next;
	m->prev = tmp->prev;
	
	x->prev->next = x;
	tmp->prev->next = m;
	
	x->next->prev = x;
	tmp->next->prev = m;
	
	tmp->next = NULL;
	tmp->prev = NULL;
}