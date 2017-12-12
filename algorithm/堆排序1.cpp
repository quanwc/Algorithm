/*
堆排序
2015年2月2日09:41:49 
*/ 


# include <iostream>
# include <stdlib.h>
using namespace std;


typedef struct node
{
	int data;
	struct node * left;
	struct node * right; 
}BTnode;


void DaGenDui(BTnode*root)
{
	if(root->left)
	{
		DaGenDui(root->left);
		if(root->left->data > root->data)
		{
			int	t = root->left->data;
			root->left->data = root->data;
			root->data = t;
		}
	}
	
	if(root->right)
	{
		DaGenDui(root->right);
		if(root->right->data > root->data) 
		{
			int t = root->right->data;
			root->right->data = root->data;
			root->data = t;
		}
	}
} 

BTnode * createtree(int n, int * Forest)
{
	BTnode * root, *p; 
	root = (BTnode *)malloc(sizeof(BTnode));
	root->data  = Forest[0];
	root->left = root->right = NULL;
	BTnode ** btree = (BTnode **)malloc(n*sizeof(BTnode*)) ;//建队列，按层遍历，生成完全二叉树
	int front = 0, rear = 1;
	btree[0] = root;
	for(int i=1; i<n; ++i)
	{
		p = btree[rear++] = (BTnode*)malloc(sizeof(BTnode));
		p->data = Forest[i];
		p->left = p->right = NULL;
		if(btree[front]->left)
		{
			btree[front++]->right = p;
		}
		else
		{
		btree[front]->left = p;
		} 
	} 
	
	// 处理
	for(int i=0; i<n-1; ++i)
	{
		DaGenDui(root);
		Forest[i] = root->data;
		rear--;
		root->data = btree[rear]->data;
		free(btree[rear]);
		if(rear%2)
		{
			btree[(rear-1)/2]->left = NULL;
		}
		else
		{
			btree[(rear-1)/2]->right = NULL;
		}
	} 
	Forest[n-1] = root->data;
	free(root);
	free(btree);
	return root;
}


int main(void)
{
	int Forest[]={8,2,6,9,20,16,7,4};
	BTnode * root = createtree(8,Forest);
//	dealtree(root,Forest);
//	printtree(head);
cout<<"排序后的顺序为:"<<endl;
for(int i=0; i<8; ++i)
{
	printf("%3d", Forest[i]);
}
	return 0;
} 

/*
程序运行结果正确：
排序后的顺序为:
 20 16  9  8  7  6  4  2
*/
