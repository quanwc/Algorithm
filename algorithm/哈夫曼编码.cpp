/*
��������ʽ�洢
2014��12��15��20:31:45
*/


# include <stdio.h>
# include <stdlib.h>


typedef struct 
{
	char word;
	int left, right;
	int weight;
	int parent;
	int * code;
}HuffTree;



HuffTree * init(int n)
{
	HuffTree * F;
	// ����2n-1��Ԫ�ص�ɭ��
	F = (HuffTree *)malloc((2*n-1)*sizeof(HuffTree));
	for(int i=0; i<n-1; ++i)
	{
		printf("������һ���ַ�:\n");
		scanf("%c", &F[i].word);
		printf("�������ַ���Ȩֵ:\n");
		scanf("%d", &F[i].weight);
		F[i].left = F[i].right = F[i].parent = -1;	
		// ������̬����
		F[i].code  = (int * )malloc(n*sizeof(int));// n����Ϊ�����n-1�㣬����һ��λ��Ҫ���볤
	}
	return F;
}


void CreateHuffmanTree(HuffTree * F, int n)
{
	int k1, k2;
	int j;
	for(int i=0; i<n; ++i)
	{
		for(k1=0; k1<=n+i-1&&F[k1]parent!=-1; ++k1);
		for(k2=k1+1; k2<=n+i-1&&F[k2].parent!=-1; ++k2);
		for(j=k2; j<n+i; j++)
		{
			if(F[j].parent==-1)
			{
				if(F[j].weight<F[k1].weight)
				{
					k2 = k1; 
					k1 = j;
				}
				else if(F[j].weight<F[k2].weight)
					k2 = j;
			}

			F[n+i].weight = F[k1].weight + F[k2].weight;
			F[k1].parent = F[k2].parent = n+i;
			F[n+i].left = k1;
			F[n+i].right = k2;
			F[n+i].parent = -1;
		}
	}
}


void Huffmancode(HuffTree * F, int n)
{
	for(int i=0; i<n; ++i)
	{
		F[i].code[0] = 0;
		c = i;
		while(F[c].parent!=-1)
		{
			p = F[c].parent;
			F[i].code[++F[i].code[0]] = (F[p].right == c);
			c = p;
		}
	}
}


void print(HuffTree * F, int n)
{
	for(int i=0; i<n; ++i)
	{
		printf("%c:", F[i].word);
		for(int j=F[i].code[0]; j>0; --j)// F[i].code[0]��ŵ���Ԫ�ظ����� �Ӻ�����ǰ���
			printf("%3d", F[i].code[j]);
		printf("\n");
	}
}


int main(void)
{
	Huffman * F;// Fָ��ɭ��
	int n;// nΪҶ�Ӹ���
	printf("please input n:\n");
	scanf("%d", &n);
	// ��ʼ��ɭ��
	F = init(n);
	// ����HuffmanTree
	CreateHuffmanTree(F, n);
	// ����
	CreateHuffmanCode(F, n);
	// ���
	print(F, n);
	return 0;
}