/*
�˻ʺ����⣺
	��8*8��Ĺ��������ϰڷŰ˸��ʺ� ʹ�䲻���໥����
	�������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһ��б����
	2015-01-24 22:45:30 
*/ 

# include <stdio.h>

int cnt=0; // �жϹ��ж����ֽ� 
int col[8] ={0}; // �ж���������û�лʺ� 
int left[15] ={0}; // �ж���б����û�лʺ� 
int right[15] ={0}; // �ж���б����û�лʺ� 
int Q[8] ={0}; // ��ʺ��±�Ϊ�ʺ������У�ֵΪ�ʺ����ڵ��� 


void printQueen()
{
	/*
	int flag=1;
	printf("��%2d�ֽ�(*����ʺ�):\n", ++cnt);
	printf(" ");
	for(int i=0; i<8; ++i)
		printf("-");
	printf("\n");
	for(int i=0; i<8; ++i)
	{
		printf("|");
		for(int j=0; j<8; ++j)
		{
			if(Q[i]==j)
				printf("*");
			else
			{
				if(flag<0)
					printf(" ");// �����ɫ��Ԫ��
				else
					printf("#"); 
			}
			flag = -flag;	
		}
		printf("|\n");
		flag = -flag;
	}
	printf(" ");
	for(int i=0; i<8; ++i)
		printf("-");
	printf("\n");
	*/
	printf("\n\n��%2d���Ϊ:\n", ++cnt);
	for(int i=0; i<8; ++i) 
	{
		for(int j=0; j<8; ++j)
			{
				if(Q[i]==j)
					printf("Q");
				else
					printf("X");
			}
		printf("\n");
	}
	//cnt++; // ������printf���Ѿ�ÿ�θ�cnt�ӹ��ˣ� ���Բ��ܸ�cnt�ڼ��ˡ� ������������Ϊ184 
}


void Queen(int i)
{
	for(int j=0; j<8; ++j)  // ����Ϊ��λ�� ����ж� 
	{
		if(col[j]==0 && left[i+j]==0 && right[i-j+7]==0) // ����ܷŻʺ� 
		{
			//��
			Q[i] = j;  // ������Q�д�Żʺ����ڵ��б� ��ÿ�δ������Ķ���Ҫ�����i 
			left[i+j] = 1;
			right[i-j+7] = 1;
			col[j] = 1; // �ܷŻʺ�Ļ����������ڵ��и�ֵΪ1 
			if(i<7)
			{
				Queen(i+1);
			}
			else
				{
					printQueen();
				}
				// Ĩ�ʺ�
			col[j]  = 0;
			left[i+j] = 0;
			right[i-j+7] = 0;
		}
	}
}

int main(void) 
{

	printf("�˻ʺ���������:\n");  
	Queen(0);
	printf("����%d�ֽ�", cnt);
	return 0;
}

/*
�������н����ȷ�� 
��66���Ϊ:
XXXXXQXX
XQXXXXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXQXXX
XXXXXXXQ
XXXQXXXX


��67���Ϊ:
XXXXXQXX
XQXXXXXX
XXXXXXQX
QXXXXXXX
XXXQXXXX
XXXXXXXQ
XXXXQXXX
XXQXXXXX


��68���Ϊ:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX


��69���Ϊ:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXXQ
XXXQXXXX
XQXXXXXX
XXXXXXQX
XXXXQXXX


��70���Ϊ:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXXQ
XXXXQXXX
XQXXXXXX
XXXQXXXX
XXXXXXQX


��71���Ϊ:
XXXXXQXX
XXQXXXXX
XXXXQXXX
XXXXXXQX
QXXXXXXX
XXXQXXXX
XQXXXXXX
XXXXXXXQ


��72���Ϊ:
XXXXXQXX
XXQXXXXX
XXXXQXXX
XXXXXXXQ
QXXXXXXX
XXXQXXXX
XQXXXXXX
XXXXXXQX


��73���Ϊ:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XQXXXXXX
XXXQXXXX
XXXXXXXQ
QXXXXXXX
XXXXQXXX


��74���Ϊ:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XQXXXXXX
XXXXXXXQ
XXXXQXXX
QXXXXXXX
XXXQXXXX


��75���Ϊ:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XXXQXXXX
QXXXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX


��76���Ϊ:
XXXXXQXX
XXXQXXXX
QXXXXXXX
XXXXQXXX
XXXXXXXQ
XQXXXXXX
XXXXXXQX
XXQXXXXX


��77���Ϊ:
XXXXXQXX
XXXQXXXX
XQXXXXXX
XXXXXXXQ
XXXXQXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX


��78���Ϊ:
XXXXXQXX
XXXQXXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXQXXX
XQXXXXXX
XXXXXXXQ


��79���Ϊ:
XXXXXQXX
XXXQXXXX
XXXXXXQX
QXXXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX
XXQXXXXX


��80���Ϊ:
XXXXXQXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXQXXXXX


��81���Ϊ:
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXXXXQ
XXXXXQXX
XXXQXXXX
XQXXXXXX
XXXXQXXX


��82���Ϊ:
XXXXXXQX
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXXQ
XXXXQXXX
XXQXXXXX
XXXXXQXX


��83���Ϊ:
XXXXXXQX
XQXXXXXX
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXQXXXX
XXXXXXXQ
XXXXQXXX


��84���Ϊ:
XXXXXXQX
XXQXXXXX
QXXXXXXX
XXXXXQXX
XXXXXXXQ
XXXXQXXX
XQXXXXXX
XXXQXXXX


��85���Ϊ:
XXXXXXQX
XXQXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX
QXXXXXXX
XXXXXQXX
XXXQXXXX


��86���Ϊ:
XXXXXXQX
XXXQXXXX
XQXXXXXX
XXXXQXXX
XXXXXXXQ
QXXXXXXX
XXQXXXXX
XXXXXQXX


��87���Ϊ:
XXXXXXQX
XXXQXXXX
XQXXXXXX
XXXXXXXQ
XXXXXQXX
QXXXXXXX
XXQXXXXX
XXXXQXXX


��88���Ϊ:
XXXXXXQX
XXXXQXXX
XXQXXXXX
QXXXXXXX
XXXXXQXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX


��89���Ϊ:
XXXXXXXQ
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXQXXXXX
XXXXXQXX


��90���Ϊ:
XXXXXXXQ
XQXXXXXX
XXXXQXXX
XXQXXXXX
QXXXXXXX
XXXXXXQX
XXXQXXXX
XXXXXQXX


��91���Ϊ:
XXXXXXXQ
XXQXXXXX
QXXXXXXX
XXXXXQXX
XQXXXXXX
XXXXQXXX
XXXXXXQX
XXXQXXXX


��92���Ϊ:
XXXXXXXQ
XXXQXXXX
QXXXXXXX
XXQXXXXX
XXXXXQXX
XQXXXXXX
XXXXXXQX
XXXXQXXX
����92�ֽ�
*/
