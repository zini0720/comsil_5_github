#include<iostream>
#include"LinkedList.h"
#include"Stack.h"

using namespace std;

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입 2. 삭제 3. 출력 4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요 : ";
}

int main(){
//스택 및 열결 리스트 테스트용 코드
	int mode, selectNumber, tmpItem;
	LinkedList<int> *p;
	bool flag = false;

	cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
	cin>>mode;

	//기반 클래스의 포인터를 사용하여 기반 클래스 뿐만 아니라
	//파생 클래스의 인스턴스 또한 접근할 수 있다
	if(mode == 1)	p=new Stack<int>();
	else	p=new LinkedList<int>();
	//처리부분
	do{
		prnMenu();
		cin>>selectNumber;
		switch(selectNumber){
		case 1:
			cout<<"원하시는 값을 입력해주세요 : ";
			cin>>tmpItem; p->Insert(tmpItem);
			cout<<tmpItem<<"가 삽입되었습니다."<<endl;
			break;
		case 2:
			if(p->Delete(tmpItem)==true)
			cout<<tmpItem<<"가 삭제되었습니다."<<endl;
			else cout<<"비어있습니다. 삭제 실패"<<endl;
			break;
		case 3:
			cout<<"크기: "<<p->GetSize()<<endl;
			p->Print();
			break;
		case 4:
			flag = true; break;
		default:
			cout<<"잘못 입력하셨습니다."<<endl;
			break;
		}
		if(flag) break;
	} while(1);
	return 0;
}
