//	�����������ݵ�ĩβ����û���ݴ��������޷���֤������λС����
//	����ͨ��modi�����������ȥβ������

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

int min(int a,int b){
	a = a < b ? a : b;
}

//void�������ڴ洢�����С��n���ں�������ɡ�ȥ��С���㡱�͡�ȥ��ĩβ0������������ 
void modi(char a[],char n[]){
	int tmp = 40,flag = 1,i = 0,l = 0;
	for(i = 0;i < 40;i++){
		if(i == 0){
			a[i] = n[i];
			if(a[i] == '0'){
				tmp = min(tmp,i);//tmp��¼������ֵ�0��λ�� 
				flag &= 0;
			}
		}
		else{
			a[i] = n[i+1];
			if(a[i] == '0'){
				tmp = min(tmp,i);
				flag &= 0;//���������һ�γ���0��flag = 0����������0����flag = 0
			}
			else if(a[i] == '\0'){
				l = i;
				break;
			}
			else{
				flag = 1;//һ��0�������������ˢ��tmpλ�ú�flag״̬
				tmp = 40;
			}
		}
	} 
	if(flag == 0){
		if(tmp == 0){// �˴����Ի���Ϊ��ʵ��Ϊ��0.0����ȷ�������������̫�����⡣ 
			a[tmp] = '\0';
		}
		else{
			for(i = 0;i < tmp-1;i++){
			a[i] = a[i];
			}
			a[i+1] = '\0';
		}
	}
	
} 

int main() {
	char n[41] = {'0'},a[40] = {'0'},e;
	int k = 0,tmp = 0,flag = 0,i = 0;
	scanf("%s %c %d",n,&e,&k);

	modi(a,n);

	if(k > 38){//k̫������ҳ��� 
		for(i = 0;i < 40;i++){
			if(a[i] == '\0'){
				tmp = i;
				break;
			}
			else printf("%c",a[i]);
		}
		for(i = tmp+1;i < k+tmp-38;i++){
			printf("0");
		}
		printf(".");
		for(i = 0;i < 8;i++){
			printf("0");
		}
		printf("\n");
	}
	else if(k < 0){ 
		printf("0.");//С���������ƶ������ݿ�ѧ��������ֱ�����¡�0.����ǰ 
		for(i = 0;i < ((-k-1)<8 ? (-k-1) : 8);i++){//�˴��ж�kֵ�Ƿ��С��������������0
			printf("0");
		}
		for(i = 0;i < 9+k;i++){
			if(a[i] == '\0'){
				tmp = i;
				break;
			}
			else printf("%c",a[i]);
			
		}
		for(i = tmp;i < 9+k;i++){
			printf("0");
		}
		printf("\n");		
	}
	else{//�˴�������������ֱ����ַ���a��С����ǰ�ľ�����С�����ľ������
		for(i = 0;i < 1+k;i++){
			if(a[i] == '\0'){
				tmp = i;
				for(i = tmp;i < 1+k;i++){
					printf("0");
				}
				break;
			}
			else printf("%c",a[i]); 
		}
		printf(".");
		for(i = 1+k;i < 9+k;i++){
			if(a[i] == '\0'){
				tmp = i;
				for(i = tmp;i < 9+k;i++){
					printf("0");
				}
				break;
			}
			else printf("%c",a[i]); 
		}
		printf("\n");
	}
	return 0;
}



