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


#include "functions.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

const std::string PrefixOfFileName = "E:/Database_For_Experiment/car";

/**
 * @brief OnMouse The call back function used to the mouse moving
 * @param Event   The mouse event
 * @param X       The position x of the mouse
 * @param Y       The position y of the mouse
 * @param flag
 * @param Userdata
 *
 *
 * @author sheng
 * @date   2014-08-26
 * @version 0.1
 *
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-26          0.1
 *
 *
 */
void OnMouse( int Event, int X, int Y, int flag, void* Userdata)
{
    static int StartedX = -1;
    static int StartedY = -1;
    static int Index = 0;

    // get the Image
    cv::Mat* Image = static_cast<cv::Mat*>(Userdata);


    switch (Event)
    {
        case CV_EVENT_LBUTTONDOWN:
            if (StartedX == -1)
            {
                StartedX = X;
                StartedY = Y;
            }
            std::cout << "LButtondown is click." << std::endl;
            break;

        case CV_EVENT_LBUTTONUP:
            if (StartedX != -1)
            {
                std::string FileName = PrefixOfFileName + "/" +
                        IntToString(Index) +".jpg";

                if(!Screenshot(*Image, FileName, StartedX, StartedY, X, Y))
                {
                    std::cout << "Screenshot failed." << std::endl;
                }
                Index++;
            }
            break;

        case CV_EVENT_MOUSEMOVE:
            std::cout << "The mouse is moding" << std::endl;
            break;

        default:
            break;
    }
}
