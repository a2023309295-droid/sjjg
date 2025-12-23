#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 6
typedef struct Queue{
	int data[MAXSIZE];
	int rear;
	int front;
}Queue;

Queue* create(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->rear = 0;
	q->front = 0;
	return q;
}

int isfull(Queue *q){
	if((q->rear+1)%MAXSIZE==q->front%MAXSIZE){
		return 1;
	}else{
		return 0;
	}
}

int isempty(Queue *q){
	if(q->front==q->rear){
       return 1;		
	}else{
		return 0;
	}
}

void enqueue(Queue *q,int data){
	if(isfull(q)){
		printf("¶ÓÁÐÒÑÂú!");
		return;
	}else{
		q->data[(q->rear+1)%MAXSIZE] = data;
		q->rear = q->rear+1;
	}
}

void dequeue(Queue *q){
	if(isempty(q)){
		return;
	}else{
	  q->front = q->front+1;
	}
}

void printNode(Queue *q){
   int i = q->front;
   while(i!=q->rear){
   	 printf("%d",q->data[(i+1)%MAXSIZE]);
     i++;
   }
   printf("\n");
}

int main(){
	Queue *q = create();
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	enqueue(q,5);
	printNode(q);
	dequeue(q);
	printNode(q);
	enqueue(q,6);
	printNode(q);
	enqueue(q,7);
	return 0;
}
