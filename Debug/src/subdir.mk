################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/EasyComputer.cpp \
../src/HardComputer.cpp \
../src/HumanPlayer.cpp \
../src/Player.cpp \
../src/Player2.cpp \
../src/Player2Factory.cpp \
../src/main.cpp 

OBJS += \
./src/Ball.o \
./src/EasyComputer.o \
./src/HardComputer.o \
./src/HumanPlayer.o \
./src/Player.o \
./src/Player2.o \
./src/Player2Factory.o \
./src/main.o 

CPP_DEPS += \
./src/Ball.d \
./src/EasyComputer.d \
./src/HardComputer.d \
./src/HumanPlayer.d \
./src/Player.d \
./src/Player2.d \
./src/Player2Factory.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


