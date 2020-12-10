#pragma once
#include "variantENUM.h"
#include <string>

class Variant
{
public:

	VARIANT_TYPE type;
	std::string name;
	union {
		int i;
		float f;
			
	};

	Variant(std::string name, VARIANT_TYPE type) {
		this->name = name;
		this->type = type;
	}

	Variant() {

	}

	std::string getName() {
		return name;
	}

	int getType() {
		return (int) type;
	}

	int getI() {
		return i;
	}

	float getF() {
		return f;
	}



};

