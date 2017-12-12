/*
����һ�ö��������
   �����������������ֵ���ڵ�������Ů��ֵ
               ������ֵС�ڵ�������Ů��ֵ
2014��8��29��11:17:50
*/

# include <stdio.h>
# include <stdlib.h>
# define   NULL   0

typedef struct node 
{
	int data;
	struct node * left;
	struct node * right;
}BTNode;


// �������������
BTNode * CreateBTree (int Data[], int n)
{
	BTNode * root, * parent, * current, * insert;
	// ���������
	root = (BTNode * )malloc(sizeof(BTNode));
	root->data = Data[0];
	root->left = root->right = NULL;
	// �����������
	for (int loop=1; loop<n; ++loop)
	{
		insert = (BTNode * )malloc(sizeof(BTNode));
		insert ->data = Data[loop];
		insert->left = insert->right = NULL;

		current = root;// forѭ��ÿ�ζ������һ��Ԫ�أ�����ÿ��Ԫ�ظս�������֪��
                      // Ҫ������壬Ҳ����˵ÿ��Ԫ�ض�Ҫ�жϴ���λ�ã�����ÿ����
                      //whileѭ��֮ǰ��Ҫ��currentָ������root��
		while(current)   // whileѭ����Ϊ���ҳ��������λ��
		{      // ������currentһֱ�����ܣ�parent��һֱ�� 
			parent = current;//current�����棬һֱѭ����ֱ��currentΪ0���ҳ�Ҫ����ڵ��λ��
			if(current->data > insert->data )
			{          //  ��ǰ��current����������Ƚϣ����������߻�������
		        current = current->left ;// ������һֱ�Ƚ���ȥ��ֱ��currentΪ0��
			}                            // �ҵ�����λ�á�
			else 
				current = current->right ;
		}

		if(parent->data > insert->data )// if��Ϊ���ж�insert����廹���Ҳ壬
		{                           
			parent->left = insert;    // �����ж�parent->leftָ��insert����
		}                    //  parent->rightָ��insert
		else
			parent->right = insert;
	}
	return root;

}


int main(void)
{
	int Data[8]={10,20,30,40,50,60,70,80};
	BTNode * root;

	// �������������
	root = CreateBTree(Data, 8);
	return 0;
}