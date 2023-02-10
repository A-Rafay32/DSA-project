#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

template<class T>
class Node{
	public:
		T info;
	   	Node *next, *prev;
		Node()
		{ next = prev = 0;}
		Node(T el , Node* n=0 , Node* p=0)
		{ info = el ; next = n ; prev = p ;} 
};



template<class T>
class DLList{
	public:
		Node<T>* head , *tail;
	public:
	    DLList()
		{ head = tail = 0 ; }
		int isEmpty(){
			return head == 0;
		}
		void addtoTail(T);
		void addtoHead(T);
		void insertion(int,T);
		void deleteNode(T); 		
		void deleteFirstNode();
		void display();	
};

//Node<char> DLList<char> :: head = 0;
//Node<char> DLList<char> :: tail = 0;

template<class T>
void DLList<T>::addtoHead(T el){
	if (head != 0) {
 		head = new Node<T>(el,head,0);
 		head->next->prev = head;
 	}
 	else head = tail = new Node<T>(el);
}

template<class T>
void DLList<T>::addtoTail(T el) {
 	if (tail != 0) {
 		tail = new Node<T>(el,0,tail);
 		tail->prev->next = tail;
 	}
 	else head = tail = new Node<T>(el);
}

template<class T>
void DLList<T>::insertion(int position , T el ){
	Node<T> *p, *tmp ; int i = 0;
	for(p = head ; i<position-1 ; p=p->next ,++i );
	tmp = new Node<T>(el,p,p->prev);
	p->prev->next = tmp;
	p->prev = tmp;
	cout << el << " is inserted at position " << position << endl;
}
	
template<class T>	
void DLList<T>::deleteNode(T el){
	Node<T> *p, *tmp ,*pred ; int pos = 1 ;
	for(p = head ; p->info!= el ; p=p->next, ++pos );
	pred = p->prev ; tmp = p->next;
	delete p;
	pred->next = tmp;
	tmp->prev = pred;	
	cout << el << " is deleted from position "<< pos << endl; 	
}
template<class T>
void DLList<T>::deleteFirstNode()
    {
        if (tail == 0)
        {
            return; // list is empty
        }
        Node<T> *temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = NULL;
        }
//        cout << "deleted node: " << temp->info << endl;
        delete temp;
    }

template<class T>	
void DLList<T>::display(){
	Node<T> *current = head;
	while(current != tail){
		cout << current->info ;
		current = current->next;
	}
}