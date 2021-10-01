// RPN calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "stddefine.h"
int getPrec(char op);
void writeQueue(queue<char> qu);
void writeStack(stack<char> st);


int main()
{


	std::string str = " ";
	cin >> str;
	stack<char> st;
	queue<char> qu;
	const int size = 500;
	char tokens[500];

	//PSEUDOCODE???
	/*
	1.  While there are tokens to be read:
	2.        Read a token
	3.        If it's a number add it to queue
	4.        If it's an operator
	5.               While there's an operator on the top of the stack with greater precedence:
	6.                       Pop operators from the stack onto the output queue
	7.               Push the current operator onto the stack
	8.        If it's a left bracket push it onto the stack
	9.        If it's a right bracket
	10.            While there's not a left bracket at the top of the stack:
	11.                     Pop operators from the stack onto the output queue.
	12.             Pop the left bracket from the stack and discard it
	13. While there are operators on the stack, pop them to the queue
	*/

	//Here's what we need:
	//token list
	//operator stack
	//output queue
	//While there are tokens to be read :
	for (int i = 0; i < str.length(); i++)
	{
		tokens[i] = str[i];
	}

	for (int i = 0; i < str.length(); i++)
	{
		cout << "Token: " << i << " = " << tokens[i] << endl;
		cout << "Stack value = ";
		writeStack(st);
		cout << "Queue value = ";
		writeQueue(qu);
		
		switch (tokens[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			qu.push(tokens[i]);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			// While there's an operator on the top of the stack with greater precedence:
			while (!st.empty() && getPrec(st.top()) > getPrec(tokens[i]))
			{
				qu.push(st.top());
				st.pop();
			}
			
			st.push(tokens[i]);
			break;
		case '(':
			st.push(tokens[i]);
			break;
		case ')':
			while(!st.empty() && st.top() != '(')
			{
				qu.push(st.top());
				st.pop();
			}

			st.pop();
			break;

		}

	}

	while (!st.empty())
	{
		qu.push(st.top());
		st.pop();
	}
}

int getPrec(char op)
{
	switch (op)
	{
	    case '+':
		case '-':
			return 1;
		case '/':
		case '*':
			return 2;
		default:
			return 0;
	}
}

void writeQueue(queue<char> qu)
{
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop();
	}
	cout << endl;
}

void writeStack(stack<char> st)
{
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}




