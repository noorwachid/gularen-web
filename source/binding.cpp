#include <Gularen/Backend/Html/Composer.h>
#include <emscripten/bind.h>
#include <string>

std::string transpile(const std::string& input) {
	Gularen::Parser parser;

	Gularen::Html::Composer composer;
	std::string_view output = composer.compose(parser.parse(input));

	return std::string(output.data(), output.size());
}

EMSCRIPTEN_BINDINGS(gularen) {
	emscripten::function("transpile", transpile);
}
