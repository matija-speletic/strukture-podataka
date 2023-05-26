#include "Stack.h"
#include <iostream>
using namespace std;

//OKTOBAR 2020
int calcPostfix(char* expr)
{
	Stack s(strlen(expr));
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == ' ')
			continue;
		else if (expr[i] >= '0' && expr[i] <= '9')
			s.push(expr[i] - '0');
		else
		{
			int op2 = s.pop(), op1 = s.pop();
			switch (expr[i])
			{
			case '+':
				s.push(op1 + op2);
				break;
			case '-':
				s.push(op1 - op2);
				break;
			case '*':
				s.push(op1 * op2);
				break;
			case '/':
				s.push(op1 / op2);
				break;
			}
		}
	}
	return s.pop();
}

int calcPrefix(char* expr)
{
	Stack s(strlen(expr));
	for (int i = strlen(expr) - 1; i >= 0; i--)
	{
		if (expr[i] == ' ')
			continue;
		else if (expr[i] >= '0' && expr[i] <= '9')
			s.push(expr[i] - '0');
		else
		{
			int op1 = s.pop(), op2 = s.pop();
			switch (expr[i])
			{
			case '+':
				s.push(op1 + op2);
				break;
			case '-':
				s.push(op1 - op2);
				break;
			case '*':
				s.push(op1 * op2);
				break;
			case '/':
				s.push(op1 / op2);
				break;
			}
		}
	}
	return s.pop();
}

//JUN 2018
char* infix2Postfix(char* expr)
{
	char* ret = new char[strlen(expr) + 1];
	int j = 0;
	Stack s(strlen(expr));
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == ' ')
			continue;
		if (expr[i] == '(')
			s.push(expr[i]);
		else if (expr[i] == ')')
			while (s.getTop() != '(')
				ret[j++] = s.pop(), ret[j++] = ' ';
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			if (s.getTop() == '*' || s.getTop() == '/' || s.getTop() == expr[i])
			{
				ret[j++] = s.pop(), ret[j++] = ' ';
				s.push(expr[i]);
			}
			else
				s.push(expr[i]);
		else
			ret[j++] = expr[i], ret[j++] = ' ';
	}
	while (!s.isEmpty())
		if (s.getTop() != '(')
			ret[j++] = s.pop(), ret[j++] = ' ';
		else
			s.pop();
	ret[j] = 0;
	return ret;
}

//JANUAR 2020
int Calc(char* expr)
{
	Stack brojevi(strlen(expr)), operatori(strlen(expr));
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == ' ')
			continue;
		if (expr[i] == '(')
			operatori.push(expr[i]);
		else if (expr[i] == ')')
		{
			while (operatori.getTop() != '(')
			{
				int op2 = brojevi.pop(), op1 = brojevi.pop();
				switch (operatori.pop())
				{
				case '*':
					op1 = op1 * op2;
					break;
				case '+':
					op1 = op1 + op2;
				}
				brojevi.push(op1);
			}
		}
		else if (expr[i] == '+' || expr[i] == '*')
		{
			if (operatori.getTop() == '*' || operatori.getTop() == expr[i])
			{
				int op2 = brojevi.pop(), op1 = brojevi.pop();
				if (operatori.getTop() == '*')
					brojevi.push(op1 * op2);
				else
					brojevi.push(op1 + op2);
				operatori.pop();
				operatori.push(expr[i]);
			}
			else
				operatori.push(expr[i]);
		}
		else
			brojevi.push(expr[i] - '0');
		brojevi.printStack();
		operatori.printStack();
		cout << endl;
	}
	while (operatori.getTop() != '(')
	{
		int op2 = brojevi.pop(), op1 = brojevi.pop();
		switch (operatori.pop())
		{
		case '*':
			op1 = op1 * op2;
			break;
		case '+':
			op1 = op1 + op2;
		}
		brojevi.push(op1);
	}
	return brojevi.pop();
}

//KOLOKVIJUM1 2017
bool isCorrect(const char* expr)
{
	Stack s(strlen(expr));
	for (int i = 0; i < strlen(expr); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
			s.push(expr[i]);
		else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
		{
			if (s.isEmpty())
				return false;
			char temp = s.pop();
			if ((temp == '(' && expr[i] != ')') || (temp == '[' && expr[i] != ']') || (temp == '{' && expr[i] != '}'))
				return false;
		}
	}
	if (s.isEmpty())
		return true;
	return false;
}

int prioritet(char op)
{
	if (op == '*' || op == '/')
		return 2;
	if (op == '+' || op == '-')
		return 1;
	if (op == '^')
		return 3;
	return -1;
}

int calculateExpression(char* expr)
{
	Stack num(strlen(expr)), ops(strlen(expr));
	for (int i = 0; i < strlen(expr); i++)
	{
		char t = expr[i];
		if (t == ' ')
			continue;
		else if (t >= '0' && t <= '9')
			num.push(t - '0');
		else if (t == '(')
			ops.push(t);
		else if (t == ')')
		{
			while (ops.getTop() != '(')
			{
				char op = ops.pop();
				int o2 = num.pop(), o1 = num.pop();
				switch (op)
				{
				case '+':num.push(o1 + o2); break;
				case '-':num.push(o1 - o2); break;
				case '*':num.push(o1 * o2); break;
				case '/':num.push(o1 / o2); break;
				case '^':num.push(pow(o1, o2)); break;
				}
			}
			ops.pop();
		}
		else if (t == '+' || t == '-' || t == '*' || t == '/' || t == '^')
		{
			while (!ops.isEmpty() && prioritet(ops.getTop()) >= prioritet(t))
			{
				char op = ops.pop();
				int o2 = num.pop(), o1 = num.pop();
				switch (op)
				{
				case '+':num.push(o1 + o2); break;
				case '-':num.push(o1 - o2); break;
				case '*':num.push(o1 * o2); break;
				case '/':num.push(o1 / o2); break;
				case '^':num.push(pow(o1, o2)); break;
				}
			}
			ops.push(t);
		}
	}
	while (!ops.isEmpty())
	{
		char op = ops.pop();
		int o2 = num.pop(), o1 = num.pop();
		switch (op)
		{
		case '+':num.push(o1 + o2); break;
		case '-':num.push(o1 - o2); break;
		case '*':num.push(o1 * o2); break;
		case '/':num.push(o1 / o2); break;
		case '^':num.push(pow(o1, o2)); break;
		}
	}
	return num.pop();
}

char* infixToPostfix(char* expr)
{
	Stack s(strlen(expr));
	char* str = new char[strlen(expr) * 2];
	int j = 0;
	for (int i = 0; i < strlen(expr); i++)
	{
		char t = expr[i];
		if (t == ' ')
			continue;
		if (t == '(')
			s.push(t);
		if (t >= 'a' && t <= 'z')
			str[j++] = t;
		if (t == ')')
		{
			while (!s.isEmpty() && s.getTop() != '(')
				str[j++] = s.pop();
			if (!s.isEmpty())s.pop();
		}
		if (t == '+' || t == '-' || t == '*' || t == '/' || t == '^')
		{
			while (!s.isEmpty() && prioritet(s.getTop()) >= prioritet(t))
				str[j++] = s.pop();
			s.push(t);
		}
	}
	while (!s.isEmpty())
		str[j++] = s.pop();
	str[j] = 0;
	return str;
}

void main()
{
	//OKTOBAR 2020
	/*cout << calcPostfix("5 3 + 8 2 - *"); //48
	cout << calcPrefix("- / * 2 * 5 + 3 6 5 2"); //16*/

	//JUN 2018
	/*cout << infix2Postfix("( ( a + b ) * c / d + e * f ) / g");
	*/

	//JANUAR 2020
	/*cout << Calc("(((3+5)*4+3*2+(4+2)*5)*3+8)");
	*/

	//KOLOKVIJUM1 2017
	/*cout << isCorrect("1*(2+3)+{1-[2*(3+2)+4]*5}")
		<< isCorrect("1*(2+3)+{1-[(2*(3+2)+4]*5}")
		<< isCorrect("1*(2+3)+(1-[2*(3+2)+4]*5}");*/

	/*cout << calculateExpression("5 + 2 * 6") << "\n";
	cout << calculateExpression("3 * 2 + 2") << "\n";
	cout << calculateExpression("7 * ( 2 + 5 )") << "\n";
	cout << calculateExpression("9 * ( 2 + 8 ) / 5");*/

	cout << infixToPostfix("((a+b)*c/d+e^f)/g");

}