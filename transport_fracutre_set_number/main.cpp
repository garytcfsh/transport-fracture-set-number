#include <QCoreApplication>
#include <QDebug>
#include <QFile>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList fabList;
    QString filepathIn = "E:\\toothpick\\program\\transport_fracuter_set_number\\MaficDefinition_3.fab";
    QString filepathOut = "E:\\toothpick\\program\\transport_fracuter_set_number\\MaficDefinition_3_out.fab";
    QFile fabFile( filepathIn);
    QFile fileOut( filepathOut);
    fabFile.open( QFile::ReadOnly|QFile::Text);
    fileOut.open( QFile::WriteOnly|QFile::Text);
    QTextStream fabFileTextStream( &fabFile);
    QTextStream fileOutTextStream( &fileOut);
    QString singleLine = fabFileTextStream.readLine();
    QStringList singleLineSeparateData;

    for (int i=0; i<28; i++)
    {
        singleLine = fabFileTextStream.readLine();
    }

    int i=0, k=0;
    while (!fabFileTextStream.atEnd())
    {
        singleLine = fabFileTextStream.readLine();
        if (singleLine == "END FRACTURE")
        {
            fileOutTextStream << "END FRACTURE" << endl;
            fileOutTextStream << endl;
            fileOutTextStream << "BEGIN TESSFRACTURE" << endl;
            fileOutTextStream << "END TESSFRACTURE" << endl;
            qDebug()<<"finish";
            return a.exec();
        }
        singleLineSeparateData = singleLine.split( QRegExp( "\\s+"), QString::SkipEmptyParts);
        if (i==k)
        {
            k = k + singleLineSeparateData[1].toInt() + 2;
            singleLineSeparateData[2] = "1";
        }

        for (int j=0; j<singleLineSeparateData.count(); j++)
        {
            fileOutTextStream << " " << singleLineSeparateData[j];
        }
        fileOutTextStream << endl;
        i++;
    }


    return a.exec();
}
