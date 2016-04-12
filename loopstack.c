
struct Stack
{
        char a[MAX];
        int head;

}loopstack;

int s_top()
{
    return loopstack.a[loopstack.head-1];
}
void s_push(char x)
{
    if(loopstack.head<MAX)
    {
     //   printf("enterd char %c",x);
        loopstack.a[loopstack.head++]=x;

    }
   // else
     //   cout<<"overflow"<<endl;

}
void s_pop()
{
    if(loopstack.head>=0)
    {
      //  printf("popped char %c",s_top());
        loopstack.head--;
    }
   // else
       // cout<<"underflow"<<endl;
}
