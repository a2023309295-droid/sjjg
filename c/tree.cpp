#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
	char data;
	Tree *lchild;
	Tree *rchild;
}Tree;

void CreateTree(Tree **T){
	*T = (Tree*)malloc(sizeof(Tree));
	char data = 0;
	scanf("%c",&data);
	if(data=='#'){
		*T = NULL;
	}else{
	   (*T)->data = data;
	   CreateTree(&((*T)->lchild));
	   CreateTree(&((*T)->rchild));	
	}
}

void printTree(Tree *T){
	if(T!=NULL){
	   	printf("%c",T->data);
	   	printTree(T->lchild);
	   	printTree(T->rchild);
	}
}
int main(){
	Tree *T;
	CreateTree(&T);
	printTree(T);
	return 0;
}
