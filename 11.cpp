#include<stdio.h>
#include<stdlib.h>
#define N 13 /*参加游戏的人数*/
typedef struct node{
			int code;	/*游戏者的编号*/
			struct node * next;
}NODE,* LinkList;

LinkList create_list(int n){
/*用尾插法创建一结点数为n的单循环链表，返回值为数据域为1的结点指针*/
	LinkList head,p;
	int i;
	head=(NODE *)malloc(sizeof(NODE));/*创建循环链表的第一个结点*/
	if(!head){
		printf("memory allocation error! \n");
		exit(1);
	}
	head->code=1; head->next=head;
	for(i=n;i>1;--i){
		p=(NODE *)malloc(sizeof(NODE));
		if(!p){
			printf("memory allocation error! \n");
			exit(1);
		}
		p->code=i;p->next=head->next;head->next=p;
	}
	return head;
}

void output(LinkList head){
	LinkList p;
	p=head;
	do{
		printf("%4d",p->code);p=p->next;
	}while(p!=head);
	printf("\n");
}

void play(LinkList head,int n){
	LinkList p,q;
	int c=0,k;
	p=head;c=1; k=n;
	while(k>1){
		if(c==2){
			q=p->next;p->next=q->next;
			printf("%4d",q->code);free(q);
			c=0;k--;
		}
		else{c++;p=p->next;}
	}
	printf("\n%4d was the winner.",p->code);
}
void main(void){
	LinkList head;
	int n;
	printf("input a numer:");scanf("%d",&n);
	head=create_list(n);
	output(head);
	play(head,n);
}