
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
//interview bit question
using namespace std;
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
            //cout<<"\npopping->"<<elem->ch;
            return elem;

        }

}
char getTop(stacke * top)
{   if(top==NULL)
    return '%';
    return (top->ch);

}
int getPrecedence(char ch)
{
        switch(ch)
        {
            case '*': return 2;
            case '/': return 2;
            case '+': return 1;
            case '-': return 1;
            case '(': return -1;  // so that we can stop popping


        }


}
char * infixToPostfix(char * infix)
{   stacke * top=NULL;
    int i=0;
    char ch=infix[i];
    char * answer=(char * )(malloc(sizeof(char )*strlen(infix)));
    int j=0;
    while(ch!='\0')
    {       ch=infix[i];

            if((ch<='z'&&ch>='a')||(ch>='A'&&ch<='Z'))
            {
                answer[j]=ch;
                i++;
                j++;

            }
            else if(ch=='(')
            {


                    push(&top,'(');
                    i++;

            }
            else if(ch==')')
            {       stacke * popped=pop(&top);
                    while(popped->ch!='(')
                    {
                        answer[j]=popped->ch;
                        j++;
                        popped=pop(&top);
                        if(popped==NULL)
                        break;

                    }
                i++;
            }
            else
            {
                    int precch=getPrecedence(ch);
                    int pretop=getPrecedence(getTop(top));
                    if(precch>pretop)
                    push(&top,ch);
                    else
                    {

                        while(precch<=pretop)
                        {
                            stacke * popped=pop(&top);
                            if(popped==NULL)
                            break;        // if stack gets empty then break the loop
                            answer[j]=popped->ch;
                            j++;
                            pretop=getPrecedence(getTop(top));


                        }
                        push(&top,ch); //push the new character

                    }
                    i++;

            }
        //cout<<"\nch is="<<ch<<"  Stack is->";
          //  printStack(top);
          //  cout<<"\n postfix is"<<answer;



    }
    while(top!=NULL)
    {
        stacke * popped=pop(&top);
        if(popped==NULL)
        break;
        answer[j]=popped->ch;
        j++;

    }
    return answer;

}
using namespace std;
int main()
{
        cout<<infixToPostfix("(A*B-(C+D)+E)");

}
