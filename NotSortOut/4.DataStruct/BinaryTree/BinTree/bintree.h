#include "../BinnNode/BinNode.h"
template<typename T>
class BinTree{
protected:
	int _size;
	BinNode<T>* _root;
	virtual int updateHeight(BinNode<T>* x);
	void updateHeightAbove(BinNode<T>* x);
public:
	BinTree():_size(0),_root(NULL){}
	~BinTree(){
		if(0 < _size)
			remove(_root);
	}
	
	int size() const {return _size;}
	bool empty() const {return !_root;}
	BinNode<T>* root() const {return _root;}
	
	BinNode<T>* insertAsRoot(T const& e);
	BinNode<T>* insertAsLC(BinNode<T>* x,T const& e);
	BiNode<T>* insertAsRC(BinNode<T>* x,T const& e);
	BinNode<T>* attachAsLC(BinNode<T>* x,BinTree<T>* &T);
	BinNode<T>* attachAsRC(BinNode<T>* x,BinTree<T>* &T);

	int remove(BinNode<T>* x);
	
	template<typename VST>
	void travLevel(VST& visit){
		if(_root){
			_root->travLevel(visit);
		}
	}
	
	template<typename VST>
	void travPre(VST& visit){
		if(_root){
			_root->travPre(visit);
		}
	}
	
	template<typename VST>
	void travIn(VST& visit){
		if(_root){
			_root->travIn(visit);
		}
	}

	template<typename VST>
	void travPost(VST& visit){
		if(_root){
			_root->travPost(visit);
		}
	}	
	
	
};

#include "BinTree_implementation.h"