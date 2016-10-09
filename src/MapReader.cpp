#include <MapReader.hpp>


vector<vector<int>> MapReader::BuildMap(const char* file){
	try{
		ifstream flux(file, ios::binary);
		if (!flux){ throw std::string("Erreur lecture fichier");}
		else{
			vector<vector<int>> res;

			int l = 0;
			string line;
			while(getline(flux, line)){
				res.push_back(vector<int>());
				for (int i = 0; i < line.size(); ++i)
				{
					int nb = line[i] - '0';
					res[l].push_back(nb);
				}
				++l;
			}

			return res;
		}
	}
	catch(std::string const& err){ std::cerr << err << "\n"; }
}