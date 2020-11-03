
struct _project_
{
    int price;
    float ratings;
    char title[30];
    char domain[20];

    struct _project_ *ptr;
};

typedef struct _project_ Pro;


struct _linkedlist_word_
{
    Pro *head, *tail;
    int count;
};

typedef struct _linkedlist_word_ ListW;

ListW * initialize_list_W(ListW *newList);
int insert_pro_head(ListW *myList,char title[],char domain[],int price,float ratings);
Pro *getPro(char title[],char domain[],int price,float ratings);

void display(ListW *test);
void free_list(ListW *mylist);

int search_project_domain(ListW *test, char domain[]);
int search_project_title(ListW *test, char title[]);
int search_project_price(ListW *test, int price);
