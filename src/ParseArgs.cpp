#include "ParseArgs.h"
#include "CLI/CLI.hpp"
#include "version.h"
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>

using namespace ParseArgs;
using namespace std;
using namespace CLI;

unique_ptr<Args_s> ParseArgs::parseArgs(int argc, char** argv) {
	App oApp("resizeimg", "A command line tool can resize image.");
	unique_ptr<Args_s> poArgs = make_unique<Args_s>();

	oApp.add_option("input_path", poArgs->m_sInputImagePath,
			"Give an input image to resize.")
		->option_text(" ")
		->required()
		->check(CLI::ExistingFile);
	oApp.add_option("result_path", poArgs->m_sResultImagePath,
			"Give the path to store the result image. The default value is `result.png`")
		->option_text(" ")
		->default_val("result.png");
	oApp.add_option("-W,--width", poArgs->m_iWidth,
			"Give the expected width to resize the input image. The default value is 800")
		->default_val(800)
		->check(CLI::Range(1, INT32_MAX));
	oApp.add_option("-H,--height", poArgs->m_iHeight,
			"Give the expected height to resize the input image. The default value is 800.")
		->default_val(800)
		->check(CLI::Range(1, INT32_MAX));

	oApp.usage("Usage: " + string(argv[0]) + " [options] <input_path> [result_path]");
	oApp.set_version_flag("-v,--version", RESIZEIMG_VERSION, "Display the current version.");
	argv = oApp.ensure_utf8(argv);

	try {
		oApp.parse(argc, argv);
	} catch (const CLI::CallForHelp& e) {
		oApp.exit(e);

		return nullptr;
	} catch (const CLI::CallForVersion& e) {
		oApp.exit(e);

		return nullptr;
	} catch (const CLI::Error& e) {
		fprintf(stderr, "Error: Failed to parse command line arguments.\n  Details:\t%s\n\n", e.what());
		oApp.exit(e);

		return nullptr;
	} // End of try-catch

	return poArgs;
} // End of parseArgs
