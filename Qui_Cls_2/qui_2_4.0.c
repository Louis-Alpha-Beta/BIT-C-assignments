#include<stdio.h>
#define Mx 100

int l1,l2,s1[Mx+5],s2[Mx+5],F[Mx+5][Mx+5];
inline int ck(char ch)
{
	return ch==32||ch==10||ch==EOF||ch=='\r'||ch=='\0'?0:ch;//����Ƿ��ַ������ڶ��� 
}
#define gc getchar
#define pc putchar
inline char gt()
{
	char ch;
	for(ch=gc();!ck(ch);ch=gc());//���룬Ӧ���ܹ���Ԥ�ÿ�ֵ�ܺ��Ǹ������� 
	return ch;
}
int ans,chr[Mx+5];
inline void Slv(int x,int y,int z);
inline void Get(int a,int b,int x,int y,int z)
{
	int i,j;
	chr[z]=s1[a];//��Ծǰ��¼ 
	Slv(a-1,b-1,z-1);//�߽�Խǣ�������Ծ 
	for(i=a;i<=x&&F[i][b-1]^z;i++);//�Ȱ�λ��򣬺��߼��룬�ҵ������������λ�ã����ж��Ƿ�Ϸ� 
	if(i>x)return;//�����Ͳ��������˳� 
	for(j=b;j&&F[i][j]==z;j--);//�����ҵ��߽� 
	j++;
	Get(i,j,x,y,z);//�ȼ���ѭ�� 
}
inline void Slv(int x,int y,int z)
{
	if(!z)//���LCS���� 
	{
		int i;
		for(i=1;i<=ans;i++)pc(chr[i]);
		pc(10);//���'\n' 
		return;
	}
	int i,j;
	for(i=x;i&&F[i][y]==z;i--);//���ض�˳�����Ϻ��󣩵ķ�ʽ�ҵ���ǰ������dp��ı߽� 
	i++;
	for(j=y;j&&F[i][j]==z;j--);
	j++;
	Get(i,j,x,y,z);//�ȼ���ѭ�� 
}
inline int Max(int x,int y)
{
	return x>y?x:y;
}
#define output 0
signed main()
{
	int i,j;char ch;
	for(ch=gt();ck(ch);ch=gc())s1[++l1]=ck(ch);//����str1���� 
	for(ch=gt();ck(ch);ch=gc())s2[++l2]=ck(ch);//����str2���� 
	for(i=1;i<=l1;i++)for(j=1;j<=l2;j++)if(s1[i]==s2[j])F[i][j]=F[i-1][j-1]+1;else F[i][j]=Max(F[i-1][j],F[i][j-1]);//�ҵ�LCS���� 
	Slv(l1,l2,ans=F[l1][l2]);//ͨ�����µ��������֤Ψһ�Ժ��걸�� 
	return output;
}

