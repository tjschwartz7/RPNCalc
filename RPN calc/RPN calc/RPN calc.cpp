// RPN calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "stddefine.h"

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
	enum ops { ADD = 0, SUB = 0, MUL = 1, DIV = 1 };
	for (int i = 0; i < 500; i++)
	{		
		tokens[i] = str[i];
	}
	int stPrec;
	for (int i = 0; i < 500; i++)
	{
		switch (str[i])
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			qu.push(str[i]);
			break;
		case '+':
		case '-' :

		case '*':
		case '/':
			switch (str[i])
			{
			case '+':
				stPrec = ADD;
				break;
			case '-':
				stPrec = SUB;
				break;
			case '*':
				stPrec = MUL;
				break;
			case '/':
				stPrec = DIV;
				break;
			}

			break;
	}

}


