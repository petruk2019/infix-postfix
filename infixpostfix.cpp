#include <iostream>
#define MAX_STACK_SIZE 10
using namespace std;

struct Element {
int data, atas;
Element *next;
};

class MyStack {
	private:
		Element deret;
		Element *head = NULL;

	public:
		void max(){
		deret.atas = -1;
		}
		bool kosong(){
		if(deret.atas == -1){
			return 1;
		}else{
			return 0;
		}
			}

	bool penuh(){
		if(deret.atas == MAX_STACK_SIZE-1){
			return 1;
		} else{
			return 0;
		}
	}
	
	void push(int a){
		if (!penuh()){
			
			Element *drt = new Element;
			drt->data = a;
			drt->next = NULL;
			if(kosong()){
				head = drt;
				head->next = NULL;
			} else{
				drt->next = head;
				head = drt;
				
				}
				deret.atas++;
			}
		else {
			cout<<"\nStack Penuh!!\n"<<endl;
			}
		}
	Element pop(){
		Element item;
			if (kosong()){
				cout<<"\nStack Kosong\n";
			}
			else{
				Element *drt = new Element;
				drt = head;
				head = head->next;
				delete drt;
				deret.atas--;
			}
