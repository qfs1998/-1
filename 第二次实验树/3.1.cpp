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
	cout << "���нڵ���"<<AllNodeCount_Copy(T) << endl;
	cout << "Ҷ�ڵ�"<<Leaf_Count(T) << endl;
	cout << "���"<<Depth(T) <<endl;
	ListQueue Q;
	InitListQueue (Q);
	cout << "��α���Ϊ";
	BiTreeTraverse_Queue(T, Q);
	cout << endl;
	system("pause");
	return 0;
}