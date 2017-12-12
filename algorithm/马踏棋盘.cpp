/*
马踏棋盘(递归) 
2015年1月27日11:34:35 
*/ 

# include <stdio.h>

int count=0;
int cnt=1;
int q[12][12];
int move[8][2]={{-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}};
//int move[8][2]={{-2,1}, {1,-2}, {1,2}, {2,1}, {2,-1}, {-1,2}, {-1,-2}, {-2,-1}};

void Init()
{
	for(int i=0; i<12; ++i)
	{
		for(int j=0; j<12; j++)
		{
			if(i>=2&&i<=9 && j>=2&&j<=9)  
			{
				q[i][j] = 0;
			}
			else
			{
				q[i][j] = -1;
			}
		}
	}
}


void print()
{
	printf("\n\n第%3d组解为:\n", ++count);
	for(int i=2; i<=9; ++i)
	{
		for(int j=2; j<=9; ++j)
			printf("%3d", q[i][j]);
		printf("\n");
	}
}


void Horse(int x, int y)
{
	int a, b; 
	int j;
	for(j=0; j<8; ++j)
	{
		a = x + move[j][0];
		b = y + move[j][1]; 
		if(q[a][b]==0)
		{
			q[a][b] = ++cnt;
			if(cnt==64) 
			{
				print();
			}
			else
			{
				Horse(a, b);
			}
			 // 抹
			 cnt--;
			 q[a][b] = 0;
		} 
		
	}
}

int main(void)
{
	Init();
	q[2][2]=1;
	Horse(2,2);
	return 0;
}
