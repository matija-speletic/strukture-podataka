#include "Test.h"
#include <iostream>
#include "SLL.h"
#include "Niz.h"
#include "DLL.h"
#include "Queue.h"
#include "Stack.h"
#include "Teniseri.h"
#include "PolynomLL.h"
#include "LList.h"
#include <string.h>
#include "KeyList.h"
#include "SparseMatrix.h"
#include "StaticDLL.h"

using namespace std;

void Test::DLL_Test()
{
	DLList<int>* lista = new DLList<int>();
	for (int i = 0; i < 10; i++)
	{
		lista->addToHead(i);
		lista->addToTail(i * 3);
	}
	lista->printAll();
	cout << endl;
	lista->deleteEl(9);
	lista->printAll();
	cout << endl;
	lista->deleteEl(27);
	lista->printAll();
	cout << endl;
	lista->deleteEl(5);
	lista->printAll();
	cout << endl;
	lista->deleteEl(12);
	lista->printAll();
	cout << endl;
	lista->deleteEl(24);
	lista->printAll();
	cout << endl;
	lista->deleteEl(83);
	lista->printAll();
	cout << endl;
	lista->deleteEl(28);
	lista->printAll();
	cout << endl;
	lista->deleteEl(9);
	lista->printAll();
	cout << endl;
	lista->deleteEl(15);
	lista->printAll();
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		lista->deleteFromTail();
		lista->deleteFromHead();
	}

	delete lista;
}

void Test::SLL_Test()
{
	SLL<int> a;
	a.addToTail(1);
	a.addToHead(2);
	a.printAll();
	a.addToHead(3);
	a.printAll();
	a.addToTail(4);
	a.printAll();
	a.addToTail(5);
	a.addToHead(6);
	a.addToTail(7);
	a.printAll();
	a.deleteEl(1);
	a.printAll();
	a.deleteFromHead();
	a.printAll();
	a.deleteFromTail();
	a.printAll();
}

void Test::Niz_Test()
{
	Niz text = "abcdefghijklmnopqrstuvwxyzabcdefgihabcdebeobfabcefoiesfn";
	umetanjeUzorka(text, "jkl", "123");
	deleteAll(text, "abc");
	cout << text;
}

void Test::Queue_Test()
{
	Queue<int>* q1 = new StaticQueue<int>(15);
	for (int i = 0; i < 15; i++)q1->enqueue(i);
	for (int i = 0; i < 15; i++)cout << q1->dequeue() << ", ";
	cout << endl;
	for (int i = 0; i < 4; i++)q1->enqueue(i);
	//for (int i = 0; i < 15; i++)cout << q1->dequeue() << ", ";
	for (int i = 79; i < 87; i++)q1->enqueue(i);
	for (int i = 0; i < 15; i++)cout << q1->dequeue() << ", ";
	cout << endl;
	for (int i = 0; i < 15; i++)q1->enqueue(i);
	for (int i = 0; i < 5; i++)cout << q1->dequeue() << ", ";
	delete q1;
}

void Test::Stack_Test()
{
	Stack<int>* s1 = new DynamicStack<int>();
	Stack<int>* s2 = new StaticStack<int>(20);
	for (int i = 0; i < 15; i++)s1->push(i);
	Stack<int>::ReverseAStack(s1, s2);
	s1->printStack();
	s2->printStack();
}

//doradi
char* Test::InfixToPostfix(const char* str)
{
	bool prviVisiPriorOdDrugog(char, char);
	Stack<char>* s1 = new DynamicStack<char>();
	char* str1 = new char[2*strlen(str) + 1];
	int j = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			s1->push('(');
		else if (str[i] == ')')
		{
			char s = s1->pop();
			str1[j++] = ' ';
			while (s != '(')
			{
				str1[j++] = s;
				s = s1->pop();
			}
		}
		else if ((str[i] >= 'a' && str[i] <= 'z')||
			(str[i] >= '0' && str[i] <= '9'))
			str1[j++] = str[i];
		else if (str[i] == '\0')
		{
			while (!s1->isEmpty())
				str1[j++] = s1->pop();
			break;
		}
		else
		{
			str1[j++] = ' ';
			if (!s1->isEmpty() && s1->getHead() != '(' && prviVisiPriorOdDrugog(s1->getHead(), str[i]))
			{
				str1[j++] = s1->pop();
				s1->push(str[i]);
			}
			else s1->push(str[i]);
		}
	}
	str1[j] = 0;
	cout << str1;
	delete s1;
	return str1;
}

char* Test::LargeNumAdd(const char* num1, const char* num2)
{
	Stack<char>* s1 = new DynamicStack<char>()
		, * s2 = new DynamicStack<char>()
		, * s3 = new DynamicStack<char>();
	int i = 0;
	while (num1[i])s1->push(num1[i++]);
	i = 0;
	while (num2[i])s2->push(num2[i++]);
	int sum = 0, carry = 0;
	while (!(s1->isEmpty() && s2->isEmpty()))
	{
		sum = (int)((s1->isEmpty() ? 0 : (s1->pop() - '0')) +
			(s2->isEmpty() ? 0 : (s2->pop() - '0'))) + carry;

		if (sum >= 10)sum = sum - 10, carry = 1;
		else carry = 0;
		s3->push((char)(sum + '0'));
	}
	if (carry)s3->push('1');
	char* num3 = new char[s3->numOfEl() + 1];
	for (i = 0; !s3->isEmpty(); num3[i++] = s3->pop());
	num3[i] = 0;
	delete s1, s2, s3;
	return num3;
}

//doradi
double Test::PostfixToResult(const char* exp)
{
	Stack<int>* s1 = new DynamicStack<int>();

	//prolazak kroz sam izraz
	//moglo je i preko while petlje...nije toliko bitno
	for (int i = 0; i < strlen(exp); i++)
	{
		//ako je karakter broj
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			int num = 0;
			//ako ima vise cifara
			while (exp[i] >= '0' && exp[i] <= '9')
			{
				num *= 10;
				num += exp[i] - '0';
				i++;
			}
			s1->push(num);
		}
		else//ako je operator
		{
			int num1, num2;
			//izvrsi operaciju na osnovu skeniranog operatora
			switch (exp[i])
			{
			case '+':
				num2 = s1->pop(), num1 = s1->pop();
				s1->push(num1 + num2);
				break;
			case '-':
				num2 = s1->pop(), num1 = s1->pop();
				s1->push(num1 - num2);
				break;
			case '*':
				num2 = s1->pop(), num1 = s1->pop();
				s1->push(num1 * num2);
				break;
			case '/':
				num2 = s1->pop(), num1 = s1->pop();
				s1->push(num1 / num2);
				break;
			default: break;
			}
		}
		//s1->printStack(); cout << endl;
	}
	//rezultat je na vrhu stack-a
	int res = s1->pop();
	return res;
}

//doradi
double Test::CalcExpression(const char* exp)
{
	/*
		1)  jedan stek cuva operatore i zagrade a drugi stek cuva operande
		2)  kada se naidje na otvorenu zagradu ona se cuva na prvom steku
		3)  kada se naidje na operator 4) ako na steku nema operatora ili je stek prazan, operator se smesta na stek
								      5) ako se na steku nalazi operator nizeg prioriteta od trenutnog - smesta se na stek
								      6) ako se na steku nalazi operator viseg ili istog prioriteta:
											7)  operator viseg prioriteta se uzima sa steka
											8)  taj operator se izvrsava nad operandima koji se popuju iz drugog steka
											9)  rezultat se cuva u drugom steku
											10) procitani operator nizeg prioriteta se smesta na prvi stek
		11) kada se naidje na broj, tj operand, on se smesta na drugi stek
		12) kada se naidje na zatvorenu zagradu nad operandima koji se popuju iz drugog steka se izvrsava operacija 
		  predvidjena operatorom koji se popuje iz prvog steka. rezultat se cuva u drugom steku
		13) prethodni niz obrada se izvrsava dok se ne dodje do kraja polaznog izraza
		14) po izlasku iz petlje proverava se da li se na drugom steku nalaze dva operanda ili jedan
					15) ako se nalaze dva rezultat se odredjuje primenom operacije koja je na vrhu prvog steka nad njima
					16) ako je ostao jedan - to je rezultat
	*/
	Stack<char>* s1 = new DynamicStack<char>();//1
	Stack<int>* s2 = new DynamicStack<int>();
	int i = 0;
	while (exp[i])
	{
		if (exp[i] == '(') s1->push(exp[i++]);//2

		else if (exp[i] >= '0' && exp[i] <= '9')//11
			s2->push(exp[i++] - '0');

		else if ((!s1->isEmpty() && exp[i] == '*' && s1->getHead() == '+') ||
			(s1->isEmpty() || s1->getHead() == '('&& (exp[i] == '*' || exp[i] == '+')))//4 i 5 objedinjeno
			s1->push(exp[i++]);

		else if (!s1->isEmpty() && ((exp[i] == '+' && s1->getHead() == '+') || s1->getHead() == '*'))//6
		{
			int num2 = s2->pop(), num1 = s2->pop();
			char op = s1->pop();//7
			if (op == '+')s2->push(num1 + num2);//8 i 9
			if (op == '*')s2->push(num1 * num2);//8 i 9
			s1->push(exp[i++]);//10
		}

		else if (exp[i] == ')')//12 (slicno kao 7 8 9 10)
		{
			int num2 = s2->pop(), num1 = s2->pop();
			char op = s1->pop();
			if (op == '+')s2->push(num1 + num2);
			if (op == '*')s2->push(num1 * num2);
			s1->pop();
			i++;
		}
		else i++;
		//s1->printStack();
		//s2->printStack();
	}
	int res = 0;
	if (exp[i] == 0 && s2->numOfEl() == 2)//15
	{
		int num2 = s2->pop(), num1 = s2->pop();
		char op = s1->pop();
		if (op == '+')res = num1 + num2;
		if (op == '*')res = num1 * num2;

	}
	else res = s2->pop();//16
	delete s1, s2;
	return res;
}

void Test::DLL_Test2()
{
	DLList<int>* list = new DLList<int>();
	int temp;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		list->addToTail(temp);
	}
	cout << endl;
	list->printAll();
	cout << endl;
	list->bubbleSort();
	list->printAll();
}

void Test::SLL_Test2()
{
	SLL<int>* list1 = new SLL<int>(), * list2 = new SLL<int>();
	int temp;
	/*for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		list1->addToTail(temp);
	}*/
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		list2->addToTail(temp);
	}
	/*list1->Exchange(*list2, 4, 3);
	cout << endl;
	list1->printAll();
	cout << endl;
	list2->printAll();
	list1->bubbleSort();*/
	//list2->bubbleSort();
	list2->insertionSort();
	cout << endl;
	//list1->printAll();
	cout << endl;
	list2->printAll();
	delete list1, list2;
}

bool Test::bracketsIsCorrect(const char* exp)
{
	int i = 0;
	Stack<char>* s1 = new StaticStack<char>(20);

	while (exp[i])
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s1->push(exp[i]);
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (s1->isEmpty())
				return false;
			if (exp[i] == ')' && s1->pop() != '(')
				return false;
			if (exp[i] == ']' && s1->pop() != '[')
				return false;
			if (exp[i] == '}' && s1->pop() != '{')
				return false;
		}
		i++;
	}
	if (!s1->isEmpty())
		return false;
	return true;
}

void Test::KVListTest()
{
	
	KVList* l = new KVList();
	for (int i = 0; i < 20; i++)
	{
		int k, v;
		cin >> k >> v;
		l->UpdateNode(k, v);
		l->print();
	}
	for (int i = 0; i < 5; i++)
	{
		int id;
		cin >> id;
		//l->Increment(id);
		l->Decrement(id);
		l->print();
	}
}

void Test::Polynom_Test()
{
	PolynomLL* p1 = new PolynomLL()
		, * p2 = new PolynomLL(), * p3, * p4;
	p1->AddOne(5, 8);
	p1->AddOne(7, 4);
	p1->AddOne(9, 3);
	p1->AddOne(8, 7);
	p2->AddOne(2, 5);
	p2->AddOne(1, 2);
	p2->AddOne(0, 9);
	p1->printPoly();
	p2->printPoly();
	p3 = PolynomLL::Add(p1, p2);
	p3->printPoly();
	p4 = PolynomLL::Multiply(p1, p2);
	p4->printPoly();
	p4->derivative(3);
	p4->printPoly();
	delete p1, p2, p3, p4;
}

void Test::DLL_Test3()
{
	DLList<int>* list = new DLList<int>();

	for (int i = 0; i < 10; i++)
	{
		int p;
		cin >> p;
		list->addToTail(p);
	}
	/*list->printAll();
	list->MovePartToEnd(7, 4);
	list->printAll();
	list->MovePartToEnd(1, 3);
	list->printAll();
	list->MovePartToEnd(5, 5);
	list->printAll();
	list->MovePartToEnd(7, 5);
	list->printAll();*/
	list->printAll();
	list->selectionSort();
	list->printAll();
	delete list;
}

void Test::Teniseri()
{
	Lista* l = new Lista();
	for (int i = 20; i > 0; i -= 2)
	{
		char* n = new char[25];
		cin >> n;
		l->AddToHead(new TNode(n, 10 - i / 2, i));
		delete[] n;
	}
	l->print();
	while (true)
	{
		char* n = new char[50];
		cin >> n;
		int br;
		cin >> br;
		if (br == 0)break;
		l->UpdatePlayer(n, br);
		cout << endl << endl;
		l->print();
		delete[] n;
	}
	delete l;
}

void Test::LListMergeTest()
{
	LList* l1 = new LList(),
		* l2 = new LList();
	for (int i = 9; i >= 0; i--)
	{
		l1->addToHead(i+5);
		l2->addToHead(2*i);
	}
	l1->printAll();
	cout << endl;
	l2->printAll();
	cout << endl;
	LList* l3 = LList::Merge(l1, l2);
	l3->printAll();
	delete l3;
}

void Test::LListSortTest()
{
	LList* l1 = new LList();
	for (int i = 0; i < 7; i++)
	{
		int br;
		cin >> br;
		l1->addToTail(br);
	}
	l1->printAll();
	l1->insertionSortOptimized();
	l1->printAll();
	l1->fillInTheBlanks();
	l1->printAll();
}

void Test::duplicatesTest()
{
	LList* l1 = new LList();
	for (int i = 0; i < 9; i++)
	{
		int br;
		cin >> br;
		l1->addToTail(br);
	}
	l1->printAll();
	l1->groupDuplicates();
	l1->printAll();
}

void Test::LListTest()
{
	LList* l1 = new LList();
	for (int i = 0; i < 7; i++)
	{
		int br;
		cin >> br;
		l1->addToTail(br);
	}
	cout << l1->MoveToBeginning(20) << endl;
	l1->printAll();
}

void Test::minmaxTest()
{
	LList* l1;
	while(true)
	{
		l1 = new LList();
		for (int i = 0; i < 10; i++)
		{
			int broj;
			cin >> broj;
			if (broj == 6969)
			{
				delete l1;
				return;
			}
			l1->addToTail(broj);
		}
		l1->printAll();
		l1->swapMinMax();
		l1->printAll();
		delete l1;
	}
}

//uradjeno kompletno
double Test::calcPrefix(const char* inStr)
{
	/*
	 *	=> prolazimo kroz niz karaktera zdesna ulevo
	 *		=> ako naidjemo na operand 
	 *			=> smeštamo ga na stack
	 *		=> ako naidjemo na operator (označimo ga sa @)
	 *			=> pop-ujemo dve vrednosti sa steka (prvo se popuje prvi operand pa onda drugi)
	 *			=> na stek push-ujemo vrednost prviOperand @ drugiOperand
	 *	=> rezultat se nalazi na vrhu steka
	 * 
	 *	NAPOMENE: 
	 *		1) algoritam je 'otporan' na blanko znake
	 *		2) da bi radio sa visecifrenim brojevima razdvojenim razmacima
	 *		   dekomentarisati naznacen deo
	 */
	Stack<double>* s = new DynamicStack<double>();
	for (int i = strlen(inStr)-1; i>=0; i--)
	{
		if (inStr[i] >= '0' && inStr[i] <= '9')
		{
			/*//Ovaj deo treba dekomentarisati da bi radilo za visecifrene brojeve
			int num = 0, dg = 1;
			while (inStr[i] >= '0' && inStr[i] <= '9')
			{
				//konvertovanje niza cifara u broj (od nazad)
				num += (inStr[i] - '0') * dg;
				dg *= 10;
				i--;
			}
			s->push(num);*/
			s->push(inStr[i] - '0');//zakomentarisati za rad sa visecifrenim
			
		}

		else if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/')
		{
			double op1 = s->pop(), op2 = s->pop();
			switch (inStr[i])
			{
			case '+':
				s->push(op1 + op2);
				break;
			case '-':
				s->push(op1 - op2);
				break;
			case '*':
				s->push(op1 * op2);
				break;
			case '/':
				s->push(op1 / op2);
				break;
			default: break;
			}
		}
		//cout << "##########" << endl;
		//s->printStack();
	}
	double res = s->pop();
	delete s;
	return res;
}

//uradjeno kompletno
void Test::prefixToInfix(const char* exp)
{
	/*
	potpuno isti algoritam kao i za calcPrefix
	*/
	Stack<string>* s = new DynamicStack<string>();
	bool isOperand(char);
	bool isOperator(char);
	for (int i = strlen(exp) - 1; i >= 0; i--)
	{
		if (isOperand(exp[i]))
			s->push(string(1, exp[i]));
		else if(isOperator(exp[i]))
		{
			string op1 = s->isEmpty() ? "" : s->pop();
			string op2 = s->isEmpty() ? "" : s->pop();
			s->push("(" + op1 + string(1, exp[i]) + op2 + ")");
		}
	}
	cout << s->pop();
	delete s;
	
}

double Test::calcPostfix(const char* exp)
{
	return 0.0;
}

void Test::SMTest()
{
	SparseMatrix<int>* mat = new SparseMatrix<int>(3,4);
	mat->load();
	mat->print();
}

void Test::SDLTest()
{
	SDLList<int> l1(20);
	for (int i = 0; i < 7; i++)
	{
		l1.addToHead(i);
		l1.addToTail(i + 1);
	}
	l1.print();
}





bool prviVisiPriorOdDrugog(char a, char b)
{
	//funkcija koja proverava prioritet operatora
	//ne pripada ni jednoj klasi
	if (a == '^') return true;
	if (b == '^')return false;
	if (a == '*' || a == '/')return true;
	if (b == '*' || b == '/')return false;
	return true;
}

bool isOperand(char op)
{
	return (op >= 'a' && op <= 'z')
		|| (op >= 'A' && op <= 'Z')
		|| (op >= '0' && op <= '9');
}

bool isOperator(char op)
{
	return op == '+' || op == '-' || op == '*' || op == '/';
}