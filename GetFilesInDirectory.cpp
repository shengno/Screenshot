#include <QDir>
#include <iostream>
/**
 * @brief GetFilesInDirectory This function get the
 * @param Directory
 * @return A list of the names of all the files, or An empty list if the
 *          directory is unreadable, does not exist,or dose not contain
 *          any files.
 *
 * @author  sheng
 * @version 1.0.0
 * @date    2014-04-03
 *
 * @history   <author>      <date>         <description>
 *             sheng      2014-04-03         build the function
 *
 */
QStringList GetFilesInDirectory(const QString &Directory)
{
    // set the directory
    QDir Dir(Directory);

    // set the filter and sorting rules.
    Dir.setFilter(QDir::Files | QDir::NoSymLinks);
    Dir.setSorting(QDir::Size | QDir::Name);

    // return the FileList in the directory
    return Dir.entryList();
}
