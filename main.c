#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int q1[MAX], q2[MAX];
int count=0;
int f1=-1; int f2=-1; int r1=-1; int r2=-1;
void push()
{
    int item;
    printf("\nEnter the value to be inserted in stack:- ");
    scanf("%d",&item);
    if(r1==-1)
        f1=0;

    q1[++r1]=item;
}
int pop()
{
    int val;

    if(r1==-1 && r2==-1)
    {
        printf("\nStack is empty\n");
        return -1;
    }
    if(f1!=-1)
    {
        if(f2==-1)
        {
            f2=0;
        }
        while(f1!=r1)
        {
            q2[++r2]=q1[f1++];
        }
        val=q1[f1];
        f1=-1; r1=-1;
    }
    else
    {
        if(f1==-1)
        {
            f1=0;
        }
        while(f2!=r2)
        {
            q1[++r1]=q2[f2++];
        }
        val=q2[f2];
        f2=-1; r2=-1;
    }
    return val;
}
void peek()
{
    if(f1==-1 && f2==-1)
    {
        printf("\nStack is empty\n");
        return;
    }
    if(f1!=-1 || r1!=-1)
    {
        printf("\nTop value= %d\n",q1[r1]);
    }
    if(f2!=-1 || r2!=-1)
    {
        printf("\nTop value= %d\n",q2[r2]);
    }

}
int main()
{
    int ch, val;

    printf("\n1.Push\n");
    printf("\n2.Pop\n");
    printf("\n3.Peek\n");
    printf("\n4.Exit\n");
    while(1)
    {
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
          switch(ch)
          {
          case 1:
             push();
             break;
          case 2:
             val=pop();
            if(val!=-1)
            {
                printf("\nDeleted value is %d\n",val);
            }
            break;
          case 3:
            peek();
            break;
          case 4:
            exit(0);
          default:
            printf("\nWrong choice\n");
          }
    }
    return 0;

}
