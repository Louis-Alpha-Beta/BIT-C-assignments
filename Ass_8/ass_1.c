#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long long int i = 0;

void dfs(int n,int N){//�ݹ��ǽ���������ΪС���������������Ǵ�С������� 
	if(n == N){
		i++;//����Ҫ����֮ǰ����ֵ������ÿ����ǰ���� 
	}
	else if(n > N);
	else{
		dfs(n + 1,N);
		dfs(n + 2,N);
	}
} 

int main() {
	int a = 0,b = 0;
	scanf("%d%d",&a,&b);
	dfs(a,b);
	printf("%lld\n",i);
	return 0;
}

