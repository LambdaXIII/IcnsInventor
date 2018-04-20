#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTextStream>

#include "functions.h"



int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  QCoreApplication::setApplicationName("IcnsInventor");
  QCoreApplication::setApplicationVersion("0.1alpha");

  QCommandLineParser parser;
  parser.setApplicationDescription(TRANSLATE("将一个图片文件转换成苹果icns图标的工具。"));
  parser.addHelpOption();
  parser.addPositionalArgument("source", TRANSLATE("原始图片文件"));
  parser.addPositionalArgument("desitiny", TRANSLATE("需要导出的目标位置"));


  parser.process(a);

  const QStringList args = parser.positionalArguments();
  if (args.size() < 2)
    return 2;

  const QString source_src = args[0];
  const QString dest_src = args[1];

  QImage image = readImage(source_src);
  image.save(dest_src);

  return 0;
}
