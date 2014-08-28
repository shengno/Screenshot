/*M///////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, sheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimer in the documentation
//       and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//M*/


#include "opencv2/opencv.hpp"

/**
 * @brief DrawRectangle Draw a rectangle in the image.
 * @param Image        The image
 * @param StartedX     The x-coordinate of the started point
 * @param StartedY     The y-coordinate of the started point
 * @param EndedX       The x-coordinate of the ended point
 * @param EndedY       The y-coordinate of the ended point
 * @param Color        The color of the rectangle
 * @param Thickness    The thickness of the lines of the rectangle
 * @param LintType     The tpye of the line
 * @return true if the operation is successed
 *         false otherwise
 *
 * @author sheng
 * @date   2014-08-27
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2014-08-27         0.1            build the module
 */
bool DrawRectangle(cv::Mat& Image, const int& StartedX, const int& StartedY,
                   const int& EndedX, const int& EndedY,
                   const cv::Scalar& Color, int Thickness, int LineType)
{

    if (Image.empty())
    {
        std::cout << "The image is empty. " << std::endl;
        return false;
    }


    // set the started point and the ended point
    cv::Point StartedPoint(StartedX, StartedY);
    cv::Point EndedPoint(EndedX, EndedY);


    // draw the rectangle
    cv::rectangle(Image, StartedPoint, EndedPoint, Color, Thickness, LineType);

    return true;
}
