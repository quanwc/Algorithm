/*
�˻ʺ���������:(�ǵݹ�) 
2015��1��26��20:07:03 
*/ 

# include <stdio.h>


int col[8];
int left[15];
int right[15];
int Q[8]; 
int cnt=0;


void Init()
{
	for(int i=0; i<15; ++i)
	{
		left[i] = right[i] = 0;
		if(i<8)
		{
			col[i] =  0;
			Q[i] = -1;
		}
	}
}


void printQueen()
{
	int i, j;
	printf("\n\n��%d���Ϊ:\n", ++cnt);
	for(i=0; i<8; ++i)
	{
		for(j=0; j<8; ++j)
		{
			if(Q[i] == j)
				printf("Q");
			else
				printf("X");
		}
		printf("\n");
	}
} 


void Queen()
{
	int i, j;
	int top=0;// top�ĳ�ʼֵΪ0�� ��Ϊtop�Ѿ�ָ����ջ�ĵ�һ��Ԫ�أ���Ӧ��ָ���һ��ջ��Ԫ��-1 
	for(i=1; i<8 && i>0; ++i)// ÿ���ӵ�һ�п�ʼ���ϱ��� 
	{
		j = Q[top+1] + 1;
		Q[top+1] = -1;
		for(; j<8; ++j)// ����ÿһ�� 
		{
			if(!col[j] && !left[i+j] && !right[i-j+7])  // �ܷ� 
			{
				col[j] = left[i+j] = right[i-j+7] = 1;// �ܷţ����޸��С���б�ߡ���б�ߵ�ֵ 
				Q[++top] = j;
				break;
			} 
		}
		
		//if: j==8 --> i�в����ԷŻʺ� ��Ĩ�ʺ󣬵���һ�У���Ϊfor����i++����i=i-2�����ܻص���һ�� 
		if(j==8) // j==8��û���ҵ����Դ�Żʺ��λ�� 
		{
			// Ĩ�ʺ� 
			top--;//��ջ          // i==>top+1  j==>Q[top+1]+1 
			col[Q[top+1]] = left[i-1+Q[top+1]] = right[i-1-Q[top+1]+7] = 0;//
			i-=2;// i-=2��for����i++���ܻص���һ�� 
		}
		else if(i==7) // ���i==7��˵�������һ���ˣ� ��Ҫ����ˣ�Ȼ����Ĩ�ʺ�(top����)���޸��С���б�ߡ���б�ߵ�ֵ 
		{
			printQueen();
			// Ĩ�ʺ�
			top--;
			col[j] = left[i+j] = right[i-j+7] = 0;
			i--; // i��1��Ȼ����for���ټ�1���͸ոջص����� 
		} 
	}
}


int main(void) 
{
	for(int j=0; j<8; ++j)   // ��8�Σ�ÿ�ζ��ǵ�������һ������������һ�����������
	{
		Init();
		Q[0] = j;     // ÿ�ν��б��ŵ�ջ�׵ĵ�һ��Ԫ��
		col[j] = left[j] = right[-j+7] = 1;
		Queen();
	}
	printf("\n����%d���\n", cnt);
	return 0;
}
