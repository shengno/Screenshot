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



#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QStringList>
#include <string>
#include "opencv2/opencv.hpp"

QStringList GetFilesInDirectory(const QString &Directory);

bool SaveImageInJPEG(const std::string& FileName, const cv::Mat& Image);

bool Screenshot(cv::Mat Image, const std::string& FileName,
                const int& StartedX, const int& StartedY,
                const int& EndedX, const int& EndedY);

void OnMouse( int Event, int X, int Y, int flag, void* Userdata);


std::string IntToString(int value);

bool DrawRectangle(cv::Mat& Image, const int& StartedX, const int& StartedY,
                   const int& EndedX, const int& EndedY,
                   const cv::Scalar& Color = cv::Scalar(255,0,0),
                   int Thickness = 2, int LintType = 8);

bool MakingRectanglePoint(int& StartedX, int& StartedY,
                          int& EndedX, int& EndedY);

#endif // FUNCTIONS_H
