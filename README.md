# STM32BackupRegs

A library for STM32 backup registers.

* **`uint32_t getRegister(uint32_t index)`** Reads a 32-bit value from the specified register
* **`void setRegister(uint32_t index, uint32_t value)`** Writes a 32-bit value to the specified register
* **`REGISTER_COUNT`** Constant that holds the number of backup registers available in hardware
