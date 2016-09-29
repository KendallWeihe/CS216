//course: CS216-00x
//Project: Lab Assignment 5
//Date: 09/27/2016
//Purpose: This program demonstrates the collection of baskets for the Easter Bunny.
//	   Help the bunny to put his collection of baskets in order according to eggs in each basket.
//	   Allow the bunny to add new baskets, or remove baskets from his collection. 
//
//Author: (your name)

#include<iostream>
#include<string>
#include"BasketList.h"

using namespace std;

int readEggsInBasket(string);

int main()
{

   char choice;
   int egg_in_a_basket;
   BasketList BL_of_bunny;
   
   cout << "This program demonstrates the collection of baskets for the Easter Bunny. " << endl;
   cout << "Initially, you will be asked to create the basket list for the bunny." << endl;
   cout << "You will be later prompted to manipulate the basket list." <<endl << endl;
   
   BL_of_bunny.makeBasketList(); 
   cout << "The basket collection for the Easter Bunny are in order: "<< endl;
   BL_of_bunny.printBasketList();
   
   do
   {
      cout << "*******************************************************" << endl;
      cout<<"i: Insert a new basket" << endl;
      cout<<"d: Delete (Delete a basket with the given number of eggs)" << endl;
      cout<<"p: Print  (Display the number of eggs in each basket from the basket list)" << endl;
      cout<<"q: Quit   (Quit the program)" << endl;
      cout << "*******************************************************" << endl << endl;
      cout<< endl << "Please enter your choice here:";
      cin>>choice;
      cin.ignore(256, '\n');    
      
      switch(choice)
      {
	 case 'i':
	    egg_in_a_basket = readEggsInBasket("to insert:");
	    BL_of_bunny.insertBasket(egg_in_a_basket);
	    break;
	    
	 case 'd':
	    egg_in_a_basket = readEggsInBasket("to delete:");
	    BL_of_bunny.deleteBasket(egg_in_a_basket);		
	    break;

	 case 'p':
	    cout << "The basket collection for the Easter Bunny are in order: "<< endl;
	    BL_of_bunny.printBasketList();
	    break;
	    
	 case 'q':
	    break;
	    
	 default:
	    cout<<"\n Invalid choice. Please try again.\n";
	    break;
      }
   } while(choice != 'q');
   
   cout<< "Thank you for using this program" << endl;
   return 0;
}

int readEggsInBasket(string descr)
{
   int eggs;
   cout << endl << "Please enter the number of eggs in the basket " << descr; 
   cin >> eggs;
   cin.ignore(256, '\n');
   
   while(cin.fail())
   {
       cin.clear();
       cin.ignore(256,'\n');
       cout << endl << "Please enter the number of eggs in the basket " << descr; 
       cin >> eggs;
       cin.ignore(256,'\n');
   }

   return eggs;
}
