#include "ComputingCenter.h"
#include <iostream>
#pragma warning (disable : 4996)


ComputingCenter::ComputingCenter() : size(0) {
	for (size_t i = 0; i < MAX_CAP; i++) {
		devices[i] = nullptr;
	}
}

ComputingCenter::ComputingCenter(const ComputingCenter& other) : size(other.size) {
	for (size_t i = 0; i < MAX_CAP; i++) {
		devices[i] = nullptr;
	}

	for (size_t i = 0; i < other.size; i++) {
		try {
			devices[i] = other.devices[i]->clone();
		}
		catch (...) {
			clearData();
			throw;
		}
	}
}

ComputingCenter& ComputingCenter::operator=(const ComputingCenter& other) {
	if (this != &other) {
		ComputingCenter copy(other);
		std::swap(size, copy.size);

		for (size_t i = 0; i < MAX_CAP; i++) {
			std::swap(devices[i], copy.devices[i]);
		}
	}
	return *this;
}

ComputingCenter::~ComputingCenter() noexcept {
	clearData();
}

bool ComputingCenter::addDevice(const Device& d) {
	if (size >= MAX_CAP) {
		return false;
	}

	Device* newDevice = nullptr;
	newDevice = d.clone();

	if (!newDevice) {
		return false;
	}

	devices[size++] = newDevice;
	return true;
}

bool ComputingCenter::removeDevice(const char* brand) {
	if (!brand || !*brand) {
		return false;
	}

	bool removed = false;

	for (size_t i = 0; i < size; i++) {
		if (strcmp(devices[i]->getBrand(), brand) == 0) {
			delete devices[i];
			devices[i] = devices[size - 1];
			size--;
			removed = true;
			i--;
		}
	}
	return removed;
}

void ComputingCenter::totalCompute(const uint8_t program[], size_t size) const {
	for (size_t i = 0; i < this->size; i++) {
		unsigned result = devices[i]->compute(program, size);

		std::cout << result << std::endl;
	}
}

void ComputingCenter::clearData() {
	for (size_t i = 0; i < size; i++) {
		delete devices[i];
		devices[i] = nullptr;
	}
}