#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BookShop{
	
	public:
		
		BookShop();
		
		void AddBook();
		void ShowBook();		
	    void BuyBook();
	
	private:
		char* book_name;		
		char* author;		
		char* publisher;
		int page_number;
		float price;
		int stock;	    
};

void Password();
int myStrcmp(char *s1,char *s2);

#endif
