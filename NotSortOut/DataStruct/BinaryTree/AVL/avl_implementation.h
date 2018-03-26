#include "AVL_insert.h"
#include "AVL_remove.h"

inline BinTree<T>* tallerChild(BinTree<T>* x){
    return stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : (stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : (IsLChild( * (x) ) ? (x)->lc : (x)->rc)); 
}
		