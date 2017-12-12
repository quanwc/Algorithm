/*
�Թ����⣺
2015-01-30 15:24:50 
*/ 

# include <stdio.h>

const int endx=3;  //������ 
const int endy=3;

int Maze[4][4]={0,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};//�����Թ� 
int move[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}}; // �����ĸ����� 
int path[16][2];//��ά���飬���·������:(ջ) 
int count=0;//��ĸ��� 
int top=0;//ָ��ջ

void print()
{
	printf("��%d��·��:\n", ++count);
	for(int i=0; i<top+1; ++i)
	{
		printf("(%d, %d) ", path[i][0], path[i][1]);
	}
	printf("\n");
} 
void Mgpath(int x, int y)
{
	int j, a, b;
	for(j=0; j<4; ++j)//����4������
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
			
			//Ĩa��b
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
	Mgpath(0,0);//ÿ�ζ��Ǵ�����ӣ�ÿ�����ӵĴ���һ�� 
	return 0;
} 

/*
�������н����ȷ��
��1��·��:
(0, 0) (1, 0) (2, 0) (2, 1) (3, 1) (3, 2) (3, 3)
��2��·��:
(0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (3, 2) (3, 3)
��3��·��:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (3, 2) (3, 3)
��4��·��:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (2, 1) (3, 1) (3, 2) (3, 3) 
*/
