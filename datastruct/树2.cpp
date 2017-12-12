/*
将二叉树按层遍历
  2014年8月29日11:58:25
*/

             // 注： 程序运行没有错误
# include <stdio.h>
# include <stdlib.h>
# define   NULL   0
# define   size   10

typedef struct node 
{
	int data;
	struct node * left;
	struct node * right;
}BTNode;


// 创建二叉搜索树
BTNode * createBTree (int Data[], int n)
{
	BTNode * root, * parent, * current, * insert;
	// 创建根结点
	root = (BTNode * )malloc(sizeof(BTNode));
	root->data = Data[0];
	root->left = root->right =	NULL;
	// 创建其它结点
	for (int loop=1; loop<n; ++loop)
	{
		insert = (BTNode * )malloc(sizeof(BTNode));
		insert->data = Data[loop];
		insert->left = insert->right = NULL;
		current = root;
		while (current)
		{
			parent = current;
			if(current->data > insert->data )
			{
                current = current->left ;
			}
			else
				current = current->right ;
		}

		if(parent->data > insert->data )
		{
			parent->left = insert;
		}
		else
			parent->right = insert;
	}
	return root;
}


void levelorder(BTNode * root)
{
	BTNode * p;
	BTNode ** Q;
	int front,rear;
	// 创建循环队列
	Q = (BTNode ** )malloc(size*sizeof(BTNode * ));
	front = rear = 0;
	// 按层遍历
    rear = (rear+1)%size;
	Q[rear] = root;
	while(front-rear)
	{
		front = (front+1)%size;
		p = Q[front];
		printf("%5d", p->data );
		if(p->left)
		{
			rear = (rear+1)%size;
			Q[rear] = p->left ;
		}
		if(p->right)
		{
			rear = (rear+1)%size;
			Q[rear] = p->right ;
		}
	}
}


int main(void)
{
	int Data[8]={10,20,30,40,50,60,70,80};
	BTNode * root;
	// 创建二叉搜索树
	root = createBTree(Data, 8);

	// 按层遍历二叉搜索树
	levelorder(root);
	printf("\n");
	return 0;
}


/*
运行结果正确：
   10   20   30   40   50   60   70   80
Press any key to continue
*/