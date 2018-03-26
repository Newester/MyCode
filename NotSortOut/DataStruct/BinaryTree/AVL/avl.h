#include "../BST/BST.h"

template<typename T>
class AVL : public BST<T> {
	BinNode<T>*  insert(const T& e);
	bool remove(const T& e);
};

#include "AVL_implementation.h"
