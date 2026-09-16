#pragma once
#include "Device.h"

class IoT : public Device {
public:
	IoT(const char* brand, const char* model, float frequency, const Architecture arc,
		const char* sensors);

	IoT(const IoT& other);

	IoT& operator=(const IoT& other);

	~IoT() noexcept;

	const char* getSensors() const;

	bool setSensors(const char* sensors);

	unsigned compute(const uint8_t program[], size_t size) const override;

	IoT* clone() const override;

private:
	char* sensors;

private:
	static bool isSpace(char ch);

	static bool containsWord(const char* text, const char* word);
};