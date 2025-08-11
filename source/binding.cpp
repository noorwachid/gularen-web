#include <Parser.hpp>
#include <HTMLGen.hpp>
#include <emscripten/bind.h>
#include <string>

std::string transpile(const std::string& input) {
	String inputStr = input.c_str();
	Node* node = parse(inputStr);
	if (node == nullptr) {
		return "";
	}
	String outputStr = genHTML(node);
	return std::string(reinterpret_cast<char const*>(outputStr.items()), outputStr.size());
}

EMSCRIPTEN_BINDINGS(gularen) {
	emscripten::function("transpile", transpile);
}
