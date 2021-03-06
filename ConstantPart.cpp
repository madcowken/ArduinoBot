

#include "ConstantPart.h"
#include <Arduino.h>


ConstantPart::ConstantPart(const char* constant_out, int val){
	this->constant_out_name = (char *)constant_out;
	this->const_val_int = val;
	this->usingInt = true;
}

ConstantPart::ConstantPart(const char* constant_out, float val){
	this->constant_out_name = (char *)constant_out;
	this->const_val_float = val;
	this->usingInt = false;
}

void* ConstantPart::getOutputValue(char* name){
	if(debug){
		Serial.print("ConstantPart asked for '");
		Serial.print(name);
		Serial.println("'");
	}
	if(this->sameName(name, this->constant_out_name)){
		if(this->usingInt){
			if(debug){
				Serial.print("ConstantPart-'");
				Serial.print(name);
				Serial.println("'");
				Serial.print(this->const_val_int);
				Serial.println("");
			}
			return &this->const_val_int;
		}else{
			if(debug){
				Serial.print("ConstantPart-'");
				Serial.print(name);
				Serial.print("': ");
				Serial.print(this->const_val_float);
				Serial.println("");
			}
			return &this->const_val_float;
		}
	}
	return nullptr;
}


void ConstantPart::Update(){
	if (debug) {
		Serial.print("Updating called for constant: ");
		if(usingInt){
			Serial.println(this->const_val_int);
		}else{
			Serial.println(this->const_val_float);
		}
	}
}
