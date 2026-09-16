#pragma once
#include "Device.h"

class ComputingCenter {
public:
	ComputingCenter();

	ComputingCenter(const ComputingCenter& other);

	ComputingCenter& operator=(const ComputingCenter& other);

	~ComputingCenter() noexcept;

	bool addDevice(const Device& d);

	bool removeDevice(const char* brand);

	void totalCompute(const uint8_t program[], size_t size) const;

private:
	static const size_t MAX_CAP = 16;

	Device* devices[MAX_CAP];
	size_t size;

private:
	void clearData();
};