#ifndef DEF_MAPREADER
#define DEF_MAPREADER

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class MapReader{
	public:	
		static vector<vector<int>> BuildMap(const char* fichier);
};





#endif