#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int f(int m,int n){
	if(n==1 || m==1)return 1;
	else if(m == n && n!=1)return f(m,n-1) + 1;
	else if(m < n)return f(m,m);
	else return f(m-n,n) + f(m,n-1);//��һ�֤�ֽ���һ��n��ʣ�ಿ�ֲ��ؼƽϣ����ڶ���Ϊ����n��������� 
}

int main() {
	int m = 0,n = 0;
	scanf("%d%d",&m,&n);
	printf("%d\n",f(m,n));
	return 0;
}

