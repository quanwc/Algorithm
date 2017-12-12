/*
马踏棋盘（递归） 
2015-01-25 21:01:10 
*/ 

# include <stdio.h> 

int chessboard[8][8]={0};// 棋盘坐标 
int curstep; // 马跳的步骤序号 

typedef struct
{
	int x;
	int y;
}Coordinate;

Coordinate move[8][2]={{1,2}, {2,1}, {-1,2}, {2,-1} ,{-1,-2}, {-2,-1} ,{1,-2}, {-2,1}};



void display()
{
	int i, j;
	for(i=0; i<8; ++i)
		for(j=0; j<8; ++j)
		{
			printf("%5d", chessboard[i][j]);
			printf("\n");
		}
}


void travel(Coordinate curpos)
{
	Coordinate next;
	int i;
	if(curpos.x<0 || curpos.x>7 || curpos.y<0 || curpos.y>7)
	{
		printf("越界");
		return; 
	}
	if(chessboard[curpos.x][curpos.y])
		return;
	
	chessboard[curpos.x][curpos.y] = curstep;
	curstep++;
	if(curstep>64)
	{
		display();
		printf("\n");
	}
	else
	{
		for(i=0; i<8; ++i)
		{
			next.x = curpos.x + move[i].x;
			next.y = curpos.y + move[i].y;
			if(next.x<0 || next.x>7 || next.y<0 || next.y>7);
			else
			{
				travel(next);
			}
		}
	}
	chessboard[curpos.x][curpos.y] = 0;
	curstep--;
}


int main(void)
{
	Coordinate start;
	printf("请输入马的起始位置:\n");
	scanf("%d%d", start.x, start.y); 
	if(start.x <1 || start.x >7 || start.y < 1 || start.y >7)
		{
			printf("坐标输入有误， 请重新输入:\n");
			exit(0); 
		} 
	start.x--;
	start.y--;
	curstep = 1;
	travel(start);
	return 0;
}
