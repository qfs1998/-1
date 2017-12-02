#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct BitNode
{
	char data;
	BitNode* lchild, *rchild;
}BiTNode, *BiTree;
//copy


//my
void CreatBiTree(BiTree&T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode))))
		{
			cout << "空间申请失败\n";
			return;
		}
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	return;
}

void PreorderTraverse(BiTree&T)
{
	if (T)
	{
		cout << T->data << ' ';
		PreorderTraverse(T->lchild);
		PreorderTraverse(T->rchild);
	}
	return;
}

void InorderTraverse(BiTree&T)
{
	if (T)
	{
		InorderTraverse(T->lchild);
		cout << T->data << ' ';
		InorderTraverse(T->rchild);
	}
	return;
}

void PostorderTraverse(BiTree&T)
{
	if (T)
	{
		PostorderTraverse(T->lchild);
		PostorderTraverse(T->rchild);
		cout << T->data << ' ';
	}
	return;
}
//所有节点数my法一
void AllNodeCount(BiTree&T, int &count)
{
	if (!T)
		return;
	else
	{
		++count;
		AllNodeCount(T->lchild, count);
		AllNodeCount(T->rchild, count);
	}
	return;
}
//所有节点法二
int AllNodeCount_Copy(BiTree&T)
{
	int num = 0;
	if (!T)
		return 0;
	num = 1 + AllNodeCount_Copy(T->lchild) + AllNodeCount_Copy(T->rchild);
	return num;
}

int Leaf_Count(BiTree&T)
{
	int count = 0;
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild)
		return 1;
	else
		count = Leaf_Count(T->lchild) + Leaf_Count(T->rchild);
	return count;
}

int Depth(BiTree&T)
{
	if (!T)
		return 0;
	int ldepth = 0, rdepth = 0;
	 ldepth = Depth(T->lchild);
	 rdepth = Depth(T->rchild);
	return  1+(ldepth > rdepth ? ldepth : rdepth);
}

//Queue
typedef struct QNode
{
	BiTree data;
	QNode*next;
}QNode, *QNodePtr;
struct ListQueue
{
	QNodePtr front;
	QNodePtr rear;
};
void InitListQueue(ListQueue&T)
{
	T.front = (QNodePtr)malloc(sizeof(QNode));
	if (!T.front)
	{
		cout << "申请空间失败\n";
		return;
	}
	T.rear = T.front;
	return;
}

void AddElem(ListQueue&Q,const BiTree&T )
{
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	if (!p)
	{
		cout << "申请空间失败\n";
		return;
	}
	p->data = T;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

BiTree DeleteQNode(ListQueue&Q)
{
	if (Q.front==Q.rear)
	{
		cout << "空队列\n";
		return NULL;
	}
	QNodePtr p = Q.front->next;
	BiTree T = p->data;
	
	if (p == Q.rear)
		Q.rear = Q.front;
	Q.front->next = p->next;
	free(p);
	return T;
}
void BiTreeTraverse_Queue(BiTree T, ListQueue&Q)
{
	if (!T)
		return;
	BiTree p = T;
	AddElem(Q, p);
	while (Q.front != Q.rear)
	{
		p = DeleteQNode(Q);
		cout << p->data << ' ';
		if (p->lchild)AddElem(Q,p->lchild);
		if (p->rchild)AddElem(Q,p->rchild);
	}
	return;
}