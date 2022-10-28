#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include "HashTable.h"

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");
	int isThere {};

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");

	/* std::vector<string> vect;

	int i;
	for(i = 0; i < vect.end(); i++){
		if(find(vect.begin(), vect.end(), word)){
			continue;
		}
	}
	*/

	/*
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		// word est maintenant "tout propre"
		if (nombre_lu % 10000 == 0)
			// on affiche un mot "propre" sur 10000
			cout << nombre_lu << ": "<< word << endl;
	
	

		nombre_lu++;
	}
	*/

	// Question 2.
	/*
	vector<string> vect;
	// vector qui contient tous les mots différents rencontrés
	isThere = 0;
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		// vect.push_back(word);
		isThere = 0;
		for(size_t i = 0; i < vect.size(); ++i){

		 	if(word == vect[i]){
				isThere ++;
				break;
		 	}
		}
		if(isThere == 0){
				vect.push_back(word);
		}

		if (nombre_lu % 10000 == 0)
			// on affiche un mot "propre" sur 10000
			cout << nombre_lu << ": "<< word << endl;

		nombre_lu++;
	}

	cout << "There are " << vect.size() << "different words." << endl;
	*/

	// Question 3.
	vector<pair<string, int>> vect2;
	isThere = 0;
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		// vect.push_back(word);
		isThere = 0;
		for(size_t i = 0; i < vect2.size(); ++i){

		 	if(word == vect2[i].first){
				isThere ++;
				vect2[i].second ++;
				break;
		 	}
		}
		if(isThere == 0){
				vect2.push_back(pair<string, int> (word, 1));
		}

		if (nombre_lu % 10000 == 0)
			// on affiche un mot "propre" sur 10000
			cout << nombre_lu << ": "<< word << endl;

		nombre_lu++;
	}

	cout << "There are " << vect2.size() << " different words." << endl;

	string word_to_find1 {"war"};
	string word_to_find2 {"peace"};
	string word_to_find3 {"toto"};

	// auto find_word1 = find(vect2.begin(), vect2.end(), word_to_find1);
	// auto find_word2 = find(vect2.begin(), vect2.end(), word_to_find2);
	// auto find_word3 = find(vect2.begin(), vect2.end(), word_to_find3);

	int find_word1 {};
	int find_word2 {};
	int find_word3 {};

	for(size_t i = 0; i < vect2.size(); ++i){
		if(vect2[i].first == word_to_find1){
			find_word1 = vect2[i].second;
			break;
		}
	}
	for(size_t i = 0; i < vect2.size(); ++i){
		if(vect2[i].first == word_to_find2){
			find_word2 = vect2[i].second;
			break;
		}
	}
	for(size_t i = 0; i < vect2.size(); ++i){
		if(vect2[i].first == word_to_find3){
			find_word3 = vect2[i].second;
			break;
		}
	}

	cout << "The word \"" << word_to_find1 << "\" is repeated " << find_word1 << " times in the text file." << endl;
	cout << "The word \"" << word_to_find2 << "\" is repeated " << find_word2 << " times in the text file." << endl;
	cout << "The word \"" << word_to_find3 << "\" is repeated " << find_word3 << " times in the text file." << endl;
	



	// Question 5. Table de Hash

	HashTable<string, int> map;
	


	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;

    return 0;
}





/*
Question 1.
	Il y a 566193 mots.


Question 4.
	Complexité O(n).
	On aurait pu utiliser la table de Hash pour diminuer la complexité à O(1).
*/