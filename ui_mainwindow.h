/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionSet_logic_level;
    QAction *actionNew_project;
    QAction *actionSave;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;
    QPushButton *connector;
    QFrame *line;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_2;
    QPushButton *addInOut;
    QPushButton *addNet;
    QTabWidget *tab;
    QWidget *tab_1;
    QGridLayout *gridLayout_3;
    QPushButton *notButton;
    QPushButton *andButton;
    QPushButton *orButton;
    QWidget *tab_2;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuProject;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(851, 419);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/resources/open-file_40455.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/resources/Save-as_37111.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon1);
        actionSet_logic_level = new QAction(MainWindow);
        actionSet_logic_level->setObjectName(QString::fromUtf8("actionSet_logic_level"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/resources/edit_pencil_write_1574.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSet_logic_level->setIcon(icon2);
        actionNew_project = new QAction(MainWindow);
        actionNew_project->setObjectName(QString::fromUtf8("actionNew_project"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/resources/new-file_40454.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_project->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/resources/Save_37110.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 2, 9, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 0, 1, 1);

        connector = new QPushButton(centralwidget);
        connector->setObjectName(QString::fromUtf8("connector"));

        gridLayout_4->addWidget(connector, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 1, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        addInOut = new QPushButton(centralwidget);
        addInOut->setObjectName(QString::fromUtf8("addInOut"));

        gridLayout_2->addWidget(addInOut, 0, 1, 1, 1);

        addNet = new QPushButton(centralwidget);
        addNet->setObjectName(QString::fromUtf8("addNet"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addNet->sizePolicy().hasHeightForWidth());
        addNet->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(addNet, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 1, 1, 1);

        tab = new QTabWidget(centralwidget);
        tab->setObjectName(QString::fromUtf8("tab"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy4);
        tab->setLayoutDirection(Qt::LeftToRight);
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_3 = new QGridLayout(tab_1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        notButton = new QPushButton(tab_1);
        notButton->setObjectName(QString::fromUtf8("notButton"));

        gridLayout_3->addWidget(notButton, 0, 0, 1, 2);

        andButton = new QPushButton(tab_1);
        andButton->setObjectName(QString::fromUtf8("andButton"));

        gridLayout_3->addWidget(andButton, 1, 0, 1, 1);

        orButton = new QPushButton(tab_1);
        orButton->setObjectName(QString::fromUtf8("orButton"));

        gridLayout_3->addWidget(orButton, 1, 1, 1, 1);

        tab->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab->addTab(tab_2, QString());

        gridLayout->addWidget(tab, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 851, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuProject = new QMenu(menubar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBar->setAutoFillBackground(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuProject->menuAction());
        menuFile->addAction(actionNew_project);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuProject->addAction(actionSet_logic_level);
        toolBar->addAction(actionNew_project);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_As);
        toolBar->addAction(actionSet_logic_level);

        retranslateUi(MainWindow);

        tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionSet_logic_level->setText(QCoreApplication::translate("MainWindow", "Set logic level", nullptr));
        actionNew_project->setText(QCoreApplication::translate("MainWindow", "New project", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_project->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add logical element", nullptr));
        connector->setText(QCoreApplication::translate("MainWindow", "Add connector", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        addInOut->setText(QCoreApplication::translate("MainWindow", "Add input/output", nullptr));
        addNet->setText(QCoreApplication::translate("MainWindow", "Add net", nullptr));
        notButton->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
        andButton->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
        orButton->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
        tab->setTabText(tab->indexOf(tab_1), QCoreApplication::translate("MainWindow", "Binary logic", nullptr));
        tab->setTabText(tab->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Ternary logic", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuProject->setTitle(QCoreApplication::translate("MainWindow", "Project", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
