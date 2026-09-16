#include "Device.h"
#include "StringUtils.hpp"

#include <iostream>
#include <stdexcept>

Device::Device(const char* brand, const char* model, float frequency, Architecture arc)
	: brand(nullptr), model(nullptr), frequency(frequency), arc(arc)
{
	if (!setBrand(brand) || !setModel(model) || !setFrequency(frequency)) {
		clearData();
		throw std::invalid_argument("Invalid arguments in Device constructor!");
	}
}

Device::Device(const Device& other)
	: Device(other.brand, other.model, other.frequency, other.arc) {}

Device& Device::operator=(const Device& other) {
	if (this != &other) {
		copyString(brand, other.brand);
		copyString(model, other.model);

		frequency = other.frequency;
	}
	return *this;
}

Device::~Device() noexcept {
	clearData();
}

const char* Device::getBrand() const {
	return brand;
}

const char* Device::getModel() const {
	return model;
}

float Device::getFrequency() const {
	return frequency;
}

Architecture Device::getArc() const {
	return arc;
}

bool Device::setBrand(const char* brand) {
	return copyString(this->brand, brand);
}

bool Device::setModel(const char* model) {
	return copyString(this->model, model);
}

bool Device::setFrequency(float frequency) {
	if (frequency <= 0.0) {
		return false;
	}
	this->frequency = frequency;
	return true;
}

void Device::clearData() {
	delete[] brand;
	delete[] model;
}