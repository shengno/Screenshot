#include <QDir>
#include <Functions.h>
#include <iostream>

void Test_GetFilesInDirectory()
{


    QStringList FileList =
            GetFilesInDirectory("E:/Database_For_Experiment/vehicle/1");

    std::cout << "The size of the FileList is " << FileList.size()
              << std::endl;

    for (int i = 0; i < 10; i++)
    {
        QString FileName = FileList.at(i);
        std::cout << "No." << (i + 1) << "Picture's name is ";
        std::cout << FileName.toLocal8Bit().constData() << std::endl;
    }


}
