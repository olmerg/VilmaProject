/********************************************************************************
** Form generated from reading UI file 'plotui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTUI_H
#define UI_PLOTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotUI
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *QPlotUI;

    void setupUi(QWidget *PlotUI)
    {
        if (PlotUI->objectName().isEmpty())
            PlotUI->setObjectName(QStringLiteral("PlotUI"));
        PlotUI->resize(400, 300);
        gridLayout = new QGridLayout(PlotUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        QPlotUI = new QCustomPlot(PlotUI);
        QPlotUI->setObjectName(QStringLiteral("QPlotUI"));
        QPlotUI->setAutoFillBackground(false);

        gridLayout->addWidget(QPlotUI, 0, 0, 1, 1);

        QPlotUI->raise();

        retranslateUi(PlotUI);

        QMetaObject::connectSlotsByName(PlotUI);
    } // setupUi

    void retranslateUi(QWidget *PlotUI)
    {
        PlotUI->setWindowTitle(QApplication::translate("PlotUI", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotUI: public Ui_PlotUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTUI_H
