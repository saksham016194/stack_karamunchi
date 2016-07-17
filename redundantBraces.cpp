#include<iostream>
#include<bits/stdc++.h>
//interview bit question
typedef struct Stack
{
        char ch;
        struct Stack * next;
}stacke;
void printStack(stacke *top)
{   if(top==NULL)
        {
            printf("stack is empty");
            return ;
        }
    printf("\n");
    stacke * temp=(top);
    while((temp)->next)
    {printf("%c ",(temp)->ch);
        temp=temp->next;
        }
        printf("%c ",(temp)->ch);
}
void push(stacke ** top, char elem)
{       stacke * node=(stacke *) malloc(sizeof(stacke));
        if(node==NULL)
        {perror("cannot allocate memory!!");
        return;
        }
        node->ch=elem;
        node->next=NULL;
        if((*top)==NULL)
        {
            (*top)=node;
            return;
        }
        else
        {
            node->next=(*top);
            (*top)=node;
            return;

        }
}
stacke * pop(stacke **top)
{
        if((*top)==NULL)
        {
            perror("Underflow returning");
            return NULL;
        }
        else
        {
            stacke * elem=(*top);
            (*top)=(*top)->next;
            elem->next=NULL;
            return elem;

        }

}
char getTop(stacke * top)
{   if(top==NULL)
    return '%';
    return (top->ch);

}
int braces(char* A) {
    stacke * top=NULL;
    int answer=0;
    int i=0;
    char ch;
      while(1)
      {     if(A[i]=='('||A[i]=='\0')
            break;
          i++;
      }  //traverse the string until you find first opening brance

      if(A[i]=='\0')
      return 0;
    while(A[i]!='\0')
    {
        ch=A[i];
        i++;

        if(ch=='(')
        {//printf("\nInside ch, pushing %c",ch);
        push(&top,ch);
        //cout<<"\nstack now is\n";
        //printStack(top);
        continue;
        }

        else if(ch!=')')
        {   //printf(".%c",ch);

                if(ch=='*'||ch=='/'||ch=='-'||ch=='+')
                    {
                        char topchar=getTop(top);
                        if(topchar!='$'&&topchar!='%')
                        push(&top,'$');
                    }
                     // printf("\ninside first else ifstack is in i = %d \n",i);
                //printStack(top);
        }
        else
        {   //printf(".%c",A[i]);
       // printStack(top);
                char one;
                one=getTop(top);
              //  printf("\n%c popped",one->ch);
                if(one=='$')
              { pop(&top);
                pop(&top);
              answer=0;
              }
               else
               {
              return 1;
               }
                // printf("\ninside last else stack is in i = %d \n",i);
        //printStack(top);
        }

    }



    return answer;
}
using namespace std;
int main()
{
        cout<<braces("(((a+b))+c)");

}
