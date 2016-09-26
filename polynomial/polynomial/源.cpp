#define _CRT_SECURE_NO_WARNINGS
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
//定义多项式链表的'结点'存储结构，每一个结点对应稀疏多项式中的一项 
typedef struct LNode {
	float _coef; //多项式的系数 
	int _expn; //多项式的指数
	struct LNode *_next; //指向下一个多项式结点的指针 
} *Link;
//定义'多项式链表'存储结构 
typedef struct {
	Link _head, _tail; //指向多项式链表的‘头结点’、‘尾结点’的指针 
	int _len; //多项式链表中除去头结点后的结点数，即多项式的项数 
}LinkList;
typedef LinkList Polynomial; //定义一元稀疏多项式类型Polynomial 
							 /* 根据用户输入的多项式的系数和指数float coef, int expn，生成多项式结点*/
bool MakeNode(Link *p, float coef, int expn);
/* 初始化一个带头节点单链表头、尾指针均指向_head, _tail头结点*/
void InitList(LinkList *L);
/*销毁带头节点单链表L，多项式链表使用完后，应将链表占用的内存进行释放*/
void DestroyList(LinkList *L);
/*一元多项式类型接口函数的定义部分,此部分对Polynomial类型的使用者公开*/
void CreatPolyn(Polynomial *p);
/*销毁一元稀疏多项式链表，程序结束前应调用此函数释放多项式链表内存*/
void DestroyPolyn(Polynomial *p);
/*以多项式指数递减格式输出一元稀疏多项式，例如： 34X^100 + 45X^60 –4X^2 + 3*/
void PrintPolyn(const Polynomial *p);
/*两个一元稀疏多项式Pa、Pb相加、相减、相乘，生成和多项式链表PSum*/
void AddPolyn(Polynomial& Pa, Polynomial& Pb, Polynomial& PSum);
void SubPolyn(Polynomial& Pa, Polynomial& Pb, Polynomial& PSub);
void MultiplyPolyn(Polynomial& Pa, Polynomial& Pb, Polynomial& PMulti);
int main() {
	int Len = 5;
	double *coef = (double*)malloc(Len * sizeof(double));
	int *expn = (int *)malloc(Len * sizeof(int));
}
bool MakeNode(Link *p, float coef, int expn) {
	(*p)->_coef = coef;
	(*p)->_expn = expn;
	if (!(*p)) {
		return false;
	}
	return true;
}
void InitList(LinkList *L) {
	L->_head->_next = NULL;
	L->_tail = L->_head;

}
void DestroyList(LinkList *L) {
	Link p, q;
	p = L->_head;
	free(L);
	while (p) {
		q = p->_next;
		free(p);
		p = q;
	}
}
void CreatPolyn(Polynomial *p) {
	InitList(p);
	float coef;
	int expn;
	Link *p1 = NULL;
	while (scanf("%f %d", &coef, &expn) != EOF) {
		*(p1) = (Link)malloc(sizeof(LNode));
		MakeNode(p1, coef, expn);
		p->_tail->_next = (*p1);
		p->_tail = (*p1);
		p->_tail->_next = NULL;
	}

}
void PrintPolyn(const Polynomial *p) {

	while (true)
	{

	}
}