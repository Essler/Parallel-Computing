CC         = gcc
CINCS      =
CLIBS      = -lspe2 -pthread
CFLAGS     = -Wall

SPU_CC     = spu-gcc
SPU_CINCS  =
SPU_CLIBS  =
SPU_CFLAGS = -Wall

all: multi_vec_abs_ppe.elf vec_abs_spe.elf

multi_vec_abs_ppe.elf: multi_vec_abs_ppe.c
	$(CC) $(CFLAGS) $(CINCS) $(CLIBS) $^ -o $@

vec_abs_spe.elf: vec_abs_spe.c
	$(SPU_CC) $(SPU_CFLAGS) $(SPU_CINCS) $(SPU_CLIBS) $^ -o $@

clean:
	rm -f *.elf
