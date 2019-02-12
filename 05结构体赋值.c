//
// Created by phoenix on 2/6/2019.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Person51
{
    char * name;
    int age;
};
void test51()
{
    struct Person51 p={"tom",21};
    struct Person51 p2={"cat",18};
    p2=p;
    printf("%s  %d\n",p.name,p.age);
    printf("%p\n",p);
    printf("%p\n",p2);
    printf("%p\n",&p);
    printf("%p\n",&p2);
}

struct Teacher5
{
    char *name;
    int age;
};

void test52()
{
    struct Teacher5 t1;
    t1.name=malloc(sizeof(char)*64);
    memset(t1.name,0,sizeof(char)*64);
    strcpy(t1.name,"aaa");
    t1.age=24;
    printf("teacher: %s   %d\n",t1.name,t1.age  );
    struct Teacher5 t2;
    t2.name=malloc(sizeof(char)*128);
    memset(t2.name,0,sizeof(char)*128);
    strcpy(t2.name,"bbb");
    t2.age=999;
    printf("teacher: %s %d\n",t2.name,t2.age);


    if(t1.name!=NULL)
    {
        free(t1.name);
        t1.name=NULL;
    }
    t1.name=malloc(strlen(t2.name)+1);
    strcpy(t1.name,t2.name);
    t1.age=t2.age;
    printf("t1: %s   %d\n",t1.name,t1.age);
    printf("t2: %s    %d\n",t2.name,t2.age);
    if(t1.name!=NULL)
    {
        free(t1.name);
        t1.name=NULL;
    }
    if(t2.name!=NULL)
    {
        free(t2.name);
        t2.name=NULL;
    }
}
int main5()
{
    test51();
    test52();
    printf("%s","中文");
    return 0;
}

