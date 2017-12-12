/*
Լɪ�����⣺
    ��n��С�������ֳ�һȦ���ӵ�m��С����ʼ��ÿs��С����Ȧ��
	��С����Ȧ����
2014��9��7��20:48:23
*/


# include <stdio.h>
# define   N   10

void JosephusRing(int a[], int N, int m, int n, int s)
{
	int i, j;
	int x;
	i=m-1;
	while (n>1)
	{
		i = (i+s-1)%N;
		x = a[i];
		for(;j<n-1; ++j)
			a[j] = a[j+1];
		a[j] = x;
		n--;

	}
}



int main(void)
{
	int a[N], i;
	a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("please input the number of kids,n=:\n");
	scanf("%d", &n);
	printf("������ӵڼ������ӿ�ʼ����,m=:\n");
	scanf("%d", &i);
	printf("������ÿ��������Ҫ��Ȧ,s=:\n");
	scanf("%d", &s);
	
    JosephusRing(a, N, i, n, s);

	return 0;
}
