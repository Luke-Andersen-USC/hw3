#include "llrec.h"
#include <iostream>

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	
	if(head != NULL)
	{
		cout << "Going in..." << endl;
		llpivot(head->next, smaller, larger, pivot);
	}
	else
	{
		smaller = NULL;
		larger = NULL;
		return;
	}

	if(head->val > pivot)
	{
		cout << "Here!: " << head->val << endl;
		Node* temp = NULL;
		//going backwards - setting next to next element, else will be NULL 
		if(larger != NULL)
		{
			cout << "achieved!" << endl;
			temp = larger;
		}
		
		larger = head;
		larger->next = temp;	
	}
	else
	{
		cout << "Here!: " << head->val << endl;
		Node* temp = NULL;
		if(smaller != NULL)
		{
			cout << "achieved!" << endl;
			temp = smaller;
		}


		smaller = head;

		smaller->next = temp;
	}

	head = NULL;

}