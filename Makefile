#################################
##							   ##
##    C_ALGOTITHMS MAKEFILE    ##
## Created by Leon Wandruschka ##
##      Date: 10.06.2022	   ##
##							   ##
#################################


#<-- Variables -->#
DEBUG ?= 0
COMPILER ?= 0
REMOVE_OBJ_FILES = 0

#<-- PATH TO DIRECTORIES -->#
INCLUDE_DIR = include
BUILD_DIR = build
SRC_DIR = src

#<-- SET COMPILERFLAGS -->#
ifeq ($(DEBUG), 1)
C_COMPILER_FLAGS = -g -O0 -Wall -Wextra -Wpedantic -Wconversion -std=c17
EXECUTABLE_NAME = mainDebug
else
C_COMPILER_FLAGS = -O3 -std=c17
EXECUTABLE_NAME = main
endif

#<-- SET COMPILER -->#
ifeq ($(COMPILER), 1)
C_COMPILER = clang
else
C_COMPILER = gcc
endif

#<-- DELETE OBJECT FILES -->#
ifeq ($(REMOVE_OBJ_FILES), 0)
RM_OF = rm $(BUILD_DIR)/*.o
endif


C_COMPILER_CALL = $(C_COMPILER) $(C_COMPILER_FLAGS)

C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRCS))

#<-- BUILD -->#
build: $(C_OBJECTS)
	$(C_COMPILER_CALL) $^ -o $(BUILD_DIR)/$(EXECUTABLE_NAME)
	$(RM_OF)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(C_COMPILER_CALL) -I $(INCLUDE_DIR) -c $< -o $@

#<-- CLEAN -->#
clean: 
	rm $(BUILD_DIR)/$(EXECUTABLE_NAME)
	
doxygen:
	doxygen