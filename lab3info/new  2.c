void print(int i, int lvl){
	int j;
	for(j=0; j<lvl; j++)
		printf('+');
	puts(A[i].name);

	for(j=i;A[j].Xnext>0;j=A[j].Xnext){
		if(a[j].Ynext>0)
			print(j, ++lvl);
	}

	return;
}

void print(int m,int lvl){
	int i;
	int l;
	l=m;
	while(m>=0){
		for(i=0;i<lvl;i++)
			printf("+");
		puts(A[m].name);
		//printf("[%d]",A[m].Ynext);
		while(A[l].Ynext>0){
			//Hhelloprintf("+");
			print(A[l].Ynext,++lvl);
			l=A[l].Ynext;
		}
		//printf(" Xnext:%d\n",A[m].Xnext);
		m=A[m].Xnext;
	};
	return;
}