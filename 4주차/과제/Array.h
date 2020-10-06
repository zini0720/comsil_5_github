#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<cstdlib>

//Array.h내용
using namespace std;

template <typename T>
class Array{
	protected:
		T *data;
		int len;
	public:
		Array(){};//no matching function for call to... 에러 해결
		Array(int size);
		~Array();

		int length() const;

		virtual T& operator[](int i);
		virtual T operator[](int i)const;

		void print();
};


//Array.cpp내용
template <typename T>
Array<T>::Array(int size){
	if(size<=0){
		cerr<<"Size error\n";
		exit(-1);
	}

	data=new T[size];
	if(data==NULL){
		cerr<<"Memory allocation error\n";
		exit(-1);
	}
	len=size;
}

template<typename T>
Array<T>::~Array(){
	delete[] data;
}

template<typename T>
int Array<T>::length() const{
	return len;
}

template<typename T>
T& Array<T>::operator[](int i){
	static T temp;
	if(i>=0 && i<len){
		return data[i];
	}
	else{
		cerr<<"Array bound error!\n";
		return temp;
	}
}

template<typename T>
T Array<T>::operator[](int i)const{
	if(i>=0&&i<len)	return data[i];
	else{
		cerr<<"Array bound error!\n";
		return 0;
	}
}


template<typename T>
void Array<T>::print(){
	cout<<"[";
	for(int i=0;i<len;i++){
		cout<<' '<<data[i];
	}
	cout<<"]\n";
}

#endif
