#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//	���ݹ�ģ�ϴ��ƺ��������Ч�ʸ��� 
int read(){
	char ch = getchar();
	int x = 0;
	for(;'0'<=ch&&ch<='9';x = (x<<1)+(x<<3)+(ch^48),ch = getchar());
	return x;
}

int main() {
	int n,m,i,j,res = 1,a[(int)5e4],b[(int)5e4],flg[(int)5e4+2] = {0};
	n = read();
	m = read();
	for(i = 0;i < n;i++)a[i] = read();
	for(i = 0;i < m;i++)b[i] = read();
//	����flg��λ�߽磬���ں�������������Ƭ����Ŀ	
	flg[0] = 1;
	for(j = 0;j < m;j++){
		for(i = 0;i < n;i++){
			if(a[i] == b[j])flg[i+1] = 1;
		}
		flg[i+1] = 1;
	}
//	���ñ߽�1ֵ��ʹ���зֶε��һǰһ���������	
	for(i = 0;i < n;i++){
		if(flg[i]^flg[i+1])res++;
	}
	printf("%d",res/2);
	return 0;
}

