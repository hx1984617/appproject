/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#include "lightstyle.h"

LightStyle::LightStyle() : LightStyle(styleBase()) {}

LightStyle::LightStyle(QStyle *style) : QProxyStyle(style) {}

QStyle *LightStyle::styleBase(QStyle *style) const {
    static QStyle *base =
            !style ? QStyleFactory::create(QStringLiteral("Fusion")) : style;
    return base;
}

QStyle *LightStyle::baseStyle() const { return styleBase(); }

void LightStyle::polish(QPalette &palette) {

    QProxyStyle::polish(palette);

//    // modify palette to dark
//    palette.setColor(QPalette::Window, QColor(53, 53, 53));
//    palette.setColor(QPalette::WindowText, Qt::black);
//    palette.setColor(QPalette::Disabled, QPalette::WindowText,
//                     QColor(127, 127, 127));
//    palette.setColor(QPalette::Base, QColor(42, 42, 42));
//    palette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
//    palette.setColor(QPalette::ToolTipBase, Qt::white);
//    palette.setColor(QPalette::ToolTipText, QColor(53, 53, 53));
//    palette.setColor(QPalette::Text, Qt::white);
//    palette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
//    palette.setColor(QPalette::Dark, QColor(35, 35, 35));
//    palette.setColor(QPalette::Shadow, QColor(20, 20, 20));
//    palette.setColor(QPalette::Button, QColor(53, 53, 53));
//    palette.setColor(QPalette::ButtonText, Qt::white);
//    palette.setColor(QPalette::Disabled, QPalette::ButtonText,
//                     QColor(127, 127, 127));
//    palette.setColor(QPalette::BrightText, Qt::red);
//    palette.setColor(QPalette::Link, QColor(42, 130, 218));
//    palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
//    palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
//    palette.setColor(QPalette::HighlightedText, Qt::white);
//    palette.setColor(QPalette::Disabled, QPalette::HighlightedText,
//                     QColor(127, 127, 127));
}

void LightStyle::polish(QApplication *app) {
    if (!app) return;

    // increase font size for better reading,
    // setPointSize was reduced from +2 because when applied this way in Qt5, the
    // font is larger than intended for some reason
    QFont defaultFont = QApplication::font();
    defaultFont.setPointSize(defaultFont.pointSize() + 1);
    app->setFont(defaultFont);

    // loadstylesheet
    QFile qfLightstyle(QStringLiteral(":/styles/lightstyle/lightstyle.qss"));
    if (qfLightstyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // set stylesheet
        QString qsStylesheet = QString::fromLatin1(qfLightstyle.readAll());
        app->setStyleSheet(qsStylesheet);
        qfLightstyle.close();
    }
}
