
struct _dictionary_
{
    char word[20];
    char meaning[30];

    struct _dictionary_ *ptr;
};

typedef struct _dictionary_ Dict;


struct _linkedlist_word_
{
    Dict *head, *tail;
    int count;
};

typedef struct _linkedlist_word_ ListW;


int hash_W(char word[]);
ListW * initialize_list_W();
ListW ** initialize_htw(int size);
int insert_htW_head(ListW **ht, char [], char []);
int insert_word_head(ListW *myList, char [],char []);
Dict * getDict(char [],char []);
void display_dict(ListW **ht, int size);

void deallocate_list(ListW **ht, int size);

