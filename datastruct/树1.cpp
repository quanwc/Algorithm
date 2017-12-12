/*
创建一棵二叉查找树
   二叉查找树：根结点的值大于等于左子女的值
               根结点的值小于等于右子女的值
2014年8月29日11:17:50
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


// 创建二叉查找树
BTNode * CreateBTree (int Data[], int n)
{
	BTNode * root, * parent, * current, * insert;
	// 创建根结点
	root = (BTNode * )malloc(sizeof(BTNode));
	root->data = Data[0];
	root->left = root->right = NULL;
	// 创建其它结点
	for (int loop=1; loop<n; ++loop)
	{
		insert = (BTNode * )malloc(sizeof(BTNode));
		insert ->data = Data[loop];
		insert->left = insert->right = NULL;

		current = root;// for循环每次都会进来一个元素，并且每个元素刚进来还不知道
                      // 要往哪里插，也就是说每个元素都要判断待插位置，所以每次在
                      //while循环之前都要将current指向根结点root。
		while(current)   // while循环是为了找出待插结点的位置
		{      // 所以让current一直往下跑，parent且一直在 
			parent = current;//current的上面，一直循环，直到current为0，找出要插入节点的位置
			if(current->data > insert->data )
			{          //  当前的current与待插结点做比较，决定是左走还是右走
		        current = current->left ;// 就这样一直比较下去，直到current为0，
			}                            // 找到待插位置。
			else 
				current = current->right ;
		}

		if(parent->data > insert->data )// if是为了判断insert是左插还是右插，
		{                           
			parent->left = insert;    // 即：判断parent->left指向insert还是
		}                    //  parent->right指向insert
		else
			parent->right = insert;
	}
	return root;

}


int main(void)
{
	int Data[8]={10,20,30,40,50,60,70,80};
	BTNode * root;

	// 创建二叉查找树
	root = CreateBTree(Data, 8);
	return 0;
}