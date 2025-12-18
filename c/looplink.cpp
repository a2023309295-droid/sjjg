#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
}Node;

Node *initCreate(){
	Node *L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;
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


void tailInsert(Node *L,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	Node *p = L;
	while(p->next!=L){
		p = p->next;
	}
	pnew->next = p->next;
	p->next = pnew;
}

void headInsert(Node *L,int data){
	Node *pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	Node *p = L;
	pnew->next = p->next;
	p->next = pnew;
}

void insert(Node *L,int index,int data){
	int i = 0;
	Node *p = L;
	if(index<=0||index>len(L)){
		printf("���ݴ���!\n");
		return;
	}else{
		Node *pnew = (Node*)malloc(sizeof(Node));
		pnew->data = data;
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
	Node *p = L;
	if(index<=0||index>len(L)){
		printf("���ݴ���!\n");
		return;
	}else{
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
void printNode(Node *L){
	Node *p = L->next;
	while(p!=L){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	Node *L = initCreate();
	tailInsert(L,1);
	tailInsert(L,2);
	tailInsert(L,3);
	tailInsert(L,4);
	printNode(L);
	headInsert(L,5);
	printNode(L);
	deleteNode(L,2);
	printNode(L);
	insert(L,2,9);
	printNode(L);
	printf("%d\n",len(L));
	return 0;
}
