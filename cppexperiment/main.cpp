#include <iostream>
#include "SLList.h"
using namespace std;

void PrintMsg(const std::string& msg){
    cout << endl;
	cout << "---------------------------------------------" << endl;
    cout << msg << endl;
	cout << "---------------------------------------------" << endl;
}

//////////////////////////////////////////////////////
///////// DO NOT TOUCH ANYTHING INSIDE main! /////////
//////////////////////////////////////////////////////

int main()
{
    //Declare Singly Linked List and insert integer 0 ~ 9
    PrintMsg("Singly Linked List: insert integer 0 ~ 9");
	SLList<int> sll;
	for (int i = 0; i < 10; i++){sll.InsertNodeIndex(i,i);}
	sll.Display();
	cout << "Length of the current SLL: "  << sll.Length()<< endl;

	//Insert Nodes by using index
	PrintMsg("Singly Linked List: insert nodes by using index");
	sll.InsertNodeIndex(0, 11111);
	sll.InsertNodeIndex(6, 22222);
	sll.InsertNodeIndex(12, 33333);
	sll.InsertNodeIndex(100, 77777);    //put an invalid index
	sll.Display();
	cout << "Length of the current SLL: "  << sll.Length()<< endl;

    //Search Nodes
    PrintMsg("Search index of an item in a Linked List");
    cout << "index of 11111: " << sll.Search(11111) << endl;
    cout << "index of 22222: " << sll.Search(22222) << endl;
    cout << "index of 33322: " << sll.Search(33333) << endl;
    cout << "index of 77777: " << sll.Search(77777) << endl;    //put an invalid value
    cout << "Length of the current SLL: "  << sll.Length()<< endl;

	//Delete Nodes by using index
	PrintMsg("Singly Linked List: delete node by using index");
    sll.DeleteNodeIndex(0);
    sll.DeleteNodeIndex(100);   //put an invalid index
	sll.Display();
	cout << "Length of the current SLL: "  << sll.Length()<< endl;

    //Delete Nodes by using value
    PrintMsg("Singly Linked List: delete node by using value");
	sll.DeleteNodeValue(0);
	sll.DeleteNodeValue(77777); //put an invalid value
	sll.Display();
	cout << "Length of the current SLL: "  << sll.Length()<< endl;

	//Reverse Singly Linked List
	PrintMsg("Singly Linked List: reverse List");
	sll.Reverse();
	sll.Display();

	return 0;
}

