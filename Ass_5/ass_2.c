#include <stdio.h>
#include <math.h>
//n+(n-1)*2+(n-2)*2+......+1*2 == n^2 !!!  
//[n+n-1+n-1+n-2]+[n-2+n-3+n-3+n-4]......NO!!
//0-(n-1)*4 1-(n-1-2*1)*4......(n-1)*4*(l-1)+2*4*(1+2+...+l-1) = 4*(l-1)(n+l-1)

//lev���������ж����ڵڼ�����֣����������� 
int lev(int i,int n){
	int l = 0,j = 0;
	if(n%2){
		for(j = n-1;j >= 1/2;j -= 2){//�˴� j ���������ȷ��������n^2�߽�ֵ�����ѭ������ô�����ģ� 
			if(i <= 0){
				break;
			}
			else{
				i -= j*4;
				l = (n-j-1)/2;
			}
		}
	}
	else{
		for(j = n-1;j >= 1;j -= 2){//�˴� j ���������ȷ��������n^2�߽�ֵ�����ѭ������ô�����ģ� 
			if(i <= 0){
				break;
			}
			else{
				i -= j*4;
				l = (n-j-1)/2;
			}
		}
	}
	

	return l;
} 

//mod���������ж����ڲ��е�ģ�顣ÿһ����ַָ���Ŀ�ȳ�ģ�顣 
int mod(int i,int n,int l){
	int m = 0,j = 0;
	for(j = 0;j < l;j++){
		i -= (n-1-2*j)*4;
	}
	if(n%2){
		if(i != 1){
			m = (i-1)/(n-1-2*j);
		}
	}
	else m = i=(i-1)/(n-1-2*j);
	
	return m;
}

//uni���������ж�����ģ���е�λ�á���һ��ģ���е�λ�á� 
int uni(int i,int n,int l){
	int u = 0,j = 0;
	for(j = 0;j < l;j++){
		i -= (n-1-2*j)*4;
	}
	if(n%2){
		if(i != 1){
			u = (i-1)%(n-1-2*j);
		}
	}
	else u = (i-1)%(n-1-2*j);
	
	return u;
}

int main(){
	int n = 0,l = 0,m = 0,u = 0,i = 0,j = 0;
	scanf("%d",&n);
	int M[n][n];
	for(i = 1;i <= n*n;i++){
		l = lev(i,n);
		m = mod(i,n,l);
		u = uni(i,n,l);

		switch (m){
			case 0:
				M[l][l+u] = i;
				break;
			case 1:
				M[l+u][n-l-1] = i;
				break;	
			case 2:
				M[n-l-1][n-l-u-1] = i;
				break;
			case 3:
				M[n-l-u-1][l] = i;
				break;		
		}
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("%3d",M[i][j]);
		}
		printf("\n");
	}
}

