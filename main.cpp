#include<iostream>
#include<stdlib.h>
//#include"DLL.h"
#include"textEditor1.h"
#include<Windows.h>
//#include<graphics.h>
//#include<dos.h>
//using namespace std;
  void loadingBar()
{
    // 0 - black background,
    // A - Green Foreground
    system("color 0E");
  
    // Initialize char for printing
    // loading bar
    char a = 176, b = 219;
  
    printf("\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t"  "Loading...\n\n");
    printf("\t\t\t\t\t");
  
    // Print initial loading bar
    for (int i = 0; i < 40; i++)
        printf("%c", a);
  
    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");
  
    // Print loading bar progress
    for (int i = 0; i < 10; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(20);
    }
    for (int i = 10; i < 25; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(10);
    }
    for (int i = 25; i < 40; i++) {
        printf("%c", b);
  
        // Sleep for 1 second
        Sleep(50);
    }
}


int take_choice(){
	int choice ;
	cin >> choice ;
	if ( choice == 1 || choice == 2 || choice == 3) 
		return choice;
	else {
		cout << "Invalid Input!\nEnter again : " ;
		take_choice();	
	}
}
void main_menu(){
	cout<<"*************************************************************************"<<endl;
	cout<<"*                            PROJECT TEXT EDITOR                        *"<<endl;
	cout<<"*************************************************************************"<<endl;
	cout << "Select one of the options below:" << endl;
	cout<<"-----------------------------------"<<endl;
	cout << "1. Open a file" << endl;
	cout << "2. Create a file" << endl;
	cout << "3. To Quit" << endl;

}
  
void option_bar(){
	cout << "1. Edit file " << "  ";
	cout << "2. Search a Word" << "  ";
	cout << "3. Delete a Word " << "  ";
	cout << "4. Delete Lines " << "  ";
	cout << "5. Delete File" << "  ";
	cout << "6. To main menu" << "  ";
	cout << endl;
	cout << endl;
}  

string take_filepath(){
		string filename ; 
		string filepath = "";
		if (filepath.length() != 0 ){
			cout << "Enter name of file :" ;
			cin >> filename ; }
		else{ cout << "Enter path of file \n Make sure to add one more backslash(\\) with each backslash(\\)";
		    cout << endl  << "for e.g : C:\\DSA project\\txtFiles "; 	
			cin >> filepath ;
			cout << "Enter name of file :" ;
			cin >> filename ;  }	
		filepath  = filepath + "\\" + filename + ".txt";
		cout << filepath << endl;
		return filepath;
}

void the_main(){
	textEditor t;
	main_menu();
	
	int choice = take_choice();
//	int choice;
//	cin >> choice ;
	if (choice == 1){
			system("cls");
			string filepath = take_filepath();
			bool b = t.openFile(filepath);
			while( b != true){
				filepath = take_filepath();
				b = t.openFile(filepath);
			}

			t.feedDLL(filepath);
			option_bar();
			t.display();
			char ch;
			int choice1;
			while(choice1 != 6){ // CTRL+E
				cout << "\n\nOption: ";
				cin >> choice1;
				
				if ( choice1 == 1)
					t.edit(filepath);
					
				if ( choice1 == 2){						
					cout << "Enter the word:";
					string str ; cin >> str; int n = str.length();
					char arr[n];
//					str.c_str();
					strcpy(arr,str.c_str());
//					for (int i = 0; i < n ; i++) 
//				        	arr[i] = str[i];
				        	
				    system("cls") ;
					option_bar();
					t.display();   	
	    			t.searchWord2(arr,sizeof(arr));
				}
				if ( choice1 == 3){
					cout << "Enter the word:";
					string str ; cin >> str; ; int n = str.length();
					char arr[n];
					strcpy(arr,str.c_str());
					
					system("cls") ;
					option_bar();
				
				    t.deleteWords(arr,sizeof(arr),filepath);
				    t.display(); 
				}
				if ( choice1 == 4 ){
						int choice2;
						cout << "1) Delete from Beginning\n"
							 <<	"2) Delete From End " << endl;
						cin >> choice2;
						if ( choice2 == 1){
				
							cout << "How many lines you want to delete" << endl;
							int n ; cin >> n;
							for(int i = 0 ; i < n ; ++i) 
							t.deleteLine_fromBeg(filepath);
							cout << "\n**************Deleted "<< n <<" Line(s) from Beginning************** " << endl;
						}
						else{
							cout << "How many lines you want to delete" << endl;
							int n ; cin >> n;
							for(int i = 0 ; i < n ; ++i) 
							t.deleteLine_fromEnd(filepath);
							cout << "\n**************Deleted "<< n <<" Line(s) from End**************" << endl;
						}
							 					
				}
				if ( choice1 == 5 ){
						cout << "Do you really want to delete this file(y/n)?" << endl;	
						char ch ; cin >> ch;
						if (ch == 'y')
							t.deleteFile(filepath);									
				}
				if ( choice1 == 6 ){
					system("cls");
					the_main(); 
				}
				 
			}//while 	
		}//if 1
		if (choice == 2){			
			t.write();
			string file ;
			cout << "Enter the name of file: " << endl; 
			cin >> file ;
			file = file + ".txt";
			t.feedFile(file);
//			t.openFile("abcd.txt");
//			t.save();
		}
		if (choice == 3)
			exit(0);
		else
			choice = take_choice();
			
	
} 

	

int main(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Create a CONSOLE_FONT_INFOEX struct and set the font size
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 10;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    wcscpy_s(cfi.FaceName, L"Consolas");

    // Set the new font size
    SetCurrentConsoleFontEx(hConsole, false, &cfi);
  cout<<"******************************************************************************"<<endl;
  cout<<"*Please wait until the program's functionalities are loaded and ready to use!*"<<endl;
  cout<<"******************************************************************************"<<endl;
	loadingBar();
	system("cls");
		
	the_main(); 		
}


	
	
