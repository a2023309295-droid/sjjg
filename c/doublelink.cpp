#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
	Node *next;
	Node *pre;	
}Node;

Node *initCreate(){
	Node *L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	L->pre = NULL;
	return L;
}

void headInsert(Node *L,int data){
    Node *pnew = (Node*)malloc(sizeof(Node));
    pnew->data = data;
    pnew->next = NULL;
    pnew->pre = NULL;
    Node *p = L;
    if(p->next==NULL){
    	pnew->pre = p; 
		p->next = pnew;
	}else{
		pnew->pre = p;
		pnew->next = p->next;
		p->next->pre = pnew;
		p->next = pnew;
	}
}

void tailInsert(Node *L,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;
	pnew->pre = NULL;
	Node *p = L;
	while(p->next!=NULL){
		p = p->next;
	}
	pnew->pre = p;
	p->next = pnew;
}

int len(Node *L){
	int i = 0;
	Node *p = L->next;
	while(p!=NULL){
		p = p->next;
		i++;
	}
	return i;
}

void insert(Node *L,int index,int data){
	int i = 0;
	if(index<0 || index > len(L)){
		return;
	}else{
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew->data = data;
		pnew->next = NULL;
		pnew->pre = NULL;
		Node *p = L;
		while(i<index-1){
			p = p->next;
			i++;
		}
        pnew->next = p->next;
		pnew->pre = p;
		p->next = pnew;		
	}
}

void deleteNode(Node *L,int index){
	int i = 0;
	if(index<0 || index>len(L)){
		return;
	}else{
		Node *p = L;
		while(i<index-1){
			p = p->next;
			i++;
		}
		Node *q = p->next;
		p->next = q->next;
		q->next->pre = p;
		free(q);
	}
}

void printfNode(Node *L){
	Node *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	Node *L = initCreate();
	headInsert(L,1);
	headInsert(L,2);
	tailInsert(L,3);
	printfNode(L);
	insert(L,2,5);
	printfNode(L);
	deleteNode(L,2);
	printfNode(L);
	printf("%d ",len(L));
	return 0;
}
