# -*- Makefile -*-

programmer = avrispmkII
target_mcu = atmega328p
target_partno = m328p
#f_cpu = 20000000L
f_cpu = 16000000L
#f_cpu = 8000000L

all: compile upload

compile: bin/output.hex

bin/output.hex: bin/main.o bin/pinouts.o bin/fuses.o bin/parallel_programming.o
	avr-gcc -mmcu=$(target_mcu) bin/pinouts.o bin/fuses.o bin/parallel_programming.o bin/main.o -o bin/output.elf
	avr-objcopy -j .text -j .data -O ihex bin/output.elf bin/output.hex

bin/main.o: src/main.c
	avr-gcc --param=min-pagesize=0 -D F_CPU='$(f_cpu)' -Wall -Os -mmcu=$(target_mcu) -c src/main.c -o bin/main.o

bin/pinouts.o: src/pinouts.c
	avr-gcc --param=min-pagesize=0 -D F_CPU='$(f_cpu)' -Wall -Os -mmcu=$(target_mcu) -c src/pinouts.c -o bin/pinouts.o

bin/fuses.o: src/fuses.c
	avr-gcc --param=min-pagesize=0 -D F_CPU='$(f_cpu)' -Wall -Os -mmcu=$(target_mcu) -c src/fuses.c -o bin/fuses.o

bin/parallel_programming.o: src/parallel_programming.c
	avr-gcc --param=min-pagesize=0 -D F_CPU='$(f_cpu)' -Wall -Os -mmcu=$(target_mcu) -c src/parallel_programming.c -o bin/parallel_programming.o

upload:
	avrdude -v -c $(programmer) -p$(target_partno) -U flash:w:bin/output.hex:i

clean:
	rm bin/*.o bin/*.hex bin/*.elf
