//fibonacijev metod
unsigned int g(unsigned int k)
{
	unsigned const int a = 2654435769;
	unsigned const ak = a * k;
	unsigned int ret = ak >> (32 - sizeExp); //sizeExp je vrednost koja se postavlja u konstruktoru kao ceil(log2(size))
	return ret;
}




/*
Klasa Record je zamisljena klasa, u realnim zadacima ce to da bude nekoliko parametara (ime, prezime itd.)
HashObject je klasa elementa hash tablice, nije bitno kako je nazovete u svom resenju i u redu je da pretpostavite da postoji konstruktor koji postavlja sve parametre (dakle u zadacima ce biti vise parametara kao sto su ime prezime itd.)
funkcija s(int) je sekundarna transformacija (obavezno naglasite u komentarima u resenju) 
*/

//############################################################
//otvoreno adresiranje
//############################################################
void InsertOrUpdate(char* key, Record* r)
{
    unsigned int hash=h(key),probe =hash,prvoSlobodno=-1; //prvo slobodno ukazuje na prvo slobodno ili obrisano mesto
    for(int i= 0;i<size;i++)//obilazimo sinonime
    {
        probe=(hash+c(i))%size;
        if(array[probe].status<2 && prvoSlobodno==-1)//nasli smo slobodno ili obrisano mesto
            prvoSlobodno=probe;
        if(array[probe].status==0)//dosli smo do kraja - nema vise sinonima i element nije pronadjen, pa ga dodajemo
        {
            array[prvoSlobodno]=HashObject(key,r);
            array[prvoSlobodno].status=2;
            count++;
            return;
        }
        if(array[probe].isEqualKey(key))//pronasli smo element pa ga azuriramo
        {
            array[probe].record=r;
            return;
        }
    }
    throw "Slobodno mesto nije pronadjeno";
}

unsigned int OpenScatterTable::findUnoccupied(ScatterObject obj)
{
	unsigned int hash = h(obj.getKey());
	unsigned int probe = hash;
	if (array[probe].status < 2)  
		return probe; // slobodan
	int i = 1;
	do {
		probe = (hash + c(i))%m;
		if (array[probe].status < 2)  
			return probe;
		i++;
	} while (probe != hash && i<m);
	throw new exception("Tablica je puna");
}

void OpenScatterTable::withdraw(char * key)
{
	if (count == 0) throw new exception("Tablica je prazna");
	long offset = findMatch(key);
	if (offset < 0) throw new exception("Nije nadjen!");
	array[offset].status = 1; // obrisan
	array[offset].deleteRecord();
	count--;

}

unsigned int OpenScatterTable::findMatch(char* key)
{
	unsigned int hash = h(key);
	for (unsigned int i = 0; i < m; i++)
	{
		unsigned int probe = (hash + c(i))%m;
		if (array[probe].status == 0) return -1;//nije pronadjen
		if (array[probe].isEqualKey(key)) return probe;
	}
	return ~0U;//greska - nije pronadjeno
}

void OpenScatterTable::insert(ScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int offset = findUnoccupied(obj);
	array[offset] = obj;
	array[offset].status = 2; // zauzet
	count++;
}








//############################################################
//unutrasnje ulancavanje sa izdvojenim prostorom za sinonime
//############################################################
void InsertOrUpdate(char*key, Record* r)
{
    unsigned int probe=h(key),prev=-1;
    while(probe!=-1 && probe!=0 && array[probe].status==2)//obilazimo listu sinonima
    {
        if(array[probe].isEqualKey(key))//pronadjen element - azurira se i vraca se iz funkcije
        {
            array[probe].record=r;
            return;
        }
        prev=probe;
        probe=array[probe].next;
    }//po izlasku iz petlje prev pokazuje na poslednji u listi sinonima
    if(probe==0) //ako je probe 0 to znaci da nema mesta (takva je konfiguracija projekta koji je davidovic pokazao)
        throw "Prostor za sinonime je pun";
    if(prev!=-1) //ako prvi element  nije bio slobodan potrebno je iz lrmp uzeti sledecu slobodnu memorijsku lokaciju
    {
        probe=prev;
        array[probe].next=lrmp;
        probe=lrmp;
        lrmp=array[probe].next;
    }
    array[probe]=HashObject(key,r);//dodavanje elementa
    array[probe].next=-1;
    array[probe].status=2;
    count++;
}

void ChainedScatterTable::insert(ChainedScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
		{
			probe = array[probe].next;
		}
		if (array[probe].next == 0)
			throw new exception("Izdvojeni prostor za sinonime je pun!");
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else
			return array[probe];
	}
	return ChainedScatterObject();
}








//############################################################
//unutrasnje ulancavanje  bez izdvojenog adresnog prostora
//############################################################
void InsertOrUpdate(char* key, Record* r)
{
    unsigned int probe=h(key),prev=-1;
    if(array[probe].status==2) //ako prvi element nije slobodan
    {
        while(probe!=-1 && array[probe].status==2) //obilazimo listu sinonima i postavljamo se na njen kraj
        {
            if(array[probe].isEqualKey(key))//ako usput pronadjemo trazeni element azuriramo ga i vracamo se iz funkcije
            {
                array[probe].record=r;
                return;
            }
            prev=probe;
            probe=array[probe].next;
        }
        unsigned int tail = prev;//poslednji u listi sinonima
        probe=s(tail);
        while(array[probe].status==2 && probe!= tail)//trazimo slobodno mesto
            probe=s(probe);
        if(probe==tail)//ako slobodno mesto nije pronadjeno
            throw "Losa sekundarna transformacija";
        array[tail].next=probe; //ulancavamo pronadjeno slobodno mesto u listu sinonima
    }
    array[probe]=HashObject(key,r);//dodajemo element
    array[probe].status=2;
    array[probe].next=-1;
    count++;
}

void insert(ChainedScatterObject obj)
{
    if(count == getLength ())
        throw "The table is full!"; 
    long probe = h(obj);
    if(array[probe].status!=0)
    {
        while (array [probe].next != -1)
        {
            probe = array [probe].next;
        }
        long tail = probe; 
        probe = sekundarnaTransformacija(probe);
        while (!array [probe].free && probe!=tail) 
            probe = sekundarnaTransformacija(probe);
        if(probe==tail)
            throw "Poor secondary transformation!"; 
        array [tail].next = probe;
    }
    array[probe] = obj; 
    array[probe].status = 2; // zauzet 
    array[probe].next = -1;
    count++;
}

ChainedScatterObject find(char* key)
{
    long probe = f(key)%length; 
    while(probe != -1)
    {
        if(!array[probe].isEqualKey(key))
            probe = array[probe].next;
        else
            return array[probe];
    }
    throw "Element not found!";
}

