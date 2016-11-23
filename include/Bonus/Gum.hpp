#ifndef DEF_GUM
#define DEF_GUM

#include <Bonus/Bonus.hpp>
#include <SDL2/SDL.h>
#include <Prototype/Prototype.hpp>

using namespace std;

/**
 * \brief Concrete bonus Gum implementation for the Nampac game.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Concrete bonus implementation : Gum. The Gum is the basic bonus (no game modifications done when picked). Add +50 pts to the player score. End the game when there's no more Gum to eat.
 *
 */	
class Gum : public Bonus , public Prototype<Gum>{

	public:

		/**
		* Gum(SDL_Renderer* renderer, int posX, int posY);
		* \brief Gum constructor.
		*
		* \param renderer : unique SDL_Renderer used to render the game.
		* \param posX : X position in the 700x775 map. 
		* \param posY : Y position in the 700x775 map.
		*/
		Gum(SDL_Renderer* renderer,int posX, int posY);	

		/**
		 * Gum(const Gum &bonus);
		 * \brief Gum copy constructor.
		 * \param bonus : gum bonus to copy;
		*/
		Gum(const Gum &bonus);

		/**
		 * int getPoint() override;
		 * \brief Point getter.
		 *
		 * \return int : 50 pts
		  */
		int getPoint() override;

		/**
		 * char getBonusType() override;
		 * \brief Bonus type getter.
		 * \return char : '0' : gum bonus type.
		 */
		char getBonusType() override;

		/**
		 *  shared_ptr<Gum> clone(int posX,int posY) override;
		 * \brief Prototype method used to instantiate a new Gum object. Change the created Gum position to (posX,posY).
		 *
		 * \return shared_ptr<Gum> the new object created with the prototype.
		 */
		shared_ptr<Gum> clone(int posX,int posY) override;

};

#endif