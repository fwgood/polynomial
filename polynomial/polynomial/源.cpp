#define _CRT_SECURE_NO_WARNINGS
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
//�������ʽ�����'���'�洢�ṹ��ÿһ������Ӧϡ�����ʽ�е�һ�� 
typedef struct LNode {
	float _coef; //����ʽ��ϵ�� 
	int _expn; //����ʽ��ָ��
	struct LNode *_next; //ָ����һ������ʽ����ָ�� 
} *Link;
//����'����ʽ����'�洢�ṹ 
typedef struct {
	Link _head, _tail; //ָ�����ʽ����ġ�ͷ��㡯����β��㡯��ָ�� 
	int _len; //����ʽ�����г�ȥͷ����Ľ������������ʽ������ 
}LinkList;
typedef LinkList Polynomial; //����һԪϡ�����ʽ����Polynomial 
							 /* �����û�����Ķ���ʽ��ϵ����ָ��float coef, int expn�����ɶ���ʽ���*/
bool MakeNode(Link *p, float coef, int expn);
/* ��ʼ��һ����ͷ�ڵ㵥����ͷ��βָ���ָ��_head, _tailͷ���*/
void InitList(LinkList *L);
/*���ٴ�ͷ�ڵ㵥����L������ʽ����ʹ�����Ӧ������ռ�õ��ڴ�����ͷ�*/
void DestroyList(LinkList *L);
/*һԪ����ʽ���ͽӿں����Ķ��岿��,�˲��ֶ�Polynomial���͵�ʹ���߹���*/
void CreatPolyn(Polynomial *p);
/*����һԪϡ�����ʽ�����������ǰӦ���ô˺����ͷŶ���ʽ�����ڴ�*/
void DestroyPolyn(Polynomial *p);
/*�Զ���ʽָ���ݼ���ʽ���һԪϡ�����ʽ�����磺 34X^100 + 45X^60 �C4X^2 + 3*/
void PrintPolyn(const Polynomial *p);
/*����һԪϡ�����ʽPa��Pb��ӡ��������ˣ����ɺͶ���ʽ����PSum*/
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