#include<assert.h>
#include <stdlib.h>
#include<stdio.h>
#include "listt.h"
int main()
{
    ListW **ht_test;
    int i;
    //Dict *temp;

    ht_test = initialize_htw(26); //to initialize

    assert(insert_htW_head(ht_test, "Delirious", "drowsiness")); // parameters :(hashtable,word,meaning)
    assert(insert_htW_head(ht_test, "Awesome", "impressive"));
    assert(insert_htW_head(ht_test, "Blasphemy", "offense"));
    assert(insert_htW_head(ht_test, "Clever", "wise"));
    assert(insert_htW_head(ht_test, "Bold", "courageous"));
    assert(insert_htW_head(ht_test, "Anemia", "lack of RBC"));
    assert(insert_htW_head(ht_test, "Blog", "website published  on WWW"));
    assert(insert_htW_head(ht_test, "Quarantine", "Restriction on the movement"));
    assert(insert_htW_head(ht_test, "Undermine", "to subvert"));
    assert(insert_htW_head(ht_test, "Elegant", "graceful"));
    assert(insert_htW_head(ht_test, "Flabbergasted", "astound"));
    assert(insert_htW_head(ht_test, "glorious", "worth glorifying"));
    assert(insert_htW_head(ht_test, "Zeal", "Enthusiasm"));
    assert(insert_htW_head(ht_test, "Various", "diffrent"));
    assert(insert_htW_head(ht_test, "Serendipity", "occurence of happy events"));

    display_dict(ht_test,26);  //to display


    deallocate_list(ht_test,26);

    return 0;
}
