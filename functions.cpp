
#include "functions.h"

#include <QFileInfo>
#include <QSvgRenderer>
#include <QPainter>


QImage readImage(QString source_path)
{
  QImage image;
  image = QImage(1024, 1024, QImage::Format_ARGB32);
  QFileInfo source(source_path);
  if (source.suffix() == "svg") {
    QSvgRenderer renderer(source.absoluteFilePath());
    image.fill(Qt::transparent);
    QPainter painter(&image);
    renderer.render(&painter);
  } else {
    image.load(source.absoluteFilePath());
    image = image.scaled(1024, 1024, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
  }
  return image;
}
