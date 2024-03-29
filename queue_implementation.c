#include <stdio.h>
#include <stdlib.h>
#include "queue_implementation.h"
int arr[4];

Queue * createQueue(int maxElements)
{
        /* Create a Queue */
        Queue *Q;
        Q = (Queue *)malloc(sizeof(Queue));
        /* Initialise its properties */
        Q->elements = (int *)malloc(sizeof(int)*maxElements);
        Q->size = maxElements;
        Q->s=0;
        Q->front = -1;
        Q->rear = -1;
        /* Return the pointer */
        return Q;
}


void Enqueue(Queue *Q,int element) 
{ 
    if ((Q->front == 0 && Q->rear == Q->size-1) || 
            (Q->rear == (Q->front-1)%(Q->size-1))) 
    { 
        printf("Queue is Full"); 
        return; 
    } 
  
    else if (Q->front == -1) /* Insert First Element */
    { 
        Q->front = 0;
		Q->rear = 0; 
        Q->elements[Q->rear] = element;
        Q->s++; 
    } 
  
    else if (Q->rear == Q->size-1 && Q->front != 0) 
    { 
        Q->rear = 0; 
        Q->elements[Q->rear] = element;
        Q->s++;  
    } 
  
    else
    { 
        Q->rear++; 
        Q->elements[Q->rear] = element;
        Q->s++; 
    } 
	return;
} 
 



int Dequeue(Queue *Q) 
{ 
    if (Q->front == -1) 
    { 
        //printf("\nQueue is Empty"); 
        return -1; 
    } 
   	int data=Q->elements[Q->front];
    Q->elements[Q->front] = -1; 
    if (Q->front == Q->rear) 
    { 
        Q->front = -1; 
        Q->rear = -1; 
        Q->s--; 
    } 
    else if (Q->front == Q->size-1){
        Q->front = 0; 
        Q->s--; 
    }
    else{
        Q->front++; 
        Q->s--; 
    }
	return data;
} 
  
int front(Queue *Q)
{
        if(Q->front==-1)
        {
                //printf("Queue is Empty\n");
                return -1;//exit(0);
        }
        /* Return the element which is at the front*/
        return Q->elements[Q->front];
}
int display(Queue *Q)
{
    int arr[4];
    int r=0;
		if(Q->front==-1)
        {
                printf("Queue is Empty\n");
                
                //exit(0);
        }
        else
		{

				if(Q->rear>=Q->front)
				{ 
					printf("Queue is:\n");
					for(int y=(Q->front);y<=(Q->rear);y++)
					{
					printf("%d ",Q->elements[y]);
					arr[r]=Q->elements[y];
					 //set label to "display"
    				//g_free(display); 
					}
				}
				else
				{
					printf("Queue is:\n");
					for(int y=(Q->front);y<(Q->size);y++)
					{
					printf("%d ",Q->elements[y]);
					arr[r]=Q->elements[y];
					r++;
					}
					for(int y=0;y<= (Q->rear);y++)
					{
					printf("%d ",Q->elements[y]);
					arr[r]=Q->elements[y];
					r++;
					}
				}
				
				for(int y=0;y< 4;y++)
					{
					if(arr[y]==0 || arr[y]==1 ||arr[y]==2 ||arr[y]==3){}
					else
						arr[y]= -1 ;
					}	
				printf("\n");
		}
		
}

int search(Queue *Q,int element)
{
		if(Q->size==0)
        {
                printf("Queue is Empty\n");
               
        }
        else
		{
				int j;
				for(j=(Q->front);j<= (Q->rear);j++)
				{
					if(Q->elements[j]==element)
						return 1;
				}
		}
		
}

