/*
����������
	��ʽ�洢
2015��1��19��23:41:09
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
	HuffTree * *F;	// Fָ��ɭ��
	HuffTree  * end; //����������
	int n;			// Ҷ�Ӹ���
	printf("please input n:\n");
	scanf("%d", &n);
	F = (HuffTree**)malloc(n*sizeof(HuffTree));//����ɭ��
	
	//��ʼ��Ҷ��
	for(int i=0; i<n; ++i)
	{
		F[i] = (HuffTree*)malloc(HuffTree); //ÿ�δ���һ��Ҷ��

		//��ʼ��Ҷ�ӽڵ���Ϣ
		printf("������һ���ַ�:\n");
		scanf("%c", &F[i].word);
		fflush(stdin);
		printf("�������ַ���Ȩֵ:\n");
		scanf("%d", &F[i].weight);
		fflush(stdin);
		F[i].left = F[i].right = NULL;
	}

	end = createHuffmanTree(F, n);
	return 0;
}