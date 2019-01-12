All:
	arm-none-eabi-gcc -g -c start.S -o start.o
	arm-none-eabi-gcc -g -c main.c -o main.o
	arm-none-eabi-ld -T0x08000000 start.o main.o -o nuttx
	arm-none-eabi-objcopy -O binary -S nuttx nuttx.bin
	arm-none-eabi-objdump -D -m arm  nuttx > nuttx.dis
All_mini:
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c start.S -o start.o
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c main.c -o main.o
	arm-none-eabi-ld -T0x08000000 start.o main.o -o nuttx
	arm-none-eabi-objcopy -O binary -S nuttx nuttx.bin
	arm-none-eabi-objdump -D -m arm  nuttx > nuttx.dis
clean:
	-rm start.o nuttx nuttx.bin

flash: All_mini
	sudo stm32flash -w nuttx.bin -v -g 0 /dev/ttyUSB0
