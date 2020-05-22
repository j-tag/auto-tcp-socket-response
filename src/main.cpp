#include "includes/MainWindow.hpp"
#include "includes/AutoSocket.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QCoreApplication::setOrganizationName("Pure Soft");
  QCoreApplication::setOrganizationDomain("puresoftware.org");
  QCoreApplication::setApplicationName("Auto TCP Socket Response");
  QCoreApplication::setApplicationVersion("1.1.0");

  MainWindow w;
  w.show();
  return a.exec();
}
