
#define stature(p) ((p)?(p->height):-1)
typedef enum{RB_RED,RB_BLACK} RBColor;
template <typename T> struct BinNode {
	T data;
    BinNode<T>* parent;
	BinNode<T>* lc;
	BinNode<T>* rc;
	int height;
	int npl;
	RBColor color;
	
	BinNode():parent(NULL),lc(NULL),rc(NULL),height(0),npl(1),color(RB_RED){}
	BinNode(T e,BinNode<T>* p = NULL,BinNode<T>* lc = NULL,BinNode<T>* rc = NULL,int h = 0,int l = 1,RBColor c = RB_RED):data(e),parent(p),lc(lc),rc(rc),height(h),npl(l),color(c){}
	
	int size();
	
	BinNode<T>* insertAsLC(T const&);
	BinNode<T>* insertAsRC(T const&);
	
	BinNode<T>* succ();
	
	template<VST> void travLevel(VST&);
	template<VST> void travPre(VST&);
	template<VST> void travIn(VST&);
	template<VST> void travPost(VST&);
	
	bool operator< (BinNode const& bn){return data < bn.data;}
	bool operator== (BinNode const& bn){return data == bn.data;}
	
	BinNode<T>* zig();
	BinNode<T>* zag();
	
};
#include "BinNode_implementation.h"