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


#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"

#include "functions.h"



/**
 * @brief Screenshot Sava the srceen shot
 * @param Image      The hole image
 * @param FileName   The file name
 * @param StartedX   The started position x for the ROI
 * @param StartedY   The started position y for the ROI
 * @param EndedX     The ended position x for the ROI
 * @param EndedY     The ended position y for the ROI
 * @return true when the operation is successed
 *         false otherwise
 *
 * @author sheng
 * @date  2014-08-27
 * @version 0.2
 *
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-27          0.2         fixed the bug that the
 *                                                       program terminaled when
 *                                                       the mouse is out of
 *                                                       the image window.
 *      sheng       2014-08-26          0.1          build the module
 *
 */
bool Screenshot(cv::Mat Image, const std::string& FileName,
                const int& StartedX, const int& StartedY,
                const int& EndedX, const int& EndedY)
{
    if (StartedX < 0 )
    {
        std::cout << "The started is smaller than zero." << std::endl;
        return false;
    }

    if (StartedY < 0)
    {
        std::cout << "The strated is smaller than zero." << std::endl;
        return false;
    }


    if (EndedY > Image.rows)
    {
        std::cout << "The EndedY is bigger than the width." << std::endl;
        return false;
    }

    if (EndedX > Image.cols)
    {
        std::cout << "The EndedX is bigger than heigh." << std::endl;
        return false;
    }

    int Width = EndedX - StartedX;
    int Heigh = EndedY - StartedY;



    // get the ROI rectangle.
    cv::Rect ROI(StartedX, StartedY, Width, Heigh);
    std::cout << "ROI rec." << std::endl;


    // get the ROI image
    cv::Mat ScreenshorImage = Image(ROI);


    // save the ROI image.
    bool Result = SaveImageInJPEG(FileName, ScreenshorImage);


    return Result;

}

