#include "llrec.h"


using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	
	if(head != NULL)
	{
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
		Node* temp = NULL;
		//going backwards - setting next to next element, else will be NULL 
		if(larger != NULL)
		{

			temp = larger;
		}
		
		larger = head;
		larger->next = temp;	
	}
	else
	{
		Node* temp = NULL;
		if(smaller != NULL)
		{
			temp = smaller;
		}


		smaller = head;

		smaller->next = temp;
	}

	head = NULL;

}