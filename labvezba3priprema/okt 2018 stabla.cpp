//OKTOBAR 2018 - STABLA
double CalcExpression(Node* n)
{
    if(n==NULL)
        return 0.0;
    if(n->left==NULL && n->right==NULL)
        return n->info;
    double op1=CalcExpression(n->left);
    char op=n->info;
    double op2=CalcExpression(n->right);
    switch(op)
    {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    }
    return 0.0;
}