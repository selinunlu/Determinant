#include "bookshop.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdio>
using namespace std;

BookShop::BookShop(){

	author = new char[20];
	book_name = new char[20];
	publisher = new char[20];
	page_number = 0;
	price = 0;
	stock = 0;
	
}

//-------------------------------------------------------------------

void BookShop::AddBook(){		
	fstream dosya;
	dosya.open("bookshop.txt", ios_base::app);
			
		if(dosya.is_open()){			
			cout  << "Book Name : ";
			cin	  >> book_name;				
			dosya << book_name << " ";
				
			cout  << "Author : ";
			cin   >> author;
			dosya << author << " ";				
			
			cout  << "Publisher : ";
			cin	  >> publisher;
			dosya << publisher << " ";
				
			cout  << "Page Number : ";
			cin	  >> page_number;
			dosya << page_number << " ";
				
			cout  << "Price : ";
			cin	  >> price;
			dosya << price << " ";
			
			cout  << "Stock : ";
			cin   >> stock;			
			dosya << stock;										
		}		
	dosya.close();
}

//-------------------------------------------------------------------
		
void BookShop::ShowBook(){	
	char* name;
	name = new char[20];
	bool flag = false;
	
	cout << "Please enter name of book you want to search: ";
	cin  >> name;
		
	fstream dosya;
	dosya.open("bookshop.txt");
	
	if(dosya.is_open()){
		while(!dosya.eof()){
			dosya >> book_name >> author >> publisher >> page_number >> price >> stock;
				if(myStrcmp(book_name,name) == 0){
					cout  << "Book Name : ";
					cout  << book_name <<endl;								
				
					cout  << "Author : ";
					cout  << author << endl;								
			
					cout  << "Publisher : ";
					cout  << publisher << endl;
									
					cout  << "Page Number : ";
					cout  << page_number << endl;
									
					cout  << "Price : ";
					cout  << price << "tl" << endl;
								
					cout  << "Stock : ";
					cout  << stock << endl;			
						
					flag = true;
				}					
		}
		
		if(flag == false){
			cout << "The book is not found.." << endl;
		}
				
	}
	delete name;		
	dosya.close();
}

//-------------------------------------------------------------------

void BookShop::BuyBook(){
	int count;
	char* name;
	name = new char[20];
	bool flag = false;
	
	fstream dosya;
	dosya.open("bookshop.txt");	
	
	if(dosya.is_open()){
		cout << "Please enter name of book you want to buy: ";
		cin  >> name;
	
		cout <<"Please enter number of books you want to buy: ";
		cin  >>count;	
	
		while(!dosya.eof()){
			dosya >> book_name >> author >> publisher >> page_number >> price >> stock;
		
				if(myStrcmp(book_name,name) == 0){
					cout  << "Book Name : ";
					cout  << book_name <<endl;								
				
					cout  << "Author : ";
					cout  << author << endl;								
			
					cout  << "Publisher : ";
					cout  << publisher << endl;
									
					cout  << "Page Number : ";
					cout  << page_number << endl;
									
					cout  << "Price : ";
					cout  << price << "tl" << endl;
								
					cout  << "Stock : ";
					cout  << stock << endl;		
				
						if(count<=stock){
							stock=stock-count;
							cout << "New stock = " << stock << endl;
							cout << "Total cost " << price*count << " tl" << endl;
							cout << "Books Bought Successfully" << endl;							
	                	}
						else{						
							cout<<"No Enough Stock!"<<endl;
						}
						flag = true;
				}										
		}
		
		if(flag == false){
					cout << "The book is not found.." <<endl;
				}
				
	}
	delete name;
	dosya.close();
}

//-------------------------------------------------------------------
	
int myStrcmp(char *s1, char *s2){	
	int result;	
	int i;	
	for(i=0 ; s1[i]!='/0' && s2[i]!='/0' ; i++){
		if(s1[i]==s2[i]){
			result=0;
			break;
		}			
		else if(s1[i]<s2[i]){
			result=-1;
			break;
		}		
		else{
			result=1;
			break;
		}			
	}
	return result;	
}

//-------------------------------------------------------------------
	
void Password(){
	char *username1="selinbeyza";
	char username[15];
	
	char *password1="BS";
	char password[15];
	
	int hak=3;
	
	cout << "You can try up to 3 times."<<endl;
	
	while(hak-- >0){		
				
		cout << "Username: ";
		cin  >> username;
		
		cout << "Password : ";
		cin  >> password;
		
		if(myStrcmp(username1,username)==0 && myStrcmp(password1,password)==0){
			cout << "WELCOME!" << endl;
			break;
		}
		else{
			cout << "Try again\a" << endl;
			cout << "You can try " << hak << " time again" << endl;	
		}
		exit(0);				
	}		
}


