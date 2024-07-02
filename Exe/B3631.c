#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int num;
	struct node*next;
}NODE;

int read(int* px,int* py){
	int flg;
	scanf("%d",&flg);
	if(flg == 1)scanf("%d%d",px,py);
	else scanf("%d",px);
	return flg;
}

NODE* insert(NODE*head,int x,int y){//1�Ų������ 
	NODE*tmp = NULL;
	tmp = (NODE*)malloc(sizeof(NODE));
	tmp->num = y;
	tmp->next = NULL;
	while(head != NULL){
		if(head->num == x){
			tmp->next = head->next;
			head->next = tmp;
			break;
		}
		else head = head->next;
	}
	if(head == NULL)return NULL;
	else return head;
} 

int inquire(NODE*head,int x){//2�Ų�ѯ���� 
	while(head->next != NULL){
		if(head->num == x)break;
		else head = head->next;
	}
	if(head->next == NULL)return 0;
	else return head->next->num;
}

NODE* oust(NODE*head,int x){//3��ɾ������ 
	NODE*tmp = NULL;
	while(head->next != NULL){
		if(head->num == x){
			tmp = head->next;
			head->next = head->next->next;
			free(tmp);
			break;
		}
		else head = head->next;
	}
	if(head->next == NULL)return NULL;
	else return head;
} 

int main() {
//	���ñ�ͷ 
	NODE* head = NULL;
	head = (NODE*)malloc(sizeof(NODE));
	head->num = 1;
	head->next = NULL;
//	�������� 
	int n,i;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		int flg,x,y;
		int*px = &x,*py = &y;
		flg = read(px,py);
//		�жϲ�����		
		switch(flg){
			case 1:
				insert(head,x,y);
				break;
			case 2:
				y = inquire(head,x);
				printf("%d\n",y);
				break;
			case 3:
				oust(head,x);
				break;
		}
	}
	return 0;
}

