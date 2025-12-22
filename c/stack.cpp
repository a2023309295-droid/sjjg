#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
}Node;

Node *initCreate(){
	Node *s = (Node*)malloc(sizeof(Node));
	s->data = 0;
	s->next = NULL;
	return s;
}

int empty(Node *s){
	if(s->data==0||s->next==NULL){
		return 1;
	}else{
		return 0;
	}
}

void pop(Node *s){
	if(empty(s)){
		printf("у╩ря©у!");
	}else{
		Node *p = s;
		Node *q = p->next;
		int d = q->data;
		p->next = q->next;
		printf("%d\n",d);
		s->data--;
	}
}

void push(Node *s,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;
	Node *p = s;
	pnew->next = p->next;
	p->next = pnew;
	s->data++; 
}


void printNode(Node *s){
	Node *p = s->next;
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	Node *s = initCreate();
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	printNode(s);
	printf("%d\n",s->data);
	pop(s);
	printNode(s);
	printf("%d\n",s->data);
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	return 0;
}
