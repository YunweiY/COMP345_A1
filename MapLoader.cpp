#include "Map.h"
#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

Map MapLoader::readMap(string mapFile) {
		try {
			Map map;
			ifstream file(mapFile);
			vector <string> continentsList;
			vector<string> territoryList;
			string str;
			//moving to continents
			while (getline(file, str) && str != "[continents]") {}
			while (getline(file, str) && !str.empty()) {
				string continent = str.substr(0, str.find(" "));
				continentsList.push_back(continent);
				map.addContinent(new Continent(continent));
			}
			//moving to Territory
			while (getline(file, str) && str != "[countries]") {}
			while (getline(file, str) && !str.empty()) {
				stringstream st(str);
				string w;
				vector<string> LSplit;
				while (getline(st, w, ' ')) {
					LSplit.push_back(w);
				}
				territoryList.push_back(LSplit[1]);
				int continentIndex = stoi(LSplit[2]) - 1;
				map.addTerritory(new Territory(LSplit[1], map.getContinents()[continentIndex]));
			}
			//moving to Borders
			while (getline(file, str) && str != "[borders]") {}
			while (getline(file, str) && !str.empty()) {
				stringstream st(str);
				string w;
				vector<string> LSplit;
				while (getline(st, w, ' ')) {
					LSplit.push_back(w);
				}
				for (int i = 1; i < LSplit.size(); i++) {
				    map.getTerritories()[stoi(LSplit[0]) - 1]->addNeighbour(map.getTerritories()[stoi(LSplit[i]) - 1]);
				}
			}
			if (map.validate()) {
			    map.print();
				return map;
			}
			else {
				cerr << "This map is invalid!" << endl;
				return 0;
			}

		}
		catch (...) {
			cerr << "This map file contains some errors." << endl;
		}
	
}
