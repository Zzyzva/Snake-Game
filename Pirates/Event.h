#pragma once

#include "Variant.h"
#include "variantENUM.h"
#include <string>
#include <vector>
#include "json.h"
#include <iostream>

using json = nlohmann::json;

class Event
{
	std::string name;
	std::vector<Variant*>* params;
	long handleTime;
	
public:
	int id; //ID of the client/ server who raised it

	int getHandleTime() {
		return handleTime;
	}

	void setHandleTime(long time) {
		handleTime = time;
	}

	std::string getName() {
		return name;
	}

	std::vector<Variant*>* getParams() {
		return params;
	}

	std::vector<Variant*> getParamsByValue() {
		return *params;
	}


	void addParam(Variant* p) {
		params->push_back(p);
	}

	Event(std::string name, long time, int id) {
		this->name = name;
		this->params = new std::vector<Variant*>;
		this->handleTime = time;
		this->id = id;
	}

	Event(json JSON, int id) {
		this->params = new std::vector<Variant*>;
		this->name = JSON["EVENTS"][std::to_string(id)]["NAME"];
		this->handleTime = JSON["EVENTS"][std::to_string(id)]["TIME"];
		int count = JSON["EVENTS"][std::to_string(id)]["COUNT"];
		this->id = JSON["EVENTS"][std::to_string(id)]["ID"];
		for (int i = 0; i < count; i++) {
			Variant* v = new Variant;
			v->name = JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["NAME"];
			v->type = JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["TYPE"];

			if (v->type == VARIANT_TYPE::VINT) {
				v->i = JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["VALUE"];
			}
			else if (v->type == VARIANT_TYPE::VFLOAT) {
				v->f = JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["VALUE"];
			}

			this->addParam(v);
		}
	}

	json addToJson(json JSON, int id) {
		JSON["EVENTS"][std::to_string(id)]["NAME"] = this->name;
		JSON["EVENTS"][std::to_string(id)]["TIME"] = this->handleTime;
		JSON["EVENTS"][std::to_string(id)]["COUNT"] = params->size();
		JSON["EVENTS"][std::to_string(id)]["ID"] = this->id;
		int i = 0;
		for (Variant* v : *params){
			JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["NAME"] = v->name;
			JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["TYPE"] = v->type;

			if (v->type == VARIANT_TYPE::VINT) {
				JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["VALUE"] = v->i;
			}
			else if (v->type == VARIANT_TYPE::VFLOAT) {
				JSON["EVENTS"][std::to_string(id)][std::to_string(i)]["VALUE"] = v->f;
			}
			i++;
		}
		return JSON;
	}

	~Event() {
		for(Variant* v : *params) {
			delete v;
		}
		delete params;
	}
	
};

