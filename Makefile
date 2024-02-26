CFLAGS+=-Wall -Wextra -pedantic -ggdb

OUTDIR=./obj

SOURCE_DIR:=./src

INCLUDES:=./src

OBJS =\
	./obj/lexer.o\
	./obj/utils/string_builder.o\
	./obj/utils/vector.o\

$(OUTDIR)/%.o: $(SOURCE_DIR)/%.c
	-@mkdir -p ./obj/utils
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "compiling: [$<]"

all: $(OBJS) tiny 

tiny: main.c 
	@$(CC) $(CFLAGS) -o $@ $< $(OBJS) -I$(INCLUDES)
	@echo "compiling and linking main executable:" $@

clean:
	-@rm -rf ./obj/*