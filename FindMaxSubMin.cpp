int FindMaxSubMin(BinTree *root)
{
    stack<BinTree*> s;  //用栈实现中序遍历
    BinTree *p=root;
    int MaxNode = p->data;
    int MinNode = p->data;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            if(p->data > MaxNode)
            {
                MaxNode = p->data;
            }
            if(p->data < MinNode)
            {
                MinNode = p->data;
            }
            s.pop();
            p=p->rchild;
        }
 }
 return abs(MaxNode - MinNode);
 }
