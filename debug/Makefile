CC            = gcc
CFLAGS        =-g -Wall -Wextra -pedantic -std=c17 -D_GNU_SOURCE -D_DEBUG -D_UNIT_TEST -I./include
#-L # GLFW -L/opt/homebrew/opt/glfw/lib
LDFLAGS       = -L/opt/homebrew/opt/sdl2/lib
#-l
LDLIBS        = -lm -lpthread -lSDL2 -framework OpenGL
#-I GLFW -I/opt/homebrew/opt/glfw/include
INCLUDE_PATHS = -I/opt/homebrew/opt/sdl2/include  -I./include
CFLAGS += $(INCLUDE_PATHS)
# Makefile settings - Can be customized.
APPNAME = TETRIS_MAIN
EXT = .c
SRCDIR = src
OBJDIR = obj

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

all: $(APPNAME)

$(APPNAME): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
# $(RM) $(DELOBJ) $(DEP) $(APPNAME)
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(APPNAME)

#################### Cleaning rules for Windows OS #####################
# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

