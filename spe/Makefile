all: hello_ppe.elf hello_spe.elf

hello_ppe.elf: hello_ppe.c
	gcc -lspe2 $^ -o $@

hello_spe.elf: hello_spe.c
	spu-gcc $^ -o $@

clean:
	rm -f *.elf
