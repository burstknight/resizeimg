#include "ParseArgs.h"
#include "ResizingImage.h"
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;
using namespace ResizingImage;

int main(int argc, char** argv) {
	auto poArgs = ParseArgs::parseArgs(argc, argv);
	if (nullptr == poArgs) {
		exit(1);
	} // End of if-condition

	printf("The arguments is:\n"
		   "The input image path: %s\n"
		   "The result image path: %s\n"
		   "Expected width: %d\n"
		   "Expected height: %d\n\n",
		poArgs->m_sInputImagePath.c_str(), poArgs->m_sResultImagePath.c_str(), poArgs->m_iWidth, poArgs->m_iHeight);

	resizeImage(std::move(poArgs));

	return 0;
} // End of main
