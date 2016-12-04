#ifndef DEF_PROTOTYPE
#define DEF_PROTOTYPE

#include <memory>

using namespace std;

	/**
	 * 
	 * \brief Template abstract class implementation for the Prototype pattern.
	 * \author Florent ALAPETITE / Dorian LATOUCHE
	 *
	 *  Template abstract class used for the Prototype pattern. To used the pattern, a class must extends this class configured with the class type. Example : Gum extends Prototype<Gum>. To create new objects using the pattern, the method clone must be called.
	 *
 	*/	

template <class T>
class Prototype{
	
	public:
		/**
		 * virtual shared_ptr<T> clone(int posX,int posY)=0;
		 * \brief Abstract Prototype method used to instantiate a new T object. Change the created T object position to (posX,posY).
		 *
		 * \return shared_ptr<T> the new object created with the prototype.
		 */
		virtual shared_ptr<T> clone(int posX,int posY)=0;

};

#endif