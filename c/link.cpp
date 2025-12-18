#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
}Node;

Node *initCreate(){
	Node *L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}


void headInsert(Node *L,int data){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = data;
	if(L->next==NULL){
		L->next = p;
	}else{
		p->next = L->next;
		L->next = p;
	}
}

void tailInsert(Node *L,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->next = NULL;
	pnew->data = data;
    Node *p = L;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = pnew;
}

void printNode(Node *L){
    Node *p = L->next;
    while(p!=NULL){
    	printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int len(Node *L){
	int i = 0;
	Node *p = L->next;
	while(p!=NULL){
		i++;
		p = p->next;
	}
	return i; 
}

void insert(Node *L,int index,int data){
	int i = 0;
	if(index<=0||index>len(L)){
		printf("���ݴ���!\n");
		return;
	}else{
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew->data = data;
		pnew->next = NULL;
		Node *p = L;
		while(i<index-1){
		   p = p->next;	
		   i++;	
		}
	    pnew->next = p->next;
	    p->next = pnew;
	}
}

void deleteNode(Node *L,int index){
	int i = 0;
	if(index <= 0||index>len(L)){
		printf("���ݴ���!\n");
		return;
	}else{
		Node *p = L;
		while(i<index-1){
			p = p->next;
			i++;
		}
		Node *q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
	}
}
int main(){
    Node *L = initCreate();
	tailInsert(L,1);
	tailInsert(L,2);
	tailInsert(L,3);	
	tailInsert(L,4);
	headInsert(L,5);
	printNode(L);
	insert(L,2,9);
	printNode(L);
	deleteNode(L,3);
	printNode(L);
	printf("%d\n",len(L));
	insert(L,6,1);
	insert(L,5,1);
	printNode(L);
	return 0;
}
