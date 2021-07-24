/*
* 单链表数据结构
* 以下代码及注释都是纯小白级别，轻喷。
*/

#include<iostream>
#include <cstdio>
using namespace std;

typedef int ElemType;//定义ElemType为int类型

typedef struct LNode {//单链表：每个结点中只含一个链接域（指针字段）的链表
	ElemType data;//数据域
	struct LNode* next;//指针域
}LNode, * LinkList;
//注意：以上两种重命名的区别
class singlelist {
	public:
		singlelist();
		//~singlelist();
		LNode* CreateNode(ElemType data);//创建结点
		void DisplayNode(LNode* node);//查看结点内容
		void DisplayList();
		void List_HeadInsert(LNode* s);//头插法
		void List_TailInsert(LNode* s);//尾插法
		LNode* GetElem(int index);//按照序号查找
		LNode* LocateElem(ElemType e);
		bool InsertNode(LNode* p,LNode* s);//插入结点在p之后插入s
		bool DeleteNode(LNode* p);//删除该结点
		int getSize();
	private: 
		LinkList head;
		LinkList tail;
		int size;
};
//注意：头指针和头结点的区别、引入头结点的优点
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

void singlelist::DisplayNode(LNode* node) {//用&和*哪个更合适一点。
	if (node == NULL) {
		cout << "没有该结点" << endl;
		return;
	}
	cout << node->data <<" ";
}
void singlelist::DisplayList() {
	cout << "链表内有" << size << "个元素:" ;
	LNode* p=head->next;
	while (p!=NULL) {
		DisplayNode(p);
		p = p->next;
	}
}

/*头插法建立单链表*/
void singlelist::List_HeadInsert(LNode* s) {//LinkList& L
	s->next = head->next;
	head->next = s;
	size++;
}

/*尾插法建立单链表*/
void singlelist::List_TailInsert(LNode* s) {
	tail->next = s;
	tail = s;
	size++;
}

/*按序号查找结点值*/
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

/*按值查找结点*/
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

/*插入结点操作(后插)*/
bool singlelist::InsertNode(LNode* p, LNode* s) {
	s->next = p->next;
	p->next = s;
	size++;
	return true;
}

/*删除结点操作(删除本结点）*/
bool singlelist::DeleteNode(LNode* p) {
	LNode* q;
	q = p->next;
	p->data = p->next->data;//交换数据域
	p->next = q->next;//q结点摘下来
	free(q);
	size--;
	return true;
}

/*求表长*/
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
	s = list.GetElem(2);//按序号查找
	list.DisplayNode(s);
	cout << endl;

	p = list.CreateNode(6);
	list.InsertNode(s, p);
	list.DisplayList();

	cout << endl;
	cout << list.getSize() << endl;
	return 0;
}
