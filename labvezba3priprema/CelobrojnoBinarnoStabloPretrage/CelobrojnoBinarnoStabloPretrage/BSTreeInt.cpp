#include "BSTreeInt.h"

#include <exception>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

void BSTreeInt::deleteTree(BSTNodeInt* ptr)
{
	if (ptr != nullptr) {
		deleteTree(ptr->left);
		deleteTree(ptr->right);
		delete ptr;
	}
}

BSTNodeInt* BSTreeInt::search(int el) const
{
	BSTNodeInt* ptr = root;
	while (ptr != nullptr)
		if (ptr->isEQ(el))
			return ptr;
		else if (ptr->isGT(el))
			ptr = ptr->left;
		else
			ptr = ptr->right;
	return nullptr;
}

void BSTreeInt::insert(int el)
{
	BSTNodeInt* ptr = root, * par = nullptr;
	while (ptr != nullptr) {  // trazenje mesta za umetanje novog cvora
		par = ptr;
		if (ptr->isLT(el))
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	if (root == nullptr)    // stablo je prazno
		root = new BSTNodeInt(el);
	else if (par->isLT(el))
		par->right = new BSTNodeInt(el);
	else
		par->left = new BSTNodeInt(el);
	numOfElements++;
}

void BSTreeInt::deleteByCopying(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) { 	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)             // cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)         // cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			BSTNodeInt* parent = node;
			while (tmp->right != nullptr) {		// nalazenje krajnjeg desnog cvora
				parent = tmp;             		// u levom podstablu
				tmp = tmp->right;
			}
			node->setKey(tmp->getKey());		// prepisivanje reference na kljuc 
			if (parent == node)           		// tmp je direktni levi potomak node-a
				parent->left = tmp->left;		// ostaje isti raspored u levom podstablu
			else
				parent->right = tmp->left; 		// levi potomak tmp-a 
			delete tmp;							// se pomera na mesto tmp-a
			numOfElements--;
			return;
		}
		if (ptr == root)						// u slucaju (1) i (2) samo je pomerena
			root = node;						// referenca node pa je potrebno
		else if (par->left == ptr)				// izmeniti i link prethodnog cvora
			par->left = node;					// u slucaju (3) ovo nema dejstva
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::deleteByMerging(int el)
{
	BSTNodeInt* node, * ptr = root, * par = nullptr;
	while (ptr != nullptr && !ptr->isEQ(el)) {	// nalazenje cvora sa zeljenim el.
		par = ptr;
		if (ptr->isLT(el)) ptr = ptr->right;
		else ptr = ptr->left;
	}
	node = ptr;
	if (ptr != nullptr && ptr->isEQ(el)) {
		if (node->right == nullptr)				// cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == nullptr)			// cvor nema levog potomka (2)
			node = node->right;
		else {									// cvor ima oba potomka (3)
			BSTNodeInt* tmp = node->left;
			while (tmp->right != nullptr)		// nalazenje krajnjeg desnog cvora
				tmp = tmp->right;				// u levom podstablu
			tmp->right = node->right;			// prebacivanje desnog linka node-a u tmp
			node = node->left;					// na tekucem mestu bice prvi levi potomak
		}
		if (ptr == root)
			root = node;
		else if (par->left == ptr)
			par->left = node;
		else
			par->right = node;
		delete ptr;
		numOfElements--;
	}
	else if (root != nullptr)
		throw new exception("Element is not in the tree!");
	else
		throw new exception("The tree is empty!");
}

void BSTreeInt::preorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		ptr->visit();
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void BSTreeInt::inorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		inorder(ptr->left);
		ptr->visit();
		inorder(ptr->right);
	}
}

void BSTreeInt::postorder(const BSTNodeInt* ptr) const
{
	if (ptr != nullptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		ptr->visit();
	}
}

void BSTreeInt::iterativePreorder() const
{
	BSTNodeInt* ptr = root;
	StackAsArrayBSTNodeInt stack(numOfElements);
	if (ptr != nullptr) {
		stack.push(ptr);
		while (!stack.isEmpty()) {
			ptr = stack.pop();
			ptr->visit();
			if (ptr->right != nullptr)	// levi potomak se stavlja u magacin
				stack.push(ptr->right); // posle desnog, da bi se prvi obradio
			if (ptr->left != nullptr)
				stack.push(ptr->left);
		}
	}
}

void BSTreeInt::breadthFirstSearch() const
{
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt queue(numOfElements);
	if (ptr != nullptr) {
		queue.enqueue(ptr);
		while (!queue.isEmpty()) {
			ptr = queue.dequeue();
			ptr->visit();
			if (ptr->left != nullptr)
				queue.enqueue(ptr->left);
			if (ptr->right != nullptr)
				queue.enqueue(ptr->right);
		}
	}
}

int BSTreeInt::countSL()
{
	int cnt = 0;
	zbirPodstablaIBrojSL(root, &cnt);
	return cnt;
}

int BSTreeInt::zbirPodstablaIBrojSL(BSTNodeInt* node, int* brojSL)
{
	if (node == NULL)
		return 0;
	int zbirL = zbirPodstablaIBrojSL(node->left, brojSL),
		zbirR = zbirPodstablaIBrojSL(node->right, brojSL);
	if (zbirL > zbirR)
	{
		(*brojSL)++;
		cout << node->key << ' ' << zbirL << ' ' << zbirR << endl;
	}
	return zbirL + zbirR + node->key;
}

int BSTreeInt::countSLHelper(BSTNodeInt* node, int* br)
{
	if(node == NULL)
		return 0;
	int leftSum = countSLHelper(node->left, br);
	int rightSum = countSLHelper(node->right, br);
	if (leftSum > rightSum)
		(*br)++;
	return leftSum + rightSum + node->key;
}

BSTNodeInt* BSTreeInt::maxZbirPotomaka()
{
	if (root == NULL)
		return NULL;
	int maxZbir = 0;
	BSTNodeInt* maxCvor = root;
	traziMaxZbir(&maxZbir, &maxCvor, root);
	return maxCvor;
}

void BSTreeInt::traziMaxZbir(int* maxSum, BSTNodeInt** maxNode, BSTNodeInt* node)
{
	if (node == NULL)
		return;
	int thisSum = 0;
	if (node->left != NULL)
		thisSum += node->left->key;
	if (node->right != NULL)
		thisSum += node->right->key;
	//cout << node->key << ' ' << thisSum << endl;
	if (thisSum > *maxSum)
	{
		*maxSum = thisSum;
		*maxNode = node;
	}
	traziMaxZbir(maxSum, maxNode, node->left);
	traziMaxZbir(maxSum, maxNode, node->right);
}

int BSTreeInt::brojRazlika(BSTreeInt* t1, BSTreeInt* t2)
{
	int razlike = 0;
	traziRazlike(&razlike, t1->root, t2->root);
	return razlike;
}

void BSTreeInt::traziRazlike(int* brojRazlika, BSTNodeInt* n1, BSTNodeInt* n2)
{
	if (n1 == NULL && n2 == NULL)
		return;
	if (n1 == NULL && n2 != NULL)
	{
		(*brojRazlika)++;
		cout << "u t1 nema, u t2 je " << n2->key << endl;
		traziRazlike(brojRazlika, NULL, n2->left);
		traziRazlike(brojRazlika, NULL, n2->right);
	}
	else if (n1 != NULL && n2 == NULL)
	{
		(*brojRazlika)++;
		cout << "u t2 nema, u t1 je " << n1->key << endl;
		traziRazlike(brojRazlika, n1->left, NULL);
		traziRazlike(brojRazlika, n1->right, NULL);
	}
	else
	{
		if (n1->key != n2->key)
			(*brojRazlika)++;
		cout << n1->key << ' ' << n2->key<<endl;
		traziRazlike(brojRazlika, n1->left, n2->left);
		traziRazlike(brojRazlika, n1->right, n2->right);
	}
}

BSTNodeInt* BSTreeInt::findClosestValueLeaf(BSTNodeInt* root, int value)
{
	if (root == NULL)
		return NULL;
	BSTNodeInt* closestNode = root;
	int closest = root->key;
	traziNajbliziList(root, value, &closest, &closestNode);
	return closestNode;
}

void BSTreeInt::traziNajbliziList(BSTNodeInt* node, int value, int* closest, BSTNodeInt** closestNode)
{
	if (node == NULL)
		return;
	//cout << node->key << ' ' << value << ' ' << *closest << ' ' << (*closestNode)->key << endl;
	if (node->left == NULL && node->right == NULL)
	{
		if (abs(node->key - value) < abs(*closest - value))
		{
			*closest = node->key;
			*closestNode = node;
		}
		return;
	}
	traziNajbliziList(node->left, value, closest, closestNode);
	traziNajbliziList(node->right, value, closest, closestNode);
}

int BSTreeInt::findMaxPathLeaf(BSTNodeInt* root, BSTNodeInt** leaf)
{
	int maxPath = 0;
	BSTNodeInt* maxLeaf = root;
	traziMaxPut(root, 0, &maxPath, &maxLeaf);
	*leaf = maxLeaf;
	return maxPath;
}

void BSTreeInt::traziMaxPut(BSTNodeInt* node, int currentPath, int* maxPath, BSTNodeInt** maxLeaf)
{
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
	{
		if (currentPath + node->key > *maxPath)
		{
			*maxPath = currentPath + node->key;
			*maxLeaf = node;
		}
		return;
	}
	traziMaxPut(node->left, currentPath + node->key, maxPath, maxLeaf);
	traziMaxPut(node->right, currentPath + node->key, maxPath, maxLeaf);
}

void BSTreeInt::formirajNizOdBST(int niz[], BSTNodeInt* node, int* index)
{
	if (node == NULL)
		return;
	if (node->left != NULL)
		formirajNizOdBST(niz, node->left, index);
	niz[(*index)] = node->key;
	(*index)++;
	if (node->right != NULL)
		formirajNizOdBST(niz, node->right, index);
	return;
}

BSTNodeInt* BSTreeInt::deepestLeaf(BSTNodeInt* root)
{
	BSTNodeInt* deepLeaf = root;
	int maxDepth = 0;
	traziNajdubljiList(root, 0, &deepLeaf, &maxDepth);
	return deepLeaf;
}

void BSTreeInt::traziNajdubljiList(BSTNodeInt* node, int depth, BSTNodeInt** deepestLeaf, int* maxDepth)
{
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
	{
		if (depth + 1 > *maxDepth)
		{
			*maxDepth = depth + 1;
			*deepestLeaf = node;
		}
		return;
	}
	traziNajdubljiList(node->left, depth + 1, deepestLeaf, maxDepth);
	traziNajdubljiList(node->right, depth + 1, deepestLeaf, maxDepth);
}

BSTNodeInt* BSTreeInt::maxDifferenceSubtree()
{
	int maxDiff = 0;
	BSTNodeInt* maxDiffNode = root;
	traziNajvecuRazliku(root, &maxDiff, &maxDiffNode);
	return maxDiffNode;
}

int BSTreeInt::traziNajvecuRazliku(BSTNodeInt* node, int* maxDiff, BSTNodeInt** maxDiffNode)
{
	if (node == NULL)
		return 0;
	int leftSubtree = traziNajvecuRazliku(node->left, maxDiff, maxDiffNode),
		rightSubtree = traziNajvecuRazliku(node->right, maxDiff, maxDiffNode);
	if (abs(leftSubtree - rightSubtree) > *maxDiff)
	{
		*maxDiff = abs(leftSubtree - rightSubtree);
		*maxDiffNode = node;
	}
	cout << "cvor: " << node->key << ", leva suma: " << leftSubtree << ", desna suma: " << rightSubtree << endl;
	return leftSubtree + rightSubtree + node->key;
}

BSTreeInt* BSTreeInt::createTreeFromArray(int arr[], int n)
{
	if (n == 0)
		return NULL;
	BSTreeInt* tree = new BSTreeInt();
	tree->root = new BSTNodeInt(arr[0]);
	for (int i = 1; i < n; i++)
	{
		BSTNodeInt* ptr = tree->root, * prev = NULL;
		while (ptr != NULL)
		{
			prev = ptr;
			if (arr[i] < ptr->key)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if (arr[i] < prev->key)
			prev->left = new BSTNodeInt(arr[i]);
		else
			prev->right = new BSTNodeInt(arr[i]);
	}
	tree->numOfElements = n;
	return tree;
}

void BSTreeInt::topmostNoChildren(BSTNodeInt* node, int level, BSTNodeInt** result, int* resultLevel)
{
	if (node == NULL)
		return;
	if (node->left == NULL && node->right == NULL)
	{
		if (level < *resultLevel)
		{
			*resultLevel = level;
			*result = node;
		}
		return;
	}
	topmostNoChildren(node->left, level + 1, result, resultLevel);
	topmostNoChildren(node->right, level + 1, result, resultLevel);
}

void BSTreeInt::topmostNoChildren2(BSTNodeInt* root, int level, BSTNodeInt** result, int* resultLevel)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		if (level < *resultLevel)
		{
			*resultLevel = level;
			*result = root;
		}
		//return;
	}
	topmostNoChildren2(root->left, level + 1, result, resultLevel);
	topmostNoChildren2(root->right, level + 1, result, resultLevel);
}


int BSTreeInt::GetMaxLevel()
{
	if (root == NULL)
		return 0;
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt que(numOfElements); 
	int level = 0, maxDiffLevel = 0, maxDiff = 0;
	que.enqueue(ptr);
	while (!que.isEmpty())
	{
		//br el u queue je br cvorova u nivou
		int nodesInThisLevel = que.numberOfElements();
		int min = 0, max = 0;
		for (int i = 0; i < nodesInThisLevel; i++)
		{//prolazimo kroz isti nivo
			ptr = que.dequeue();
			if (i == 0)//krajnje levi
				min = ptr->key;
			if (i == nodesInThisLevel - 1)//krajnje desni
				max = ptr->key;
			if (ptr->left != NULL)
				que.enqueue(ptr->left);
			if (ptr->right != NULL)
				que.enqueue(ptr->right);
		}
		if (max - min > maxDiff)
		{
			maxDiff = max - min;
			maxDiffLevel = level;
		}
		cout << "Nivo je " << level << ", razlika je " << max - min << endl;
		level++;
	}
	return maxDiffLevel;
}

int BSTreeInt::maxLevelNodes(BSTNodeInt* node, int* count)
{
	if (node == NULL)
		return 0;
	QueueAsArrayBSTNodeInt que(numOfElements);
	que.enqueue(node);
	int level = 0, maxLevel = 0, maxNodes = 0;
	while (!que.isEmpty())
	{
		int nodesInThisLevel = que.numberOfElements();
		if (nodesInThisLevel > maxNodes)
		{
			maxNodes = nodesInThisLevel;
			maxLevel = level;
		}
		for (int i = 0; i < nodesInThisLevel; i++)
		{
			BSTNodeInt* ptr = que.dequeue();
			if (ptr->left != NULL)
				que.enqueue(ptr->left);
			if (ptr->right != NULL)
				que.enqueue(ptr->right);
		}
		level++;
	}
	*count = maxNodes;
	return maxLevel;
}

int BSTreeInt::maxLevelNodes2(BSTNodeInt* node, int* count)
{
	int maxLevel = -1, maxLevelCount = -1, level = 0;
	QueueAsArrayBSTNodeInt q(numOfElements);
	q.enqueue(node);
	while (!q.isEmpty())
	{
		int nodesInThisLevel = q.numberOfElements();
		if (nodesInThisLevel > maxLevelCount)
		{
			maxLevelCount = nodesInThisLevel;
			maxLevel = level;
		}
		for (int i = 0; i < nodesInThisLevel; i++)
		{
			node = q.dequeue();
			if (node->left != NULL)q.enqueue(node->left);
			if (node->right != NULL)q.enqueue(node->right);
		}
		level++;
	}
	*count = maxLevelCount;
	return maxLevel;
}

int BSTreeInt::levelDiff(int v1, int v2)
{
	int l1 = 0, l2 = 0;
	findLevelDiff(v1, v2, root, 0, &l1, &l2);
	cout << l1 << ' ' << l2 << endl;
	return abs(l1 - l2);
}

void BSTreeInt::findLevelDiff(int v1, int v2, BSTNodeInt* node, int level, int* level1, int* level2)
{
	if (node == NULL)
		return;
	if (node->key == v1)
		*level1 = level;
	if (node->key == v2)
		*level2 = level;
	findLevelDiff(v1, v2, node->left, level + 1, level1, level2);
	findLevelDiff(v1, v2, node->right, level + 1, level1, level2);
}

BSTNodeInt* BSTreeInt::findMaxTested(BSTNodeInt* node, int day)
{
	int brojTestiranih = -1;
	BSTNodeInt* n = NULL;
	findMaxSubtree(node, day, &n, &brojTestiranih);
	cout << "najvise testiranih za " << day << " je bilo u cvoru " 
		<< n->key << " i to " << brojTestiranih << endl;
	return n;
}

int BSTreeInt::findMaxSubtree(BSTNodeInt* node, int day, BSTNodeInt** currentMax, int* maxSum)
{
	if (node == NULL)
		return 0;
	int leftSum = findMaxSubtree(node->left, day, currentMax, maxSum);
	int rightSum = findMaxSubtree(node->right, day, currentMax, maxSum);
	cout << "cvor " << node->key << " levo podstablo suma je " << leftSum 
		<< " desno podstablo suma je " << rightSum;
	if (leftSum + rightSum + node->key > *maxSum && node->key > day)
	{
		*maxSum = leftSum + rightSum + node->key;
		*currentMax = node;
		cout << " jeste novi max";
	}
	cout << endl;
	return leftSum + rightSum + node->key;
}

int BSTreeInt::maxDif()
{
	int maxDiff = -1, maxNode = -1;
	findMaxHeightDiff(root, &maxDiff, &maxNode);
	return maxNode;
}

int BSTreeInt::findMaxHeightDiff(BSTNodeInt* n, int* maxHeightDiff, int* maxNode)
{
	if (n == NULL)
		return 0;
	int leftH = findMaxHeightDiff(n->left, maxHeightDiff, maxNode);
	int rightH = findMaxHeightDiff(n->right, maxHeightDiff, maxNode);
	cout << "cvor " << n->key << " leva visina " << leftH << " desna visina " << rightH;
	if (abs(leftH - rightH) > *maxHeightDiff)
	{
		*maxHeightDiff = abs(leftH - rightH);
		*maxNode = n->key;
		cout << " jeste novi max" << endl;
	}
	else
		cout << " nije novi max" << endl;
	return max(leftH, rightH) + 1;
}

int BSTreeInt::findMaxHeightDiff2(BSTNodeInt* n, int* maxHeightDiff, int* maxNode)
{
	if (n == NULL)
		return 0;
	int visLev = findMaxHeightDiff2(n->left, maxHeightDiff, maxNode);
	int visDes = findMaxHeightDiff2(n->right, maxHeightDiff, maxNode);
	if (abs(visLev - visDes) > *maxHeightDiff)
	{
		*maxNode = n->key;
		*maxHeightDiff = abs(visLev - visDes);
	}
	return max(visLev, visDes) + 1;
}

bool BSTreeInt::isBalanced()
{
	bool balanced = true;
	checkIfBalanced(root, &balanced);
	return balanced;
}

int BSTreeInt::checkIfBalanced(BSTNodeInt* n, bool* balanced)
{
	if (!(*balanced) || n == NULL)
		return 0;
	int leftH = checkIfBalanced(n->left, balanced);
	int rightH = checkIfBalanced(n->right, balanced);
	cout << "cvor " << n->key << " leva visina " << leftH << " desna visina " << rightH << endl;
	if (abs(leftH - rightH) > 1)
	{
		*balanced = false;
		cout << "nije balansirano, kraj pretrage" << endl;
	}
	return max(leftH, rightH) + 1;
}

void BSTreeInt::longestLeftPath(BSTNodeInt* r, BSTNodeInt** start, int* maxLength)
{
	if (r == NULL)
		return;
	int pathLength = leftPath(r);
	longestLeftPath(r->right, start, maxLength);
	longestLeftPath(r->left, start, maxLength);
	if (pathLength > *maxLength)
	{
		*start = r;
		*maxLength = pathLength;
	}
	return;
}

int BSTreeInt::leftPath(BSTNodeInt* n)
{
	if (n == NULL)
		return 0;
	return 1 + leftPath(n->left);
}

int BSTreeInt::Sum(int min, int max)
{
	int sum = 0;
	getSum(root, min, max, 0, &sum);
	return sum;
}

void BSTreeInt::getSum(BSTNodeInt* n, int min, int max, int level, int* sum)
{
	if (n == NULL)
		return;
	if (level >= min && level <= max)
		(*sum) += n->key;
	getSum(n->left, min, max, level + 1, sum);
	getSum(n->right, min, max, level + 1, sum);
}

int BSTreeInt::getDepth(int n)
{
	int depth = -1;
	findDepth(root, n, 0, &depth);
	return depth;
}

void BSTreeInt::findDepth(BSTNodeInt* r, int n, int level, int* depth)
{
	if (r == NULL || *depth != -1)
		return;
	if (r->key == n)
	{
		*depth = level;
		return;
	}
	findDepth(r->left, n, level + 1, depth);
	findDepth(r->right, n, level + 1, depth);
}

void BSTreeInt::deleteAllLeftLeaves(BSTNodeInt* n)
{
	if (n == NULL)
		return;
	if (n->left != NULL && n->left->left == NULL && n->left->right == NULL)
	{
		cout << "brisem cvor " << n->left->key << endl;
		delete n->left;
		n->left = NULL;
	}
	else
		deleteAllLeftLeaves(n->left);
	deleteAllLeftLeaves(n->right);
}

void BSTreeInt::deleteAllLeftLeaves2(BSTNodeInt* n)
{
	if (n == NULL)
		return;
	if (n->left != NULL && n->left->left == NULL && n->left->right == NULL)
		delete n->left;
	deleteAllLeftLeaves2(n->left);
	deleteAllLeftLeaves2(n->right);
}

BSTreeInt* BSTreeInt::MirrorCopy()
{
	BSTreeInt* ret = new BSTreeInt();
	if (root == NULL)
		return ret;
	ret->root = new BSTNodeInt(root->key);
	mirrorCopyBST(ret->root, root);
	ret->numOfElements = numOfElements;
	return ret;
}

void BSTreeInt::mirrorCopyBST(BSTNodeInt* copy, const BSTNodeInt* orig)
{
	if (orig == NULL || copy == NULL)
		return;;
	if (orig->left != NULL)
		copy->right = new BSTNodeInt(orig->left->key);
	if (orig->right != NULL)
		copy->left = new BSTNodeInt(orig->right->key);
	mirrorCopyBST(copy->left, orig->right);
	mirrorCopyBST(copy->right, orig->left);
}

void BSTreeInt::Mirror(BSTNodeInt* root)
{
	if (root == NULL)
		return;
	BSTNodeInt* temp = root->left;
	root->left = root->right;
	root->right = temp;
	Mirror(root->left);
	Mirror(root->right);
}

int BSTreeInt::findPathWithMostOddNodes(BSTNodeInt* root, BSTNodeInt** leaf)
{
	int x = -1;
	BSTNodeInt* l = NULL;
	fintPathWithMostOddNodesHelper(root, &l, &x, 0);
	*leaf = l;
	return x;
}

void BSTreeInt::fintPathWithMostOddNodesHelper(BSTNodeInt* n, BSTNodeInt** leaf, int* maxOdd, int currOdds)
{
	if (n == NULL)
		return;
	if (n->key % 2 == 1)
		currOdds++;
	if (n->left == NULL && n->right == NULL && currOdds > *maxOdd)
	{
		*leaf = n;
		*maxOdd = currOdds;
	}
	else
	{
		fintPathWithMostOddNodesHelper(n->left, leaf, maxOdd, currOdds);
		fintPathWithMostOddNodesHelper(n->right, leaf, maxOdd, currOdds);
	}
}

int BSTreeInt::visina(BSTNodeInt* n, int* maxRazVis, BSTNodeInt** maxRazCvor)
{
	if (n == NULL)
		return 0;
	int leva = visina(n->left,maxRazVis,maxRazCvor);
	int desna = visina(n->right, maxRazVis, maxRazCvor);
	if (abs(leva - desna) > *maxRazVis)
	{
		*maxRazVis = abs(leva - desna);
		*maxRazCvor = n;
	}
	return max(leva,desna ) + 1;
}

int BSTreeInt::maxNode(int& maxDif)
{
	int maxDif1 = 0;
	BSTNodeInt* node = NULL;
	visina(root, &maxDif1, &node);
	maxDif = maxDif1;
	return node->key;
}

void BSTreeInt::maxPathHelper(BSTNodeInt* n, int* maxPath, BSTNodeInt** maxSumLeaf, int trenutnaSuma)
{
	if (n == NULL)
		return;
	if (n->left == NULL && n->right == NULL)
	{
		if (trenutnaSuma + n->key > *maxPath)
		{
			*maxPath = trenutnaSuma + n->key;
			*maxSumLeaf = n;
		}
		//return;
	}
	maxPathHelper(n->left, maxPath, maxSumLeaf, trenutnaSuma + n->key);
	maxPathHelper(n->right, maxPath, maxSumLeaf, trenutnaSuma + n->key);
}

int BSTreeInt::findMaxPathLeaf2(BSTNodeInt* root, BSTNodeInt** leaf)
{
	int maxPath = -1;
	BSTNodeInt* resultLeaf = NULL;
	maxPathHelper(root, &maxPath, &resultLeaf, 0);
	*leaf = resultLeaf;
	return maxPath;
}

int BSTreeInt::GetMaxLevel2()
{
	BSTNodeInt* ptr = root;
	QueueAsArrayBSTNodeInt q(numOfElements);
	int level = 0, maxLevDif = 0, maxLev = 0;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		int cvorovaUOvomNivou = q.numberOfElements(), minCvor = 0, maxCvor = 0;
		for (int i = 0; i < cvorovaUOvomNivou; i++)
		{
			ptr = q.dequeue();
			if (i == 0)
				minCvor = ptr->key;
			if (i == cvorovaUOvomNivou - 1)
				maxCvor = ptr->key;

			if (ptr->left != NULL)
				q.enqueue(ptr->left);
			if (ptr->right != NULL)
				q.enqueue(ptr->right);
		}
		if (maxCvor - minCvor > maxLevDif)
		{
			maxLevDif = maxCvor - minCvor;
			maxLev = level;
		}
		level++;
	}
	return maxLev;
}

