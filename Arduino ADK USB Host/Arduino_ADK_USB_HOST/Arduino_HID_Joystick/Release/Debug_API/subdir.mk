################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Debug_API/Debug_LED_Function.cpp 

OBJS += \
./Debug_API/Debug_LED_Function.o 

CPP_DEPS += \
./Debug_API/Debug_LED_Function.d 


# Each subdirectory must supply rules for building sources it contributes
Debug_API/%.o: ../Debug_API/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Applications/Development/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino" -I"/Applications/Development/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/mega" -I"/Volumes/DataHDD/Documents/4th Year Project/Black-Box-Mouse-Interface/Arduino ADK USB Host/Arduino_ADK_USB_HOST/Arduino_HID_Joystick" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=100 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


