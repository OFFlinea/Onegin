CC = g++

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJECTS = sort.o text.o file.o Onegin.o


all: Onegin.exe


Onegin.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o Onegin.exe


sort.o: sort.cpp sort.h
	$(CC) $(CFLAGS) sort.cpp


file.o: file.cpp file.h
	$(CC) $(CFLAGS) file.cpp


text.o: text.cpp text.h
	$(CC) $(CFLAGS) text.cpp


Onegin.o: Onegin.cpp structures.h
	$(CC) $(CFLAGS) Onegin.cpp
