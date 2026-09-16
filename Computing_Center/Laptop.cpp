#include "Laptop.h"
#include <stdexcept>


Laptop::Laptop(const char* brand, const char* model, float frequency, const Architecture arc,
	unsigned ramGB, unsigned diskGB)
	: Device(brand, model, frequency, arc)
	, ramGB(0), diskGB(0)
{
	if (arc != Architecture::x86_64 && arc != Architecture::ARM) {
		throw std::invalid_argument("Architecture must be x86_64 and ARM!");
	}

	if (!setRamGB(ramGB) || !setDiskGB(diskGB)) {
		throw std::invalid_argument("Invalid arguments!");
	}
}

unsigned Laptop::getRamGB() const {
	return ramGB;
}

unsigned Laptop::getDiskGB() const {
	return diskGB;
}

bool Laptop::setRamGB(unsigned ramGB) {
	if (ramGB == 0) {
		return false;
	}

	this->ramGB = ramGB;
	return true;
}

bool Laptop::setDiskGB(unsigned diskGB) {
	if (diskGB == 0) {
		return false;
	}

	this->diskGB = diskGB;
	return true;
}

unsigned Laptop::compute(const uint8_t program[], size_t size) const {
	if (!program || size == 0) {
		return 0;
	}

	if (ramGB < size) {
		return 0;
	}

	unsigned result = 0;

	for (size_t i = 0; i < size; i++) {
		result += program[i];
	}
	return result;
}

Laptop* Laptop::clone() const {
	return new Laptop(*this);
}