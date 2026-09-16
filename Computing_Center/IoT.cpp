#include "IoT.h"
#include "StringUtils.hpp"
#include <stdexcept>

#pragma warning (disable : 4996)


IoT::IoT(const char* brand, const char* model, float frequency, const Architecture arc,
	const char* sensors)
	: Device(brand, model, frequency, arc)
	, sensors(nullptr)
{
	if (!setSensors(sensors)) {
		throw std::invalid_argument("Invalid sensors!");
	}
}

IoT::IoT(const IoT& other) : Device(other), sensors(nullptr) {
	copyString(sensors, other.sensors);
}

IoT& IoT::operator=(const IoT& other) {
	if (this != &other) {
		Device::operator=(other);

		copyString(sensors, other.sensors);
	}
	return *this;
}

IoT::~IoT() noexcept {
	delete[] sensors;
}

const char* IoT::getSensors() const {
	return sensors;
}

bool IoT::setSensors(const char* sensors) {
	if (!sensors || !*sensors) {
		return false;
	}

	return copyString(this->sensors, sensors);
}

unsigned IoT::compute(const uint8_t program[], size_t size) const {
	if (!program && size != 0) {
		throw std::invalid_argument("Invalid arguments!");
	}

	if (size == 0) {
		return 0;
	}

	if (!containsWord(sensors, "min-calc")) {
		return 0;
	}

	uint8_t minValue = program[0];

	for (size_t i = 0; i < size; i++) {
		if (program[i] < minValue) {
			minValue = program[i];
		}
	}
	return minValue;
}

IoT* IoT::clone() const {
	return new IoT(*this);
}

bool IoT::isSpace(char ch) {
	return ch == ' ' || ch == '\n';
}

bool IoT::containsWord(const char* text, const char* word) {
	if (!text || !word || !*word) {
		return false;
	}

	const char* current = text;

	while (*current) {
		while (*current && isSpace(*current)) {
			current++;
		}
		if (!*current) {
			return false;
		}
		const char* start = current;

		while (*current && !isSpace(*current)) {
			current++;
		}
		const char* end = current;

		size_t tokenLen = (size_t)(end - start);
		size_t wordLen = strlen(word);

		if (tokenLen == wordLen && strncmp(start, word, wordLen) == 0) {
			return true;
		}
	}
	return false;
}