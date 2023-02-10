#include<iostream>
#include<queue>
#include<windows.h>
#include"DLL.h" 
#include<conio.h>
using namespace std;

class textEditor{
	public :
		 DLList<char> l;
		 Node<char> *n ,*p , *q , *curr , *firstchar , *fchar  ;
	public :
		
		bool openFile(string filePath) {
	    	ifstream file(filePath);
	    	if (file.is_open()) 
	       	{	cout << "File successfully opened." << endl; return true ;}
	    	else 
	        {	cout << "Failed to open file.Check if file actually exits! " << endl; return false;}
	        	
	    	
		}	
		
		void feedDLL(string filePath){  
			char ch;
			fstream	fin;
			fin.open(filePath);
			while(fin){
				fin.get(ch);
				l.addtoTail(ch);
			}
			cout << "Done" << endl;
		}
		
		void feedFile(string filePath){  
			char ch;
			string file = filePath;
			char file1[file.size()];  
			strcpy(file1,file.c_str());
			
			cout<< file1 << endl;	
			remove(file1);
			
			ofstream fout(filePath);
			Node<char>*curr = l.head;
			while( curr != l.tail ){
				ch = curr->info;
				cout << ch ;
				fout.put(ch);
				curr = curr->next;
			}
			cout << "Done" << endl;
		}
		
		void deleteLine_fromBeg(string filePath){
			char ch; Node<char>* tmp;
//			l.head = l.head->prev->prev->prev;
			while(ch  != '\n'){
//				tmp = l.tail;
				l.head = l.head->next;
				ch = l.head->info;
//				delete tmp;
			}
			feedFile(filePath);

		} 
		
		void deleteLine_specific(string filePath, int line){
			char ch; Node<char>* tmp;
			for(int i = 0 ; i < line ; ++i  ){	
				while(ch  != '\n'){
//				tmp = l.tail;
					l.head = l.head->prev;
					ch = l.head->info;
//				delete tmp;
				}
			}
			feedFile(filePath);

		} 
		void deleteLine_fromEnd(string filePath){
			char ch; Node<char>* tmp;
			l.tail = l.tail->prev->prev->prev;
			while(ch  != '\n'){
//				tmp = l.tail;
				l.tail = l.tail->prev;
				ch = l.tail->info;
//				delete tmp;
			}
			feedFile(filePath);
//			l.tail = l.tailprev->prev;

		} 
		
		void display(){
		    l.display();				
		}
		
		void display(DLList<char> x){
		    x.display();				
		}
		
		
		void createFile(string filename){
			ofstream fout(filename+".txt");
			char str[20];
			
			char ch;
			while(int(ch)!= 24){				
				cin.getline(str,20,'\n');
		
				for(int i = 0 ; i < 20 ; ++i){				
					if(int(str[i]) == 24) 	
						ch = str[i];
					else fout.put(str[i]);		
				}
			strcpy(str," ");
			}
			
		}
		 
		
		
		void deleteFile(string filePath){
			string file = filePath;
			char file1[file.size()];
			for(int i =0 ; i < file.size() ; ++i)
				file1[i] = file[i]; 
				
			int result = remove(file1);
			if (result != 0) 			 
			    cerr << endl << "**************File deletion failed**************" << endl;  
			else 
			    cout << endl << "**************File deleted successfully**************" << endl;
		}
		
		void edit(string filename){

			DLList<char> dll ; char limit = '1';
			int n = 4  ; char arr[n]; char ch;
			cout << "Start Writing ...............                                   > Press Ctrl-X to quit " << endl ;
			while(true){
				cin >> ch;
				if (int(ch) == 24) // when ctrl + x pressed
					break;
				else{
					dll.addtoTail(ch);
				}
				
			}
			//concatenate
			dll.head->prev = l.tail;
			l.tail->next = dll.head;
			//combine
			l.tail = dll.tail;
			display() ;
			feedFile(filename);
		}
		
		void save(){
			string filename ; fstream fin; Node<char> *p ;
			p = l.head;
			cout << "Enter file name: " << 	endl;
			cin >> filename;
			string str = filename + ".txt";
			fin.open(str);
			
			while(!l.isEmpty()){
			     fin.put(p->info);
			     p = p->next;
			}		
		}
	
		
	
		int wordCount(string filename){
			feedDLL(filename); int count = 0;
			for(Node<char>* i = l.head ; i != 0 ; i=i->next )
				count++;
			return count;	
		}
		void deleteWords(char arr[] , int n, string filePath){
			string f = filePath;
    		Node<char> *fchar, *lchar ; 
			int pos = 1 ; int i = 0 ;
			
			if (checkWord(arr,n)){
				fchar = p;
				while ( i < n+1){	
					fchar = fchar->prev ;
					++i;
				}
				
				i = 0 ; lchar = fchar;	//p = p->next ; 
				while ( i <= n ){
					lchar = lchar->next;					
					++i;
				}
				
				fchar->next = lchar;
				lchar->prev = fchar;
				feedFile(f);						
			}
			else cout << "word( " << arr << " ) does not exist" << endl;
		}
		
		void searchWord2(char arr[] , int n){
			Node<char>* i ,*j, *curr, *x   ; char word[n];
			x = j = l.head ; int count  = 0 ; int c = 0;
			
			Node<char>* end = l.tail;
			while(count < 4 ){
				end = end->prev;
				count++;
			}
			count = 0;
			
			while( j != end || j != end->prev || j != end->next ){
				curr =  x;
				for ( int i1 = 0  ; i1 < n ; i1++ ,  curr = curr->next ){
					if (curr->info != ' ')
						word[i1] = curr->info;	
					else 
						break;
				}	
				
//				for( int i=0 ; i < n ; ++i )
//					cout << word[i] ;	
//				cout << endl;	
				
				if (strcmp(word,arr) == 0 ){
					++count ;
					cout << "count " << count << endl;
				}
				
				for( int i=0 ; i < n ; ++i )
					word[i] = ' ';
					
				if (curr == end || curr == end->next || curr == end->next->next || curr == end->prev
					|| curr == end->prev->prev || curr == end->next->next->next || curr == end->prev->prev->prev ||
					 curr == end->next->next->next->next ||curr == end->prev->prev->prev->prev)
					break;
										
				j = curr->next; 
				++c ;
				x = curr->next;	
							
			}	
				cout << "\n\nThe word (" << arr << ") has occurred " << count << " times" << endl;
		}
		
		checkWord(char arr[] , int n){			
			Node<char>* i ,*j, *curr, *x   ; char word[10];
			x = j = l.head ; int count = 0;
			Node<char>* end = l.tail; 
			while(count < 4 ){
				end = end->prev;
				count++;
			} 
			
			while( j != l.tail || curr != l.tail || j->next != 0 ){
				curr =  x;
				for ( int i1 = 0  ; i1 < n  ; i1++ ,  curr = curr->next ){
					if (curr->info != ' ')
						word[i1] = curr->info;	
					else 
						break;
				}	
//				for( int i=0 ; i < n ; ++i )
//					cout << word[i] ;	
//				cout << endl;	
				
				if (strcmp(word,arr) == 0 ){
					//for searchWord()
					firstchar = curr;
					//for deleteWord()
					p = curr;
					return true;	
					break;							
				}
				if (curr == end || curr == end->next || curr == end->next->next || curr == end->prev
					|| curr == end->prev->prev || curr == end->next->next->next || curr == end->prev->prev->prev ||
					 curr == end->next->next->next->next ||curr == end->prev->prev->prev->prev)
					break;
				for( int i=0 ; i < n ; ++i )
					word[i] = ' ';
				
				
				j = j->next;
				x = curr->next;
			}
			return false ;			
		}
		
			
void write()
    {
        char op = 'f';
        char *ch;
        ch = new char[500];
        int j = 0;
        while (op == 'c' || op == 'f')
        {
            cout << "\nStart Writing ..............." << endl;
            if (j > 0)
            {
                cin.ignore();
            }
            cin.getline(ch, 500, 'q');
            int i = 0;
            while (ch[i] && i < 500)
            {
                l.addtoHead(ch[i]);
                i++;
            }
            cout << ": Save(s)\n"
                    ": Continue writing(c)\n"
                    ": Undo last edit(z)\n";
            cin >> op;
            j++;
        }

        if (op == 's')
        {
            return;
        }
        while (op == 'z')
        {
            queue<char> s = Undo(ch);
            cout << ": Save(s)\n"
                    ": Redo(r)\n";
            cin >> op;
            if (op == 's')
            {
                return;
            }
            if (op == 'c')
            {
                delete ch;
                write();
            }
            if (op == 'r')
            {
                while (!s.empty())
                {
                    l.addtoHead(s.front());
                    s.pop();
                }
                return;
            }
        }

        delete ch;
    }

    queue<char> Undo(char ch[])
    {
        queue<char> s;
        int i = 0;

        while (ch[i] && i < 500)
        {
            s.push(ch[i]);
            l.deleteFirstNode();
            i++;
        }
        return s;
    }
	
		
	
	
};
	
		
	
	
	
