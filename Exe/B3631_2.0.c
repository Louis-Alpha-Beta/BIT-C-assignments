#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*ʹ������ʵ�������ռ������ʽϵͣ�����������ʽ��������������ʽ����ö� 
����ֻ������1e5�������С���ύʱ��Ϊ1e6����*/ 

int main() {
//	���ñ�ͷ 
	int lst[(int)1e5];//Ĭ������xλ�ô���x��ֵ��������һ����ֵ��λ�ã�=��ֵ�� 
	lst[1] = 0; 
//	�������� 
	int n,i;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		int op,x,y; 
		scanf("%d",&op);
		if(op == 1){//1�Ų������ 
			scanf("%d%d",&x,&y);
			lst[y] = lst[x];
			lst[x] = y;
		}
		else if(op == 2){//2�Ų�ѯ���� 
			scanf("%d",&x);
			printf("%d\n",lst[x]); 
		}
		else if(op == 3){//3��ɾ������ 
			scanf("%d",&x);
			y = lst[x];
			lst[x] = lst[lst[x]];
			lst[y] = 0;//��ʽ���ͷſռ� 
		}
	}
	return 0;
}

