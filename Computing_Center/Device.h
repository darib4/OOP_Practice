#pragma once
#include<iostream>

enum class Architecture {
	x86_64,
	ARM,
	RISC_V,
	MIPS,
	Other_RISC,
	Other_CISC,
};

class Device {
public:
	Device(const char* brand, const char* model, float frequency, Architecture arc);

	Device(const Device& other);

	Device& operator=(const Device& other);

	virtual ~Device() noexcept;

	const char* getBrand() const;

	const char* getModel() const;

	float getFrequency() const;

	Architecture getArc() const;

	bool setBrand(const char* brand);

	bool setModel(const char* model);

	bool setFrequency(float frequency);

	virtual unsigned compute(const uint8_t program[], size_t size) const = 0;

	virtual Device* clone() const = 0;

private:
	char* brand;
	char* model;
	float frequency;
	const Architecture arc;

private:
	void clearData();
};