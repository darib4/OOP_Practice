#include "Laptop.h"
#include "IoT.h"
#include "ComputingCenter.h"

#include <iostream>
#include <stdexcept>


int main() {
	try {
		Laptop l1("Apple", "Model1", 3.6f, Architecture::ARM, 8192, 500000);
		Laptop l2("Lenovo", "Model2", 5.3f, Architecture::x86_64, 9000, 200000);

		IoT i1("IoT1", "IOT_Model1", 0.15f, Architecture::MIPS, "sensors1 min-calc");
		IoT i2("IoT2", "IOT_Model2", 0.30f, Architecture::RISC_V, "sensors2");

		ComputingCenter center;
		center.addDevice(l1);
		center.addDevice(l2);

		center.addDevice(i1);
		center.addDevice(i2);

		uint8_t program[] = { 10, 20, 30, 1, 45, 75, 8 };
		size_t programSize = sizeof(program) / sizeof(program[0]);

		center.totalCompute(program, programSize);

		std::cout << std::endl;


		std::cout << "Result after removing IoT:\n";
		center.removeDevice("IoT1");
		center.totalCompute(program, programSize);
	}

	catch (const std::exception& ex) {
		std::cerr << "Fatal error: " << ex.what() << '\n';
		return 1;
	}

	return 0;
}