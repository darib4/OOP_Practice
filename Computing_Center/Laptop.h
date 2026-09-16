#pragma once

#include "Device.h"

class Laptop : public Device {
public:
	Laptop(const char* brand, const char* model, float frequency, const Architecture arc,
		unsigned ramGB, unsigned diskGB);

	unsigned getRamGB() const;

	unsigned getDiskGB() const;

	bool setRamGB(unsigned ramGB);

	bool setDiskGB(unsigned diskGB);

	unsigned compute(const uint8_t program[], size_t size) const override;

	Laptop* clone() const override;

private:
	unsigned ramGB;
	unsigned diskGB;
};