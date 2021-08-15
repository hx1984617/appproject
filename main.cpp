#include "mainwindow.h"

#include <QApplication>
#include "darkstyle.h"
#include "lightstyle.h"
#include "framelesswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle(new LightStyle);
    QApplication::setPalette(QApplication::style()->standardPalette());

    // create frameless window (and set windowState or title)
    FramelessWindow framelessWindow;
    //framelessWindow.setWindowState(Qt::WindowFullScreen);
    //framelessWindow.setWindowTitle("test title");
    //framelessWindow.setWindowIcon(a.style()->standardIcon(QStyle::SP_DesktopIcon));

    // create our mainwindow instance
    MainWindow *mainWindow = new MainWindow;

    // add the mainwindow to our custom frameless window
    framelessWindow.setContent(mainWindow);
//#ifdef Q_OS_UNIX
    framelessWindow.setTitleBarVisible(false);
//#endif
    framelessWindow.show();

    return a.exec();
}
