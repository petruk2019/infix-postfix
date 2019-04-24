#include <iostream>
using namespace std;

struct Element{
 string Q[1000];
 int top;
};

class myStack {
 private:
  Element tumpuk;
  Element *head = NULL;
  
 public:
   void init(){
  tumpuk.top = 0;
 }
 char Top(){
		return tumpuk.y[tumpuk.top];
	}
	bool kosong(){
		if(tumpuk.top <= -1)
			return 1;
		else
			return 0;	
	}
	bool isOperand(char pus){
	int x = (int)pus;
	if(x >= 48 && x <= 57 || x >= 65 && x <= 90 || x >= 97 && x <= 122)
		return true;
	else
		return false;
	}
	bool isOperator(char pus){
	int x = (int)pus;
	if(x == 94 || x >= 42 && x <= 43 || x == 45 || x == 47)
		return true;
	else
		return false;
	}
	int getlevel(char pus){
	if(pus == '^')
		return 3;
	else if(pus == '*' || pus == '/')
		return 2;
	else if(pus == '+' || pus == '-')
		return 1;
	else if(pus == '(' || pus == ')')
		return 0;
	else
		return -1;
	}
	bool precedence(char pus1, char pus2){
	int c1 = getlevel(pus1);
	int c2 = getlevel(pus2);

	
