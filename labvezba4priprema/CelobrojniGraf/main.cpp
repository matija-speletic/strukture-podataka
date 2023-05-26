#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt* g = new GraphAsListsInt();
	for (int i = 1; i <= 10; i++)
		g->insertNode(i);
	g->insertEdge(1, 6, 20);
	g->insertEdge(1, 2, 3);
	g->insertEdge(1, 9, 14);
	g->insertEdge(6, 7, 10);
	g->insertEdge(2, 3, 17);
	g->insertEdge(2, 5, 11);
	g->insertEdge(9, 2, 8);
	g->insertEdge(8, 4, 19);
	g->insertEdge(3, 8, 5);
	g->insertEdge(3, 4, 4);
	g->insertEdge(10, 4, 15);
	g->insertEdge(10, 3, 9);
	g->insertEdge(5, 10, 19);
	g->insertEdge(5, 3, 10);
	g->insertEdge(8, 7, 12);
	g->insertEdge(7, 3, 18);
	g->insertEdge(9, 5, 7);

	//jun2021
	/*cout << g->putDoAerodromaBiliC(1, 7, 7, 19) << endl; //4
	cout << g->putDoAerodromaBiliC(1, 7, 7, 25) << endl;  //2
	cout << g->putDoAerodromaBiliC(1, 3, 3, 15) << endl;  //3
	cout << g->putDoAerodromaBiliC(1, 3, 3, 25) << endl;  //2
	cout << g->putDoAerodromaBiliC(1, 4, 7, 19) << endl;  //3
	cout << g->putDoAerodromaBiliC(1, 4, 7, 25) << endl;  //2
	cout << g->putDoAerodromaBiliC(2, 7, 7, 25) << endl; //3
	cout << g->putDoAerodromaBiliC(2, 7, 10, 25);        //2
	cout << endl << endl << g->maxIndeg()->node;*/

	//jun2020
	/*cout << g->canConnect2(10, 7, 2) << endl;
	cout << g->canConnect2(10, 7, 3) << endl;
	cout << g->canConnect2(10, 7, 4) << endl;
	cout << g->canConnect2(1, 4, 3) << endl;
	cout << g->canConnect2(8, 2, 20) << endl;
	cout << g->canConnect2(2,8,3) << endl;
	//ocekivano: 011101*/

	//septembar2020
	/*GraphAsListsInt* g = new GraphAsListsInt();
	g->insertNode(1);
	g->insertNode(2);
	g->insertNode(3);
	g->insertNode(4);
	//g->insertNode(5);
	g->insertEdge(1, 2);
	g->insertEdge(2, 3);
	g->insertEdge(3, 4);
	g->insertEdge(1, 4);
	cout << endl << g->isWeeklyConnected();*/

	//junII2020
	/*GraphAsListsInt* g1 = new GraphAsListsInt();
	for (int i = 1; i < 9; i++)
		g1->insertNode(i);
	g1->insertEdge(1, 2);
	g1->insertEdge(2, 3);
	g1->insertEdge(3, 4);
	g1->insertEdge(4, 5);
	g1->insertEdge(5, 6);
	g1->insertEdge(6, 7);
	g1->insertEdge(7, 8);
	g1->insertEdge(8, 1);
	g1->insertEdge(2, 4);
	g1->insertEdge(4, 6);
	g1->insertEdge(6, 8);
	g1->insertEdge(8, 2);
	cout << g1->findLeastNodesPath(g1->findNode(1), g1->findNode(7)) << endl;
	cout << g1->findLeastNodesPath(g1->findNode(7), g1->findNode(1)) << endl;
	cout << g1->findLeastNodesPath(g1->findNode(2), g1->findNode(8)) << endl;*/

	//oktobar2020
	/*cout << g->putnikBiraNajduzeGdeNijeBio(1) << endl;
	cout << g->putnikBiraNajduzeGdeNijeBio(5) << endl;
	cout << g->putnikBiraNajduzeGdeNijeBio(9) << endl;
	cout << g->putnikBiraNajduzeGdeNijeBio(4) << endl;*/

	//septembar2019
	/*GraphAsListsInt* g = new GraphAsListsInt();
	for (int i = 1; i <= 10; i++)
		g->insertNode(i);
	g->insertEdge(1, 6, 20);
	g->insertEdge(1, 2, 3);
	g->insertEdge(1, 9, 14);
	g->insertEdge(6, 7, 10);
	g->insertEdge(2, 3, 17);
	g->insertEdge(2, 5, 11);
	g->insertEdge(9, 2, 8);
	g->insertEdge(8, 4, 19);
	g->insertEdge(3, 8, 5);
	g->insertEdge(3, 4, 4);
	g->insertEdge(10, 4, 15);
	g->insertEdge(10, 3, 9);
	g->insertEdge(5, 10, 19);
	g->insertEdge(5, 3, 10);
	g->insertEdge(8, 7, 12);
	g->insertEdge(7, 3, 18);
	g->insertEdge(9, 5, 7);

	g->insertEdge(3, 10, 10);
	g->insertEdge(7, 6, 12);
	g->insertEdge(3, 7, 18);
	g->insertEdge(8, 3, 7);
	g->insertEdge(4, 8, 18);
	g->insertEdge(2, 9, 18);
	g->insertEdge(10, 5, 18);
	g->insertEdge(5, 9, 7);
	//cout << g->hasOppositeDirectionEdge(g->findNode(1), g->findEdge(1, 2));
	//cout << g->hasOppositeDirectionEdge(g->findNode(6), g->findEdge(6, 7));
	cout << g->findMaxReachableWithRoundTrip()->node;*/

	//jun2018
	/*GraphAsListsInt* g = new GraphAsListsInt();
	g->insertNode(1);
	g->insertNode(2);
	g->insertNode(3);
	g->insertNode(4);
	g->insertEdge(1, 2, 2);
	g->insertEdge(2, 1, 7);
	g->insertEdge(4, 3, 5);
	g->insertEdge(3, 4, 5);
	g->insertEdge(4, 1, 7);
	g->insertEdge(1, 4, 4);
	g->insertEdge(3, 2, 4);
	g->insertEdge(3, 1, 10);
	g->insertEdge(1, 3, 2);
	g->insertEdge(2, 4, 7);
	g->maxBrojDobacivanja();*/
	//teorijski deo
	/*int mat[4][5] = { {-1,-1,0, 0, 0},
					{1, 0,-1, 1, 0},
					{0, 0, 1, 0, 1},
					{0, 1, 0,-1,-1} };
	GraphAsListsInt* gg = GraphAsListsInt::formirajGrafOdMatriceIncidencije(mat, 4, 5);
	gg->showGraphDetails();*/

	//septembar2018
	/*int s[] = { 7, 5 };
	g->calcPrevious(s, 2);*/

	//januar2020
	/*int n = 0, a[] = { -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
	n = g->putnikPreseda(1, 4, a, 19);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';
	n = g->putnikPreseda(1, 4, a, 12);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';
	n = g->putnikPreseda(1, 7, a, 29);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';
	n = g->putnikPreseda(1, 7, a, 15);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';*/
	

	cout << endl;

	//oktobarII2020
	/*GraphAsListsInt* g = new GraphAsListsInt();
	for (int i = 1; i <= 8; i++)
		g->insertNode(i);
	g->insertEdge(5,7);
	g->insertEdge(7,3);
	g->insertEdge(3,1);
	g->insertEdge(1,5);
	g->insertEdge(4,1);
	g->insertEdge(4,6);
	g->insertEdge(6,2);
	g->insertEdge(2,8);
	g->insertEdge(8,6);
	cout << endl << g->maxNodes2();*/

	//april2018
	/*g->MakeFriendship2(1, 7);
	g->MakeFriendship2(10, 8);
	g->MakeFriendship2(2, 7);
	g->MakeFriendship2(5, 3);
	g->MakeFriendship2(4, 5);
	g->MakeFriendship2(5, 8);
	g->MakeFriendship2(9, 9);
	g->MakeFriendship2(3, 7);*/

	//APRIL 2019
	/*cout << g->CanReach(g->findNode(1), g->findNode(4), 2) << endl;
	cout << g->CanReach(g->findNode(1), g->findNode(7), 3) << endl;
	cout << g->CanReach(g->findNode(2), g->findNode(4), 2) << endl;
	cout << g->CanReach(g->findNode(6), g->findNode(4), 2) << endl;
	cout << g->CanReach(g->findNode(10), g->findNode(1), 30) << endl;*/

	//DECEMBAR 2020
	/*g->Merge(7, 3);
	g->showGraphDetails();*/

	//LAB ZAD1
	/*//g->insertEdge(3, 2, 18);
	//g->insertEdge(2, 1, 7);
	g->shortestCycle();*/

	//LAB ZAD2
	/*for (int i = 1; i <= 10; i++)
	{
		cout << endl << g->numberOfCloseNodes2(g->findNode(i), 2) << endl;
		cout <<endl<< g->numberOfCloseNodes(g->findNode(i), 2) << endl << endl;
	}*/
		
	//LAB ZAD3
	/*int n = 0, a[] = { -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
	n = g->nadjiPutBezPotega(g->findNode(1), g->findNode(4), g->findEdge(3,4), a);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';*/

	//KOLOKVIJUM2 2021
	/*g->findNode(2)->stanica = false;
	g->findNode(7)->stanica = false;
	g->findEdge(5, 10)->weight = 7;
	g->findEdge(5, 3)->weight = 25;
	g->findEdge(3, 4)->weight = 25;
	g->findEdge(10, 4)->weight = 25;
	cout << endl << g->putAgenta(1, 4, 20);*/

	//MOJ ZADATAK 1
	/*int a[20], n = -1;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
		{
			cout << " put od " << i << " do " << j << ":\n";
			n = g->nadjiPutOdADoB(i, j, a);
			for (int k = 0; k < n; k++)
				cout << a[k] << "->";
			cout << endl << endl;
		}*/

	//FEBRUAR 2017
	/*for (int i = 1; i <= 10; i++)
		cout << g->FindMax(i) << endl;*/

	//MOJ ZADATAK 2
	/*g->postojiPut(1, 4, 3);
	g->postojiPut(1, 4, 2);
	g->postojiPut(8, 2, 10);
	g->postojiPut(9, 7, 40);
	g->postojiPut(9, 7, 3);
	g->postojiPut(1, 7, 2);
	g->postojiPut(10, 6, 5);*/

	//MOJ ZADATAK 3
	/*g->showGraphDetails();
	cout << endl << endl;
	g->spoji(3, 2);
	g->showGraphDetails();*/

	//MOJ ZADATAK 4
	/*cout << endl;
	GraphAsListsInt* g1 = new GraphAsListsInt();
	for (int i = 1; i <= 8; i++)
		g1->insertNode(i);
	g1->insertEdge(5, 7);
	g1->insertEdge(7, 3);
	g1->insertEdge(3, 1);
	g1->insertEdge(1, 5);
	g1->insertEdge(4, 6);
	g1->insertEdge(6, 2);
	g1->insertEdge(2, 8);
	g1->insertEdge(8, 6);
	GraphAsListsInt* g2 = new GraphAsListsInt();
	for (int i = 1; i < 9; i++)
		g2->insertNode(i);
	g2->insertEdge(1, 2);
	g2->insertEdge(2, 3);
	g2->insertEdge(3, 4);
	g2->insertEdge(4, 5);
	g2->insertEdge(5, 6);
	g2->insertEdge(6, 7);
	g2->insertEdge(7, 8);
	g2->insertEdge(8, 1);
	g2->insertEdge(2, 4);
	g2->insertEdge(4, 6);
	g2->insertEdge(6, 8);
	g2->insertEdge(8, 2);
	g1->utvrdiPovezanost();
	g->utvrdiPovezanost();
	g2->utvrdiPovezanost();*/

	cout << endl;

	//SEPTEMBAR 2016
	cout << g->DisPaths(g->findNode(1), g->findNode(4));

	//KOLOKVIJUM2 2018
	/*GraphAsListsInt* g = new GraphAsListsInt();
	for (int i = 1; i <= 11; i++)
		g->insertNode(i);
	g->insertNode(60);
	g->insertEdge(5,1);
	g->insertEdge(1,6);
	g->insertEdge(6,2);
	g->insertEdge(6,9);
	g->insertEdge(6,10);
	g->insertEdge(9,10);
	g->insertEdge(10,7);
	g->insertEdge(7,6);
	g->insertEdge(7,8);
	g->insertEdge(8,60);
	g->insertEdge(2,3);
	g->insertEdge(3,4);
	g->insertEdge(4,11);
	//g->insertEdge(12,2);
	cout<<endl<<g->ucestvovaliUAkciji(60);*/


	delete g;
}

