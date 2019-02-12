//
// Created by phoenix on 2/6/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person6
{
    char *name;
    int age;
};

struct Person6** allocatePerson(int len)
{
    struct Person6 ** person=malloc(sizeof(struct Person6*)*len);
    for(int i=0;i<len;++i)
    {
        person[i]=malloc(sizeof(struct Person6));
        person[i]->name=malloc(sizeof(char)*64);
        sprintf(person[i]->name,"name_%d",i);
        person[i]->age=100+i;
    }
    return person;
}

void printPersons6(struct Person6 **p,int len)
{
    if(p==NULL)
    {
        return;
    }
    for(int i=0;i<len;++i)
    {
        printf("%s  %d\n",p[i]->name,p[i]->age);
    }
}

void freePersons6(struct Person6 **p,int len)
{
    if(p==NULL)
    {
        return;
    }
    for(int i=0;i<len;++i)
    {
        if(p[i]!=NULL)
        {
            if(p[i]->name!=NULL)
            {
                free(p[i]->name);
                p[i]->name=NULL;
            }
            free(p[i]);
            p[i]=NULL;
        }
    }
    free(p);
    p=NULL;//无效
}

void test61()
{
    struct Person6**person=NULL;
    person=allocatePerson(5);
    printPersons6(person,5);
    freePersons6(person,5);

    printf("%d\n",person==NULL);
    person=NULL;
    int arr[]={1,2,3};
    int (*p)[3]=&arr;
    printf("%d\n",**p);
}

int main()
{
    test61();
    return 0;
}
