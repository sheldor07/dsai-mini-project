#include <stdio.h>
#include <stdlib.h>


typedef struct _listnode
{
 int vertex;
 struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
 int V;
 int E;
 ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
 int size;
 QueueNode *head;
 QueueNode *tail;
} Queue;

typedef struct _stack
{
 int size;
 StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph g);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////
void buildGraph(Graph a,Graph ra, int *s,int *p,int *m);
int main()
{
 int Prj, Std, Mtr; //Project, Student and Mentor;
 int maxMatch;
 scanf("%d %d %d", &Std, &Prj, &Mtr);
 int np,nm; //number of projects and number of mentors

 //build graph
 Graph g;
 //Write your code
Graph sg;

int *arr = malloc(g.V*sizeof(int));
int *sarr = malloc(g.V*sizeof(int));
int *cap = malloc(g.V*g.V*sizeof(int));
int *mcap = malloc(g.V*g.V*sizeof(int));
buildGraph(&g,&sg,Std,Prj,Mtr);
 //apply Ford Fulkerson algorithm
 // use DFS or BFS to find a path
 fordFulkerson(np,nm,g.V,arr,sarr,cap,mcap);
 maxMatch = matching(g);
 printf("%d\n", maxMatch);
 return 0;
}

int matching(Graph g)
{

 //Write your code
 return 0;

}

int bfs(int start, int target,int n,int *arr,int* sarr, int** cap,int **m) {
  int u, v;
  Queue iq;
  iq.head=NULL;
  
  //reset
  for (u = 0; u < n; u++) {
    arr[u] = 0;
  }
  int head =0;
  int tail = 0;
  enqueue(&iq,start);
  sarr[start] = -1;
  while (head != tail) {
    u = dequeue(&iq);
    for (v = 0; v < n; v++) {
      if (arr[v] == 0 && cap[u][v] - m[u][v] > 0) {
        enqueue(&iq,v);
        sarr[v] = u;
      }
    }
  }
  return arr[target] == 1;
}

// Applying fordfulkerson algorithm
int fordFulkerson(int source, int sink,int n,int *arr,int* sarr, int** cap,int **m) {
  int i, j, u;
  int n;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      m[i][j] = 0;
    }
  }

  // Updating the residual values of edges
  while (bfs(source, sink,n,arr,sarr,cap,m)) {
    int increment = 1000000000;
    for (u = n - 1; sarr[u] >= 0; u = sarr[u]) {
      increment = min(increment, cap[sarr[u]][u] - m[sarr[u]][u]);
    }
    for (u = n - 1; m[u] >= 0; u = sarr[u]) {
      m[sarr[u]][u] += increment;
      m[u][sarr[u]] -= increment;
    }
    // Adding the path flows
    max_flow += increment;
  }
  return max_flow;
}

void buildGraph(Graph *a,Graph *ra, int s,int p,int m){
    insertAdjVertex(a->list,s);
    insertAdjVertex(a->list,p);
    insertAdjVertex(a->list,m);
    insertAdjVertex(ra->list,s);
    insertAdjVertex(ra->list,p);
    insertAdjVertex(ra->list,m);
}

void removeAdjVertex(ListNode** AdjList,int vertex)
{
 ListNode *temp, *preTemp;
 if(*AdjList != NULL)
 {
    if((*AdjList)->vertex ==vertex){//first node
      temp = *AdjList;
      *AdjList = (*AdjList)->next;
      free(temp);
      return;
    }
    preTemp = *AdjList;
    temp = (*AdjList)->next;
    while(temp!=NULL && temp->vertex != vertex)
    {
      preTemp= temp;
      temp = temp->next;
    }
    preTemp->next = temp->next;
    free(temp);
   }
}

void insertAdjVertex(ListNode** AdjList,int vertex)
{
  ListNode *temp;
  if(*AdjList==NULL)
  {
     *AdjList = (ListNode *)malloc(sizeof(ListNode));
     (*AdjList)->vertex = vertex;
     (*AdjList)->next = NULL;
  }
  else{
     temp = (ListNode *)malloc(sizeof(ListNode));
     temp->vertex = vertex;
     temp->next = *AdjList;
     *AdjList = temp;
  }
}

void enqueue(Queue *qPtr, int vertex) {
  QueueNode *newNode;
  newNode = malloc(sizeof(QueueNode));
  if(newNode==NULL) exit(0);

  newNode->vertex = vertex;
  newNode->next = NULL;

  if(isEmptyQueue(*qPtr))
     qPtr->head=newNode;
  else
     qPtr->tail->next = newNode;

     qPtr->tail = newNode;
     qPtr->size++;
}

int dequeue(Queue *qPtr) {
   if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
     return 0;
   }
   else{
     QueueNode *temp = qPtr->head;
     qPtr->head = qPtr->head->next;
     if(qPtr->head == NULL) //Queue is emptied
       qPtr->tail = NULL;

     free(temp);
     qPtr->size--;
     return 1;
}
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
   if(q.size==0) return 1;
   else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
  while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
 if(cur==NULL) printf("Empty");

 while (cur != NULL){
    printf("%d ", cur->vertex);
    cur = cur->next;
  }
 printf("\n");
}

void push(Stack *sPtr, int vertex)
{
  StackNode *newNode;
  newNode= malloc(sizeof(StackNode));
  newNode->vertex = vertex;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr)
{
  if(sPtr==NULL || sPtr->head==NULL){
     return 0;
  }
  else{
     StackNode *temp = sPtr->head;
     sPtr->head = sPtr->head->next;
     free(temp);
     sPtr->size--;
     return 1;
   }
}

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

int peek(Stack s){
   return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
   while(pop(sPtr));
}