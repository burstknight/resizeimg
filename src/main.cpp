#include <cstdio>
#include <cstdlib>
#include "ParseArgs.h"

using namespace std;

int main(int argc, char** argv) {
	auto poArgs = ParseArgs::parseArgs(argc, argv);
	if (nullptr == poArgs) {
		exit(1);
	} // End of if-condition

	printf("Input image: %s\n", poArgs->m_sInputImagePath.c_str());
	printf("Result image: %s\n", poArgs->m_sResultImagePath.c_str());
	printf("Width: %d\n", poArgs->m_iWidth);
	printf("Height: %d\n", poArgs->m_iHeight);
	return 0;
} // End of main
