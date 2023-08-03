static: seal_bool.h seal_stringConcatenation_C.h coding\ competition\ common.h lib_Roman.h from\ Roman\ numerals.c to\ Roman\ numerals.c
	gcc -c from\ Roman\ numerals.c
	gcc -c to\ Roman\ numerals.c
	-[ -f lib_Roman.a ] && rm lib_Roman.a # Yes, I'm aware that `-rm lib_Roman.a` would be shorter.
	ar -cq lib_Roman.a from\ Roman\ numerals.o
	ar -q lib_Roman.a to\ Roman\ numerals.o
	rm from\ Roman\ numerals.o
	rm to\ Roman\ numerals.o

static_PowerPC: static
	-[ -f lib_Roman.PPC.a ] && rm lib_Roman.PPC.a # Yes, I'm aware that `-rm lib_Roman.PPC.a` would be shorter.
	mv lib_Roman.a lib_Roman.PPC.a
