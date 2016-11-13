#ifndef DEF_PROTOTYPE
#define DEF_PROTOTYPE

#include <memory>

using namespace std;

template <class T>
class Prototype{
	
	public:
		virtual shared_ptr<T> clone(int,int)=0;

};

#endif