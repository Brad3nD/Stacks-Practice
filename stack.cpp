#include "stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
	Head = NULL;
	Length = 0;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
}

//-----------------------------------------------------------
// This checks to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull()
{
	return (false);
}

//-----------------------------------------------------------
// This checks to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
	return (Length == 0);
}

//-----------------------------------------------------------
// This routine pushes data into the stack.
//-----------------------------------------------------------
void Stack::Push(int Number)
{
	// Check for full stack
	if (IsFull())
		return;

	// Allocate space for data
	SNode *Temp = new SNode;
	if (Temp == NULL)
		return;

	// Insert data at head of list
	Temp->Number = Number;
	Temp->Next = Head;
	Head = Temp;
	Length++;
}

//-----------------------------------------------------------
// This routine pops data from the stack.
//-----------------------------------------------------------
void Stack::Pop(int &Number)
{
	// Check for empty stack
	if (IsEmpty())
		return;

	// Extract information from node
	Number = Head->Number;

	// Pop item from linked list
	SNode *Temp = Head;
	Head = Head->Next;
	delete Temp;
	Length--;
}

//-----------------------------------------------------------
// This routine returns the data from the front of the stack.
//-----------------------------------------------------------
void Stack::Top(int &Number)
{
	if (IsEmpty())
		return;

	Number = Head->Number;
}

//-----------------------------------------------------------
// This routine prints all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
	cout << "stack: ";
	SNode *Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->Number << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
	Stack stack;
	stack.Push(3);
	stack.Print();
	stack.Push(1);
	stack.Print();
	stack.Push(4);
	stack.Print();
	stack.Push(1);
	stack.Print();
	stack.Push(5);
	stack.Print();
	stack.Push(9);
	stack.Print();

	int num;
	stack.Pop(num);
	stack.Print();
	stack.Pop(num);
	stack.Print();
	stack.Pop(num);
	stack.Print();
	stack.Pop(num);
	stack.Print();
	stack.Pop(num);
	stack.Print();
	stack.Pop(num);
	stack.Print();
}