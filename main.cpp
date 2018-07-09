#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <locale>
#include <iostream>
#include <fstream>

typedef std::set<std::string> WordSet;
typedef std::map<std::string, int> WordCountMap;

WordSet readCommonWords();

WordCountMap processFile(const std::string &fname, const WordSet &common);

void toLowerCase(std::string &word);

/**
 * readCommonWords
 * This method reads the list of common words to ignore and places them in a set of strings
 *
 * pre:  a valid file name with 1 word per line, words all in lower case
 * post: all words int the file are placed in the WordSet
 */
WordSet readCommonWords() {
    WordSet com;
    std::string fname = "com.txt";
    std::string str;
    std::ifstream file(fname.c_str());
    // Do error checking here
    if (!file) {
        std::cout << "Unable to open file. Press enter to exit program.";
        getline(std::cin, str);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }
    std::string inserter;
    while (file >> inserter) {
        com.insert(inserter);
    }
    file.close();
    return com;
}

/**
 * processFile
 * This function reads in all words from the given file
 * after reading a word it converts it to lower case,
 * removes non alphabetic characters and stems it to STEM_LENGTH.
 * If the resulting word is considered common it is ignored.
 * Otherwise, the count in the map that matches the word
 * is incremented.
 *
 * pre:  the name of a text file and a set of words to be ignored.
 * post: The file has been read; a map of cleansed words is created and returned
 *
 */
WordCountMap processFile(const std::string &fname, const WordSet &common, size_t &count) {
    WordCountMap wordMap;
    std::string str;
    std::ifstream file(fname.c_str());
    if (!file) {
        std::cout << "Unable to open file. Press enter to exit program.";
        getline(std::cin, str);  // consume existing line
        std::cin.get();  // get the key press
        exit(1);
    }

    std::string nextWord;
    while (file >> nextWord) {
        count++;
        toLowerCase(nextWord);
        if (nextWord.length() == 0 || (common.count(nextWord) > 0)) {
            continue;
        } else {
            ++wordMap[nextWord];
        }
    }
    file.close();
    return wordMap;
}

 /**
  * toLowerCase
  * Converts a string into lowercase and also removes any non-letters from the string
  * pre: none
  * post: returns a string with all letters from first string in original order and all lowercase
  */
void toLowerCase(std::string &word) {
    for (size_t i = 0; i < word.length(); i++){
        if (word.length() > 0) {
            char changer = word[i];
            word[i] = std::tolower(changer);
        }
    }
}

int main() {
    WordSet common = readCommonWords();
    std::string inFile = "";
    std::cout << "Please enter the name/path of the file to be processed." << std::endl;
    std::cin >> inFile;
    size_t *numWordsTotal = new size_t(0);
    WordCountMap results = processFile(inFile, common, *numWordsTotal);
    std::cout << *numWordsTotal;
    WordCountMap::const_iterator it1 = results.begin();
    std::cout << "Your frequently used words are: " << std::endl;
    while (it1 != results.end()) {
        if ((double) it1->second / (double)*numWordsTotal > .005) {
            std::cout << it1->first << std::endl;
        }
        it1++;
    }
    std::cout << "You should visit www.thesaurus.com to find some replacements for those "
            "words" << std::endl;
    return 0;
}
