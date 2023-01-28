void BFS(VLink G[], int v) 
{ int w;
  VISIT(v);                    /*訪問頂點v*/
  visited[v] = 1;              /*頂點v對應的訪問標記置為1*/
  ADDQ(Q,v);
  while(!EMPTYQ(Q))
  { v = DELQ(Q);               /*退出隊頭元素v*/
    w = FIRSTADJ(G,v);         /*求v的第1個鄰接點。無鄰接點則返回-1*/
    while(w != -1)
    { if(visited[w] == 0)
      { VISIT(w);              /*訪問頂點v*/
        ADDQ(Q,w);             /*當前被訪問的頂點w進隊*/
        visited[w] = 1;        /*頂點w對應的訪問標記置為1*/
      }
      W = NEXTADJ(G,v);        /*求v的下一個鄰接點。若無鄰接點則返回-1*/
    }
  }  
}

void TRAVEL_BFS(VLink G[], int visited[], int n)
{ int i;
  for(i = 0; i < n; i ++)
  { visited[i] = 0;            /* 標記數組賦初值（清零）*/
  }
  for(i = 0; i < n; i ++)
    if(visited[i] == 0)
      BFS(G,i);
}

 struct node
 {
    int self; //?据
    node *left; //左??
    node *right; //右??
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