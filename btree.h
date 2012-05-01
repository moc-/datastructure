/*
 * 所有的数据结构的操作，无非就是
 * 创建， 销毁，增删查改
 *
 * 对于 树 来讲，
 * 增： 就是
 *
 */

#ifndef  BTREE_H
#define BTREE_H

#include "common.h"

#define MAX_TREE_SIZE 100



typedef t_elem_type sq_b_tree[MAX_TREE_SIZE];

struct Pos
{
    int level;
    int order;
};
typedef  struct Pos position;
//创建及销毁
Status  init_b_tree(sq_b_tree T);   // 构造空btree,T是定长数组，
                                    // 无需 &
void    destory_b_tree();           // sq_b_tree 是定长类型，
                                    // 无需销毁
Status  create_b_tree(sq_b_tree T); // 构造顺序存储的btree
Status  b_tree_empty(sq_b_tree T);  // btree 是否空的

//辅助函数
int b_tree_depth(sq_b_tree T);      
Status  root(sq_b_tree T, t_elem_type *value);
void    move(sq_b_tree q, int q_order, sq_b_tree T, int T_order );

void    pre_traverse(sq_b_tree T, int index);
void    in_traverse(sq_b_tree T, int index);
void    post_traverse(sq_b_tree T, int index);
void    print(sq_b_tree T);

//update
Status  assign(sq_b_tree T, position pos,  t_elem_type value);
// query
t_elem_type value(sq_b_tree T, position pos);
t_elem_type parent(sq_b_tree T, t_elem_type node);
t_elem_type lchild(sq_b_tree T, t_elem_type node);
t_elem_type rchild(sq_b_tree T, t_elem_type node);
t_elem_type lsibling(sq_b_tree T, t_elem_type node);
t_elem_type rsibling(sq_b_tree T, t_elem_type node);

Status  pre_order_traverse(sq_b_tree T, Status (*visit)(t_elem_type));
Status  in_order_traverse(sq_b_tree T, Status (*visit)(t_elem_type));
Status  post_order_traverse(sq_b_tree T, Status (*visit)(t_elem_type));

//insert
Status  insert_child(sq_b_tree T, t_elem_type node, Status lr, 
                        sq_b_tree c );
//delete
Status  delete_child(sq_b_tree T, position pos, Status lr);




#endif // BTREE_H
