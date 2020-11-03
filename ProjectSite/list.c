#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include "list.h"


ListW * initialize_list_W(ListW *newList) //initializes a list
{
    newList = (ListW *)malloc(sizeof(ListW));
    newList->head = newList->tail = NULL;
    newList->count = 0;

    return newList;
}


void free_list(ListW *mylist) //delete list
{
    Pro *temp, *node;
    temp =mylist->head;

    while(temp!=NULL)
      {
        node = temp->ptr;
        free(temp);
        temp = node;
      }

}

Pro * getPro(char title[],char domain[],int price,float ratings) //returns a node with the given details
{

    Pro *newPro;

    newPro = (Pro *)malloc(sizeof(Pro));

    strcpy(newPro->title,title);
    strcpy(newPro->domain,domain);
    newPro->price= price;
    newPro->ratings = ratings;

    newPro->ptr = NULL;

    return newPro;
}


int insert_pro_head(ListW *myList,char title[],char domain[],int price,float ratings) //insert data to the given list
{

    //printf("4..\n");
    Pro *newPro;

    newPro = getPro(title,domain,price,ratings);

    if(newPro == NULL)
        return 0;

    if(myList->count == 0)
        myList->head = myList->tail = newPro;
    else
    {
        newPro->ptr = myList->head;
        myList->head = newPro;
    }

    myList->count++;


    return 1;

}


void display(ListW *test) //display list elements
{
    Pro *temp;

    for(temp = test->head;temp!=NULL;temp= temp->ptr)
     {
       printf("Title of the Project : %s \n",temp->title);
       printf("Domain : %s \n",temp->domain);
       printf("price : %d \n",temp->price);
       printf("Ratings : %.1f \n\n\n",temp->ratings);

       if(temp->ptr == NULL)
        break;
     }
}


int search_project_domain(ListW *test, char domain[]) //search an element- domain from given list
{
    Pro *temp;

    printf("\n projects based on domain \n");
    for(temp = test->head; temp!=NULL; temp=temp->ptr)
        {

          if((strcmp(temp->domain,domain))==0)
          {
              printf("\nTitle of the Project : %s \n",temp->title);
              printf("Domain : %s \n",temp->domain);
              printf("price : %d \n",temp->price);
              printf("Ratings : %.1f \n\n\n",temp->ratings);

          }
        }
  return 1;
}


int search_project_title(ListW *test, char title[]) //search an element- title from given list
{
    Pro *temp;

    printf("\n projects based on title \n");
    for(temp = test->head; temp!=NULL; temp=temp->ptr)
        {
          if((strcmp(temp->title,title))==0)
          {
              printf("\nTitle of the Project : %s \n",temp->title);
              printf("Domain : %s \n",temp->domain);
              printf("price : %d \n",temp->price);
              printf("Ratings : %.1f \n\n\n",temp->ratings);

          }
        }
  return 1;
}


int search_project_price(ListW *test, int price) //search an element-price from given list
{
    Pro *temp;

    printf("\n projects based on price \n");
    for(temp = test->head; temp!=NULL; temp=temp->ptr)
        {
          if(temp->price <= price)
          {
              printf("\nTitle of the Project : %s \n",temp->title);
              printf("Domain : %s \n",temp->domain);
              printf("price : %d \n",temp->price);
              printf("Ratings : %.1f \n\n\n",temp->ratings);

          }
        }
  return 1;
}


