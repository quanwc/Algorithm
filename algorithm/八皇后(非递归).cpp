/*
八皇后排列问题:(非递归) 
2015年1月26日20:07:03 
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
	printf("\n\n第%d组解为:\n", ++cnt);
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
	int top=0;// top的初始值为0， 因为top已经指向了栈的第一个元素，本应该指向第一个栈底元素-1 
	for(i=1; i<8 && i>0; ++i)// 每个从第一行开始向上遍历 
	{
		j = Q[top+1] + 1;
		Q[top+1] = -1;
		for(; j<8; ++j)// 遍历每一列 
		{
			if(!col[j] && !left[i+j] && !right[i-j+7])  // 能放 
			{
				col[j] = left[i+j] = right[i-j+7] = 1;// 能放，就修改列、左斜线、右斜线的值 
				Q[++top] = j;
				break;
			} 
		}
		
		//if: j==8 --> i行不可以放皇后， 就抹皇后，调上一行，因为for中有i++，则i=i-2，才能回到上一行 
		if(j==8) // j==8，没能找到可以存放皇后的位置 
		{
			// 抹皇后 
			top--;//出栈          // i==>top+1  j==>Q[top+1]+1 
			col[Q[top+1]] = left[i-1+Q[top+1]] = right[i-1-Q[top+1]+7] = 0;//
			i-=2;// i-=2，for中在i++才能回到上一行 
		}
		else if(i==7) // 如果i==7，说明是最后一行了， 就要输出了，然后再抹皇后(top下移)，修改列、左斜线、右斜线的值 
		{
			printQueen();
			// 抹皇后
			top--;
			col[j] = left[i+j] = right[i-j+7] = 0;
			i--; // i减1，然后再for中再加1，就刚刚回到本行 
		} 
	}
}


int main(void) 
{
	for(int j=0; j<8; ++j)   // 调8次，每次都是调给定第一个，从最下面一行依次往后调
	{
		Init();
		Q[0] = j;     // 每次讲列标存放到栈底的第一个元素
		col[j] = left[j] = right[-j+7] = 1;
		Queen();
	}
	printf("\n共有%d组解\n", cnt);
	return 0;
}
