NAME = Submarine
OBJECTS = mathematics.o config.o component.o panel.o main.o


# DIRECTORIES

DIRECTORY_BIN_LINUX = linux
DIRECTORY_BIN_WINDOWS = win

DIRECTORY_SRC = src
DIRECTORY_INC = include
DIRECTORY_LIB = lib


# COMPILER FLAGS

MINGW = i686-w64-mingw32-g++
CPP = g++

FLAGS_LINUX = -Wall -std=gnu++0x
FLAGS_WINDOWS = -std=c++11 -static -mwindows -DSFML_SHARED 

LIBS_LINUX = -lpthread -lsfml-graphics -lsfml-window -lsfml-system
LIBS_WINDOWS = -L/usr/i686-w64-mingw32/lib -lsfml-audio-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s


# EXECUTABLES FILES

TARGET_LINUX = $(DIRECTORY_BIN_LINUX)/$(NAME)
TARGET_WINDOWS = $(DIRECTORY_BIN_WINDOWS)/$(NAME).exe

DEPS_LINUX = $(patsubst %, $(DIRECTORY_BIN_LINUX)/%, $(OBJECTS))
DEPS_WINDOWS = $(patsubst %, $(DIRECTORY_BIN_WINDOWS)/%, $(OBJECTS))


# COMMANDS

clearConsole:
	-clear;

clean: clearConsole
	-rm -f $(DEPS_LINUX) $(DEPS_WINDOWS) $(TARGET_LINUX) $(TARGET_WINDOWS)

run: clearConsole
	./$(TARGET_LINUX)


#BUILD FOR WINDOWS

$(DIRECTORY_BIN_WINDOWS)/%.o: $(DIRECTORY_SRC)/%.cpp
	$(MINGW) $(FLAGS_WINDOWS) -I$(DIRECTORY_INC) -c $^ -o $@

$(TARGET_WINDOWS): $(DEPS_WINDOWS)
	$(MINGW) $(DEPS_WINDOWS) $(LIBS_WINDOWS) $(FLAGS_WINDOWS) -o $@

buildForWindows: clearConsole $(TARGET_WINDOWS)


# BUILD FOR LINUX

$(DIRECTORY_BIN_LINUX)/%.o: $(DIRECTORY_SRC)/%.cpp
	$(CPP) $(FLAGS_LINUX) -I$(DIRECTORY_INC) -c $^ -o $@

$(TARGET_LINUX): $(DEPS_LINUX)
	$(CPP) $(DEPS_LINUX) $(LIBS_LINUX) $(FLAGS_LINUX) -o $@

buildForLinux: clearConsole $(TARGET_LINUX)