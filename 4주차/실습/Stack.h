#ifndef STACK_H //redefinition error 해결!!!
#define STACK_H

#include "LinkedList.h"

//LinkedList class 상속하기
//Delete 재정의하기
template<typename T>
class Stack:public LinkedList<T>{
public:
	bool Delete(T &element);
};

template <typename T>
bool Stack<T>::Delete(T &element){//앞에거 없애고 하나씩 당기기
	if(this->first==NULL) return false;
	element = this->first->data;//element 업데이트
	Node<T> *temp = this->first;//temp로 first였던 것을 delete해줌
	this->first = this->first->link;
	delete temp;
	this->current_size-=1;
	return true;
}

#endif
