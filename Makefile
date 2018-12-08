# Determine the platform
PLAT_NAME := $(shell uname -s)
# CC
ifeq ($(PLAT_NAME),Darwin)
	CC=clang++ -arch x86_64
else
	CC=g++
endif

# Folders
SRCDIR := src
BUILDDIR := build
APPDIR := bin

# Target
EXECUTABLE := sfml-app
APP := $(APPDIR)/$(EXECUTABLE)

# Code properties
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Headers path
#INCDIRS := $(shell find include/**/* -name '*.hpp' -o -name '*.h' -exec dirname{} \; | sort | uniq)
INCDIRS := $(shell find include/**/* \( -name '*.hpp' -o -name '*.h' \) -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))

INC := -I include $(INCLIST)
FRAMEWORKS:= -framework Foundation
LIB:= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lstdc++

#CFLAGS=-c -std=c++1z -Wall -Werror -g -v
CFLAGS=-c
#LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
#INC := -I include

$(APPDIR): $(OBJECTS)
	@mkdir -p $(APPDIR)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(APP) $(LIB)"
	@echo "   Linking $(APPDIR)"; $(CC) $^ -o $(APP) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" 
	@echo "Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

#.PHONY: clean
#all:
#	@echo "$(SOURCES)"
#	@echo "$(OBJECTS)"
#	@echo ""
#	@echo "$(INCDIRS)"
#	@echo "$(INCLIST)"
#	@echo "$(BUILDLIST)"
#	$(CC) $(CFLAGS) $(LDFLAGS) $(OUT)