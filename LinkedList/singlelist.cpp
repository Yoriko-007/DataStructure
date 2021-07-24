/*
* ���������ݽṹ
* ���´��뼰ע�Ͷ��Ǵ�С�׼������硣
*/

#include<iostream>
#include <cstdio>
using namespace std;

typedef int ElemType;//����ElemTypeΪint����

typedef struct LNode {//������ÿ�������ֻ��һ��������ָ���ֶΣ�������
	ElemType data;//������
	struct LNode* next;//ָ����
}LNode, * LinkList;
//ע�⣺��������������������
class singlelist {
	public:
		singlelist();
		//~singlelist();
		LNode* CreateNode(ElemType data);//�������
		void DisplayNode(LNode* node);//�鿴�������
		void DisplayList();
		void List_HeadInsert(LNode* s);//ͷ�巨
		void List_TailInsert(LNode* s);//β�巨
		LNode* GetElem(int index);//������Ų���
		LNode* LocateElem(ElemType e);
		bool InsertNode(LNode* p,LNode* s);//��������p֮�����s
		bool DeleteNode(LNode* p);//ɾ���ý��
		int getSize();
	private: 
		LinkList head;
		LinkList tail;
		int size;
};
//ע�⣺ͷָ���ͷ������������ͷ�����ŵ�
singlelist::singlelist(){
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;

	tail = head;

	size = 0;
}

LNode* singlelist::CreateNode(ElemType data) {
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = data;
	s->next = NULL;
	return s;
}

void singlelist::DisplayNode(LNode* node) {//��&��*�ĸ�������һ�㡣
	if (node == NULL) {
		cout << "û�иý��" << endl;
		return;
	}
	cout << node->data <<" ";
}
void singlelist::DisplayList() {
	cout << "��������" << size << "��Ԫ��:" ;
	LNode* p=head->next;
	while (p!=NULL) {
		DisplayNode(p);
		p = p->next;
	}
}

/*ͷ�巨����������*/
void singlelist::List_HeadInsert(LNode* s) {//LinkList& L
	s->next = head->next;
	head->next = s;
	size++;
}

/*β�巨����������*/
void singlelist::List_TailInsert(LNode* s) {
	tail->next = s;
	tail = s;
	size++;
}

/*����Ų��ҽ��ֵ*/
LNode* singlelist::GetElem(int index) {
	int i = 1;
	LNode* p = head->next;
	while (p != NULL&&i<index) {
		p = p->next;
		i++;
	}
	if (i == index) {
		return p;
	}
	else {
		return NULL;
	}
}

/*��ֵ���ҽ��*/
LNode* singlelist::LocateElem(ElemType e) {
	LNode* p = head->next;
	while (p != NULL) {
		if (p->data == e) {
			break;
		}
		p = p->next;
	}
	return p;
}

/*���������(���)*/
bool singlelist::InsertNode(LNode* p, LNode* s) {
	s->next = p->next;
	p->next = s;
	size++;
	return true;
}

/*ɾ��������(ɾ������㣩*/
bool singlelist::DeleteNode(LNode* p) {
	LNode* q;
	q = p->next;
	p->data = p->next->data;//����������
	p->next = q->next;//q���ժ����
	free(q);
	size--;
	return true;
}

/*���*/
int singlelist::getSize() {
	return size;
}

int main(){
	singlelist list;
	LNode* s,* p;
	for (int i = 1; i <= 5; i++) {
		s = list.CreateNode(i);
		list.List_TailInsert(s);
	}
	list.DisplayList();

	cout << endl;
	s = list.GetElem(2);//����Ų���
	list.DisplayNode(s);
	cout << endl;

	p = list.CreateNode(6);
	list.InsertNode(s, p);
	list.DisplayList();

	cout << endl;
	cout << list.getSize() << endl;
	return 0;
}
