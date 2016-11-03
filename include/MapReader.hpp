#ifndef DEF_MAPREADER
#define DEF_MAPREADER

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


/**
 * \file MapReader.cpp
 * \brief Labyrinth file reader.
 * \author Florent ALAPETITE / Dorian LATOUCHE
 *
 * Static labyrinth file (.laby) reader;
 *
 */


class MapReader{
	public:	

		/**
		 * static vector<vector<int>> BuildMap(const char* file);
		 * \brief Static method used to build an integer representation of the map contained in the file given.
		 *
		 * \param file .laby file containing an integer representation of a map.
		 * \return Vector of vector of integer : map integer representation used to build a graphical labyrinth.
		 */
		static vector<vector<char>> BuildMap(const char* fichier);
};





#endif