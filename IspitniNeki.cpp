//1. kol 2017 zad 3b
bool bracketsIsCorrect(const char* exp)
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



//oktobar 2020 zad 1b
double PostfixToResult(const char* exp)
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
		//s1->printStack(); cout << endl;//za prikaz koraka
	}
	//rezultat je na vrhu stack-a
	int res = s1->pop();
	return res;
}



//jun 2 2020 zad 1b + slika
template<class Tip>
inline void SLL<Tip>::Exchange(SLL<Tip>& list, Tip value, int length)
{
	SLLNode<Tip>* temp1 = list.getHead();
	SLLNode<Tip>* temp2 = this->getHead();
	//trazenje cvora u obe lista ciji je sledeci cvor value
	while (temp1->getLink()->getInfo() != value || temp2->getLink()->getInfo() != value)
	{
		if (temp1->getLink()->getInfo() != value)temp1 = temp1->getLink();
		if (temp2->getLink()->getInfo() != value)temp2 = temp2->getLink();
	}
	//prespajanje ovih cvorova
	SLLNode<Tip>* tempptr = temp1->getLink();
	temp1->setLink(temp2->getLink());
	temp2->setLink(tempptr);
	//prolazak kroz obe liste duzine length
	for (int i = 0; i < length; i++)
	{
		temp1 = temp1->getLink();
		temp2 = temp2->getLink();
	}
	//prespajanje (cak i ako je u pitanju tail, ne menja se kod)
	tempptr = temp1->getLink();
	temp1->setLink(temp2->getLink());
	temp2->setLink(tempptr);
}




//januar 2020 zad 1b
double CalcExpression(const char* exp)
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
		//s1->printStack(); //za prikaz svih koraka
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