/*
八皇后问题：
	在8*8格的国际象棋上摆放八个皇后， 使其不能相互攻击
	即就任意两个皇后都不能处于同一行、同一列或同一条斜线上
	2015-01-24 22:45:30 
*/ 

# include <stdio.h>

int cnt=0; // 判断共有多少种解 
int col[8] ={0}; // 判断所在列有没有皇后 
int left[15] ={0}; // 判断左斜线有没有皇后 
int right[15] ={0}; // 判断右斜线有没有皇后 
int Q[8] ={0}; // 存皇后，下标为皇后所在行，值为皇后所在的列 


void printQueen()
{
	/*
	int flag=1;
	printf("第%2d种解(*代表皇后):\n", ++cnt);
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
					printf(" ");// 输出白色单元格
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
	printf("\n\n第%2d组解为:\n", ++cnt);
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
	//cnt++; // 在上面printf中已经每次给cnt加过了， 所以不能给cnt在加了。 否则结果翻倍，为184 
}


void Queen(int i)
{
	for(int j=0; j<8; ++j)  // 以列为单位， 逐个判断 
	{
		if(col[j]==0 && left[i+j]==0 && right[i-j+7]==0) // 如果能放皇后 
		{
			//放
			Q[i] = j;  // 给数组Q中存放皇后所在的列标 ，每次传过来的都是要处理的i 
			left[i+j] = 1;
			right[i-j+7] = 1;
			col[j] = 1; // 能放皇后的话，给其所在的列赋值为1 
			if(i<7)
			{
				Queen(i+1);
			}
			else
				{
					printQueen();
				}
				// 抹皇后
			col[j]  = 0;
			left[i+j] = 0;
			right[i-j+7] = 0;
		}
	}
}

int main(void) 
{

	printf("八皇后排列问题:\n");  
	Queen(0);
	printf("共有%d种解", cnt);
	return 0;
}

/*
程序运行结果正确： 
第66组解为:
XXXXXQXX
XQXXXXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXQXXX
XXXXXXXQ
XXXQXXXX


第67组解为:
XXXXXQXX
XQXXXXXX
XXXXXXQX
QXXXXXXX
XXXQXXXX
XXXXXXXQ
XXXXQXXX
XXQXXXXX


第68组解为:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX


第69组解为:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXXQ
XXXQXXXX
XQXXXXXX
XXXXXXQX
XXXXQXXX


第70组解为:
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXXXXXQ
XXXXQXXX
XQXXXXXX
XXXQXXXX
XXXXXXQX


第71组解为:
XXXXXQXX
XXQXXXXX
XXXXQXXX
XXXXXXQX
QXXXXXXX
XXXQXXXX
XQXXXXXX
XXXXXXXQ


第72组解为:
XXXXXQXX
XXQXXXXX
XXXXQXXX
XXXXXXXQ
QXXXXXXX
XXXQXXXX
XQXXXXXX
XXXXXXQX


第73组解为:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XQXXXXXX
XXXQXXXX
XXXXXXXQ
QXXXXXXX
XXXXQXXX


第74组解为:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XQXXXXXX
XXXXXXXQ
XXXXQXXX
QXXXXXXX
XXXQXXXX


第75组解为:
XXXXXQXX
XXQXXXXX
XXXXXXQX
XXXQXXXX
QXXXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX


第76组解为:
XXXXXQXX
XXXQXXXX
QXXXXXXX
XXXXQXXX
XXXXXXXQ
XQXXXXXX
XXXXXXQX
XXQXXXXX


第77组解为:
XXXXXQXX
XXXQXXXX
XQXXXXXX
XXXXXXXQ
XXXXQXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX


第78组解为:
XXXXXQXX
XXXQXXXX
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXQXXX
XQXXXXXX
XXXXXXXQ


第79组解为:
XXXXXQXX
XXXQXXXX
XXXXXXQX
QXXXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX
XXQXXXXX


第80组解为:
XXXXXQXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXQXXXXX


第81组解为:
XXXXXXQX
QXXXXXXX
XXQXXXXX
XXXXXXXQ
XXXXXQXX
XXXQXXXX
XQXXXXXX
XXXXQXXX


第82组解为:
XXXXXXQX
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXXQ
XXXXQXXX
XXQXXXXX
XXXXXQXX


第83组解为:
XXXXXXQX
XQXXXXXX
XXXXXQXX
XXQXXXXX
QXXXXXXX
XXXQXXXX
XXXXXXXQ
XXXXQXXX


第84组解为:
XXXXXXQX
XXQXXXXX
QXXXXXXX
XXXXXQXX
XXXXXXXQ
XXXXQXXX
XQXXXXXX
XXXQXXXX


第85组解为:
XXXXXXQX
XXQXXXXX
XXXXXXXQ
XQXXXXXX
XXXXQXXX
QXXXXXXX
XXXXXQXX
XXXQXXXX


第86组解为:
XXXXXXQX
XXXQXXXX
XQXXXXXX
XXXXQXXX
XXXXXXXQ
QXXXXXXX
XXQXXXXX
XXXXXQXX


第87组解为:
XXXXXXQX
XXXQXXXX
XQXXXXXX
XXXXXXXQ
XXXXXQXX
QXXXXXXX
XXQXXXXX
XXXXQXXX


第88组解为:
XXXXXXQX
XXXXQXXX
XXQXXXXX
QXXXXXXX
XXXXXQXX
XXXXXXXQ
XQXXXXXX
XXXQXXXX


第89组解为:
XXXXXXXQ
XQXXXXXX
XXXQXXXX
QXXXXXXX
XXXXXXQX
XXXXQXXX
XXQXXXXX
XXXXXQXX


第90组解为:
XXXXXXXQ
XQXXXXXX
XXXXQXXX
XXQXXXXX
QXXXXXXX
XXXXXXQX
XXXQXXXX
XXXXXQXX


第91组解为:
XXXXXXXQ
XXQXXXXX
QXXXXXXX
XXXXXQXX
XQXXXXXX
XXXXQXXX
XXXXXXQX
XXXQXXXX


第92组解为:
XXXXXXXQ
XXXQXXXX
QXXXXXXX
XXQXXXXX
XXXXXQXX
XQXXXXXX
XXXXXXQX
XXXXQXXX
共有92种解
*/
