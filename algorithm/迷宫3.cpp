/*
迷宫问题：
			输出所有路径， 并输出最短的路径
			如果有多个最短路径，输出所有最短 路径 
	2015年1月30日20:42:32 
*/ 

# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	int x;
	int y;
}ElemPath; 

const int endx=3;//定义出口 
const int endy=3;

int top=0; // top表示：当前路径的最短路径
int count=0;// 表示解的个数
 
int Maze[4][4]={0,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};
int move[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
int path[16][2];//存放路径 
int MinPathLength=0; // 最短路径长度
int MinPathCount=0; // 最短路径个数 

ElemPath ** MP;//MP定义为全局的可以直接用，不用传。 

void gua()
{
	MP[MinPathCount] = (ElemPath*)malloc((top+1)*sizeof(ElemPath));
	MinPathLength = top+1; 
	for(int i=0; i<MinPathLength; ++i) 
	{
		MP[MinPathCount][i].x = path[i][0];
		MP[MinPathCount][i].y = path[i][1];
	}
	MinPathCount++;
}

void MgMinPath()
{
	if(count==1)
	{
		gua();
	}
	else if(MinPathLength==top+1)
	{
		gua();
	}
	else if(MinPathLength>top+1)
	{
		for(int i=0; i<MinPathLength; ++i) 
		{
			free(MP[i]);
		}
		MinPathCount=0; 
		gua();
	}
}

void print()
{
	//输出路径
	printf("第%d组解：\n", ++count);
	for(int i=0; i<top+1; ++i) 
	{
		printf("(%d, %d ):\n", path[i][0], path[i][1]);
	}
	printf("\n");
	MgMinPath();
}


void Mgpath(int x, int y)
{
	int j, a, b;
	for(j=0; j<4; ++j)
	{
		a = x + move[j][0];
		b = y + move[j][1]; 
		if(a>=0&&a<=3 && b>=0&&b<=3 && !Maze[a][b])
		{
			Maze[a][b] = 1;
			top++;
			path[top][0] = a;
			path[top][1] = b;
			if(a==endx && b==endy) 
			{
				print();
			}
			else
			{
				Mgpath(a,b);
			}
			
			// 抹a，b
			Maze[a][b] = 0; 
			top--;
		}
	}
	
// 如果for的4个方向都访问完了，没有可以地方可以访问，那么就回上次的调用	
}


int main(void)
{
	MP = (ElemPath**)malloc(12*sizeof(ElemPath)); 
	path[0][0] = 0;//??
	path[0][1] = 0;
	Maze[0][0]=1;
	Mgpath(0,0);
	//for(int i=0; i<MinPathCount; ++i)
	//{
		printf("共有%d组最短路径:\n", MinPathCount);
		for(int i=0; i<MinPathCount; ++i)
		{
			printf("第%d组最短路径:\n", i+1); 
			for(int j=0; j<MinPathLength; j++)
			{
				printf("(%d, %d) ", MP[i][j].x, MP[i][j].y);
			}
			printf("\n");
		}
	//}
	for(int i=0; i<MinPathCount; ++i)
	{
		free(MP[i]);
	
	} 
		free(MP);// 释放指针MP所指向的对象 
	return 0;
} 

/*
程序运行结果正确：
第1组解：
(0, 0 ):
(1, 0 ):
(2, 0 ):
(2, 1 ):
(3, 1 ):
(3, 2 ):
(3, 3 ):

第2组解：
(0, 0 ):
(1, 0 ):
(2, 0 ):
(2, 1 ):
(2, 2 ):
(3, 2 ):
(3, 3 ):

第3组解：
(0, 0 ):
(0, 1 ):
(0, 2 ):
(1, 2 ):
(2, 2 ):
(3, 2 ):
(3, 3 ):

第4组解：
(0, 0 ):
(0, 1 ):
(0, 2 ):
(1, 2 ):
(2, 2 ):
(2, 1 ):
(3, 1 ):
(3, 2 ):
(3, 3 ):

共有3组最短路径:
第1组最短路径:
(0, 0) (1, 0) (2, 0) (2, 1) (3, 1) (3, 2) (3, 3)
第2组最短路径:
(0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (3, 2) (3, 3)
第3组最短路径:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (3, 2) (3, 3) 
*/
