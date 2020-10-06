#ifndef __STRING__
#define __STRING__

class Str{
	private:
		char*str;//string의 내용
		int len;//string의 길이
	public:
		Str(int leng);//string의 길이
		Str(char *neyong);//neyong은 초기화할 내용
		~Str();//소멸자
		int length();//string의 길이를 리턴하는 함수
		char*contents();//string의 내용을 리턴하는 함수
		int compare(class Str& a);//a의 내용과 strcmp
		int compare(char *a);//a의 내용과 strcmp
		void operator=(char*a);//string의 값을 대입
		void operator=(class Str& a);//Str에 내용을 대입
};

#endif
