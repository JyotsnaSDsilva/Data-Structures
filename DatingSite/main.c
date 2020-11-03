#include<assert.h>
#include <stdlib.h>
#include<stdio.h>
#include "list.h"
int main()
{
    ListW *test;

    test = initialize_list_W(test); //to initialize

    //printf("1..\n");

    assert(insert_word_head(test, "Asha","Dehli","Female",25,"Singing,Reading","Tall,Educated"));
    assert(insert_word_head(test, "Amisha","Dehli","Female",26,"Singing,Reading","Tall,Educated"));
    assert(insert_word_head(test, "Rahul","Dehli","Male",28,"Gaming,Reading","Fair,Educated"));
    assert(insert_word_head(test, "Ali","Dehli","Male",28,"Gaming,Reading","Educated,Muslim"));
    assert(insert_word_head(test, "Aayisha","Dehli","Male",28,"Gaming,Reading","Educated,Muslim"));

     // printf("2..\n");

     //display(test);


     //match_user(test);

    free_list(test);

    return 0;
}
