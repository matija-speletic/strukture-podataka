#include "GraphInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
	// cout << "Not implemented!" << endl;
	//u svakom prolazu brisemo prvi element lancane liste cvorova
	LinkedNodeInt* ptr = start;
	while (ptr != NULL)
	{
		LinkedNodeInt* ptr2 = ptr->next;
		deleteNode(ptr->node);
		ptr = ptr2;
	}
	start = NULL;
}

LinkedNodeInt* GraphAsListsInt::findNode(const int& data) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data)
		ptr = ptr->next;
	return ptr;
}

LinkedEdgeInt* GraphAsListsInt::findEdge(const int& dataSrc, const int& dataDest) const
{
	LinkedNodeInt* ptr = findNode(dataSrc);
	if (ptr == nullptr)
		return nullptr;
	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest)
		pEdge = pEdge->link;
	return pEdge;
}

void GraphAsListsInt::insertNode(const int& data)
{
	start = new LinkedNodeInt(data, nullptr, start);
	nodeNum++;
}

bool GraphAsListsInt::insertEdge(const int& dataSrc, const int& dataDest, const double& weight /*= 0*/)
{
	LinkedNodeInt* pSrc = nullptr;
	LinkedNodeInt* pDest = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && (pSrc == nullptr || pDest == nullptr)) {
		if (ptr->node == dataSrc) {
			pSrc = ptr;
		}
		else if (ptr->node == dataDest) {
			pDest = ptr;
		}
		ptr = ptr->next;
	}
	if (pSrc == nullptr || pDest == nullptr)
		return false;
	pSrc->adj = new LinkedEdgeInt(pDest, weight, pSrc->adj);
	return true;
}

bool GraphAsListsInt::deleteEdge(const int& dataSrc, const int& dataDest)
{
	LinkedNodeInt* pSrc = findNode(dataSrc);
	if (pSrc == nullptr)
		return false;

	LinkedEdgeInt* pEdgePrev = nullptr;
	LinkedEdgeInt* pEdge = pSrc->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest) {
		pEdgePrev = pEdge;
		pEdge = pEdge->link;
	}
	if (pEdge == nullptr)
		return false;

	if (pEdgePrev == nullptr)
		pSrc->adj = pEdge->link;
	else
		pEdgePrev->link = pEdge->link;

	delete pEdge;

	return true;
}

void GraphAsListsInt::deleteEdgeToNode(const LinkedNodeInt* pDest)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdgePrev = nullptr;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr && pEdge->dest != pDest) {
			pEdgePrev = pEdge;
			pEdge = pEdge->link;
		}
		if (pEdge != nullptr)
		{
			if (pEdgePrev == nullptr)
				ptr->adj = pEdge->link;
			else
				pEdgePrev->link = pEdge->link;
			delete pEdge;//mislim da je ovo falilo
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::deleteNode(const int& data)
{
	LinkedNodeInt* prev = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;

	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr) {
		LinkedEdgeInt* pEdgeTmp = pEdge->link;
		delete pEdge;
		pEdge = pEdgeTmp;
	}
	ptr->adj = nullptr;

	deleteEdgeToNode(ptr);

	if (prev == nullptr)
		start = start->next;
	else
		prev->next = ptr->next;

	delete ptr;
	nodeNum--;

	return true;
}

void GraphAsListsInt::print() const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		cout << ptr->node << " -> ";
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			cout << pEdge->dest->node << " | ";
			pEdge = pEdge->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

void GraphAsListsInt::setStatusForAllNodes(int status) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = status;
		ptr = ptr->next;
	}
}

long GraphAsListsInt::breadthFirstTraversal(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(ptr);
	ptr->status = 2;
	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				queue.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalIterative(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(ptr);
	ptr->status = 2;
	while (!stack.isEmpty()) {
		ptr = stack.pop();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				stack.push(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(LinkedNodeInt* ptr) const
{
	int retVal = 0;
	if (ptr->status != 1) {
		ptr->visit();
		ptr->status = 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			retVal += depthFirstTraversalRecursive(pEdge->dest);
			pEdge = pEdge->link;
		}
		retVal++;
	}
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(const int& data) const
{
	LinkedNodeInt* pNode = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		if (ptr->node == data) {
			pNode = ptr;
		}
		ptr = ptr->next;
	}

	if (pNode == nullptr)
		return 0;

	return depthFirstTraversalRecursive(pNode);
}

long GraphAsListsInt::topologicalOrderTravrsal() const
{
	int retVal = 0;

	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status += 1;
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == 0)
			queue.enqueue(ptr);
		ptr = ptr->next;
	}

	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status--;
			if (pEdge->dest->status == 0)
				queue.enqueue(pEdge->dest);
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

void GraphAsListsInt::showGraphDetails()
{
	LinkedNodeInt* ptr = start;
	while (ptr != NULL)
	{
		cout << "Cvor " << ptr->node << " je povezan sa: ";
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			cout << pEdge->dest->node << "(" << pEdge->weight << "), ";
			pEdge = pEdge->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

int GraphAsListsInt::putDoAerodromaBiliC(int a, int b, int c, int maxMinuta)
{
	/* klasican postupak za trazenje najkraceg puta koriscenjem BFS s tim
	sto biramo samo puteve krace od zadatog boja minuta i stajemo kada 
	naidjemo na b ili c*/
	if (start == NULL)
		return -1;
	LinkedNodeInt* ptr = start;
	while (ptr->node != a)
	{
		ptr = ptr->next;
		if (ptr == NULL)
			return -1;
	}
	setStatusForAllNodes(-1);
	QueueAsArrayLinkedNodeInt que(nodeNum);
	que.enqueue(ptr);
	int distance = 0;
	ptr->status = 0;
	while (!que.isEmpty())
	{
		ptr = que.dequeue();
		distance = ptr->status;
		if (ptr->node == b || ptr->node == c)
		{
			cout << ptr->node << ' ';
			return distance;
		}
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			if (pEdge->dest->status == -1 && pEdge->weight <= maxMinuta)
			{
				//cout << "idemo linijom od " << ptr->node << " do " << pEdge->dest->node << endl;
				que.enqueue(pEdge->dest);
				pEdge->dest->status = distance + 1;
			}
			pEdge = pEdge->link;
		}
	}
	return -1;
}

LinkedNodeInt* GraphAsListsInt::maxIndeg()
{
	int maxDeg = -1;
	LinkedNodeInt* maxPtr = NULL, * ptr = start;
	setStatusForAllNodes(0);
	while (ptr != NULL)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			pEdge->dest->status++;
			if (pEdge->dest->status > maxDeg)
			{
				maxDeg = pEdge->dest->status;
				maxPtr = pEdge->dest;
			}
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}
	cout << maxDeg;
	return maxPtr;
}

bool GraphAsListsInt::canConnect(int a, int b, int n)
{
	/*klasican postupak za najkraci put preko bfs uz brojenje 
	razdaljine...kada razdaljina postane veca od n, prekidamo 
	, narano, ako prethodno nismo naisli*/
	LinkedNodeInt* ptr = start;
	while (ptr != NULL && ptr->node != a)
		ptr = ptr->next;
	if (ptr == NULL)
		return false;
	int distance = 0;
	setStatusForAllNodes(-1);
	QueueAsArrayLinkedNodeInt que(nodeNum);
	que.enqueue(ptr);
	ptr->status = 0;
	while (!que.isEmpty())
	{
		ptr = que.dequeue();
		distance = ptr->status;
		if (distance > n)
			return false;
		else if (ptr->node == b)
			return true;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			if (pEdge->dest->status == -1)
			{
				pEdge->dest->status = distance + 1;
				que.enqueue(pEdge->dest);
			}
			pEdge = pEdge->link;
		}
	}
	return false;
}

bool GraphAsListsInt::canConnect2(int a, int b, int n)
{
	bool ret = false;
	LinkedNodeInt* ptr = start;
	while (ptr != NULL && ptr->node != a)
		ptr = ptr->next;
	if (ptr == NULL)
		return false;
	setStatusForAllNodes(0);
	canConnect2TraziPut(ptr, b, n, 0, &ret);
	return ret;
}

void GraphAsListsInt::canConnect2TraziPut(LinkedNodeInt* r, int b, int n, int distance, bool* moze)
{
	if (r == NULL || *moze || distance > n) //proveri sa emom
		return;
	if (r->node == b)
	{
		*moze = true;
		return;
	}
	//if (r->status == 1)return;
	r->status = 1;
	for (LinkedEdgeInt* pEdge = r->adj; pEdge != NULL; pEdge = pEdge->link)
		//if (pEdge->dest->status == 0) //proveri sa emom
			canConnect2TraziPut(pEdge->dest, b, n, distance + 1, moze);
}

void GraphAsListsInt::MakeUndirected()
{
	/*za svaki cvor za svaki njegov poteg, proveravamo da li postoji poteg
	istog pravca i suprotnog smera, ako ne - dodamo ga, ako da nista*/
	LinkedNodeInt* ptr = start;
	while (ptr != NULL)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			LinkedEdgeInt* peDest = pEdge->dest->adj;
			bool vecPostoji = false;
			while (peDest != NULL && !vecPostoji)
			{
				if (peDest->dest == ptr)
					vecPostoji = true;
				peDest = peDest->link;
			}
			if (!vecPostoji)
			{
				pEdge->dest->adj = new LinkedEdgeInt(ptr, pEdge->weight, pEdge->dest->adj);
				cout << "dodato od " << pEdge->dest->node << " do " << ptr->node << endl;
			}
			cout << "proverio za od " << ptr->node << " do " << pEdge->dest->node << endl;
			pEdge = pEdge->link;

		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::isWeeklyConnected()
{
	//postupak opisan u praktikumu, traverseFrom je bfs
	LinkedNodeInt* ptr = start;
	bool inicijalnoNepovezan = false;
	while (ptr != NULL)
	{
		if (nodeNum != traverseFrom(ptr))
		{
			inicijalnoNepovezan = true;
			break;
		}
		ptr = ptr->next;
	}
	MakeUndirected();
	bool kasnijeNepovezan = false;
	while (ptr != NULL)
	{
		if (nodeNum != traverseFrom(ptr))
		{
			kasnijeNepovezan = true;
			break;
		}
		ptr = ptr->next;
	}
	cout << endl << endl << inicijalnoNepovezan << kasnijeNepovezan;
	return inicijalnoNepovezan && !kasnijeNepovezan;
}

int GraphAsListsInt::traverseFrom(LinkedNodeInt* ptr)
{//bfs
	int retVal = 0;
	setStatusForAllNodes(1);
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(ptr);
	ptr->status = 2;
	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->status = 3;
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				queue.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	return retVal;
}

int GraphAsListsInt::findLeastNodesPath(LinkedNodeInt* n1, LinkedNodeInt* n2)
{
	//modifikovan bfs, radjen 1000puta do sad
	if (n1 == NULL || n2 == NULL || start == NULL)
		return -1;
	setStatusForAllNodes(-1);
	QueueAsArrayLinkedNodeInt que(nodeNum);
	LinkedNodeInt* ptr = n1;
	int distance = 0;
	que.enqueue(ptr);
	ptr->status = 0;
	while (!que.isEmpty())
	{
		ptr = que.dequeue();
		LinkedEdgeInt* pEdge = ptr->adj;
		distance = ptr->status;
		if (ptr == n2)
			return distance + 1;
		while (pEdge != NULL)
		{
			if (pEdge->dest->status == -1)
			{
				que.enqueue(pEdge->dest);
				pEdge->dest->status = distance + 1;
			}
			pEdge = pEdge->link;
		}
	}
	return -1;
}

int GraphAsListsInt::putnikBiraNajduzeGdeNijeBio(int a)
{
	/*krecemo iz zadatog cvora i u svakom prolazu, prelazimo na
	najudaljeniji cvor koji nije prehodno obidjen, a ako takvih nema
	izlazi se iz petlje i to je kraj*/
	LinkedNodeInt* ptr = start;
	while (ptr != NULL && ptr->node != a)
		ptr = ptr->next;
	if (ptr == NULL)
		return -1;
	setStatusForAllNodes(-1);
	int distance = 0;
	while (true)
	{
		cout << "putnik je u tacki " << ptr->node;
		int maxWeight = 0;
		LinkedEdgeInt* maxPath = NULL;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			if (pEdge->weight > maxWeight && pEdge->dest->status == -1)
			{
				maxPath = pEdge;
				maxWeight = pEdge->weight;
			}
			pEdge = pEdge->link;
		}
		if (maxPath != NULL)
		{
			cout << " i izabrao je put duzine " << maxPath->weight 
				<< " do mesta " << maxPath->dest->node << endl;
			ptr = maxPath->dest;
			distance += maxPath->weight;
		}
		else
		{
			cout << " i ovde zavrsava putovanje" << endl;
			return distance;
		}
	}
	return -1;
}

LinkedNodeInt* GraphAsListsInt::findMaxReachableWithRoundTrip()
{
	/*iz svakog cvora pokrecemo pretragu za najduzim putem kojim
	moze da se vrati pozivom rekurzivne funkcije*/
	LinkedNodeInt* maxNode = NULL;
	int maxCount = 0;
	LinkedNodeInt* ptr = start;
	while (ptr != NULL)
	{
		int thisMaxCount = 0;
		LinkedNodeInt* thisMaxNode = NULL;
		setStatusForAllNodes(-1);
		ptr->status = 1;
		traziNajduziPutSaPovratkom(ptr, NULL, &thisMaxNode, &thisMaxCount);
		if (thisMaxCount > maxCount)
		{
			maxCount = thisMaxCount;
			maxNode = thisMaxNode;
		}
		ptr = ptr->next;
	}
	cout << maxCount << endl;
	return maxNode;
}

void GraphAsListsInt::traziNajduziPutSaPovratkom(LinkedNodeInt* node, LinkedNodeInt* prev,  LinkedNodeInt** maxNode, int* maxCount)
{
	/*polazimo iz node, a prev je cor iz kog smo dosli (da se ne bismo ponovo vracali unazad, jer bi se
	uslo u beskonacnu petlju), ideja je da u statusu svakog cvora bude upisan trenutni broj obidjenih cvorova do sad
	(to se uvek upisuje pre poziva fje) i ako je taj broj veci od trenutnog maxa, on postaje trenutni max
	za svaki susedni cvor ovog potega pozivamo rekurzivno ovu funkciju, ako do njega vec ne postoji put koji je duzi
	od trenutnog, ako to nije prethodni cvor i ako postoji povratni poteg i pre poziva postavljamo status odredista 
	na count+1*/
	int count = node->status;
	if (count > *maxCount)
	{
		*maxCount = count;
		*maxNode = node;
	}
	LinkedEdgeInt* pEdge = node->adj;
	while (pEdge != NULL)
	{
		if (pEdge->dest->status < count + 1 && pEdge->dest != prev && hasOppositeDirectionEdge(node, pEdge))
		{
			pEdge->dest->status = count + 1;
			//cout << "idem od " << node->node << " do " << pEdge->dest->node << endl;
			traziNajduziPutSaPovratkom(pEdge->dest, node, maxNode, maxCount);
		}
		pEdge = pEdge->link;
	}

}

bool GraphAsListsInt::hasOppositeDirectionEdge(LinkedNodeInt* node, LinkedEdgeInt* edge)
{
	//proverava da li za dati poteg postoji i povratni
	LinkedEdgeInt* pEdge = edge->dest->adj;
	while (pEdge != NULL)
	{
		if (pEdge->dest == node)
			return true;
		pEdge = pEdge->link;
	}
	return false;
}

int GraphAsListsInt::maxBrojDobacivanja()
{
	/*za svaki poteg svakog cvora proveravamo da li postoji povratni poteg - ako postoji, proveravamo da li je taj 
	broj dobacivanja veci od trenutnog max, ako jeste - on postaje nvi max (naravno, cim se pronadje povratni poteg 
	izlazi se iz te petlje. svaki put kada uradimo ovu proveru za neki cvor, njegov status postavimo na 1 i na taj 
	iznacavamo da enma potrebe proveravati broj dobacivanja od nekog drugog cvora ka ovom jer je vec provereno*/
	setStatusForAllNodes(0);
	int maxDobacivanja = 0;
	LinkedNodeInt* igrac1max = NULL, * igrac2max = NULL, * ptr = start;
	while (ptr != NULL)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			if (pEdge->dest->status != 0)
			{//ako smo vec proverili za ovaj cvor, idemo na sledeci
				pEdge = pEdge->link;
				continue;
			}
			LinkedEdgeInt* pEdge2 = pEdge->dest->adj;
			while (pEdge2 != NULL)
			{
				if (pEdge2->dest == ptr)
				{
					if (pEdge->weight + pEdge2->weight > maxDobacivanja)
					{
						maxDobacivanja = pEdge->weight + pEdge2->weight;
						igrac1max = pEdge2->dest;
						igrac2max = pEdge->dest;
					}
					break;
				}
				pEdge2 = pEdge2->link;
			}
			pEdge = pEdge->link;
		}
		//proverili smo sva dobacivanja za ovog igraca i nema potrebe ponovo da ga proveravamo (ovo je optimizacija)
		ptr->status = 1;
		ptr = ptr->next;
	}
	if (igrac1max != NULL && igrac2max != NULL)
		cout << "max broj dobacivanja je bio izmedju " << igrac1max->node << " i " << igrac2max->node
		<< " i on iznosi " << maxDobacivanja << endl;
	return maxDobacivanja;
}

GraphAsListsInt* GraphAsListsInt::formirajGrafOdMatriceIncidencije(int mat[][5], int n, int m)
{
	
	GraphAsListsInt* g = new GraphAsListsInt();
	for (int i = 1; i <= n; i++)
		g->start = new LinkedNodeInt(i, NULL, g->start);
	LinkedNodeInt* ptr = g->start;
	while (ptr != NULL)
	{
		int i = ptr->node - 1;
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == -1)
			{
				int k = 0;
				while (mat[k][j] != 1)k++;
				LinkedNodeInt* ptrDest = g->start;
				while (ptrDest->node != k + 1)
					ptrDest = ptrDest->next;
				ptr->adj = new LinkedEdgeInt(ptrDest, ptr->adj);
			}
		}
		ptr = ptr->next;
	}
	return g;
}

int GraphAsListsInt::calcPrevious(int subjects[], int n)
{
	setStatusForAllNodes(0);
	int retVal = 0;
	for (int i = 0; i < n; i++)
	{
		LinkedNodeInt* ptr = start;
		while (ptr != NULL && ptr->node != subjects[i])
			ptr = ptr->next;
		if (ptr == NULL)
			throw "Predmet ne postoji";
		obilazak(ptr, &retVal);
	}
	cout << "ukupno treba da slusa: " << retVal << endl;
	return retVal;
}

void GraphAsListsInt::obilazak(LinkedNodeInt* node, int* brCvorova)
{
	if (node == NULL || node->status == 1)
		return;
	(*brCvorova)++;
	node->status = 1;
	cout << "treba da slusa " << node->node << endl;
	LinkedEdgeInt* pEdge = node->adj;
	while (pEdge != NULL)
	{
		obilazak(pEdge->dest, brCvorova);
		pEdge = pEdge->link;
	}
}

int GraphAsListsInt::putnikPreseda(int a, int b, int aerodromi[], int maxTrajanje)
{
	LinkedNodeInt* ptr = start;
	while (ptr != NULL && ptr->node != a)
		ptr = ptr->next;
	if (ptr == NULL)
		return -1;
	int n = -1;
	/*bool nadjen = false;
	traziPut(ptr, b, 0, maxTrajanje, aerodromi, &nadjen, &n);
	if (nadjen)
		return n;
	else
		return -1;*/
	setStatusForAllNodes(0);
	traziPut4(ptr, b, 0, maxTrajanje, aerodromi, &n);
	return n;
}

void GraphAsListsInt::traziPut(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], bool* nadjen, int* n)
{
	if (node == NULL || node->status==1 || *nadjen)
		return;
	cout << node->node << ' ';
	node->status = 1;
	if (node->node == dest)
	{
		*nadjen = true;
		*n = duzina + 1;
		aerodromi[duzina] = node->node;
		cout << "\nnadjen! dodajem " << node->node;
		return;
	}
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->weight <= maxTrajanje && pEdge->dest->status == 0)
			traziPut(pEdge->dest, dest, duzina + 1, maxTrajanje, aerodromi, nadjen, n);
	if (*nadjen)
	{
		aerodromi[duzina] = node->node;
		cout << "\ndodajem " << node->node;
	}
}

void GraphAsListsInt::traziPut2(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n)
{
	if (node == NULL || *n != -1) //proveri sa emom
		return;
	if (node->node == dest)
	{
		LinkedNodeInt* ptr = node;
		*n = duzina + 1;
		for (int i = 0; i < duzina + 1; i++, ptr = ptr->prev)
			aerodromi[i] = ptr->node;
		return;
	}
	if (node->status == 1)return;
	node->status = 1;
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->weight < maxTrajanje /*&& pEdge->dest->status == 0*/)
		{
			pEdge->dest->prev = node;
			traziPut2(pEdge->dest, dest, duzina + 1, maxTrajanje, aerodromi, n);
		}
}

void GraphAsListsInt::traziPut3(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n)
{
	if (node == NULL || node->status == 1 || *n != -1)
		return;
	if (node->node == dest)
	{
		*n = duzina + 1;
		LinkedNodeInt* ptr = node;
		for (int i = duzina; i >= 0; i--, ptr = ptr->prev)
			aerodromi[i] = ptr->node;
		return;
	}
	node->status = 1;
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->weight <= maxTrajanje)
		{
			pEdge->dest->prev = node;
			traziPut3(pEdge->dest, dest, duzina + 1, maxTrajanje, aerodromi, n);
			if (*n != -1)
				return;
		}
}

void GraphAsListsInt::traziPut4(LinkedNodeInt* node, int dest, int duzina, int maxTrajanje, int aerodromi[], int* n)
{
	if (node == NULL ||*n != -1)
		return;
	if (node->node == dest)
	{
		*n = duzina + 1;
		LinkedNodeInt* ptr = node;
		for (int i = duzina; i >= 0; i--, ptr = ptr->prev)
			aerodromi[i] = ptr->node;
		return;
	}
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->weight <= maxTrajanje && pEdge->dest->status == 0)
		{
			pEdge->dest->prev = node;
			pEdge->dest->status = 1;
			traziPut4(pEdge->dest, dest, duzina + 1, maxTrajanje, aerodromi, n);
			if (*n != -1)
				return;
		}
}

int GraphAsListsInt::maxNodes()
{
	int maxN = 0;
	setStatusForAllNodes(0);
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->status == 0)
		{
			int broj = 0;
			obilazakDisjunktnogPodgrafa(ptr, &broj, ptr->node);
			cout << "iz cvora " << ptr->node << " podgraf ima cvorova " << broj << endl;
			if (broj == nodeNum)
				setStatusForAllNodes(0);
			else if (broj > maxN)
				maxN = broj;
		}
	}
	return maxN;
}

void GraphAsListsInt::obilazakDisjunktnogPodgrafa(LinkedNodeInt* node, int* brojObidjenih, int oznaka)
{
	/*ideja: da ne bismo pokretali obilazak iz svakog cvora (ako ustanovimo da neki cvorovi cine podgraf,
	nema potrebe pokretati pretragu od njih, medjutim, posto nam trebaju statusi cvorova, prilikom svakog
	obilaska, potrebno je da svaki obilazak ima svoju oznaku (npr obilazak iz cvora 5 ce oznacavati statuse
	obidjenih cvorova sa 5, a sve razlicito od 5 ce tretirati kao 0). na ovaj nacin, podgrafe trazimo samo 
	iz cvorova koji nisu deo nekog podgrafa, ali omogucavamo da podgraf bude deo veceg podgrafa*/
	if (node == NULL || node->status == oznaka)
		return;
	node->status = oznaka;
	(*brojObidjenih)++;
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->dest->status != oznaka)
			obilazakDisjunktnogPodgrafa(pEdge->dest, brojObidjenih, oznaka);
}

int GraphAsListsInt::maxNodes2()
{
	int maxNodes = -1;
	LinkedNodeInt* maxNode = NULL;
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		setStatusForAllNodes(0);
		int num = obilazakDisjunktnogPodgrafa2(ptr);
		if (num != nodeNum && num > maxNodes)
		{
			maxNodes = num;
			maxNode = ptr;
		}
	}
	cout << "Najveci pograf je iz cvora " << maxNode->node << " i on je: ";
	breadthFirstTraversal(maxNode->node);
	return maxNodes;
}

int GraphAsListsInt::obilazakDisjunktnogPodgrafa2(LinkedNodeInt* node)
{
	if (node == NULL)
		return 0;
	int retVal = 1;
	node->status = 1;
	for(LinkedEdgeInt* pEdge=node->adj;pEdge!=NULL;pEdge=pEdge->link)
		if (pEdge->dest->status == 0)
			retVal += obilazakDisjunktnogPodgrafa2(pEdge->dest);
	return retVal;
}

bool GraphAsListsInt::MakeFriendship(int a, int b)
{
	LinkedNodeInt* ptr = start, * ptrA;
	for (; ptr != NULL && ptr->node != a; ptr = ptr->next);
	if (ptr == NULL)
		return false;
	ptrA = ptr;
	setStatusForAllNodes(-1);
	int distance = 0;
	LinkedNodeInt* ptrB = NULL;
	ptr->status = 0;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(ptr);
	while (!q.isEmpty())
	{
		ptr = q.dequeue();
		distance = ptr->status;
		if (distance > 2)
		{
			cout << ptrA->node << " i " << b << " su dalji nego prijatelji prijatelja" << endl;
			return false;
		}
		if (ptr->node == b)
		{
			if (distance != 2)
			{
				cout << ptrA->node << " i " << b << " su ili vec prijatelji ili ista osoba" << endl;
				return false;
			}
			ptrB = ptr;
			break;
		}
		for (LinkedEdgeInt* pEdge = ptr->adj; pEdge != NULL; pEdge = pEdge->link)
			if (pEdge->dest->status == -1)
			{
				pEdge->dest->status = distance + 1;
				q.enqueue(pEdge->dest);
			}
	}
	if (ptrB == NULL)
	{
		cout << ptrA->node << " i " << b << " nisu povezani jer je prvi izolovan" << endl;
		return false;
	}
	else
	{
		ptrA->adj = new LinkedEdgeInt(ptrB, ptrA->adj);
		cout << "dodata grana od " << ptrA->node << " do " << ptrB->node << endl;
		return true;
	}
}

bool GraphAsListsInt::MakeFriendship2(int a, int b)
{
	LinkedNodeInt* ptr = start, * pa = NULL, * pb = NULL;
	while (ptr != NULL && (pa == NULL || pb == NULL))
	{
		if (ptr->node == a)
			pa = ptr;
		if (ptr->node == b)
			pb = ptr;
		ptr = ptr->next;
	}
	int num = friendsOfFriends(pa, pb, 0);
	if (num == 0)
	{
		cout << "nije moguce\n";
		return false;
	}
	if (num == 1)
	{
		cout << "vec su prijatelji\n";
		return false;
	}
	if (num == 2)
	{
		cout << "dodajem poteg\n";
		pa->adj = new LinkedEdgeInt(pb, pa->adj);
		return true;
	}
	cout << "greska\n";
	return false;
}

int GraphAsListsInt::friendsOfFriends(LinkedNodeInt* node, LinkedNodeInt* b, int distance)
{
	if (node == NULL || b == NULL)
		return 0;
	if (distance > 2)
		return 0;
	if (node == b)
		return distance;
	int retVal = 0;
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL && retVal == 0; pEdge = pEdge->link)
		retVal=friendsOfFriends(pEdge->dest, b, distance + 1);
	return retVal;
}

bool GraphAsListsInt::CanReach(LinkedNodeInt* n1, LinkedNodeInt* n2, int hops)
{
	if (n1 == NULL || n2 == NULL || hops == 0)
		return false;
	LinkedNodeInt* ptr = n1;
	setStatusForAllNodes(-1);
	int distance = 0;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	ptr->status = 0;
	q.enqueue(ptr);
	while (!q.isEmpty())
	{
		ptr = q.dequeue();
		distance = ptr->status;
		if (distance > hops)
			return false;
		if (ptr == n2)
			return true;
		for(LinkedEdgeInt* pEdge=ptr->adj;pEdge!=NULL;pEdge=pEdge->link)
			if (pEdge->dest->status == -1)
			{
				pEdge->dest->status = distance + 1;
				q.enqueue(pEdge->dest);
			}
	}
	return false;
}

bool GraphAsListsInt::Merge(int id1, int id2)
{
	LinkedNodeInt* n1 = NULL, * n2 = NULL, * ptr = start, *n2prev=NULL;
	while (ptr != NULL && (n1 == NULL || n2 == NULL))
	{
		if (ptr->node == id1)
			n1 = ptr;
		if (ptr->node == id2)
			n2 = ptr;
		else if (n2 == NULL)
			n2prev = ptr;
		ptr = ptr->next;
	}
	if (n1 == NULL || n2 == NULL)
		return false;
	ptr = start;
	while (ptr != NULL)
	{
		LinkedEdgeInt* pEdge = ptr->adj, *prev = NULL;
		while (pEdge != NULL)
		{
			if (ptr == n2)//potege od n2 prebacujemo na n1
			{
				if (prev == NULL)
					ptr->adj = pEdge->link;
				else
					prev->link = pEdge->link;
				if (pEdge->dest == n1)//ako su od n2 ka n1 brisemo ih
					delete pEdge;
				else//u suprotnom prebacujemo
				{
					pEdge->link = n1->adj;
					n1->adj = pEdge;
				}
				pEdge = prev != NULL ? prev->link : ptr->adj;
				continue;//na ovaj nacin zapravo nastavljamo jer je link obrisan
			}
			else if (pEdge->dest == n2)
			{
				if (ptr == n1)//ako je poteg od opstine 1 do opstine 2 brisemo ga
				{
					if (prev == NULL)
						ptr->adj = pEdge->link;
					else
						prev->link = pEdge->link;
					delete pEdge;
					pEdge = prev != NULL ? prev->link : ptr->adj;
					continue;
				}
				pEdge->dest = n1;
			}
			prev = pEdge;
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}
	n1->node = n1->node + n2->node + 100;
	if (n2prev == NULL)
		start = n2->next;
	else
		n2prev->next = n2->next;
	delete n2;
	return true;
}

int GraphAsListsInt::shortestCycle()
{
	int minCyc = nodeNum * 2;
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		int cycSize = findShortestCycleFromNode(ptr);
		if (cycSize != -1)
			cout << "nadjen ciklus iz " << ptr->node << " duzine " << cycSize << endl;
		else
			cout << "nije nadjen ciklus iz " << ptr->node << endl;
		if (cycSize < minCyc && cycSize != -1)
			minCyc = cycSize;
	}
	return minCyc;
}

int GraphAsListsInt::findShortestCycleFromNode(LinkedNodeInt* node)
{
	if (node == NULL)
		return -1;
	int distance = 0;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	setStatusForAllNodes(-1);
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
	{
		pEdge->dest->status = 1;
		q.enqueue(pEdge->dest);
	}
	while (!q.isEmpty())
	{
		LinkedNodeInt* ptr = q.dequeue();
		distance = ptr->status;
		if (ptr->node == node->node)
			return distance;
		for(LinkedEdgeInt* pEdge=ptr->adj;pEdge!=NULL;pEdge=pEdge->link)
			if (pEdge->dest->status == -1)
			{
				q.enqueue(pEdge->dest);
				pEdge->dest->status = distance + 1;
			}
	}
	return -1;
}

int GraphAsListsInt::numberOfCloseNodes(LinkedNodeInt* node, int maxDistance)
{
	int retVal = 0;
	int distance = 0;
	if (node == NULL)
		return -1;
	setStatusForAllNodes(-1);
	node->status = 0;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(node);
	cout << "Iz cvora " << node->node << "se moze doci do cvorova: ";
	while (!q.isEmpty())
	{
		node = q.dequeue();
		distance = node->status;
		if (distance > maxDistance)
			return retVal;
		retVal++;
		cout << node->node << " ";
		for(LinkedEdgeInt* pEdge=node->adj;pEdge!=NULL;pEdge=pEdge->link)
			if (pEdge->dest->status == -1)
			{
				q.enqueue(pEdge->dest);
				pEdge->dest->status = distance + 1;
			}
	}
	//cout << endl;
	return retVal;
}

int GraphAsListsInt::numberOfCloseNodes2(LinkedNodeInt* node, int maxDistance)
{
	int num = 0;
	cout << "Iz cvora " << node->node << " se moze doci do cvorova: ";
	setStatusForAllNodes(0);
	findCloseNodes(node, maxDistance, 0, &num);
	return num;
}

void GraphAsListsInt:: findCloseNodes(LinkedNodeInt* node, int maxDistance, int distance, int* num)
{
	if (node == NULL || distance > maxDistance)
		return;
	if (node->status == 0)
	{
		(*num)++;
		cout << node->node << ' ';
	}
	node->status = 1;
	if (distance == maxDistance)
		return;
	for (LinkedEdgeInt* pEdge = node->adj;pEdge!=NULL; pEdge = pEdge->link)
		//if (pEdge->dest->status == 0) //proveri
			findCloseNodes(pEdge->dest, maxDistance, distance + 1, num);
}

int GraphAsListsInt::nadjiPutBezPotega(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[])
{
	bool pronadjen = false;
	int n = -1;
	setStatusForAllNodes(0);
	traziPutBezPotega2(a, b, e, put, 0, &n);
	return n;
}

void GraphAsListsInt::traziPutBezPotega(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[], int rastojanje, bool* pronadjen, int* n)
{
	if (a == NULL || b == NULL || e == NULL || a->status != -1 || *pronadjen)
		return;
	if (a == b)
	{
		cout << "pronasao put!\n";
		*pronadjen = true;
		put[rastojanje] = a->node;
		*n = rastojanje + 1;
		return;
	}
	a->status = 1;
	for (LinkedEdgeInt* pEdge = a->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->dest->status == -1 && pEdge != e)
			traziPutBezPotega(pEdge->dest, b, e, put, rastojanje + 1, pronadjen, n);
	if (*pronadjen)
	{
		put[rastojanje] = a->node;
		cout << "dodajem " << a->node << endl;
		return;
	}
}

void GraphAsListsInt::traziPutBezPotega2(LinkedNodeInt* a, LinkedNodeInt* b, LinkedEdgeInt* e, int put[], int distance, int* n)
{
	if (a == NULL || b == NULL || e == NULL || *n != -1)
		return;
	if (a == b)
	{
		(*n) = distance + 1;
		cout << "put pronadjen, upisujem u niz\n";
		LinkedNodeInt * ptr = a;
		for (int i = distance; i >= 0; i--, ptr = ptr->prev)
			put[i] = ptr->node;
		return;
	}
	a->status = 1;
	cout << "trenutno sam u cvoru " << a->node << endl;
	for (LinkedEdgeInt* pEdge = a->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge != e && pEdge->dest->status==0 && *n==-1)
		{
			cout << "idem u poteg od " << a->node << " do " << pEdge->dest->node << endl;
			pEdge->dest->prev = a;
			traziPutBezPotega2(pEdge->dest, b, e, put, distance + 1, n);
		}
}

int GraphAsListsInt::putAgenta(int a, int b, int maxDuzina)
{
	LinkedNodeInt* ptr = start;
	while (ptr != NULL && ptr->node != a)
		ptr = ptr->next;
	if (ptr == NULL)
		return 0;
	setStatusForAllNodes(-1);
	int distance = 0;
	ptr->status = 0;
	ptr->prev = NULL;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(ptr);
	while (!q.isEmpty())
	{
		ptr = q.dequeue();
		distance = ptr->status;
		//cout << "cvor " << ptr->node << " udaljenost " << distance << endl;
		if (ptr->node == b)
			break;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			if (pEdge->dest->status == -1 && pEdge->weight < maxDuzina && pEdge->dest->stanica)
			{
				pEdge->dest->status = distance + 1;
				pEdge->dest->prev = ptr;
				q.enqueue(pEdge->dest);
			}
			pEdge = pEdge->link;
		}
	}
	if (ptr->node == b)
	{
		while (ptr != NULL)
		{
			cout << ptr->node << ' ';
			ptr = ptr->prev;
		}
		return distance;
	}
	return 0;
}

int GraphAsListsInt::nadjiPutOdADoB(int a, int b, int put[])
{
	int n = -1;
	LinkedNodeInt* pa = NULL, * pb = NULL, * ptr = start;
	while (ptr != NULL && (pa == NULL || pb == NULL))
	{
		if (ptr->node == a)pa = ptr;
		if (ptr->node == b)pb = ptr;
		ptr = ptr->next;
	}
	if (pa == NULL || pb == NULL)return -1;
	setStatusForAllNodes(0);
	traziPutOdADoB(pa, pb, 0, &n);
	ptr = pb;
	for (int i = n - 1; i >= 0; i--, ptr = ptr->prev)
		put[i] = ptr->node;
	return n;
}

void GraphAsListsInt::traziPutOdADoB(LinkedNodeInt* a, LinkedNodeInt* b, int distance, int* n)
{
	if (a == NULL || b == NULL || *n != -1 || a->status == 1)
		return;
	a->status = 1;
	if (a == b)
	{
		*n = distance + 1;
		return;
	}
	for(LinkedEdgeInt*pEdge=a->adj;pEdge!=NULL;pEdge=pEdge->link)
		if (pEdge->dest->status == 0)
		{
			pEdge->dest->prev = a;
			traziPutOdADoB(pEdge->dest, b, distance + 1, n);
			if (*n != -1)
				return;
		}
}

int GraphAsListsInt::FindMax(int airport)
{
	LinkedNodeInt* ptr = start, *a = NULL;
	while (ptr != NULL && ptr->node != airport)
		ptr = ptr->next;
	if (ptr == NULL)return -1;
	a = ptr;
	setStatusForAllNodes(-1);
	int distance = 0, maxDistance = -1;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(ptr);
	ptr->status = 0;
	while (!q.isEmpty())
	{
		ptr = q.dequeue();
		distance = ptr->status;
		if (distance > maxDistance)
			maxDistance = distance;
		for(LinkedEdgeInt*pEdge=ptr->adj;pEdge!=NULL;pEdge=pEdge->link)
			if (pEdge->dest->status == -1)
			{
				q.enqueue(pEdge->dest);
				pEdge->dest->status = distance + 1;
			}
	}
	return maxDistance;
}

bool GraphAsListsInt::postojiPut(int a, int b, int n)
{
	int hops = -1;
	trazenjePuta(findNode(a), findNode(b), 0, n, &hops);
	if (hops == -1)
		cout << "izmedju " << a << " i " << b << " ne postoji put kraci od ovog\n";
	else
		cout << "izmedju " << a << " i " << b << " postoji put duzine " << hops << endl;
	return hops != -1;
}

void GraphAsListsInt::trazenjePuta(LinkedNodeInt* a, LinkedNodeInt* b, int distance, int max, int* hops)
{
	if (a == NULL || b == NULL || distance > max || *hops != -1)
		return;
	if (a == b)
	{
		*hops = distance;
		return;
	}
	for (LinkedEdgeInt* pEdge = a->adj; pEdge != NULL; pEdge = pEdge->link)
	{
		trazenjePuta(pEdge->dest, b, distance + 1, max, hops);
		if (*hops != -1)
			return;
	}
}

void GraphAsListsInt::spoji(int A, int B)
{
	LinkedNodeInt* a = findNode(A), * b = findNode(B);
	//spajanje svih ulaznih potega
	LinkedNodeInt* ptr = start, *prevB=NULL;
	while (ptr != NULL)
	{
		if (ptr->next == b)prevB = ptr;
		if (ptr == a || ptr == b)
		{
			ptr = ptr->next;
			continue;
		}
		LinkedEdgeInt* pe = ptr->adj, * prev = NULL, * ea = NULL, * eb = NULL, * aprev = NULL, * bprev = NULL;
		while (pe != NULL)
		{
			if (pe->dest == a)
			{
				ea = pe;
				aprev = prev;
			}
			if (pe->dest == b)
			{
				eb = pe;
				bprev = prev;
			}
			prev = pe;
			pe = pe->link;
		}
		if (eb != NULL) //ako postoji poteg ka b
		{
			eb->dest = a;//prebacio ga na a
			if (ea != NULL)//ako jos postoji isti poteg ka a
			{//saberemo ih i obrisemo ovaj koji je bio ka b
				ea->weight += eb->weight;
				if (bprev == NULL)ptr->adj = eb->link;
				else bprev->link = eb->link;
				delete eb;
			}
		}
		ptr = ptr->next;
	}
	//sve potege iz b prebacujemo na a
	LinkedEdgeInt* bedge = b->adj;
	while (bedge != NULL)
	{
		if (bedge->dest == a)
		{
			b->adj = bedge->link;
			delete bedge;
			bedge = b->adj;
			continue;
		}
		LinkedEdgeInt* aedge = a->adj;
		while (aedge != NULL && aedge->dest != bedge->dest)
			aedge = aedge->link;
		if (aedge == NULL)
		{
			b->adj = bedge->link;
			bedge->link = a->adj;
			a->adj = bedge;
			bedge = b->adj;
		}
		else
		{
			aedge->weight += bedge->weight;
			b->adj = bedge->link;
			delete bedge;
			bedge = b->adj;
		}
	}
	//brisemo potege iz a do b
	LinkedEdgeInt* ae = a->adj, * aeprev = NULL;
	while (ae != NULL)
	{
		if (ae->dest == b)
		{
			if (aeprev == NULL)
				a->adj = ae->link;
			else
				aeprev->link = ae->link;
			delete ae;
			if (aeprev != NULL)
				ae = aeprev->link;
			else
				ae = a->adj;
		}
		else
		{
			aeprev = ae;
			ae = ae->link;
		}
	}
	if (prevB == NULL)
		start = b->next;
	else
		prevB->next = b->next;
	delete b;
}

void GraphAsListsInt::MakeUndirected2()
{
	LinkedNodeInt* ptr = start;
	while (ptr != NULL)
	{
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != NULL)
		{
			LinkedEdgeInt* peDest = pEdge->dest->adj;
			while (peDest != NULL && peDest->dest != ptr)
				peDest = peDest->link;
			if (peDest == NULL)
				pEdge->dest->adj = new LinkedEdgeInt(ptr, pEdge->weight, pEdge->dest->adj);
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}
}

void GraphAsListsInt::obilazakDFS(LinkedNodeInt* node, int* n)
{
	if (node == NULL || node->status == 1)
		return;
	node->status = 1;
	(*n)++;
	for (LinkedEdgeInt* pEdge = node->adj; pEdge != NULL; pEdge = pEdge->link)
		if (pEdge->dest->status == 0)
			obilazakDFS(pEdge->dest, n);
}

int GraphAsListsInt::utvrdiPovezanost()
{
	bool dosoDoSvih1 = true;
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		int num = 0;
		setStatusForAllNodes(0);
		obilazakDFS(ptr, &num);
		//cout << "Prvi obilazak: " << num << endl;
		if (num < nodeNum)
		{
			dosoDoSvih1 = false;
			break;
		}
	}
	if (dosoDoSvih1)
	{
		cout << "Jako povezan\n";
		return 1;
	}
	MakeUndirected2();
	bool dosoDoSvih2 = true;
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		int num = 0;
		setStatusForAllNodes(0);
		obilazakDFS(ptr, &num);
		//cout << "Drugi obilazak: " << num << endl;
		if (num < nodeNum)
		{
			dosoDoSvih2 = false;
			break;
		}
	}
	if (dosoDoSvih2)
	{
		cout << "Slabo povezan\n";
		return 2;
	}
	cout << "Nepovezan\n";
	return 3;
}

int GraphAsListsInt::DisPaths(LinkedNodeInt* s, LinkedNodeInt* e)
{
	LinkedNodeInt* ptr = s;
	int disPaths = 0;
	setStatusForAllNodes(0);
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(ptr);
	while (!q.isEmpty())
	{
		ptr = q.dequeue();
		cout << "na redu je " << ptr->node << endl;
		if (ptr == e)
		{
			disPaths++;
			cout << "Pronadjen jedan disjunktan put: ";
			for (LinkedNodeInt* pom = ptr; pom != NULL; pom = pom->prev)
				cout << pom->node << ", ";
			cout << endl << endl;
			ptr->status = 0;
		}
		for (LinkedEdgeInt* pEdge = ptr->adj; pEdge != NULL; pEdge = pEdge->link)
		{
			if (pEdge->dest->status == 0)
			{
				cout << "sledeci je " << pEdge->dest->node << endl;
				pEdge->dest->prev = ptr;
				if (pEdge->dest != e)
					pEdge->dest->status = 1;
				q.enqueue(pEdge->dest);
			}
			else
				cout << "trebao bi da je " << pEdge->dest->node << " sledeci, ali on je vec posecen\n";
		}
	}
	return disPaths;
}

void GraphAsListsInt::daLiJeDosaoDoGola(LinkedNodeInt* n, int oznakaGola, bool* dosaoDoGola, int igraci)
{
	if (n == NULL || *dosaoDoGola)
		return;
	if (n->node == oznakaGola)
	{
		*dosaoDoGola = true;
		return;
	}
	n->status = 1;
	for (LinkedEdgeInt* pEdge = n->adj; pEdge != NULL; pEdge = pEdge->link)
	{
		daLiJeDosaoDoGola(pEdge->dest, oznakaGola, dosaoDoGola, igraci + 1);
		if (*dosaoDoGola)
		{
			pEdge->dest->status = 2;
			return;
		}
	}

}

int GraphAsListsInt::ucestvovaliUAkciji(int go)
{
	setStatusForAllNodes(0);
	//0-nije obidjen, 1-obidjen, 2-obidjen i ucestvovao u akciji
	int ret = 0;
	for (LinkedNodeInt* ptr = start; ptr != NULL; ptr = ptr->next)
	{
		cout << "na redu je " << ptr->node;
		if (ptr->status == 0 && ptr->node != go)
		{
			bool uspeli = false;
			daLiJeDosaoDoGola(ptr, go, &uspeli, 0);
			cout << " i lopta " << (uspeli ? "jeste" : "nije") << " stigla do gola ";
			if (uspeli)
				ret++;
		}
		else
		{
			if (ptr->status == 2)
				ret++;
			cout << " i njega smo vec obisli";
		}
		cout << endl;
	}
	return ret;
}

int GraphAsListsInt::traverse(LinkedNodeInt* n)
{
	if (n == NULL)
		return 0;
	int retVal = 1;
	cout << n->node << endl;
	for(LinkedEdgeInt* pEdge=n->adj;pEdge!=NULL;pEdge=pEdge->link)
		if (pEdge->dest->status == 0)
		{
			pEdge->dest->status = 1;
			retVal += traverse(pEdge->dest);
		}
	return retVal;
}

int GraphAsListsInt::CalcPrevious2(int subjects[], int n)
{
	int retVal = 0;
	for (int i = 0; i < n; i++)
	{
		LinkedNodeInt* ptr = start;
		while (ptr != NULL && ptr->node != subjects[i])
			ptr = ptr->next;
		if (ptr != NULL && ptr->status == 0)
		{
			ptr->status = 1;
			retVal += traverse(ptr);
		}
	}
	return retVal;
}
