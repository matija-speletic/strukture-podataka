
int BSTreeInt::tezina(BSTNodeInt* ptr)
{
	if (ptr == nullptr)
		return 0;
	if (ptr->left == nullptr && ptr->right == nullptr)
		return 1;

	return tezina(ptr->left) + tezina(ptr->right);
}

void BSTreeInt::obrisiListove(BSTNodeInt* ptr)
{
	if (ptr == nullptr) //ako je prazno, vrati se
		return;
	if (ptr->left != nullptr && ptr->left->left == nullptr && ptr->left->right == nullptr)
	{//ako levi bivstvuje i ako je on list (ako nema potomke) - obrisi ga
		delete ptr->left;
		ptr->left = nullptr;
	}
	else//ako levi potomak nije list, pozovi ovu funkciju za njega
		obrisiListove(ptr->left);

		//sve to isto i za desni potomak
	if (ptr->right != nullptr && ptr->right->left == nullptr && ptr->right->right == nullptr)
	{
		delete ptr->right;
		ptr->right = nullptr;
	}
	else
		obrisiListove(ptr->right);
}

int BSTreeInt::brojCvorovaUNivou(BSTNodeInt* ptr, int trenutniNivo, int trazeniNivo)
{
	if (ptr == nullptr)
		return 0;

	if (trenutniNivo == trazeniNivo)
		return 1;

	return brojCvorovaUNivou(ptr->left, trenutniNivo + 1, trazeniNivo)
		+ brojCvorovaUNivou(ptr->right, trenutniNivo + 1, trazeniNivo);
}

void BSTreeInt::upisiBrojeveCvorovaUSvakomNivou(BSTNodeInt* ptr, int trenutniNivo, int* brojeviCvorovaUSvakomNivou)
{
	if (ptr == nullptr)
		return;
	brojeviCvorovaUSvakomNivou[trenutniNivo]++;
	upisiBrojeveCvorovaUSvakomNivou(ptr->left, trenutniNivo + 1, brojeviCvorovaUSvakomNivou);
	upisiBrojeveCvorovaUSvakomNivou(ptr->right, trenutniNivo + 1, brojeviCvorovaUSvakomNivou);

}

int BSTreeInt::maxBrojCvorovaPoNivou()
{
	int n = this->dubina();
	int* brojeviCvorovaUSvakomNivou = new int[n];
	for (int i = 0; i < n; i++)
		brojeviCvorovaUSvakomNivou[i] = 0;
	upisiBrojeveCvorovaUSvakomNivou(root, 0, brojeviCvorovaUSvakomNivou);

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (brojeviCvorovaUSvakomNivou[i] > max)
			max = brojeviCvorovaUSvakomNivou[i];
		cout << brojeviCvorovaUSvakomNivou[i] << " ";
	}
	return max;
}

BSTreeInt* BSTreeInt::mirrorCopy()
{
	void mirror(const BSTNodeInt * trenutniOriginal, BSTNodeInt * trenutniKopija);
	BSTreeInt* mirrorTree = new BSTreeInt();
	mirrorTree->root = new BSTNodeInt(root->key);
	mirror(root, mirrorTree->root);
	mirrorTree->numOfElements = this->numOfElements;
	return mirrorTree;
}

int BSTreeInt::istihIma(BSTNodeInt* ptr, int referentni)
{
	if (ptr == nullptr)
		return 0;
	if (ptr->key == referentni)
		return 1 + istihIma(ptr->left, referentni) + istihIma(ptr->right, referentni);
	return istihIma(ptr->left, referentni) + istihIma(ptr->right, referentni);
}

int BSTreeInt::brojRazlicitih(BSTNodeInt* ptr)
{
	if (ptr == nullptr)
		return 0;
	int brIstihZaOvajCvor = istihIma(root, ptr->key);
	return brojRazlicitih(ptr->left) + brojRazlicitih(ptr->right) + (brIstihZaOvajCvor == 1 ? 1 : 0);
}

int BSTreeInt::getMaxLevel()
{
	return 0;
}

BSTNodeInt* BSTreeInt::findClosestValue(BSTNodeInt* ptr, int value)
{
	if (ptr == nullptr)
		return nullptr;
	unsigned int smallestDiff = abs(value - ptr->key);
	BSTNodeInt* closest = ptr, *current=ptr;
	while (current != nullptr)
	{
		if (value == current->key)
			return current;
		unsigned int diff = abs(current->key - value);
		if (diff < smallestDiff)
		{
			smallestDiff = diff;
			closest = current;
		}
		if (value > current->key)
			current = current->right;
		else
			current = current->left;
	}
	return closest;
}

int BSTreeInt::brojRazlika(BSTNodeInt* t1, BSTNodeInt* t2)
{
	if (t1 == nullptr)
	{
		if (t2 != nullptr)
			return brojRazlika(t1, t2->left) + brojRazlika(t1, t2->right) + 1;
		else
			return 0;
	}
	else
	{
		if (t2 == nullptr)
			return brojRazlika(t1->left, t2) + brojRazlika(t1->right, t2) + 1;
		else if (t2->key != t1->key)
			return brojRazlika(t1->left, t2->left) + brojRazlika(t1->right, t2->right) + 1;
		else
			return brojRazlika(t1->left, t2->left) + brojRazlika(t1->right, t2->right);
	}
}

int BSTreeInt::getDepth(BSTNodeInt* ptr)
{
	int findDepthFrom(BSTNodeInt * root, BSTNodeInt * ptr);
	int findDepthFrom2(BSTNodeInt * refPtr, BSTNodeInt * ptr, int lvl);
	return findDepthFrom2(root, ptr,0);
}

int BSTreeInt::Sum(BSTNodeInt* p, int min, int max)
{
	int sumBetweenLevels(BSTNodeInt * p, int min, int max, int currentLevel);
	return sumBetweenLevels(p, min, max, 0);
}

BSTNodeInt* BSTreeInt::maxChildSum(BSTNodeInt* ptr, int& maxSum)
{
	if (ptr == nullptr)
	{
		return nullptr;
		maxSum = ~0;
	}
	maxSum = (ptr->left ? ptr->left->key : 0) + (ptr->right ? ptr->right->key : 0);
	int maxLeftSum = 0, maxRightSum = 0;
	BSTNodeInt* leftMax, * rightMax, *retMax=ptr;
	leftMax = maxChildSum(ptr->left, maxLeftSum);
	rightMax = maxChildSum(ptr->right, maxRightSum);
	if (maxLeftSum > maxSum)
	{
		maxSum = maxLeftSum;
		retMax = leftMax;
	}
	if (maxRightSum > maxSum)
	{
		maxSum = maxRightSum;
		retMax = rightMax;
	}
	return retMax;
}

BSTreeInt* BSTreeInt::mergeTrees(BSTreeInt* t1, BSTreeInt* t2)
{
	void merge(BSTNodeInt * dst, BSTNodeInt * src1, BSTNodeInt * src2);
	if (!t1 || !t2 || !t1->root || !t2->root)
		return nullptr;
	BSTreeInt* merged = new BSTreeInt();
	merged->root = new BSTNodeInt(t1->root->key + t2->root->key);
	merge(merged->root, t1->root, t2->root);
	return merged;
}

void BSTreeInt::topMostNoChildren(BSTNodeInt* root, int level, BSTNodeInt** result, int* resultLevel)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right && (*resultLevel < 0 || level < *resultLevel))
	{
		*result = root;
		*resultLevel = level;
		return;
	}
	else
	{
		if (root->left)
			topMostNoChildren(root->left, level + 1, result, resultLevel);
		if (root->right)
			topMostNoChildren(root->right, level + 1, result, resultLevel);
	}
}

void merge(BSTNodeInt* dst, BSTNodeInt* src1, BSTNodeInt* src2)
{
	if (src1 == nullptr && src2 == nullptr)
		return;
	if (dst == nullptr)
		return;

	if(src1==nullptr)
	{
		if (src2->left)
			dst->left = new BSTNodeInt(src2->left->key);
		else dst->left = nullptr;

		if (src2->right)
			dst->right = new BSTNodeInt(src2->right->key);
		else dst->right = nullptr;
	}
	else if (src2 == nullptr)
	{
		
		if (src1->left)
			dst->left = new BSTNodeInt(src1->left->key);
		else dst->left = nullptr;

		if (src1->right)
			dst->right = new BSTNodeInt(src1->right->key);
		else dst->right = nullptr;
	}
	else
	{
		if (src2->left || src1->left)
			dst->left = new BSTNodeInt((src2->left ? src2->left->key : 0) + (src1->left ? src1->left->key : 0));
		else dst->left = nullptr;

		if (src2->right || src1->right)
			dst->right = new BSTNodeInt((src2->right ? src2->right->key : 0) + (src1->right ? src1->right->key : 0));
		else dst->right = nullptr;
	}
	merge(dst->left, src1 ? src1->left : nullptr, src2 ? src2->left : nullptr);
	merge(dst->right, src1 ? src1->right : nullptr, src2 ? src2->right : nullptr);
}

int sumBetweenLevels(BSTNodeInt* p, int min, int max, int currentLevel)
{
	if (p == nullptr)
		return 0;
	if (currentLevel >= min && currentLevel <= max)
		return p->key + sumBetweenLevels(p->left, min, max, currentLevel+1) + sumBetweenLevels(p->right, min, max, currentLevel+1);
	else return sumBetweenLevels(p->left, min, max, currentLevel+1) + sumBetweenLevels(p->right, min, max, currentLevel+1);
}

int findDepthFrom(BSTNodeInt* root, BSTNodeInt* ptr)
{
	if (root == nullptr || ptr == nullptr)
		return -1;
	
	if (root->key == ptr->key)
		return 0;
	int dist = findDepthFrom(root->right, ptr);
	if (dist >= 0)return dist + 1;

	dist = findDepthFrom(root->left, ptr);
	if (dist >= 0)return dist + 1;

	return -1;

}

int findDepthFrom2(BSTNodeInt* refPtr, BSTNodeInt* ptr, int lvl)
{
	//refPtr je polazni cvor i lvl je nivo na kome se on nalazi
	//ako je polazni cvor nullptr onda se vraca nevalidna vrednost -1
	//ako postoji poklapanje izmedju cvora koji se trazi i referentnog, znaci
	//da se trazeni cvor nalazi na nivou lvl
	//u suprotnom, sa pretragom se nastavlja u levom i desnom podstablu 
	//max eliminise -1 nevalidnu vrednost, jer se cvor moze naci samo u jednom podstablu
	//a ovo drugo ce vratiti -1
	if (refPtr == nullptr)
		return -1;
	if (refPtr == ptr)
		return lvl;
	else
		return max(findDepthFrom2(refPtr->left, ptr, lvl + 1), findDepthFrom2(refPtr->right, ptr, lvl + 1));
}


void mirror(const BSTNodeInt* trenutniOriginal, BSTNodeInt* trenutniKopija)
{
	cout << "poziv ";
	if (trenutniOriginal == nullptr)
		return;

	if (trenutniOriginal->right != nullptr)
		trenutniKopija->left = new BSTNodeInt(trenutniOriginal->right->key);
	else
		trenutniKopija->left = nullptr;

	if (trenutniOriginal->left != nullptr)
		trenutniKopija->right = new BSTNodeInt(trenutniOriginal->left->key);
	else
		trenutniKopija->right = nullptr;

	if(trenutniKopija->right!=nullptr)
		mirror(trenutniOriginal->left, trenutniKopija->right);
	if (trenutniKopija->left != nullptr)
		mirror(trenutniOriginal->right, trenutniKopija->left);
}


