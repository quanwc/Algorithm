/*
�Թ����⣺
			�������·���� �������̵�·��
			����ж�����·�������������� ·�� 
	2015��1��30��20:42:32 
*/ 

# include <stdio.h>
# include <stdlib.h>

typedef struct
{
	int x;
	int y;
}ElemPath; 

const int endx=3;//������� 
const int endy=3;

int top=0; // top��ʾ����ǰ·�������·��
int count=0;// ��ʾ��ĸ���
 
int Maze[4][4]={0,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};
int move[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
int path[16][2];//���·�� 
int MinPathLength=0; // ���·������
int MinPathCount=0; // ���·������ 

ElemPath ** MP;//MP����Ϊȫ�ֵĿ���ֱ���ã����ô��� 

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
	//���·��
	printf("��%d��⣺\n", ++count);
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
			
			// Ĩa��b
			Maze[a][b] = 0; 
			top--;
		}
	}
	
// ���for��4�����򶼷������ˣ�û�п��Եط����Է��ʣ���ô�ͻ��ϴεĵ���	
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
		printf("����%d�����·��:\n", MinPathCount);
		for(int i=0; i<MinPathCount; ++i)
		{
			printf("��%d�����·��:\n", i+1); 
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
		free(MP);// �ͷ�ָ��MP��ָ��Ķ��� 
	return 0;
} 

/*
�������н����ȷ��
��1��⣺
(0, 0 ):
(1, 0 ):
(2, 0 ):
(2, 1 ):
(3, 1 ):
(3, 2 ):
(3, 3 ):

��2��⣺
(0, 0 ):
(1, 0 ):
(2, 0 ):
(2, 1 ):
(2, 2 ):
(3, 2 ):
(3, 3 ):

��3��⣺
(0, 0 ):
(0, 1 ):
(0, 2 ):
(1, 2 ):
(2, 2 ):
(3, 2 ):
(3, 3 ):

��4��⣺
(0, 0 ):
(0, 1 ):
(0, 2 ):
(1, 2 ):
(2, 2 ):
(2, 1 ):
(3, 1 ):
(3, 2 ):
(3, 3 ):

����3�����·��:
��1�����·��:
(0, 0) (1, 0) (2, 0) (2, 1) (3, 1) (3, 2) (3, 3)
��2�����·��:
(0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (3, 2) (3, 3)
��3�����·��:
(0, 0) (0, 1) (0, 2) (1, 2) (2, 2) (3, 2) (3, 3) 
*/
