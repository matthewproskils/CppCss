#include <iostream>
#include <vector>
#include <fstream>
#include "cssclass.hpp"
#include "parser.hpp"

using std::string;

string ReadFile(std::string name) {
	std::fstream file = std::fstream(name);

	string text = "";

	while (file.good())
		text += file.get();

	file.close();

	return text.substr(0, text.length() - 1);
}

int main() {
	dom document = parsecss(ReadFile("style.css"));
	std::cout << document.find("body").types[0].value;
}