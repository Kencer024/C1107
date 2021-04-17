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

int CC (Graph g);

void printGraphList(Graph );

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
    Graph g;
    int i,j;
    ListNode *temp;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));

    for(i=0;i<g.V;i++)
        g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&i,&j)==2)
    {
        i=i-1;

        if(g.list[i]==NULL){
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        }
        else{
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");

    int res = CC(g);
    if(res ==1)
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    printGraphList(g);
    return 0;
}


int CC (Graph g)
{
    // Write your code here
    //loop through the whole sequence
    int i,j,k,t=0,s;          //traversal variables

    int check[g.V], ch_flag = 0;    //checking array n flag

    if(g.E == 0)        //check whether the graph is just 1 point
        return -1;

    ListNode *temp1;

    int n = g.V;

    int flag = 0;       //acts a return for my bfs

    int w,vert;         //variables

    Queue q1;           //initialise queue
    q1.head = NULL;
    q1.size = 0;
    q1.tail = NULL;


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //
            if(i != j)
            {
                enqueue(&q1, i);

                //BFS traversal
                while(!isEmptyQueue(q1))
                {
                    w = getFront(q1);
                    dequeue(&q1);
                    temp1 = g.list[w-1];

                    //printf("w, j is %d, %d\n",w,j);

                    if(w == j)
                    {
                        flag = 1;
                        break;
                    }
                    //printf("A\n");
                    //check for visitation
                    for(k=0;k<n;k++)
                    {
                        if(w == check[k])
                        {
                            ch_flag =1;
                            break;
                        }
                    }
                    //printf("B\n");
                    if(ch_flag == 0)        //means not visited
                    {
                        while(temp1)
                        {
                            vert = temp1->vertex;
                            enqueue(&q1, vert);
                            temp1 = temp1->next;
                        }
                        check[t] = w;
                    }



                    //printf("C\n");
                    ch_flag = 0;
                    t++;

                }       //end while(!emptyqueue)

            }
            //printf("D\n");
            removeAllItemsFromQueue(&q1);
            if((flag == 0)&&(i!=j))       //means loop through everything already and got no match
                return -1;
            else                //match found hence must reset visitation
            {
                //printf("check reset \n");
                for(s=0;s<n;s++)
                {
                    check[s] = 0;
                }
                flag = 0;
                t = 0;
                //printf("E\n");
            }

        }       //end of for j
    }       //end of for i



    return 1;
}


void printGraphList(Graph g){
    int i;
    ListNode* temp;

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
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
