#ifndef GROWABLE_ARRAY_H
#define GROWABLE_ARRAY_H
#include "Array.h"

using namespace std;

template<typename T>
class GrowableArray:public Array<T>{
public:
	GrowableArray(int size);
	virtual T& operator[](int i);
};

template<typename T>//data에 this 안붙이면 에러나와서 다시 코딩
GrowableArray<T>::GrowableArray(int size){
	if(size<=0){//에러
		cerr<<"Size error\n";
		exit(-1);
	}

	this->data=new T[size];//this 붙이기
	if(this->data==NULL){
		cerr<<"Memory allocation error!\n";
		exit(-1);
	}
	this->len=size;
}

template<typename T>
T& GrowableArray<T>::operator[](int i){

	if(i>=this->len){//사이즈 두배 증가시키고 0 초기화
		int exlen = this->len;
		while(exlen<=i)	exlen*=2;//될때까지 두배

		//할당
		T *exdata=new T[exlen];
		if(exdata==NULL){
			cerr<<"Memory allocation error!\n";//에러
			exit(-1);
		}

		//할당한 배열에 기존 배열 옮기기
		int i;
		for(i=0;i<this->len;i++)	exdata[i]=this->data[i];
		for(;i<exlen;i++)	exdata[i]=0;//0할당

		T *trash=this->data;//해제하기1
		this->data=exdata;
		this->len=exlen;
		delete[] trash;//해제하기2
	}
	return this->data[i];
}

#endif
