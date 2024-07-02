#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 7 


char a[LIM],code[] = {'9','0','1','2','3','4','5','6','7','8','9','0'};//�������߽� 
char lst[729][LIM];

char* Format(char*a,int n){//�������ַ�����ʽ��Ϊnλ������ǰ���㣩 
	int i,len = strlen(a);
	char f[6] = {0};
	for(i = 1;i <= n-len;i++){
		strcat(f,"0");
	}
	strcat(f,a);//����ֻ�ܺ���ǰ�������ǸĶ���ǰһ�ַ������� 
	strcpy(a,f);//�ַ���ֻ���ø��ƣ������ø�ֵ 
	return a;
}

int Convert(int x,int t,int i,int n){
//	x��ʾ��ǰѡ����x��λ�ã�t��ʾһ����Ҫѡ��λ������iΪ����λ�ã�nΪ���鳤�� 
	static int c = 0;
	int j;
	if(i > n)return 0;
	if(x == t && i == n){
		for(j = 0;j < n;j++){
			lst[c][j] = a[j];
		}
		c++;
	}
	
	Convert(x,t,i+1,n);//��ѡ��ǰλ�� 
	
	a[i] = code[a[i]-48];//ѡ��ǰλ�ò�����-1 
	Convert(x+1,t,i+1,n);
	a[i] = code[a[i]-46];//��λ 
	
	a[i] = code[a[i]-46];//ѡ��ǰλ�ò�����+1 
	Convert(x+1,t,i+1,n);
	a[i] = code[a[i]-48];//��λ 
	
	return c;
}

void Sort(int c){
	int i,j;
	char(*tmp)[LIM];
	tmp = (char*)malloc(sizeof(char)*LIM);//����Ҫ��ָ�뿪�ռ䣡�����������RE����ֻ�Ǳ��ع���� 
	for(i = 0;i < c;i++){
		for(j = 0;j < c-i-1;j++){
			if(strcmp(lst[j],lst[j+1]) > 0){//�ַ���ֻ��ʹ�ø��Ʋ�������λ�� 
				strcpy(*tmp,lst[j]);
				strcpy(lst[j],lst[j+1]);
				strcpy(lst[j+1],*tmp);
			}
		}
	}
}

int power(int x,int y){
	int p = 1;
	while(y--){
		p *= x;
	}
	return p;
}

int main() {
	int n,i,c,k;
	char* p = a;
	scanf("%d%s%d",&n,a,&k);
	
	Format(p,n);
	
	for(i = 0,c = 0;i <= k;i++){
		c = Convert(0,i,0,n);//c�ں�����Ϊstatic���������һ�����еĺ�����������cֵ 
	}

	Sort(c);

	for(i = 0;i < c;i++){//���ַ���תΪ���֣��Զ�ȥ��ǰ���� 
		int j,tmp = 0;
		for(j = 0;j < n;j++){
			tmp += power(10,n-j-1)*(lst[i][j]-48);
		}
		printf("%d\n",tmp);
	}
	return 0;
}

