BINARY_NAME := game
BUILD_DIR := ./bin
LIB_DIR := ./lib
BINARY_PATH := $(BUILD_DIR)/$(BINARY_NAME)

# Only show the first error
# -Wfatal-errors \

build:
	g++ -w -std=c++14 \
	./src/*.cpp \
	-o $(BINARY_PATH) \
	-I"$(LIB_DIR)/lua" \
	-L"$(LIB_DIR)/lua" \
	-llua \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

clean:
	rm $(BINARY_PATH);

run:
	$(BINARY_PATH);
