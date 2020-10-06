#ifndef LINKED_LIST_H//redefinition error 해결
#define LINKED_LIST_H

#include<iostream>
using namespace std;


// Linked List Node
template <typename T>
class Node{
public:
	T data;//int data
	Node *link;
	Node(T element){//int element
		data = element;
		link = 0; }
};


// Linked List Class
template <typename T>
class LinkedList
{
protected:
	Node<T> *first;// Node *first
	int current_size;
public:
	LinkedList(){
		first = 0;
		current_size = 0; };
	int GetSize() { return current_size; }; // 노드 개수를 리턴
	void Insert(T element); // 맨 앞에 원소를 삽입//int element
	virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제//int &element
	void Print(); // 리스트를 출력
};

template <typename T>
void LinkedList<T>::Insert(T element){ // 새 노드를 맨 앞에 붙임//LinkeList::Insert(int element)
	Node<T> *newnode = new Node<T>(element);//Node ...
	newnode->link = first;
	first = newnode;
	current_size++;
}

template<typename T>
bool LinkedList<T>::Delete(T &element){//LinkeList...(int &element)
	// 
	if(first == 0) return false;
	Node<T> *current = first, *previous = 0;//Node
	while(1){ // 
		if(current->link == 0) // find end node
		{
			if(previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;
	return true;
}

//Print() 완성하기
template <typename T>
void LinkedList<T>::Print(){

	Node<T> *node = first;
	if(current_size==0)
		return;
	for(int i=1;i<=current_size;i++){
		cout<<'['<<i<<'|'<<node->data<<']';
		if(i!=current_size)	cout<<"->";//링크
		node=node->link;
	}
	cout<<"\n";
}

#endif
