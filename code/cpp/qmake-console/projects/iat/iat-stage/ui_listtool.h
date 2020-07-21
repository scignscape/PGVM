/********************************************************************************
** Form generated from reading UI file 'listtool.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTTOOL_H
#define UI_LISTTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ListTool
{
public:
    QLabel *Name;
    QLabel *ObjLabel;
    QLabel *InstLabel;
    QTextEdit *textObject;
    QTextEdit *textInstance;
    QPushButton *AddLine;
    QPushButton *Cancel;
    QPushButton *Save;

    void setupUi(QDialog *ListTool)
    {
        if (ListTool->objectName().isEmpty())
            ListTool->setObjectName(QString::fromUtf8("ListTool"));
        ListTool->resize(350, 150);
        Name = new QLabel(ListTool);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(110, 10, 111, 16));
        ObjLabel = new QLabel(ListTool);
        ObjLabel->setObjectName(QString::fromUtf8("ObjLabel"));
        ObjLabel->setGeometry(QRect(60, 40, 41, 16));
        InstLabel = new QLabel(ListTool);
        InstLabel->setObjectName(QString::fromUtf8("InstLabel"));
        InstLabel->setGeometry(QRect(225, 40, 51, 16));
        textObject = new QTextEdit(ListTool);
        textObject->setObjectName(QString::fromUtf8("textObject"));
        textObject->setGeometry(QRect(20, 60, 131, 31));
        textInstance = new QTextEdit(ListTool);
        textInstance->setObjectName(QString::fromUtf8("textInstance"));
        textInstance->setGeometry(QRect(180, 60, 131, 31));
        AddLine = new QPushButton(ListTool);
        AddLine->setObjectName(QString::fromUtf8("AddLine"));
        AddLine->setGeometry(QRect(20, 110, 75, 23));
        Cancel = new QPushButton(ListTool);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(250, 110, 75, 23));
        Save = new QPushButton(ListTool);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(170, 110, 75, 23));

        retranslateUi(ListTool);

        QMetaObject::connectSlotsByName(ListTool);
    } // setupUi

    void retranslateUi(QDialog *ListTool)
    {
        ListTool->setWindowTitle(QApplication::translate("ListTool", "Dialog", nullptr));
        Name->setText(QApplication::translate("ListTool", "CREATING LIST TOOL", nullptr));
        ObjLabel->setText(QApplication::translate("ListTool", "Object", nullptr));
        InstLabel->setText(QApplication::translate("ListTool", "Instance", nullptr));
        AddLine->setText(QApplication::translate("ListTool", "Add Line", nullptr));
        Cancel->setText(QApplication::translate("ListTool", "Cancel", nullptr));
        Save->setText(QApplication::translate("ListTool", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListTool: public Ui_ListTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTTOOL_H
