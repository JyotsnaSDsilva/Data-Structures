struct _employee_
{
    int *emp;
    int c_size, t_size;
};

typedef struct _employee_ ArrayD;

ArrayD * initialize_array_d(int);

int insert(ArrayD *, int);

int search(ArrayD *, int);

void display(ArrayD *);
int sum_of_array(ArrayD *);

int maxmin(ArrayD *, int *max, int *min);

int sort_ascending(ArrayD *);
int reverse_array(ArrayD *);

int replace_element(ArrayD * , int, int);
ArrayD * Merge_array(ArrayD *, ArrayD *);
int sort_descending(ArrayD *);

void search_by_pos(ArrayD *, int);

