#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include "listt.h"

//dictionary application: functions

ListW * initialize_list_W() //initializes a list
{
    ListW *newList;

    newList = (ListW *)malloc(sizeof(ListW));
    newList->head = newList->tail = NULL;
    newList->count = 0;

    return newList;
}


ListW ** initialize_htw(int size) //initializes a hash table
{
    ListW **ht;
    int i;

    ht = (ListW **)malloc(sizeof(ListW *)*size);

    for(i=0; i< size; i++)
    {
        ht[i] = initialize_list_W();
    }
     return ht;
}


Dict * getDict(char word[],char meaning[]) //returns a node with given values
{
    Dict * newWord;

    newWord = (Dict *)malloc(sizeof(Dict));
    strcpy(newWord->word,word);
    strcpy(newWord->meaning,meaning);

    newWord->ptr = NULL;

    return newWord;
}


int insert_htW_head(ListW **ht, char word[], char meaning[]) //inserts a node to hashtable
{
    int index = hash_W(word);

    ListW *myList;

    myList = ht[index];

    return insert_word_head(myList,word,meaning);

}

int hash_W(char word[]) //returns hash
{
   char str[20];
   int i;
   strcpy(str,word);

   for (i = 0; str[i]!='\0'; i++)
      {
        if(str[i] >= 'a' && str[i] <= 'z')
         {
            str[i] = str[i] - 32;
         }
      }

    char ch = str[0];

    return ch-65;

}



int insert_word_head(ListW *myList, char data[],char meaning[]) //inserts a node to linked list
{
    Dict *newWord;

    newWord = getDict(data,meaning);

    if(newWord == NULL)
        return 0;

    if(myList->count == 0)
        myList->head = myList->tail = newWord;
    else
    {
        newWord->ptr = myList->head;
        myList->head = newWord;
    }

    myList->count++;

    return 1;

}

void display_dict(ListW **ht, int size) //displays hash table
{
    Dict *temp;
    int i;

    for(i=0; i< size; i++)
    {
        temp = ht[i]->head;

        printf("Index[%d] : ", i);
        while(temp != NULL)
        {
            printf("%s : %s ||", temp->word,temp->meaning);
            temp = temp->ptr;
        }
        printf("\n");
    }

}


void deallocate_list(ListW **ht, int size) //deallocate list
{
    Dict *temp, *next;
    int i;

    for(i=0; i< size; i++)
    {
        next = ht[i]->head;
        while( next  != NULL)
        {
            temp = next ;
            next  = next ->ptr;
            free(temp);
        }

    }

}

