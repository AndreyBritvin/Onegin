COMP_MODE = DEBUG
IS_STALIN = -DNO_STALIN

CC = g++

DEBUG_FLAG = -DDEBUG_MODE $(IS_STALIN)
HEADERS_INCLUDE_FILE = -Iinclude/file
HEADERS_INCLUDE_STR = -Iinclude/strings $(HEADERS_INCLUDE_FILE)

DEBUG_FLAGS = -lm $(DEBUG_FLAG) -Iinclude -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
RELEASE_FLAGS = -lm -Iinclude -std=c++17 -O3

ifeq ($(COMP_MODE), DEBUG)
CFLAGS = $(DEBUG_FLAGS)
else
CFLAGS = $(RELEASE_FLAGS)
endif

all: a.out # double_procedures.o square_solver.o square_unit_test.o mode_parser.o main.o

a.out: build/main.o build/read_from_file.o build/sort_strings.o build/swap_strings.o build/write_to_file.o build/my_errors.o
	@$(CC) $(CFLAGS) build/main.o build/sort_strings.o build/swap_strings.o build/read_from_file.o \
					 build/write_to_file.o build/my_errors.o

build/main.o: src/main.cpp
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) $(HEADERS_INCLUDE_FILE) -c src/main.cpp -o build/main.o

build/read_from_file.o: src/file/read_from_file.cpp include/file/read_from_file.h
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/file/read_from_file.cpp -o build/read_from_file.o

build/sort_strings.o: src/strings/sort_strings.cpp include/file/write_to_file.h
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) -c src/strings/sort_strings.cpp -o build/sort_strings.o

build/swap_strings.o: src/strings/swap_strings.cpp
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) -c src/strings/swap_strings.cpp -o build/swap_strings.o

build/write_to_file.o: src/file/write_to_file.cpp include/file/write_to_file.h
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/file/write_to_file.cpp -o build/write_to_file.o

build/my_errors.o: src/my_errors.cpp include/my_errors.h
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/my_errors.cpp -o build/my_errors.o

comp_all:
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/file/write_to_file.cpp -o build/write_to_file.o
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) -c src/strings/swap_strings.cpp -o build/swap_strings.o
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) -c src/strings/sort_strings.cpp -o build/sort_strings.o
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/file/read_from_file.cpp -o build/read_from_file.o
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_FILE) -c src/my_errors.cpp -o build/my_errors.o
	@$(CC) $(CFLAGS) $(HEADERS_INCLUDE_STR) $(HEADERS_INCLUDE_FILE) -c src/main.cpp -o build/main.o
	make

run:
	./a.out texts/input/onegin_english.txt texts/output/onegin_full_2.txt

clean:
	rm a.out
