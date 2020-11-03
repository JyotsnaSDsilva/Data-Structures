#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

ListW * initialize_list_W(ListW *newList)
{
    newList = (ListW *)malloc(sizeof(ListW));
    newList->head = newList->tail = NULL;
    newList->count = 0;

    return newList;
}

void free_list(ListW *mylist)
{
    User *temp, *node;
    temp =mylist->head;

    while(temp!=NULL)
      {
        node = temp->ptr;
        free(temp);
        temp = node;
      }

}

User * getUser(char name[],char address[],char sex[],int age,char hobby[], char expec[])
{

    User * newUser;

    newUser = (User *)malloc(sizeof(User));

    newUser->age = age;
    strcpy(newUser->name,name);
    strcpy(newUser->sex,sex);
    strcpy(newUser->address,address);
    strcpy(newUser->hobby,hobby);
    strcpy(newUser->expec,expec);

    newUser->ptr = NULL;

    return newUser;
}


int insert_word_head(ListW *myList,char name[],char address[],char sex[],int age,char hobby[], char expec[])
{

    //printf("4..\n");
    User *newUser;

    newUser = getUser(name,address,sex,age,hobby,expec);

     //To find match initially
    //find_match(myList,newUser);
    find_match_preff(myList,newUser);

    if(newUser == NULL)
        return 0;

    if(myList->count == 0)
        myList->head = myList->tail = newUser;
    else
    {
        newUser->ptr = myList->head;
        myList->head = newUser;
    }

    myList->count++;


    return 1;

}

void display(ListW *test)
{
    User *temp;

    for(temp = test->head;temp!=NULL;temp= temp->ptr)
     {
       printf("Name : %s \n",temp->name);
       printf("Age : %d \n",temp->age);
       printf("Sex : %s \n",temp->sex);
       printf("Address : %s \n",temp->address);
       printf("Hobbies : %s \n",temp->hobby);
       printf("Expectations : %s \n\n",temp->expec);

       if(temp->ptr == NULL)
        break;
     }
}



int match_hobby(char user1_hobby[],char user2_hobby[])
{
  char str[20][20], str2[20][20];
  int i=0,j=0,k=0,cnt=0,c=0;

  //store hobbies into first array of strings
  for(i=0;i<=(strlen(user1_hobby));i++)
    {
        if(user1_hobby[i]==','|| user1_hobby[i]=='\0')
        {
            str[cnt][j]='\0';
            cnt++;
            j=0;
        }
        else
        {
            str[cnt][j]=user1_hobby[i];
            j++;
        }
    }

    //store hobbies into second array of strings
    for(i=0;i<=(strlen(user2_hobby));i++)
    {
        if(user2_hobby[i]==','||user2_hobby[i]=='\0')
        {
            str2[c][k]='\0';
            c++;
            k=0;
        }
        else
        {
            str2[c][k]=user2_hobby[i];
            k++;
        }
    }


    //compare equality between words in each string array
    for(i=0;i < cnt;i++)
    {
        for(j=0;j < c;j++)
        {
            if((strcmp(str[i],str2[j]))==0)
                return 1;
        }
    }

    return 0;

}

int match_preff(char user1_pr[],char user2_pr[])
{
  char str[20][20], str2[20][20];
  int i=0,j=0,k=0,cnt=0,c=0;

  //store hobbies into first array of strings
  for(i=0;i<=(strlen(user1_pr));i++)
    {
        if(user1_pr[i]==','|| user1_pr[i]=='\0')
        {
            str[cnt][j]='\0';
            cnt++;
            j=0;
        }
        else
        {
            str[cnt][j]=user1_pr[i];
            j++;
        }
    }

    //store hobbies into second array of strings
    for(i=0;i<=(strlen(user2_pr));i++)
    {
        if(user2_pr[i]==','||user2_pr[i]=='\0')
        {
            str2[c][k]='\0';
            c++;
            k=0;
        }
        else
        {
            str2[c][k]=user2_pr[i];
            k++;
        }
    }


    //compare equality between words in each string array
    for(i=0;i < cnt;i++)
    {
        for(j=0;j < c;j++)
        {
            if((strcmp(str[i],str2[j]))==0)
                return 1;
        }
    }

    return 0;

}


int match_user(ListW *test)  //to find all compatible users within the list
{
    User *temp,*temp2;

  //printf("\n\n Compatible users based on hobbies and then prefferences are \n\n");
  for(temp = test->head;temp!=NULL;temp= temp->ptr)
     {
         for(temp2 = temp->ptr;temp2!=NULL;temp2= temp2->ptr)
         {
             if((match_preff(temp->expec,temp2->expec))==1)
             {
                 printf("Name : %s \n",temp2->name);
                 printf("Age : %d \n",temp2->age);
                 printf("Sex : %s \n",temp2->sex);
                 printf("Address : %s \n",temp2->address);
                 printf("Hobbies : %s \n",temp2->hobby);
                 printf("Expectations : %s \n\n",temp2->expec);
             }

         }
     }
}


void find_match(ListW *test, User *user)
{
    User *temp;

    ListW *match_list;

    printf("\n\n Users Matched based on hobbies for %s : \n\n",user->name);

    for(temp = test->head;temp!=NULL;temp= temp->ptr)
     {
         if((match_hobby(temp->hobby,user->hobby))==1)
         {
            assert(insert_word_head(match_list,temp->name,temp->address,temp->sex,temp->age,temp->hobby,temp->expec));
         }
     }

     match_user(match_list);
}

void find_match_preff(ListW *test, User *user)
{
    User *temp;

    printf("\n\n Users Matched based on Hobbies and Preferences for %s : \n\n",user->name);

    for(temp = test->head;temp!=NULL;temp= temp->ptr)
     {
         if((match_hobby(temp->hobby,user->hobby))==1)
         {
            if((match_preff(temp->expec,user->expec))==1)
            {
                 printf("Name : %s \n",temp->name);
                 printf("Age : %d \n",temp->age);
                 printf("Sex : %s \n",temp->sex);
                 printf("Address : %s \n",temp->address);
                 printf("Hobbies : %s \n",temp->hobby);
                 printf("Expectations : %s \n\n",temp->expec);
            }
         }
     }
}



