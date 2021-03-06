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



/**
 * @brief SaveImageInJPEG Save the image in jpeg format.
 * @param FileName  The name used to save the image.
 * @param Image     The image which is to be saved.
 * @return true  when the saving operator is successed.
 *         false  otherwise
 *
 * @author sheng
 * @date  2014-08-26
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng        2014-08-26         0.1          build the module
 *
 */
bool SaveImageInJPEG(const std::string& FileName, const cv::Mat& Image)
{

    if (FileName.empty())
    {
        std::cout << "The name of the file is empty." << std::endl;
        return false;
    }


    if (Image.empty())
    {
        std::cout << "The data of the image is empty." << std::endl;
        return false;
    }


    // set the jpeg params
    std::vector<int> Params;
    Params.push_back(CV_IMWRITE_JPEG_QUALITY);
    Params.push_back(100);

    // save the image file
    bool Result = cv::imwrite(FileName, Image, Params);

    return Result;

}

