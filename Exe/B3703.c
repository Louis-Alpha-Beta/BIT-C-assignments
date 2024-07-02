#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM (int)1e6

char T[LIM][400],S[LIM][400],t[400];

void Initialize1(char*in,int len){//��ʼ��Ϊȫ��a�� 
	int i;
	for(i = 0;i < len;i++){
		*in++ = 'a';
	}
	*in = '\0';
}

int Through1(int i,int len,char*t){//�������г���Ϊlen��Сд�ַ��� 
	if(i >= len)return 0;
	static int c = 0;
	int j;
	for(j = 0;j < 26;j++){
		(*(t+i))++;
		if(*(t+i) > 'z')*(t+i) -= 26;
		strcpy(T[c++],t);
		Through1(i+1,len,t); 
	}
	
	return c;
}

int Through2(int len,char*get){//�������г���Ϊlen��get�Ӵ� 
	int i,glen = strlen(get);
	static int d = 0;
	for(i = 0;i <= glen-len;i++){
		strncpy(S[d++],get+i,len);
	}
	return d;
}

void Sort(int start,int stop,char T[LIM][400]){
	int i,j;
	char(*tmp)[400];
	tmp = (char*)malloc(sizeof(char)*400);
	for(i = start;i < stop;i++){
		for(j = start;j < start+stop-i-1;j++){
			if(strcmp(T[j],T[j+1]) > 0){
				strcpy(tmp,T[j]);
				strcpy(T[j],T[j+1]);
				strcpy(T[j+1],tmp);
			}
		}
	}
}

int Compare1(int start,int stop,char T[LIM][400],char*s){//����Ƿ�����һ�Ӵ� 
	int i;
	for(i = start;i < stop-1;i++){
		if(!strcmp(T[i+1],s))return i;
	}
	return -1;
}

int Compare2(int start,int stop,char S[LIM][400],char*str){//���get���Ƿ��и����ִ� 
	int i;
	for(i = start;i < stop;i++){
		if(!strcmp(S[i],str))return 1;
	}
	return 0;
}

int main() {
	char get[400],s[400];
	int n,i,len,flag,lst[200][2];
	static int c[201],d[201];
	scanf("%s",get);
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d%d",&lst[i][0],&lst[i][1]);
	} 
	for(i = 0;i < n;i++){
		int j;
		len = lst[i][1]-lst[i][0]+1;
		Initialize1(t,len);
		c[i+1] = Through1(0,len,t);
		Sort(c[i],c[i+1],T); 
		strncpy(s,get+lst[i][0],len);
		*(s+len) = '\0';
		d[i+1] = Through2(len,get);
		flag = Compare1(c[i],c[i+1],T,s);
		if(flag == -1)printf("NULL\n");
		else printf("%s\n",T[flag]);
		flag = Compare2(d[i],d[i+1],S,T[flag]);
		if(flag)printf("Happy New Year!\n");
		else printf("Happy Chinese New Year!\n");
	}
	
	return 0;
}

