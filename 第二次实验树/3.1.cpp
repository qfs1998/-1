#include"BiTree.h"
int main()
{
	BiTree T;
    CreatBiTree(T);
	PreorderTraverse(T);
	cout << '\n';
	InorderTraverse(T);
	cout << '\n';
	PostorderTraverse(T);
	cout << '\n';
	cout << "所有节点数"<<AllNodeCount_Copy(T) << endl;
	cout << "叶节点"<<Leaf_Count(T) << endl;
	cout << "深度"<<Depth(T) <<endl;
	ListQueue Q;
	InitListQueue (Q);
	cout << "层次遍历为";
	BiTreeTraverse_Queue(T, Q);
	cout << endl;
	system("pause");
	return 0;
}