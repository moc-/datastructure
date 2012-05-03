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



typedef Elem_type Sq_b_tree[MAX_TREE_SIZE];

struct Pos
{
    int level;
    int order;
};
typedef  struct Pos Position;
//创建及销毁
Status  init_b_tree(Sq_b_tree T);   // 构造空btree,T是定长数组，
                                    // 无需 &
void    destory_b_tree();           // Sq_b_tree 是定长类型，
                                    // 无需销毁
Status  create_b_tree(Sq_b_tree T); // 构造顺序存储的btree
Status  b_tree_empty(Sq_b_tree T);  // btree 是否空的

//辅助函数
int b_tree_depth(Sq_b_tree T);      
Status  root(Sq_b_tree T, Elem_type *value);
void    move(Sq_b_tree q, int q_order, Sq_b_tree T, int T_order );

void    pre_traverse(Sq_b_tree T, int index);
void    in_traverse(Sq_b_tree T, int index);
void    post_traverse(Sq_b_tree T, int index);
void    print(Sq_b_tree T);

//update
Status  assign(Sq_b_tree T, Position pos,  Elem_type value);
// query
Elem_type value(Sq_b_tree T, Position pos);
Elem_type parent(Sq_b_tree T, Elem_type node);
Elem_type lchild(Sq_b_tree T, Elem_type node);
Elem_type rchild(Sq_b_tree T, Elem_type node);
Elem_type lsibling(Sq_b_tree T, Elem_type node);
Elem_type rsibling(Sq_b_tree T, Elem_type node);

Status  pre_order_traverse(Sq_b_tree T, Status (*visit)(Elem_type));
Status  in_order_traverse(Sq_b_tree T, Status (*visit)(Elem_type));
Status  post_order_traverse(Sq_b_tree T, Status (*visit)(Elem_type));

//insert
Status  insert_child(Sq_b_tree T, Elem_type node, Status lr, 
                        Sq_b_tree c );
//delete
Status  delete_child(Sq_b_tree T, Position pos, Status lr);




#endif // BTREE_H
