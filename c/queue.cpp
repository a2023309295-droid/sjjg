#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
}Node;

Node *initQueue(){
	 Node *node = (Node*)malloc(sizeof(Node));
	 node->next=NULL;
	 node->data = 0;
	 return node;
}

int empty(Node *q){
	if(q->next==NULL){
		return 1;
	}else{
		return 0;
	}
}

void enQueue(Node *q,int data){
	Node *p = q;
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;
	for(int i=0;i<q->data;i++){
		p = p->next;
	}
    p->next = pnew;
	q->data++;    
}

void deQueue(Node *q){
	if(empty(q)){
		printf("╤сапря©у!");
	}
	Node *p = q;
	Node *d = p->next;
	int data = d->data;
	p->next = d->next;
	q->data--;
	free(d);
	printf("%d\n",data);
}

void printNode(Node *q){
	Node *p = q->next;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}

int main(){
    Node *q = initQueue();
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);
	printNode(q);
	deQueue(q);
	printNode(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);
	return 0;
}
