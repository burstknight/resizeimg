#ifndef INCLUDES_PARSE_ARGS_H
#define INCLUDES_PARSE_ARGS_H

#include <memory>
#include <string>

namespace ParseArgs {

/**
 * This struct represents a parsed command line arguments.
 */
struct Args_s {
	/*
	 * This field stores the input image path.
	 */
	std::string m_sInputImagePath;

	/*
	 * This field stores the result image path. The default value is `result.png`.
	 */
	std::string m_sResultImagePath;

	/**
	 * This field stores the expected width to resize the input image. The default value is 800.
	 */
	int m_iWidth;

	/**
	 * This field stores the expected the height to resize the input image. The default value is 800.
	 */
	int m_iHeight;
};

/**
 * This function can parse the command line arguments.
 *
 * @param argc Give the number of the command line arguments.
 * @param argv Give the list of the command line arguments.
 *
 * @return Return a point of the struct Args_s if this function succeeds to parse the command line arguments. Otherwise, this function will return nullpter.
 */
std::unique_ptr<Args_s> parseArgs(int argc, char** argv);

} // End of namespace ParseArgs

#endif // End of INCLUDES_PARSE_ARGS_H
