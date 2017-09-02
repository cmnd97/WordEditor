#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>


typedef struct list
{
    char l;
    struct list *next;
}list;
list *start=NULL;

int nr=0,vdl[20];

void create(list*first)
{   char x;
    list *nou,*current;
    printf("\nLet's begin by writing a word.");
    while(x!='`')
    {

    nr++;

    if(nr>9) printf("\n Input letter #%d: ",nr);
    else printf("\n Input letter #%d:  ",nr);

    x=getche();
    if(x=='`') {printf("\nInput ended successfully!\n"); break;}
    nou=malloc(sizeof(list));
    nou->l=x;
            if(first==NULL)
                   start=first=current=nou;
            else
            {
                current->next=nou;
                current=nou;
            }
    }
    current->next=NULL;
}

void display(list *first)


{ list *current;

    for(current=first;current!=NULL;current=current->next)
    {printf("%c",current->l); Sleep(100);} printf("'. ");
}


void addnewletter(int poz,char let,list *first)
{
    list *current=first,*nou;
    nou=malloc(sizeof(list));
    nou->l=let;
     if(poz==1) {nou->next=start;
                start=nou;}
    else

        {
                for(int j=1;j<poz-1;j++)
                    current=current->next;
                    if(current->next!=NULL)
                    nou->next=current->next;
                    current->next=nou;
        }
}
void deletepoz(int poz, list*first)
{ list *current=first; int j; list *p;
    if(poz==1) first=start=current->next;
    else
    for(j=1;j<poz-1;j++)




        current=current->next; p=current->next;
        current->next=current->next->next; free(p);
}

void deletelet(char let, list *first)

{
    int k=0,cnt=0,x=0,n=0;
    list *current=first;
    for(current=first;current!=NULL;current=current->next)
    {

     k++;
    if(current->l==let)
        {
            vdl[cnt]=k; cnt++;
        }

    }
            for(n=0;n<=cnt;n++)
                   {

                   if(vdl[n]>0)
                    {
                        deletepoz(vdl[n],start);
                        for(x=n+1;x<=cnt;x++)
                            vdl[x]-=1; vdl[n]=-1;

                    }
                    }

}

void modify(list *first)
{  char s='o';
 printf("\n____________________\n\nWhat do you want to do now? \n|-> To add a new letter, press A. \n|-> To delete a letter, press D.\n`->To exit, press 0.\n____________________ \n...Awaiting your input...");
    s=getch();
    while(s!='0')
    switch(s)

    {
        case 'a': case 'A':
            { int poz; char let;
            printf("\nYou chose to add a new letter!\nPlease input the desired letter: ");
                    let=getche();
            printf("\nNow please input the position which the new letter will have: ");
                    scanf("%d",&poz);
            addnewletter(poz,let,start);
            printf("\nThis is your new word:'");
            display(start); break;
            }

        case 'd': case 'D':
            {   char fdb,let2; int pos;
                printf("\nYou chose to delete a letter!\nYou can delete a letter from a specific position by pressing P. \nOr delete a specific letter by pressing L.\n...Awaiting your input...");
                fdb=getche();
                switch(fdb)
                {

                    case 'l' : case 'L':
                        {
                        printf("\n You chose to delete a specific letter! Which is it? : ");
                        let2=getche();
                        printf("\n Ok. Deleting all the positions which contain %c...",let2);
                        deletelet(let2,start);
                        printf("\nThis is your new word:'");
                        display(start); break;
                        }
                                    break;
                    case 'p':case 'P':
                    {
                        printf("\nYou chose to delete a specific position! Which is it? : ");
                        scanf("%d",&pos);
                        deletepoz(pos,start);
                        printf("\nThis is your new word:'");
                        display(start); break;
                    }
                    break;
                }
            }
       printf("\nAnything else?"); s=getch();
    }

}




int main()
{

    printf("                    WELCOME TO THE LIST REVISION PROGRAM!\n                Created: 15.02.2016 Last modified: 15:02.2016 \n################################################################################\nNote: Press ` to terminate the input.\n");
    create(start);
    printf("\nYour word is:'");
    display(start);
    modify(start);

return 0;
}
