#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *rchild;
	struct node *lchild;
}NODE, *list;

void creat_tree(list list_tree)
{
	NODE *node;  //栈
	int data;

	scanf("%d", &data);
	if(data == '0'){
		node = NULL;
	}else {
		node = (NODE *)malloc(sizeof(NODE));
		if(node == NULL){
			printf("malloc error\n");
			return ;
		}
		node->data = data;
		node->lchild = NULL;
		node->rchild = NULL;
		list_tree = node;

		creat_tree(list_tree->lchild);
		creat_tree(list_tree->rchild);
	}

	return ;
}

void print_tree(list list_tree)
{
	if(list->tree == NULL){
		return ;
	}

	printf("%d\n", list_tree->data);
	print_tree(list_tree->lchild);
	print_tree(list_tree->rchild);

	return ;
}

void reverse_tree(list list_tree)
{
	NODE *temp;
	
	if(list_tree == NULL){
		return ;
	}

	temp = list_tree->lchild;
	list_tree->lchild = list_tree->rchild;
	list_tree->rchild = temp;

	reverse_tree(list_tree->lchild);
	reverse_tree(list_tree->rchild);

	return ;
}


void main()
{
	list list_tree;

	creat_tree(list_tree);
	print_tree(list_tree);
	reverse_tree(list_tree);
	print_tree(list_tree);
	
	return ;
}