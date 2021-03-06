// Queue_Using_Stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Stack.h"

int main()
{
    std::cout << "Hello World!\n";


	CStack* pStack1 = nullptr, *pStack2 = nullptr;

	pStack1 = new CStack();
	pStack1->Push(5);
	pStack1->Push(3);
	pStack1->Push(4);
	pStack1->Push(2);
	pStack1->Push(1);
	pStack1->Push(0);


	CQueue* pQ = nullptr;
	pQ = new CQueue();

	pQ->EnQueue(4);
	pQ->EnQueue(1);
	pQ->EnQueue(3);
	pQ->EnQueue(2);

	int iVal = 0;
	while (pQ->DeQueue(&iVal)) {
		printf("\n%i", iVal);
	}

	delete(pStack1);
	delete(pQ);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
