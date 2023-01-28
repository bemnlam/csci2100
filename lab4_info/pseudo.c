void BFS(VLink G[], int v) 
{ int w;
  VISIT(v);                    /*�X�ݳ��Iv*/
  visited[v] = 1;              /*���Iv�������X�ݼаO�m��1*/
  ADDQ(Q,v);
  while(!EMPTYQ(Q))
  { v = DELQ(Q);               /*�h�X���Y����v*/
    w = FIRSTADJ(G,v);         /*�Dv����1�ӾF���I�C�L�F���I�h��^-1*/
    while(w != -1)
    { if(visited[w] == 0)
      { VISIT(w);              /*�X�ݳ��Iv*/
        ADDQ(Q,w);             /*��e�Q�X�ݪ����Iw�i��*/
        visited[w] = 1;        /*���Iw�������X�ݼаO�m��1*/
      }
      W = NEXTADJ(G,v);        /*�Dv���U�@�ӾF���I�C�Y�L�F���I�h��^-1*/
    }
  }  
}

void TRAVEL_BFS(VLink G[], int visited[], int n)
{ int i;
  for(i = 0; i < n; i ++)
  { visited[i] = 0;            /* �аO�Ʋս��ȡ]�M�s�^*/
  }
  for(i = 0; i < n; i ++)
    if(visited[i] == 0)
      BFS(G,i);
}

 struct node
 {
    int self; //?�u
    node *left; //��??
    node *right; //�k??
 };
 
 
 
 
1  procedure BFS(Graph,source):
2      create a queue Q
3      enqueue source onto Q
4      mark source
5      while Q is not empty:
6          dequeue an item from Q into v
7          for each edge e incident on v in Graph:
8              let w be the other end of e
9              if w is not marked:
10                 mark w
11                 enqueue w onto Q