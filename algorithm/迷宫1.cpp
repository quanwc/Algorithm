/*
迷宫：
2015年1月30日11:44:45 
*/

# include <stdio.h>

int move[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int chess[4][4] = {1,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};
int cnt=1; // 遍历迷宫，存放路径 
int count=0;// 遍历有多少组解 
int minload[4][4];
int min;
void print()
{
	printf("第%d组解为:\n", ++count);
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			printf("%3d", chess[i][j]);
		printf("\n");
	} 
	if(count==1)//如果是第一组解 
	{			// 将cnt给最小值， 将此时的棋盘(迷宫)给路径最短的迷宫minload 
		min = cnt;// 下一次进来又有最短路径的迷宫了，将其上次的minload覆盖 
		for(int i=0; i<4; ++i)
		{
			for(int j=0; j<4; ++j)
			{
				minload[i][j] = chess[i][j];
			}
		}
	}
	else
	{
		if(cnt<min)
		{
			min = cnt;
			for(int i=0; i<4; ++i)
			{
				for(int j=0; j<4; ++j)
				{
					minload[i][j] = chess[i][j];
				}
			}
		}
	}
}


void mi_gong(int x, int y)
{
	const int endx = 3;//endx是常量，不能赋值 
	const int endy = 3;
	int a, b;
	for(int i=0; i<4; ++i)//遍历4个方向 
	{
		a = x + move[i][0];
		b = y + move[i][1];
		if(chess[a][b] == 0&&a>=0&&a<=3&&b>=0&&b<=3)
		{
			chess[a][b] = ++cnt;
			if(a==endx&&b==endy)
			{
				print();
				
			} 
			else
			{
				mi_gong(a, b);
			}
			// 抹a，b 
			cnt--;
			chess[a][b] = 0;
		}
		
	}
			
}
 
int main(void)
{
	mi_gong(0,0);
	printf("最短路径为:\n");
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			printf("%3d", minload[i][j]);
		printf("\n");
	}
	return 0;
}

/*
程序运行结果正确：
第1组解为:
  1  0  0 -1
  2 -1  0  0
  3  4  0 -1
 -1  5  6  7
第2组解为:
  1  0  0 -1
  2 -1  0  0
  3  4  5 -1
 -1  0  6  7
第3组解为:
  1  2  3 -1
  0 -1  4  0
  0  0  5 -1
 -1  0  6  7
第4组解为:
  1  2  3 -1
  0 -1  4  0
  0  6  5 -1
 -1  7  8  9
最短路径为:
  1  0  0 -1
  2 -1  0  0
  3  4  0 -1
 -1  5  6  7
*/
