C_INCLUDE_PATH=""
CPLUS_INCLUDE_PATH=""

em++ --bind \
	-std=c++17 \
	-I source \
	-I dependency/gularen/source \
	-O2 \
	-s NO_FILESYSTEM=1 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-o library/markup/gularen.js \
	source/binding.cpp \
	dependency/gularen/source/*.cpp \
	dependency/gularen/source/Collection/*.cpp

