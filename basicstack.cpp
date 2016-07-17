
#include<bits/stdc++.h>
typedef struct Stack
{
        char ch;
        struct Stack * next;
}stacke;
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
int checkParanthesis(stacke ** top,char * buffer)
{

        char ch='a';
        int i=0;
        while(ch!='\0')
        {
                ch=buffer[i];
                i++;
                if(ch=='{'||ch=='('||ch=='[')
                push(top,ch);
                if(ch=='}'||ch==')'||ch==']')
                {
                    stacke * elem=pop(top);
                    if(elem==NULL)
                    return 0;
                    char popped=elem->ch;

                    if(popped=='[')
                    {
                            if(ch==']')
                            continue;
                            else
                            return 0;

                    }
                     if(popped=='{')
                    {
                            if(ch=='}')
                            continue;
                            else
                            return 0;

                    }
                     if(popped=='(')
                    {
                            if(ch==')')
                            continue;
                            else
                            return 0;

                    }

                }

        }

        stacke * newpop=pop(top);
        if(newpop==NULL)
        return 1;
        else
        return 0;
}
#include<iostream>
using namespace std;

int main()
{

    stacke * top=NULL;
    cout<<checkParanthesis(&top,"((A+B)+[C-D]}");


}
