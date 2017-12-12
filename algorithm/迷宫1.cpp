/*
�Թ���
2015��1��30��11:44:45 
*/

# include <stdio.h>

int move[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int chess[4][4] = {1,0,0,-1,0,-1,0,0,0,0,0,-1,-1,0,0,0};
int cnt=1; // �����Թ������·�� 
int count=0;// �����ж������ 
int minload[4][4];
int min;
void print()
{
	printf("��%d���Ϊ:\n", ++count);
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			printf("%3d", chess[i][j]);
		printf("\n");
	} 
	if(count==1)//����ǵ�һ��� 
	{			// ��cnt����Сֵ�� ����ʱ������(�Թ�)��·����̵��Թ�minload 
		min = cnt;// ��һ�ν����������·�����Թ��ˣ������ϴε�minload���� 
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
	const int endx = 3;//endx�ǳ��������ܸ�ֵ 
	const int endy = 3;
	int a, b;
	for(int i=0; i<4; ++i)//����4������ 
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
			// Ĩa��b 
			cnt--;
			chess[a][b] = 0;
		}
		
	}
			
}
 
int main(void)
{
	mi_gong(0,0);
	printf("���·��Ϊ:\n");
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			printf("%3d", minload[i][j]);
		printf("\n");
	}
	return 0;
}

/*
�������н����ȷ��
��1���Ϊ:
  1  0  0 -1
  2 -1  0  0
  3  4  0 -1
 -1  5  6  7
��2���Ϊ:
  1  0  0 -1
  2 -1  0  0
  3  4  5 -1
 -1  0  6  7
��3���Ϊ:
  1  2  3 -1
  0 -1  4  0
  0  0  5 -1
 -1  0  6  7
��4���Ϊ:
  1  2  3 -1
  0 -1  4  0
  0  6  5 -1
 -1  7  8  9
���·��Ϊ:
  1  0  0 -1
  2 -1  0  0
  3  4  0 -1
 -1  5  6  7
*/
