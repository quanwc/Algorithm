/*
约瑟夫环问题：
    有n个小孩手拉手成一圈，从第m个小孩开始，每s个小孩出圈。
	求：小孩出圈序列
2014年9月7日20:48:23
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
	printf("请输入从第几个孩子开始数起,m=:\n");
	scanf("%d", &i);
	printf("请输入每几个孩子要出圈,s=:\n");
	scanf("%d", &s);
	
    JosephusRing(a, N, i, n, s);

	return 0;
}
