#pragma once
class Test
{
protected:
	Test(){}
public:
	static void DLL_Test();
	static void SLL_Test();
	static void Niz_Test();
	static void Queue_Test();
	static void Stack_Test();
	static char* InfixToPostfix(const char* str);
	static char* LargeNumAdd(const char* num1, const char* num2);
	static double PostfixToResult(const char* exp);
	static double CalcExpression(const char* exp);
	static void DLL_Test2();
	static void SLL_Test2();
	static void Polynom_Test();
	static void DLL_Test3();
	static void Teniseri();
	static void LListMergeTest();
	static void LListSortTest();
	static void duplicatesTest();
	static void LListTest();
	static void minmaxTest();


	//ispitni
	static double calcPrefix(const char* inStr);
	static void prefixToInfix(const char* exp);
	static double calcPostfix(const char* exp);
	static void SMTest();
	static void SDLTest();
	static bool bracketsIsCorrect(const char* exp);
	static void KVListTest();

};
