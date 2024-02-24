CFLAGS+=-Wall -Wextra -pedantic -ggdb -O2

OUTDIR=./obj

SOURCE_DIR:=./src

OBJS =\
	./obj/utils/string_builder.o\
	./obj/lexer.o\
	./obj/tiny.o

$(OUTDIR)/%.o: $(SOURCE_DIR)/%.c
	-@mkdir -p ./obj/utils
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiling: [$<]"

all: $(OBJS) tiny 

tiny: $(SOURCE_DIR)/tiny.c 
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo "Compiling and linking main executable"

clean:
	-@rm -rf ./obj/*