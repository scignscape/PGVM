/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QLabel *SquareDimension;
    QLabel *SquareColor;
    QLabel *LineThickness;
    QLabel *LineColor;
    QPushButton *Save;
    QPushButton *Cancel;
    QSpinBox *spinLineThickness;
    QSpinBox *spinSquareDimension;
    QSlider *RedLineColor;
    QSlider *GreenLineColor;
    QSlider *BlueLineColor;
    QSlider *RedSquareColor;
    QSlider *BlueSquareColor;
    QSlider *GreenSquareColor;
    QLabel *Red;
    QLabel *Green;
    QLabel *Blue;
    QPushButton *Default;
    QLabel *LineColor_2;
    QSlider *GreenSelectedColor;
    QSlider *BlueSelectedColor;
    QSlider *RedSelectedColor;
    QLabel *Red_2;
    QLabel *Blue_2;
    QLabel *Green_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(740, 339);
        SquareDimension = new QLabel(Options);
        SquareDimension->setObjectName(QString::fromUtf8("SquareDimension"));
        SquareDimension->setGeometry(QRect(20, 20, 91, 16));
        SquareColor = new QLabel(Options);
        SquareColor->setObjectName(QString::fromUtf8("SquareColor"));
        SquareColor->setGeometry(QRect(20, 60, 71, 16));
        LineThickness = new QLabel(Options);
        LineThickness->setObjectName(QString::fromUtf8("LineThickness"));
        LineThickness->setGeometry(QRect(430, 20, 71, 21));
        LineColor = new QLabel(Options);
        LineColor->setObjectName(QString::fromUtf8("LineColor"));
        LineColor->setGeometry(QRect(290, 60, 51, 16));
        Save = new QPushButton(Options);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(560, 310, 75, 23));
        Cancel = new QPushButton(Options);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(650, 310, 75, 23));
        spinLineThickness = new QSpinBox(Options);
        spinLineThickness->setObjectName(QString::fromUtf8("spinLineThickness"));
        spinLineThickness->setGeometry(QRect(510, 10, 51, 31));
        spinSquareDimension = new QSpinBox(Options);
        spinSquareDimension->setObjectName(QString::fromUtf8("spinSquareDimension"));
        spinSquareDimension->setGeometry(QRect(150, 10, 51, 31));
        RedLineColor = new QSlider(Options);
        RedLineColor->setObjectName(QString::fromUtf8("RedLineColor"));
        RedLineColor->setGeometry(QRect(289, 90, 181, 20));
        RedLineColor->setOrientation(Qt::Horizontal);
        GreenLineColor = new QSlider(Options);
        GreenLineColor->setObjectName(QString::fromUtf8("GreenLineColor"));
        GreenLineColor->setGeometry(QRect(289, 120, 181, 20));
        GreenLineColor->setOrientation(Qt::Horizontal);
        BlueLineColor = new QSlider(Options);
        BlueLineColor->setObjectName(QString::fromUtf8("BlueLineColor"));
        BlueLineColor->setGeometry(QRect(289, 150, 181, 20));
        BlueLineColor->setOrientation(Qt::Horizontal);
        RedSquareColor = new QSlider(Options);
        RedSquareColor->setObjectName(QString::fromUtf8("RedSquareColor"));
        RedSquareColor->setGeometry(QRect(20, 90, 181, 19));
        RedSquareColor->setOrientation(Qt::Horizontal);
        BlueSquareColor = new QSlider(Options);
        BlueSquareColor->setObjectName(QString::fromUtf8("BlueSquareColor"));
        BlueSquareColor->setGeometry(QRect(20, 150, 181, 19));
        BlueSquareColor->setOrientation(Qt::Horizontal);
        GreenSquareColor = new QSlider(Options);
        GreenSquareColor->setObjectName(QString::fromUtf8("GreenSquareColor"));
        GreenSquareColor->setGeometry(QRect(20, 120, 181, 19));
        GreenSquareColor->setOrientation(Qt::Horizontal);
        Red = new QLabel(Options);
        Red->setObjectName(QString::fromUtf8("Red"));
        Red->setGeometry(QRect(230, 90, 21, 16));
        Green = new QLabel(Options);
        Green->setObjectName(QString::fromUtf8("Green"));
        Green->setGeometry(QRect(220, 120, 41, 16));
        Blue = new QLabel(Options);
        Blue->setObjectName(QString::fromUtf8("Blue"));
        Blue->setGeometry(QRect(230, 150, 21, 16));
        Default = new QPushButton(Options);
        Default->setObjectName(QString::fromUtf8("Default"));
        Default->setGeometry(QRect(20, 310, 75, 23));
        LineColor_2 = new QLabel(Options);
        LineColor_2->setObjectName(QString::fromUtf8("LineColor_2"));
        LineColor_2->setGeometry(QRect(541, 60, 101, 16));
        GreenSelectedColor = new QSlider(Options);
        GreenSelectedColor->setObjectName(QString::fromUtf8("GreenSelectedColor"));
        GreenSelectedColor->setGeometry(QRect(540, 120, 181, 20));
        GreenSelectedColor->setOrientation(Qt::Horizontal);
        BlueSelectedColor = new QSlider(Options);
        BlueSelectedColor->setObjectName(QString::fromUtf8("BlueSelectedColor"));
        BlueSelectedColor->setGeometry(QRect(540, 150, 181, 20));
        BlueSelectedColor->setOrientation(Qt::Horizontal);
        RedSelectedColor = new QSlider(Options);
        RedSelectedColor->setObjectName(QString::fromUtf8("RedSelectedColor"));
        RedSelectedColor->setGeometry(QRect(540, 90, 181, 20));
        RedSelectedColor->setOrientation(Qt::Horizontal);
        Red_2 = new QLabel(Options);
        Red_2->setObjectName(QString::fromUtf8("Red_2"));
        Red_2->setGeometry(QRect(490, 90, 21, 16));
        Blue_2 = new QLabel(Options);
        Blue_2->setObjectName(QString::fromUtf8("Blue_2"));
        Blue_2->setGeometry(QRect(490, 150, 21, 16));
        Green_2 = new QLabel(Options);
        Green_2->setObjectName(QString::fromUtf8("Green_2"));
        Green_2->setGeometry(QRect(480, 120, 41, 16));
        label = new QLabel(Options);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 190, 91, 16));
        label_2 = new QLabel(Options);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 190, 81, 16));

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Dialog", nullptr));
        SquareDimension->setText(QApplication::translate("Options", "Square Dimension", nullptr));
        SquareColor->setText(QApplication::translate("Options", "Square Color", nullptr));
        LineThickness->setText(QApplication::translate("Options", "Line Thickness", nullptr));
        LineColor->setText(QApplication::translate("Options", "Line Color", nullptr));
        Save->setText(QApplication::translate("Options", "Save", nullptr));
        Cancel->setText(QApplication::translate("Options", "Cancel", nullptr));
        Red->setText(QApplication::translate("Options", "Red", nullptr));
        Green->setText(QApplication::translate("Options", "  Green", nullptr));
        Blue->setText(QApplication::translate("Options", "Blue", nullptr));
        Default->setText(QApplication::translate("Options", "Default", nullptr));
        LineColor_2->setText(QApplication::translate("Options", "Selected Shape Color", nullptr));
        Red_2->setText(QApplication::translate("Options", "Red", nullptr));
        Blue_2->setText(QApplication::translate("Options", "Blue", nullptr));
        Green_2->setText(QApplication::translate("Options", "  Green", nullptr));
        label->setText(QApplication::translate("Options", "  Unselected Shape", nullptr));
        label_2->setText(QApplication::translate("Options", "Selected Shape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
