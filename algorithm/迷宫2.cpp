/*
迷宫问题：
2015-01-30 15:24:50 
*/ 

# include <stdio.h>

const int endx=3;  //　出口 
const int endy=3;

int Maze[4][4]={0,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};//定义迷宫 
int move[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}}; // 定义四个方向 
int path[16][2];//二维数组，存放路径坐标:(栈) 
int count=0;//解的个数 
int top=0;//指向栈

void print()
{
	printf("第%d组路径:\n", ++count);
	for(int i=0; i<top+1; ++i)
	{
		printf("(%d, %d) ", path[i][0], path[i][1]);
	}
	printf("\n");
} 
void Mgpath(int x, int y)
{
	int j, a, b;
	for(j=0; j<4; ++j)//遍历4个方向
	{
		a = x + move[j][0];
		b = y + move[j][1];
		if(a>=0&&a<4 && b>=0&&b<4 &&!Maze[a][b])
		{
			Maze[a][b] = 1;
			top++;
			path[top][0] = a;
			path[top][1] = b;
			if(a==endx&&b==endy)
			{
				print();
			}
			else
			{
				Mgpath(a, b);
			} 
			
			//抹a，b
			Maze[a][b] = 0;
			top--; 
		}
	} 
}

 
int main(void)
{
	path[top][0] = 0;
	path[top][1] = 0;
	Maze[0][0] = 1;
	Mgpath(0,0);//每次都是处理格子，每个格子的处理都一样 
	return 0;
} 

/*
程序运行结果正确：
第1组路径:
(0, 0) (1, 0) (2, 0) (2, 1) (3, 1) (3, 2) (3, 3)
第2组路径:
(0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (3, 2) (3, 3)
第3组路径:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (3, 2) (3, 3)
第4组路径:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (2, 1) (3, 1) (3, 2) (3, 3) 
*/
