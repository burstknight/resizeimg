#ifndef INCLUDES_RESIZINGIMAGE_H
#define INCLUDES_RESIZINGIMAGE_H

#include "ParseArgs.h"
#include <memory>

namespace ResizingImage {

/**
 * This function can resize image.
 * @param poArgs Give an instance of the struct ParseArgs::Args_s that contains the important information.
 */
void resizeImage(std::unique_ptr<ParseArgs::Args_s> poArgs);

} // End of namespace ResizingImage

#endif // End of INCLUDES_RESIZINGIMAGE_H
