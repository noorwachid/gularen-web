#include <Parser.hpp>
#include <HtmlGen.hpp>
#include <emscripten/bind.h>
#include <string>

std::string transpile(const std::string& input) {
	Node* node = parse(input.c_str());
	if (node == nullptr) {
		return "";
	}
	HtmlGen::Option option = {};
	return HtmlGen::gen(node, option).items();
}

EMSCRIPTEN_BINDINGS(gularen) {
	emscripten::function("transpile", transpile);
}
