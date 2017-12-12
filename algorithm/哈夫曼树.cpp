/*
哈夫曼编码
	链式存储
2015年1月19日23:41:09
*/

# include <stdio.h>
# include <stdlib.h>


typedef struct node
{
	char word;
	int weight;
	struct node * left, * right;
}HuffTree;


HuffTree * createHuffmanTree(HuffTree ** F, int n)
{
	int i, loop, k1, k2;
	HuffTree * p;
	for(k1=0; k1<n&&!F[k1]; k1++);
	for(k21=k1+1; k2<n&&!F[k2]; k2++);
	if(F[i])
	{

	}
}


int main(void)
{
	HuffTree * *F;	// F指向森林
	HuffTree  * end; //在主调接收
	int n;			// 叶子个数
	printf("please input n:\n");
	scanf("%d", &n);
	F = (HuffTree**)malloc(n*sizeof(HuffTree));//创建森林
	
	//初始化叶子
	for(int i=0; i<n; ++i)
	{
		F[i] = (HuffTree*)malloc(HuffTree); //每次创建一个叶子

		//初始化叶子节点信息
		printf("请输入一个字符:\n");
		scanf("%c", &F[i].word);
		fflush(stdin);
		printf("请输入字符的权值:\n");
		scanf("%d", &F[i].weight);
		fflush(stdin);
		F[i].left = F[i].right = NULL;
	}

	end = createHuffmanTree(F, n);
	return 0;
}