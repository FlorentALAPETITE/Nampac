#include <MapReader.hpp>


vector<vector<char>> MapReader::BuildMap(const char* file){
	try{
		ifstream flux(file, ios::binary);
		if (!flux){ throw std::string("Erreur lecture fichier");}
		else{
			vector<vector<char>> res;

			int l = 0;
			string line;
			while(getline(flux, line)){
				res.push_back(vector<char>());
				for (unsigned int i = 0; i < line.size(); ++i)
				{
					char nb = line[i];
					res[l].push_back(nb);
				}
				++l;
			}

			return res;
		}
	}
	catch(std::string const& err){ std::cerr << err << "\n"; }
		return vector<vector<char>>();
}