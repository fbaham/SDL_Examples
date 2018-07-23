# #OBJS specifies which files to compile as part of the project
# OBJS := src/Main.cpp src/Game.cpp src/InputHandler.cpp src/SDLGameObject.cpp src/Player.cpp src/Enemy.cpp src/TextureManager.cpp
# OBJS := $(OBJS) src/GameStateMachine.cpp src/PlayState.cpp src/MainMenuState.cpp src/MenuButton.cpp src/PauseState.cpp src/AnimatedGraphic.cpp
# OBJS := $(OBJS) src/GameOverState.cpp src/GameObjectFactory.cpp src/StateParser.cpp ../tinyxml/tinyxml.cpp

# #CC specifies which compiler we're using
# CC = g++

# #INCLUDE_PATHS specifies the additional include paths we'll need
# INCLUDE_PATHS = -IC:\TDM-GCC-64\include\

# #LIBRARY_PATHS specifies the additional library paths we'll need
# LIBRARY_PATHS = -LC:\TDM-GCC-64\lib

# #COMPILER_FLAGS specifies the additional compilation options we're using
# # -w suppresses all warnings
# # -Wl,-subsystem,windows gets rid of the console window
# COMPILER_FLAGS = -w -Wl,-subsystem,windows
# #COMPILER_FLAGS = -w -Wl,-subsystem

# #LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
# #LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = bin/Debug/main

# #This is the target that compiles our executable
#  all : $(OBJS)
#  	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# #all : $(OBJS)
# #	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin

# executable # 
BIN_NAME = runner

# extensions #
SRC_EXT = cpp

# code lists #
# Find all source files in the source directory, sorted by
# most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)

# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)

# Set the dependency files that will be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# flags #
COMPILE_FLAGS = -w -Wl,-subsystem,windows
INCLUDES = -I C:/TDM-GCC-64/include

# Space-separated pkg-config libraries used by this project
LIBS = -L C:/TDM-GCC-64/lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

.PHONY: default_target
default_target: release

.PHONY: release
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
release: dirs
	@$(MAKE) all

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

# checks the executable and symlinks to the output
.PHONY: all
all: $(BIN_PATH)/$(BIN_NAME)
	@echo "Making symlink: $(BIN_NAME) -> $<"
	@$(RM) $(BIN_NAME)
	@ln -s $(BIN_PATH)/$(BIN_NAME) $(BIN_NAME)

# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@ $(LINKER_FLAGS)

# Add dependency files, if they exist
-include $(DEPS)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@