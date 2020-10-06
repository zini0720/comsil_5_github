#include "Array.h"
#include<iostream>
#include<cstdlib>
using namespace std;

//생성자
Array::Array(int size){
	if(size <=0){
		cerr<<"Size error\n";
		exit(-1);
	}

	data = new int[size];
	if(data == NULL){
		cerr << "Memory allocation error\n";
		exit(-1);
	}
	len = size;
}

//소멸자
Array::~Array(){
	delete[] data;
}

int Array::length() const{
	return len;
}

//[] 연산자 다중정의
//배열에 값을 삽입
int& Array::operator[](int i){
	static int temp;//static으로 받아야함
	if(i>=0 && i<len){
		return data[i];
	}
	else{
		cerr << "Array bound error!\n";
		//return 0;에러 나옴 -> int&로 나와야 함
		return temp;
	}
}

//배열에 값을 읽어 반환
int Array::operator[](int i) const{
	if(i>= 0 && i<len){
		return data[i];
	}
	else{
		cerr << "Array bound error!\n";
		return 0;
	}
}


void Array::print(){
	cout << "[";
	for(int i=0;i<len;i++){
		cout << ' ' << data[i];
	}
	cout << "]\n";
}



