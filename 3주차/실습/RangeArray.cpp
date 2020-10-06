#include "RangeArray.h"
#include<iostream>
#include<cstdlib>
using namespace std;

// 생성자
RangeArray::RangeArray(int low, int high) : Array(high-low+1){
	this->low=low;
	this->high=high;
}

//소멸자
RangeArray::~RangeArray(){
}

int RangeArray::baseValue(){
	return low;
}
int RangeArray::endValue(){
	return high;
}

//[]연산자 다중정의
//삽입
int & RangeArray::operator[](int i){
	static int temp;
	if(i>=low && i<=high){
		return data[i-low];
	}
	else{
		cerr << "Array bound error!\n";
		//return 0;
		return temp;
	}
}
//반환
int RangeArray::operator[](int i) const{
	if(i>=low && i<=high){
		return data[i-low];
	}
	else{
		cerr << "Array bound error!\n";
		return 0;
	}
}
