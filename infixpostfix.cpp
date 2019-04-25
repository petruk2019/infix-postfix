Ahmad Julio Rizky 1817051042
Muhammad Arief Islamy 1857051010
	
	
	
	
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
		
	if(c1 <= c2)
		return true;
	else
		return false;
	}
	void push(char puh){
		tumpuk.Q[tumpuk.top] = puh;
		tumpuk.top++;
	}
void pop(){
		tumpuk.top--;
	}
	
	string kondisi(string pus){
		init();
		int i=0;
		string P = "";
		while(pus[i] != '\0'){
			if(isOperand(pus[i])){
				P += pus[i];
			} else if(pus[i] == '(' ){
				push(pus[i]);
			} else if(pus[i] == ')' ){
				while(!kosong() && Top() == '(' ){
					P = P + " " + Top();
					pop();
				}
				pop();
			} else if (isOperator(pus[i])){
				if(kosong() || Top() == '('){
					push(pus[i]);
				}	
			} else {
				while(!kosong() && Top() != '(' && precedence(pus[i], Top()) ){
					P = P + " " + Top();
					pop();
				}
				push(pus[i]);
				}
				if(isOperator(pus[i]))
					P += " ";
					i++;
			}
			while(!kosong()){
			P = P + " " + Top();
			pop();
			} return P; 
		}
};
int main() {
	myStack s;
	string telor;
	cout<<"masukkan infix = ";
	cin>>telor;
	string A = s.kondisi(telor);
	cout<<endl<<"infix = "<<telor<<endl<<"Posfix = "<<A<<endl;
}


	
