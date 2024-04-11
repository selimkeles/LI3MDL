# AAC-Clydespace Avionics Software Challenge
You are given the LIS3MDLTR 3-Axis Magnetometer sensor. The data sheet is
located at `doc/lism3mdl.pdf`

## Task Description
Please write a device driver that implements the following API:
- Get the full-scale configuration
- Get and set the output data rate
- Enable or disable the interrupt pin
- Read the output data of a specified axis

## Solution
- Used X-MACROS for register handling
- Tried error notifiers
- I2C library could be extended to provide better error handling and identifying exceptions
- For RTOS usage I2C function should consider bus access issues.