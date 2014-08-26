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
#include "functions.h"

void Test_OnMouse()
{
    // the directory
    QString Directory = "E:/Database_For_Experiment/vehicle/1";
    QString FileName;

    QStringList FileNameList = GetFilesInDirectory(Directory);

    cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);

    cv::Mat Image;
    cv::setMouseCallback("Image", &OnMouse, static_cast<void*>(&Image));

    for (int Index = 0; Index < FileNameList.size(); Index++)
    {
        FileName = FileNameList.at(Index);
        FileName = Directory + "/" + FileName;

        Image = cv::imread(FileName.toLocal8Bit().constData(),
                           cv::IMREAD_UNCHANGED);
        cv::imshow("Image", Image);

        bool InNext = false;

        while(!InNext)
        {
            int Result = cv::waitKey();

            switch (Result)
            {
                case 'n':
                    InNext = true;
                    break;

                default:
                    break;
            }
        }
    }
}


