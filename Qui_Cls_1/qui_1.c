#include <stdio.h>
#include <string.h>
#include <math.h>
//�˴����ܾ����ķݣ���Ҫ����һ�����⻯����������ʱ���ĵ��޷������ 
int main(){
	int N = 0,i = 1,j = 0,sum = 0,flag = 1;
	scanf("%d",&N);
	for(;i < (N+1)/2;i++){
		for(j = 0;j < N/2;j++){
			sum += i+j;
			if(sum == N){
				printf("%d~%d\n",i,i+j);
				flag = 0;
			}
			else if(sum > N){
				sum = 0;
				break;
			}
		}
	}
	if(flag)printf("None\n");
	return 0;
}

