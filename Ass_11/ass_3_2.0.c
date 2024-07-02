#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*�����Ḵ�Ʊ�����ָ�룬Ȼ���뺯������в�����
�ʱ����Ĳ�������ı亯�����������ֵ������ͬ����
����ָ�룬�ิ�ƣ�����ָ��ͬһλ�ã�ȡַ���������ͬһ�ڴ棬��������޸�*/ 
void reflect(double*px,double*py,double w,double l,char dir){
	switch(dir){
		case 'F':
			*px = *px;
			*py = -*py;
			break;
		case 'L':
			*px = -*px;
			*py = *py;
			break;
		case 'R':
			*px = 2*w-*px;
			*py = *py;
			break;
		case 'B':
			*px = *px;
			*py = 2*l-*py;
			break;
	}
}

int main() {
	double w = 0,l = 0,x1 = 0,y1 = 0,x0 = 0,y0 = 0;
	double *px = &x0,*py = &y0;
	char ref[1000];
	scanf("%lf%lf%lf%lf%lf%lf",&w,&l,&x0,&y0,&x1,&y1);
	scanf("%s",ref);
	int i = 0,slen = strlen(ref);
	for(;i < slen;i++){
		reflect(px,py,w,l,ref[i]);
	}
	
	printf("%.4lf\n",sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)));
	return 0;
}


