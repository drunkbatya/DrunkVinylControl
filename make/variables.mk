TARGET = DrunkVinylControl
DEBUG = 1
OPT = -Og
BUILD_DIR = build

C_SOURCES =  \
	src/main.c \
	src/midi.c \
	src/core.c \
	src/input.c \
	src/usb_device.c \
	src/usbd_conf.c \
	stm/Core/Src/stm32f4xx_it.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c \
	stm/Core/Src/system_stm32f4xx.c \
	stm/Core/Src/stm32f4xx_hal_msp.c \
	stm/USB_DEVICE/App/usbd_desc.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pcd_ex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
	stm/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
	stm/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
	stm/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
	stm/Middlewares/ST/STM32_USB_Device_Library/Class/MIDI/Src/usbd_midi.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c \
	stm/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c

ASM_SOURCES =  \
	stm/startup_stm32f411xe.s

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

CPU = -mcpu=cortex-m4

FPU = -mfpu=fpv4-sp-d16

FLOAT-ABI = -mfloat-abi=hard

MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

C_DEFS =  \
	-DUSE_FULL_LL_DRIVER \
	-DSTM32F411xE \
	-DUSE_HAL_DRIVER

C_INCLUDES =  \
	-Isrc \
	-Istm/Core/Inc \
	-Istm/Drivers/STM32F4xx_HAL_Driver/Inc \
	-Istm/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
	-Istm/Drivers/CMSIS/Include \
	-Istm/USB_DEVICE/App \
	-Istm/USB_DEVICE/Target \
	-Istm/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy \
	-Istm/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
	-Istm/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc \
	-Istm/Middlewares/ST/STM32_USB_Device_Library/Class/MIDI/Inc

CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"
LDSCRIPT = src/STM32F411CEUx_FLASH.ld

LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS += $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))


