#include<assert.h>
#include <stdlib.h>
#include<stdio.h>
#include "list.h"

int main()
{

    ListW *test;

    test = initialize_list_W(test); //to initialize

    //printf("1..\n");

    assert(insert_pro_head(test, "project 1","Iot",5000,4.5)); //list,title, domain, price,ratings
    assert(insert_pro_head(test, "project 2","Embedded Systems",10000,4));
    assert(insert_pro_head(test, "project 3","Electrical",6000,3.9));
    assert(insert_pro_head(test, "project 4","Mathematics",9000,3.5));
    assert(insert_pro_head(test, "project 5","Quantum Physics",25000,4.3));

     // printf("2..\n");

     display(test);

     assert(search_project_domain(test,"Iot"));
     assert(search_project_title(test,"project 1"));
     assert(search_project_price(test,7000));

     //match_user(test);

    free_list(test);

    return 0;
}

