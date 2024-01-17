#pragma once

#include <QtWidgets/QMainWindow>
#include <qsystemtrayicon.h>
#include <qmenu.h>
#include <qaction.h>
#include <qtreewidget.h>
#include <qtablewidget.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qlist.h>
#include "ui_TinyGUI.h"

/* Tiny files */
#include "GLOBALS.H"
#include "UTIL.H"
#include "SCAN.H"
#include "PARSE.H"
#include "ANALYZE.H"


class TinyGUI : public QMainWindow
{
    Q_OBJECT

public:
    TinyGUI(QWidget* parent = nullptr);
    ~TinyGUI();

private slots:
    /* Btn clicked funcitons */
    void btnOpen_Clicked();
    void btnSave_Clicked();
    void btnClear_Clicked();
    void btnGenerate_Clicked();
    void actAbout_Clicked();

private:
    Ui::TinyGUIClass ui;

    /* Qt icons */
    QIcon icon_info;
    QIcon icon_warn;
    QIcon icon_fail;

    /* Windows system message */
    QSystemTrayIcon* trayIcon;
    QMenu* trayIconMenu;
    QAction* actionHide;

    /* File Process */
    void Cleanup();
    void ShowTree(TreeNode* tree, QTreeWidgetItem* qtreeFather);
    void ShowError();
    QString getOpString(TokenType op);
};
