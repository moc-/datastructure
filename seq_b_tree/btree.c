#include "btree.h"

#if CHAR
    typedef char t_elem_type;
    t_elem_type null = ' ';
#else
    typedef int t_elem_type;
    t_elem_type null = 0;
#endif

Status
init_b_tree(sq_b_tree T)
{
    memset(T, null, MAX_TREE_SIZE);
    
    return 0;
}//init_b_tree
