#define NAME_SIZE 20        //available string size for name
#define MARKS 5         //available amount of marks
#define LENGTH 12        //number of students


typedef struct mystruct          
{
    char surname[NAME_SIZE];             
    char name[NAME_SIZE];                 
    char date[NAME_SIZE];                  
    int marks[MARKS];                
                                 
} Students;                      

typedef struct Node
{
    Students newStud; 
    struct Node* next;

} node_t;
