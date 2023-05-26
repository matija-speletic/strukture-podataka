int* addBigNumbers(int** numbers,int noNumbers,int noDigits)
{
    Stack<int>* s1=new Stack<int>(noDigits+5),*s2=new Stack<int>(noDigits+5),*s3=new Stack<int>(noDigits+5), *pom;
    int prenos=0;
    for(int i=0;i<noDigits;i++)
        s3->push(numbers[0][i]);
    for(int i=1;i<noNumbers;i++)
    {
        pom=s1;
        s1=s3;
        s3=pom;
        for(int j=0;j<noDigits;j++)
            s2->push(numbers[i][j]);
        while(!s1->isEmpty()||!s2->isEmpty())
        {
            prenos+=(s1->isEmpty())?0:s1->pop()+(s2->isEmpty())?0:s2->pop();
            s3->push(prenos%10);
            prenos/=10;
        }
    }
}