#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define lim 41
/*���Լ�ѧ�����Ѿ������͵����ˣ�*/ 

char s1[lim] = {0},s2[lim] = {0},res[lim][lim] = {0},s3[lim] = {0};
int dp[lim][lim],s1len,s2len;

int max(int a,int b){
	if(a >= b)return a;
	else return b;
}

int LCS(int a,int c){
//	���ƺ�ĩβ�ظ��ˣ����Ǳ����ڽ��뺯����ʱ����ж��Ƿ��Ѿ������˼��㣬����ʵ�ּ��仯������ 
	if(dp[a][c] != -1)return dp[a][c];
	if(a == 0 || c == 0)return 0;
	else if(s1[a-1] == s2[c-1])dp[a][c] = LCS(a-1,c-1) + 1;
	else dp[a][c] = max(LCS(a-1,c),LCS(a,c-1));
	return dp[a][c];
}

//char Trace(int a,int c){//dp������ַ������ȴ�1���������ϱ�Ե�����ж� 
//	if(a <= 0 || c <= 0);
//	if(dp[a][c] > dp[a-1][c] && dp[a][c] > dp[a][c-1]){ 
////		ͬ�ڵ��·��©���ǳ��Ͼ� 
//		Trace(a-1,c-1);
//		*ps++ = s1[a-1];
//	}
//	if(dp[a][c] == dp[a-1][c])Trace(a-1,c);
//	if(dp[a][c] == dp[a][c-1])Trace(a,c-1);
//}

void find(int x,int y,int z){
	int i;
	
	if(y == s2len || x == s1len)return;
	find(x,y+1,z);
	find(x+1,y,z);
} 

int main(){
	gets(s1);
	gets(s2);
	int i = 0,j = 0,mxl = 0;
	s1len = strlen(s1),s2len = strlen(s2);
	for(;i < lim;i++){//��ʼ����񣬱��ں������仯���� 
		for(j = 0;j < lim;j++){
			dp[i][j] = -1;
		}
	}
	mxl = LCS(s1len,s2len);
	//��ӡdp���� 
	for(i = 0;i <= s1len;i++){ 
		for(j = 0;j <= s2len;j++){
			printf("%d\t",dp[i][j]);
		}
		printf("\n");
	}
	find(0,0,0);
	
	return 0;
} 


