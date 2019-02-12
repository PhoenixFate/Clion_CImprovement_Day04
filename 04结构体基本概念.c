#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person4
{
    char name[64];
    int age;
};

void test01()
{
    struct Person4 p={"lilei",10};
    printf("name:%s age:%d\n",p.name,p.age);
    struct Person4 *pp=malloc(sizeof(struct Person4));
    strcpy(pp->name,"hanhonghong");
    pp->age=20;
    printf("name:%s age:%d\n",pp->name,pp->age);
};

void printPersons(struct Person4 *p,int len)
{
    for(int i=0;i<len;++i)
    {
        printf("name:%s  age:%d\n",p[i].name,p[i].age);
    }
}

void test02()
{
    struct Person4 persons[]={
            {"tom",20},
            {"cat",21},
            {"emm",18},
    };
    int len=sizeof(persons)/sizeof(struct Person4);
    printPersons(persons,len);

    struct Person4 *ps=malloc(sizeof(struct Person4)*5);
    for(int i=0;i<5;++i)
    {
        sprintf(ps[i].name,"name_%d",i);
        ps[i].age=i+20;
    }
    printPersons(ps,5);
}


int main4()
{
    test01();
    test02();
    printf("Hello, World!\n");
    return 0;
}