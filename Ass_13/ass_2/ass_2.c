#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE*fp;
	char file[41],line[41],ch;
	int n = 0,i = 0;
	gets(file);
	scanf("\n%d",&n);
	if((fp = fopen(file,"r")) == NULL)printf("File Name Error.\n");
	else{
		while((ch = fgetc(fp)) != EOF){
			if(ch == '\n')i++;//���ڳ�ʼ��������Ϊ�� 
			if(i == n-1)break;
		}
		if(ch == EOF)printf("Line No Error.");
		if(i == n-1){
			while((ch = fgetc(fp)) != '\n' && ch != EOF)printf("%c",ch);//�Ի��з���Ϊ�жϱ��Ͳ������ 
			if(ch == EOF)printf("Line No Error.");
		}
		printf("\n");
	} 
	return 0;
}

