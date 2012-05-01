#include "btree.h"

#define CHAR    1

int 
main(void)
{
    sq_b_tree T;
    int count = 0;
        
    for (count = 0; count < MAX_TREE_SIZE; count++)
    {
        T[count] = 'a';
    }

    init_b_tree(T);
        
    for (count = 0; count < MAX_TREE_SIZE; count++)
    {
        printf("%d   ", T[count]);
    }
    return 0;
}
