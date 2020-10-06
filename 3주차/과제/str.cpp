#include"string.h"
#include<cstring>
#include<iostream>
using namespace std;

//string길이만큼의 문자열 만들기
Str::Str(int sl){
	//예외처리
	if(sl<0){
		cerr<<"Error : String length is negative\n";
		len=0;//이상한 상황 방지
	}
	str=new char[sl+1];
	for(int i=0;i<sl+1;i++)	str[i]=' ';//모두 공백으로 만들어줌
	str[sl]='\0';
	len=sl;
}

//string 초기화
Str::Str(char*neyong){
	
	if(neyong==NULL){//위와 비슷한 예외처리
		cerr<<"Error : char pointer points NULL\n";
		str = new char[1];
		str[0]='\0';
		len=0;
	}
	else{
		len=strlen(neyong);
		str=new char[len+1];
		strcpy(str,neyong);
	}
}

//소멸자
Str::~Str(){
	delete [] str;
}


//string 길이
int Str::length(){
	return len;
}
//string 내용
char * Str::contents(){
	return str;
}

//다중정의
//string 내용 비교
int Str::compare(class Str & a){
	return strcmp(str,a.contents());
}
int Str::compare(char*a){
	return strcmp(str,a);
}

//다중정의
//string값 대입
void Str::operator=(char*a){
	delete [] str;//초기화하고 시작
	if(a==NULL){//예외처리
		len=0;
		str=new char[0];
		str[0]='\0';
	}
	else{
		len=strlen(a);
		str=new char[len+1];
		strcpy(str,a);
	}
}
//Str의 내용을 대입
void Str::operator=(class Str& a){
	delete [] str;
	len = a.length();
	str = new char[len+1];
	strcpy(str,a.contents());
}

