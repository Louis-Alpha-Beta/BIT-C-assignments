#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void reverse(char a[]){//�������������У����ں�������λȨֵ�� 
	int i = 0,j = 0,alen = 0;
	char tmp;
	alen = strlen(a);
	for(i = 0,j = alen-1;i < j;i++,j--){
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void pos(char a[],int p[]){//��ȷ�洢��ת����λ���루������ĸ�� 
	int i = 0;
	for(i = 0;i < 41;i++){
		if(a[i] == '\0')break;
		else{
			if((int)a[i]-'0' < 10){
				p[i] = (int)a[i]-'0';//�ַ�ת������ʽ 
			}
			else{
				p[i] = (int)a[i]-'0' - 7;//ǿת�ǰ���ASCII������ɵģ���ȥ��'0' = 48�� 
			}
		}
	}
}

int max(int p[]){//������λ��������Ѱ�ҽ������� 
	int i = 0,max = 0;
	for(i = 0;i < 41;i++){
		max = max > p[i] ? max : p[i];
	}
	return max;
}

int power(int i,int j){
	int k = 0,p = 1;
	for(k = 1;k <= j;k++){
		p *= i;
	}
	return p;
}

int main() {
	int i = 0,j = 0,k = 0,amax = 0,bmax = 0,ares = 0,bres = 0,p[41] = {0},q[41] = {0},flag = 0;
	char a[41] = {0},b[41] = {0};
	scanf("%s%s",a,b);
	
	reverse(a);
	reverse(b);
	
	pos(a,p);
	pos(b,q);
	
	amax = max(p);
	bmax = max(q);

	for(i = amax + 1;i <= 36;i++){
		ares = 0;
		for(j = 0;j < 41;j++){
			ares += p[j]*power(i,j);
		}

		for(j = bmax + 1;j <= 36;j++){
			bres = 0;
			for(k = 0;k < 41;k++){
				bres += q[k]*power(j,k);
			}
			
			if(ares == bres){
			flag = 1;
			break;
			}		
		}
		if(flag == 1)break;	
	}
	if(flag == 1){
		reverse(a);
		reverse(b);
		printf("%s (base %d) = %s (base %d)\n",a,i,b,j);
	}
	else{
		reverse(a);
		reverse(b);
		printf("%s is not equal to %s in any base 2..36\n",a,b);
	}
	
	return 0;
}

