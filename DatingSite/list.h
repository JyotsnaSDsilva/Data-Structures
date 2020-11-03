
struct _user_
{
    char name[20];
    char address[20];
    char sex[20];
    int age;

    char hobby[50];
    char expec[50];

    struct _user_ *ptr;
};

typedef struct _user_ User;


struct _linkedlist_word_
{
    User *head, *tail;
    int count;
};

typedef struct _linkedlist_word_ ListW;



ListW * initialize_list_W(ListW *newList);

int insert_word_head(ListW *myList,char name[],char address[],char sex[],int age,char hobby[], char expec[]);
User * getUser(char name[],char address[],char sex[],int age,char hobby[], char expec[]);

void display(ListW *test);
void free_list(ListW *mylist);

int match_hobby(char user1_hobby[],char user2_hobby[]);
int match_user(ListW *);
void find_match(ListW *test, User *user);
void find_match_preff(ListW *test, User *user);

