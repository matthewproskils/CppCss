#pragma once
#include <iostream>
#include <vector>

#pragma once

class typecss {
public:
	typecss() : name(""), value(""){}
	std::string name = "";
	std::string value = "";
};

class cssel {
public:
	cssel() : type(""), tag(""), types({}), elements(0){}
	std::string type = ""; //Element (e), Class (c), ID (i)
	std::string tag = "";
	std::vector< typecss > types = {};
	inline typecss find(std::string name) {
		bool found = false;
		typecss returnvalue;
		for (int j = 0; j < this->elements; j++) {
			if (this->types[j].name == name) {
				found = true;
				returnvalue = this->types[j];
			}
		}
		return returnvalue;
	};
	int elements = 0;
};

class dom {
public:
	std::vector< cssel > el = {};
	int elements = 0;
	inline cssel find(std::string name) {
		bool found = false;
		cssel returnvalue;
		for (int j = 0; j < this->elements; j++) {
			if (this->el[j].tag == name) {
				found = true;
				returnvalue = this->el[j];
			}
		}
		return returnvalue;
	};
};
