#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
	Node *pre;
}Node;

Node *initCreate(){
	Node *L = (Node*)malloc(sizeof(Node));
	L->next = L;
	L->pre = L;
	return L;
}

void headinsert(Node *L,int data){
  	Node *pnew = (Node*)malloc(sizeof(Node));
  	pnew->data = data;
  	pnew->next = NULL;
  	Node *p = L;
  	if(p->next == L){
  		pnew->pre = p;
  		pnew->next = p;
  		p->next = pnew;
  		p->pre = pnew;
	}else{
		pnew->pre = p;
		pnew->next = p->next;
		p->next->pre = pnew;
		p->next = pnew;
	}
}

void tailinsert(Node *L,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;
	Node *p = L;
	while(p->next!=L){
		p = p->next;
	}
	pnew->pre = p;
	pnew->next = p->next;
	p->next->pre = pnew;
	p->next = pnew;
}

int len(Node *L){
	int i = 0;
	Node *p = L->next;
	while(p!=L){
		i++;
		p = p->next;
	}
	return i;
}

void insert(Node *L,int index,int data){
	Node *p = L;
	int i = 0;
	if(index<0||index>len(L)){
	   return;
	}else{
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew->next = NULL;
		pnew->pre = NULL;
		pnew->data = data;
		while(i<index-1){
		    p = p->next;
			i++;
		}
		pnew->pre = p;
		pnew->next = p->next;
		p->next->pre = pnew;
		p->next = pnew;
	}
}

void deleteNode(Node *L,int index){
	int i = 0;
	if(index<0||index>len(L)){
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


void printNode(Node *L){
	Node *p = L->next;
	while(p!=L){
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	Node *L = initCreate();
	headinsert(L,1);
	headinsert(L,2);
	headinsert(L,3);
	tailinsert(L,4);
	printNode(L);
	printf("%d\n",len(L));
	insert(L,2,5);
	printNode(L);
	return 0;
}
