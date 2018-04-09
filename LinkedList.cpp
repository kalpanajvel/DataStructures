/* Test Driver for List class (TestList.cpp) */
#include <iostream>
#include "List.h"
using namespace std;

int main() {

	List<int> lst1;
	//cout << lst1 << endl;
	lst1.printList();
	lst1.push_front(8);
	lst1.push_back(88);
	lst1.push_front(9);
	lst1.push_back(99);
	lst1.push_back(100);
	lst1.push_back(120);
	lst1.push_back(130);
	lst1.printList();
	int result;
	lst1.pop_back(result);
	cout << "\n" << "Pop_back value is :" << result;
	lst1.printList();

	cout << "\nReverse List";
	lst1.reverseList();
	lst1.printList();
	lst1.push_front(10);
	lst1.push_back(20);

	lst1.printList();
	lst1.pop_back(result);
	cout << "\n" << "Pop_back value is :" << result;
	lst1.printList();
	lst1.pop_front(result);
	cout << "\n" << "Pop_front value is :" << result;
	lst1.printList();
	cout << "\nReverseList:";
	lst1.reverseList();
	lst1.printList();
	lst1.push_back(1000);

	List<int> lst2 = lst1;
	cout << "\nList 2 Data after copied using copy constructor:";
	lst2.printList();

	List<int> lst3;
	lst3.push_front(31);
	lst3.push_back(32);
	lst3.push_back(33);
	lst3.push_back(34);
	lst3.push_back(35);
	lst3.push_back(36);

	lst2 = lst3;

	cout << "\nList2 data after = values of list 3 : ";
	lst2.printList();

	cout << "\nList3 Data:";
	lst3.printList();



	return 0;
}