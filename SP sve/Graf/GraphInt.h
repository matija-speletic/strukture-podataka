#pragma once

//#include "LinkedEdgeInt.h"
#include "LinkedNodeInt.h"

class GraphAsListsInt
{
protected:
	LinkedNodeInt* start;
	long nodeNum;
public:
	GraphAsListsInt();
	~GraphAsListsInt();

	LinkedNodeInt* findNode(const int& data) const;
	LinkedEdgeInt* findEdge(const int& dataSrc, const int& dataDest) const;

	void insertNode(const int& data);
	bool insertEdge(const int& dataSrc, const int& dataDest, const double& weight = 0);

private:
	void deleteEdgeToNode(const LinkedNodeInt* pDest);
public:
	bool deleteEdge(const int& dataSrc, const int& dataDest);
	bool deleteNode(const int& data);

	void print() const;

private:
	void setStatusForAllNodes(int status) const;
public:
	long breadthFirstTraversal(const int& data) const;
	long depthFirstTraversalIterative(const int& data) const;
private:
	long depthFirstTraversalRecursive(LinkedNodeInt* ptr) const;
public:
	long depthFirstTraversalRecursive(const int& data) const;

	long topologicalOrderTravrsal() const;

	void showGraphDetails();






	/*
	 *	██╗░██████╗██████╗░██╗████████╗███╗░░██╗██╗  ███████╗░█████╗░██████╗░░█████╗░░█████╗░██╗
	 *	██║██╔════╝██╔══██╗██║╚══██╔══╝████╗░██║██║  ╚════██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║
	 *	██║╚█████╗░██████╔╝██║░░░██║░░░██╔██╗██║██║  ░░███╔═╝███████║██║░░██║███████║██║░░╚═╝██║
	 *	██║░╚═══██╗██╔═══╝░██║░░░██║░░░██║╚████║██║  ██╔══╝░░██╔══██║██║░░██║██╔══██║██║░░██╗██║
	 *	██║██████╔╝██║░░░░░██║░░░██║░░░██║░╚███║██║  ███████╗██║░░██║██████╔╝██║░░██║╚█████╔╝██║
	 *	╚═╝╚═════╝░╚═╝░░░░░╚═╝░░░╚═╝░░░╚═╝░░╚══╝╚═╝  ╚══════╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝░╚════╝░╚═╝
	*/

	//JUN 2021
	int putDoAerodromaBiliC(int a, int b, int c, int maxMinuta);
	//teorijski deo
	LinkedNodeInt* maxIndeg();

	//JUN 2020
	bool canConnect(int a, int b, int n);
	bool canConnect2(int a, int b, int n);
	void canConnect2TraziPut(LinkedNodeInt* r, int b, int n, int distance, bool* moze);
	
	//SEPTEMBAR 2020
	void MakeUndirected();
	bool isWeeklyConnected();
	int traverseFrom(LinkedNodeInt* ptr);

	//JUN2 2020
	int findLeastNodesPath(LinkedNodeInt* n1, LinkedNodeInt* n2);

	//OKTOBAR 2020
	int putnikBiraNajduzeGdeNijeBio(int a);

	//SEPTEMBAR 2019 (vrv nije efikasno)
	LinkedNodeInt* findMaxReachableWithRoundTrip();
	void traziNajduziPutSaPovratkom(LinkedNodeInt* node, LinkedNodeInt* prev, LinkedNodeInt** maxNode, int* maxCount);
	bool hasOppositeDirectionEdge(LinkedNodeInt* node, LinkedEdgeInt* edge);

	//JUN 2018 (ima optimizaciju, ali ne znam da li je najefikasnije)
	int maxBrojDobacivanja();
	//teorijski deo
	static GraphAsListsInt* formirajGrafOdMatriceIncidencije(int mat[][5], int n, int m);

	//SEPTEMBAR 2018
	int calcPrevious(int subjects[], int n);
	void obilazak(LinkedNodeInt* node, int* brCvorova);

	//JANUAR 2020
	int putnikPreseda(int a, int b, int aerodromi[], int maxTrajanje);
	void traziPut(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], bool* nadjen, int* n);
	void traziPut2(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n);
	void traziPut3(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n);
	void traziPut4(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n);

	//OKTOBAR2 2018
	int maxNodes();
	void obilazakDisjunktnogPodgrafa(LinkedNodeInt* node, int* brojObidjenih, int oznaka);
	int maxNodes2();
	int obilazakDisjunktnogPodgrafa2(LinkedNodeInt* node);

	//APRIL 2018
	bool MakeFriendship(int a, int b);
	bool MakeFriendship2(int a, int b);
	int friendsOfFriends(LinkedNodeInt* node, LinkedNodeInt* b, int distance); //potvrditi

	//APRIL 2019
	bool CanReach(LinkedNodeInt* n1, LinkedNodeInt* n2, int hops);

	//DECEMBAR 2020
	bool Merge(int id1, int id2);
	
	//LAB ZAD1 (broj potega u ciklusu najmanje duzine)
	int shortestCycle();
	int findShortestCycleFromNode(LinkedNodeInt* node);

	//LAB ZAD2 (broj cvorova do kojih se moze doci iz zadatog, tako da je put manji od zadatog)
	int numberOfCloseNodes(LinkedNodeInt* node, int maxDistance);
	int numberOfCloseNodes2(LinkedNodeInt* node, int maxDistance);
	void findCloseNodes(LinkedNodeInt* node, int maxDistance, int distance, int* num);
	

	//LAB ZAD3 (bilo koji od zadatog do zadatog cvora koji ne prolazi kroz zadati poteg)
	//uradi ponovo
	int nadjiPutBezPotega(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[]);
	void traziPutBezPotega(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[], int rastojanje, bool* pronadjen, int* n);
	void traziPutBezPotega2(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[], int distance, int* n);

	//KOLOKVIJUM2 2021
	int putAgenta(int a, int b, int maxDuzina);

	//MOJ ZADATAK 1 - odredjivanje puta od a do b
	int nadjiPutOdADoB(int a, int b, int put[]);
	void traziPutOdADoB(LinkedNodeInt* a, LinkedNodeInt* b, int distance, int* n);

	//FEBRUAR 2017
	int FindMax(int airport);

	//MOJ ZADATAK 2 - da li postoji kraci ili jednak put od zadate duzine
	bool postojiPut(int a, int b, int n);
	void trazenjePuta(LinkedNodeInt* a, LinkedNodeInt* b, int distance, int max, int* hops);

	//MOJ ZADATAK 3 - spajanje cvorova uz sabiranje potega
	void spoji(int a, int b);

	//MOJ ZADATAK 4 - slabo ili jako povezan ili nepovezan
	void MakeUndirected2();
	void obilazakDFS(LinkedNodeInt* node, int* n);
	int utvrdiPovezanost();

	//SEPTEMBAR 2016
	int DisPaths(LinkedNodeInt* s, LinkedNodeInt* e);

	//KOLOKVIJUM2 2018
	void daLiJeDosaoDoGola(LinkedNodeInt* n, int oznakaGola, bool* dosaoDoGola, int igraci);
	int ucestvovaliUAkciji(int go);

	//SEPTEMBAR 2018
	int traverse(LinkedNodeInt* n);
	int CalcPrevious2(int subjects[], int n);
};

