#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM (int)1e6

int F[LIM] = {0};

//쳲��������г�ָ���������ʶ��ڽϴ��Fֵ��n��Ȼ��С����n��a֮������Թ�ϵ���Է����a 
int Fibonacci(int a,int x){
	if(x == 1)return 1;
	else if(x == 2)return a;
	else if(F[x])return F[x];
	else return F[x] = Fibonacci(a,x-1) + Fibonacci(a,x-2);
} 

int main() {
	int T,i,lst[20];
	scanf("%d",&T);
	for(i = 0;i < T;i++){
		int j,k,l;
		scanf("%d",&lst[i]);
		for(j = lst[i],k = 1;j >= 0;j--){//����a����һ�����ʵķ��� 
			int tmp = Fibonacci(j,1);
			
			for(l = 1;l <= k;l++)F[l] = 0;
			
			for(k = 2;tmp != lst[i];k++){
				tmp = Fibonacci(j,k);
				if(tmp > lst[i])break;
			}
			if(tmp == lst[i])printf("%d %d\n",k-1,j);
		}
	}
	return 0;
}

