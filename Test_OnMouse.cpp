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
#include <iostream>
#include <QStringList>
#include "userdata.h"
#include "functions.h"


static const int VK_DOWN = 40;
static const int VK_UP = 38;
static const int ESC = 27;

void Test_OnMouse()
{
    // the directory
    QString Directory = "E:/Database_For_Experiment/vehicle/1";
    QString FileName;

    QStringList FileNameList = GetFilesInDirectory(Directory);

    std::string WindowName = "Image";
    cv::namedWindow(WindowName, CV_WINDOW_AUTOSIZE);

    cv::Mat Image;
    UserData userdata;
    userdata.WindowName = WindowName;
    userdata.OriginImage = &Image;
    cv::setMouseCallback(WindowName, &OnMouse, static_cast<void*>(&userdata));

    bool IsESC = false;

    for (int Index = 0; Index < FileNameList.size(); Index++)
    {
        FileName = FileNameList.at(Index);
        std::cout << "The name of the image is " <<
                     FileName.toLocal8Bit().constData() << std::endl;
        FileName = Directory + "/" + FileName;

        Image = cv::imread(FileName.toLocal8Bit().constData(),
                           cv::IMREAD_UNCHANGED);
        cv::imshow(WindowName, Image);

        bool InNext = false;

        while(!InNext)
        {
            int Result = cv::waitKey();

            switch (Result)
            {
                case 'd':
                    InNext = true;
                    break;

                case 'u':
                    if (Index != 0)
                    {
                        InNext = true;

                        // back to the front image
                        Index = Index - 2;
                    }
                    break;


                case ESC:
                    IsESC = true;
                    break;


                default:
                    break;
            }

            // break the inner loop
            if (IsESC)
            {
                break;
            }
        }

        // break the loop
        if (IsESC)
        {
            break;
        }

    }

    cv::destroyAllWindows();
}


