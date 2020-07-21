/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAnnotate_Single_Image;
    QAction *actionAnnotate_Multiple_Image;
    QAction *actionLoad_annotations;
    QAction *actionQuit;
    QAction *actionInstructions;
    QAction *actionOptions;
    QAction *actionCreate_List;
    QWidget *centralWidget;
    QFrame *EditFrame;
    QFrame *ChooseSelectionFrame;
    QRadioButton *Square;
    QRadioButton *Ellipse;
    QRadioButton *Polygon;
    QPushButton *ClearLast;
    QPushButton *ClearAll;
    QCheckBox *Highlight;
    QPushButton *ClearSelected;
    QFrame *InputFrame;
    QLabel *Object;
    QLabel *Instance;
    QLabel *Number;
    QListWidget *ObjectListView;
    QListWidget *InstanceListView;
    QListWidget *NumberListView;
    QFrame *SaveFrame;
    QFrame *NavigateFrame;
    QPushButton *LoadNext;
    QPushButton *LoadPrevious;
    QPushButton *EndProject;
    QPushButton *Save;
    QFrame *ResizeFrame;
    QSlider *ResizeSlider;
    QLabel *Zoom;
    QLabel *Minus;
    QLabel *Plus;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(670, 540);
        actionAnnotate_Single_Image = new QAction(MainWindow);
        actionAnnotate_Single_Image->setObjectName(QString::fromUtf8("actionAnnotate_Single_Image"));
        actionAnnotate_Multiple_Image = new QAction(MainWindow);
        actionAnnotate_Multiple_Image->setObjectName(QString::fromUtf8("actionAnnotate_Multiple_Image"));
        actionLoad_annotations = new QAction(MainWindow);
        actionLoad_annotations->setObjectName(QString::fromUtf8("actionLoad_annotations"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInstructions = new QAction(MainWindow);
        actionInstructions->setObjectName(QString::fromUtf8("actionInstructions"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionCreate_List = new QAction(MainWindow);
        actionCreate_List->setObjectName(QString::fromUtf8("actionCreate_List"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EditFrame = new QFrame(centralWidget);
        EditFrame->setObjectName(QString::fromUtf8("EditFrame"));
        EditFrame->setGeometry(QRect(10, 10, 101, 201));
        EditFrame->setFrameShape(QFrame::StyledPanel);
        EditFrame->setFrameShadow(QFrame::Raised);
        ChooseSelectionFrame = new QFrame(EditFrame);
        ChooseSelectionFrame->setObjectName(QString::fromUtf8("ChooseSelectionFrame"));
        ChooseSelectionFrame->setGeometry(QRect(10, 10, 81, 61));
        ChooseSelectionFrame->setFrameShape(QFrame::StyledPanel);
        ChooseSelectionFrame->setFrameShadow(QFrame::Raised);
        Square = new QRadioButton(ChooseSelectionFrame);
        Square->setObjectName(QString::fromUtf8("Square"));
        Square->setGeometry(QRect(10, 0, 82, 17));
        Ellipse = new QRadioButton(ChooseSelectionFrame);
        Ellipse->setObjectName(QString::fromUtf8("Ellipse"));
        Ellipse->setGeometry(QRect(10, 20, 82, 17));
        Polygon = new QRadioButton(ChooseSelectionFrame);
        Polygon->setObjectName(QString::fromUtf8("Polygon"));
        Polygon->setGeometry(QRect(10, 40, 82, 17));
        Polygon->setChecked(false);
        ClearLast = new QPushButton(EditFrame);
        ClearLast->setObjectName(QString::fromUtf8("ClearLast"));
        ClearLast->setGeometry(QRect(10, 140, 81, 23));
        ClearAll = new QPushButton(EditFrame);
        ClearAll->setObjectName(QString::fromUtf8("ClearAll"));
        ClearAll->setGeometry(QRect(10, 170, 81, 23));
        Highlight = new QCheckBox(EditFrame);
        Highlight->setObjectName(QString::fromUtf8("Highlight"));
        Highlight->setGeometry(QRect(20, 80, 70, 17));
        ClearSelected = new QPushButton(EditFrame);
        ClearSelected->setObjectName(QString::fromUtf8("ClearSelected"));
        ClearSelected->setGeometry(QRect(10, 110, 81, 23));
        InputFrame = new QFrame(centralWidget);
        InputFrame->setObjectName(QString::fromUtf8("InputFrame"));
        InputFrame->setGeometry(QRect(120, 10, 361, 201));
        InputFrame->setFrameShape(QFrame::StyledPanel);
        InputFrame->setFrameShadow(QFrame::Raised);
        Object = new QLabel(InputFrame);
        Object->setObjectName(QString::fromUtf8("Object"));
        Object->setGeometry(QRect(20, 10, 71, 21));
        Instance = new QLabel(InputFrame);
        Instance->setObjectName(QString::fromUtf8("Instance"));
        Instance->setGeometry(QRect(140, 10, 91, 21));
        Number = new QLabel(InputFrame);
        Number->setObjectName(QString::fromUtf8("Number"));
        Number->setGeometry(QRect(260, 10, 91, 21));
        ObjectListView = new QListWidget(InputFrame);
        ObjectListView->setObjectName(QString::fromUtf8("ObjectListView"));
        ObjectListView->setGeometry(QRect(10, 30, 101, 161));
        InstanceListView = new QListWidget(InputFrame);
        InstanceListView->setObjectName(QString::fromUtf8("InstanceListView"));
        InstanceListView->setGeometry(QRect(130, 30, 101, 161));
        NumberListView = new QListWidget(InputFrame);
        NumberListView->setObjectName(QString::fromUtf8("NumberListView"));
        NumberListView->setGeometry(QRect(250, 30, 101, 161));
        SaveFrame = new QFrame(centralWidget);
        SaveFrame->setObjectName(QString::fromUtf8("SaveFrame"));
        SaveFrame->setGeometry(QRect(490, 10, 101, 201));
        SaveFrame->setFrameShape(QFrame::StyledPanel);
        SaveFrame->setFrameShadow(QFrame::Raised);
        NavigateFrame = new QFrame(SaveFrame);
        NavigateFrame->setObjectName(QString::fromUtf8("NavigateFrame"));
        NavigateFrame->setGeometry(QRect(0, 20, 91, 101));
        NavigateFrame->setFrameShape(QFrame::StyledPanel);
        NavigateFrame->setFrameShadow(QFrame::Raised);
        LoadNext = new QPushButton(NavigateFrame);
        LoadNext->setObjectName(QString::fromUtf8("LoadNext"));
        LoadNext->setGeometry(QRect(10, 40, 75, 23));
        LoadPrevious = new QPushButton(NavigateFrame);
        LoadPrevious->setObjectName(QString::fromUtf8("LoadPrevious"));
        LoadPrevious->setGeometry(QRect(10, 70, 75, 23));
        EndProject = new QPushButton(NavigateFrame);
        EndProject->setObjectName(QString::fromUtf8("EndProject"));
        EndProject->setGeometry(QRect(10, 10, 75, 23));
        Save = new QPushButton(SaveFrame);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setEnabled(true);
        Save->setGeometry(QRect(10, 170, 75, 23));
        ResizeFrame = new QFrame(centralWidget);
        ResizeFrame->setObjectName(QString::fromUtf8("ResizeFrame"));
        ResizeFrame->setGeometry(QRect(600, 10, 61, 201));
        ResizeFrame->setFrameShape(QFrame::StyledPanel);
        ResizeFrame->setFrameShadow(QFrame::Raised);
        ResizeSlider = new QSlider(ResizeFrame);
        ResizeSlider->setObjectName(QString::fromUtf8("ResizeSlider"));
        ResizeSlider->setGeometry(QRect(20, 40, 20, 131));
        ResizeSlider->setOrientation(Qt::Vertical);
        ResizeSlider->setInvertedAppearance(true);
        ResizeSlider->setInvertedControls(true);
        Zoom = new QLabel(ResizeFrame);
        Zoom->setObjectName(QString::fromUtf8("Zoom"));
        Zoom->setGeometry(QRect(10, 0, 31, 16));
        Minus = new QLabel(ResizeFrame);
        Minus->setObjectName(QString::fromUtf8("Minus"));
        Minus->setGeometry(QRect(10, 20, 46, 13));
        Plus = new QLabel(ResizeFrame);
        Plus->setObjectName(QString::fromUtf8("Plus"));
        Plus->setGeometry(QRect(10, 180, 46, 13));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 220, 651, 291));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        scrollContents = new QWidget();
        scrollContents->setObjectName(QString::fromUtf8("scrollContents"));
        scrollContents->setGeometry(QRect(0, 0, 649, 289));
        scrollArea->setWidget(scrollContents);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAnnotate_Single_Image);
        menuFile->addAction(actionAnnotate_Multiple_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_annotations);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionInstructions);
        menuTools->addAction(actionOptions);
        menuTools->addAction(actionCreate_List);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAnnotate_Single_Image->setText(QApplication::translate("MainWindow", "Annotate Single Image          Ctrl+N", nullptr));
        actionAnnotate_Multiple_Image->setText(QApplication::translate("MainWindow", "Annotate Multiple Images    Ctrl+M", nullptr));
        actionLoad_annotations->setText(QApplication::translate("MainWindow", "Load annotations                   Ctrl+L", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit                                          Ctrl+Q", nullptr));
        actionInstructions->setText(QApplication::translate("MainWindow", "Instructions         Ctrl+I", nullptr));
        actionOptions->setText(QApplication::translate("MainWindow", "Options             Ctrl+O", nullptr));
        actionCreate_List->setText(QApplication::translate("MainWindow", "Create List         Ctrl+X", nullptr));
        Square->setText(QApplication::translate("MainWindow", "Square", nullptr));
        Ellipse->setText(QApplication::translate("MainWindow", "Ellipse", nullptr));
        Polygon->setText(QApplication::translate("MainWindow", "Polygon", nullptr));
        ClearLast->setText(QApplication::translate("MainWindow", "Clear Last", nullptr));
        ClearAll->setText(QApplication::translate("MainWindow", "Clear All", nullptr));
        Highlight->setText(QApplication::translate("MainWindow", "Highlight", nullptr));
        ClearSelected->setText(QApplication::translate("MainWindow", "Clear Selected", nullptr));
        Object->setText(QApplication::translate("MainWindow", "  Object Class", nullptr));
        Instance->setText(QApplication::translate("MainWindow", " Object Type", nullptr));
        Number->setText(QApplication::translate("MainWindow", "Object Instance ", nullptr));
        LoadNext->setText(QApplication::translate("MainWindow", "Load Next", nullptr));
        LoadPrevious->setText(QApplication::translate("MainWindow", "Load Previous", nullptr));
        EndProject->setText(QApplication::translate("MainWindow", "End Project", nullptr));
        Save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        Zoom->setText(QApplication::translate("MainWindow", "  Zoom", nullptr));
        Minus->setText(QApplication::translate("MainWindow", "     +", nullptr));
        Plus->setText(QApplication::translate("MainWindow", "     -", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
