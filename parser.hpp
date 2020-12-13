#include "cssclass.hpp"

using std::string;

#pragma once

static dom parsecss(string css) {
	dom document;
	int i = 0;
	int track = 0;
	cssel el = *(new cssel());
	typecss type = *(new typecss());
	while (i < css.length()) {
		if (track == 0) {
			if (css[i] != ' ' && css[i] != '\n' && css[i] != '	') {
				if (css[i] == '.') {
					el.type = "c";
					el.tag += css[i];
				}
				else if (css[i] == '#') {
					el.type = "i";
					el.tag += css[i];
				}
				else {
					el.type = "e";
					el.tag += css[i];
				}
				track++;
			}
		} else if (track == 1) {
			if (css[i] != '{' && css[i] != ' ' && css[i] != '\n') {
				el.tag += css[i];
			}
			else if(css[i] == '{'){
				track++;
			}
		}
		else if (track == 2) {
			if (css[i] == ':') {
				track++;
			}
			else if (css[i] == ' ' || css[i] == '\n') {

			}
			else if (css[i] == '}') {
				if (type.name != "") {
					bool found = false;
					for (int j = 0; j < el.elements; j++) {
						if (el.types[j].name == type.name) {
							found = true;
							el.types[j].value = type.value;
						}
					}
					if (!found) {
						el.types.push_back(type);
						el.elements++;
					}
				}
				if (el.tag != "") {
					document.el.push_back(el);
					document.elements++;
				}
				el = *(new(cssel));
				type = *(new(typecss));
				track = 0;
			}
			else {
				type.name += css[i];
			}
		}
		else if (track == 3) {
			if (css[i] == ';') {
				bool found = false;
				for (int j = 0; j < el.elements; j++) {
					if (el.types[j].name == type.name) {
						found = true;
						el.types[j].value = type.value;
					}
				}
				if (!found) {
					el.types.push_back(type);
					el.elements++;
				}
				type = *(new typecss());
				track--;
			}
			else if (css[i] == ' ' || css[i] == '\n') {

			}
			else if (css[i] == '}') {
				if (type.name != "") {
					bool found = false;
					for (int j = 0; j < el.elements; j++) {
						if (el.types[j].name == type.name) {
							found = true;
							el.types[j].value = type.value;
						}
					}
					if (!found) {
						el.types.push_back(type);
						el.elements++;
					}
				}
				if (el.tag != "") {
					document.el.push_back(el);
					document.elements++;
				}
				el = *(new(cssel));
				type = *(new(typecss));
				track = 0;
			}
			else {
				type.value += css[i];
			}
		}
		i++;
	}
	if (track != 0) {
		std::cout << "Warning: Unexpected End Of File";
	}
	return document;
}