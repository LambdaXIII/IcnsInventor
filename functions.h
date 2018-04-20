#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QImage>

#define TRANSLATE(T) QCoreApplication::translate("main",T)


QImage readImage(QString source_path);


#endif // FUNCTIONS_H
