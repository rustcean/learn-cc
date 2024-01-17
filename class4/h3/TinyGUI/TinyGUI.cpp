#include "TinyGUI.h"

TinyGUI::TinyGUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/* Hide Error table default */
//	ui.tblError->setVisible(false);

	/* Icons */
	QIcon icon(":/TinyGUI/resources/analyzser.ico");  // Application icon
	icon_info = QApplication::style()->standardIcon((QStyle::StandardPixmap)9);  // INFO icon
	icon_warn = QApplication::style()->standardIcon((QStyle::StandardPixmap)10);
	icon_fail = QApplication::style()->standardIcon((QStyle::StandardPixmap)11);

	/* Init tray icon */
	trayIcon = new QSystemTrayIcon(this);
	trayIconMenu = new QMenu(this);
	trayIcon->setIcon(icon);
	trayIcon->show();
	/* Set tray icon right-clickable */
	actionHide = new QAction(icon, "����", trayIconMenu);
	trayIconMenu->addAction(actionHide);
	trayIcon->setContextMenu(trayIconMenu);
	/* Show global message */
	trayIcon->showMessage(QString("����"), QString("��������ɹ�"), icon_info);

	/* Init Error tableWidget */
//	ui.tblError->setRowCount(3);
//	ui.tblError->setEditTriggers(QAbstractItemView::NoEditTriggers);

	/* Init treeWidget */
//	ui.treeWidget->setColumnCount(1);

	/* Slot funcitons */
//	QObject::connect(ui.btnOpen, SIGNAL(clicked()), this, SLOT(btnOpen_Clicked()));
//	QObject::connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(btnSave_Clicked()));
//	QObject::connect(ui.btnClear, SIGNAL(clicked()), this, SLOT(btnClear_Clicked()));
//	QObject::connect(ui.btnGenerate, SIGNAL(clicked()), this, SLOT(btnGenerate_Clicked()));
//	QObject::connect(ui.actAbout, SIGNAL(triggered()), this, SLOT(actAbout_Clicked()));
}

TinyGUI::~TinyGUI()
{}

void TinyGUI::btnOpen_Clicked()
{
	/* Using QFileDialog to open file */
	QString fileName = QFileDialog::getOpenFileName(this, tr("���ļ�"), "", tr("TinyԴ�����ļ� (*.tny);;�����ļ� (*)"));
	if (fileName.isEmpty())
	{
		/* Show warning */
		QMessageBox::warning(NULL, QString("��ʾ"), QString("��ȡ����ȡ��"));
		return;
	}

	/* Read file */
	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		QString fileContent = in.readAll();

		ui.inputTinyprogram->setPlainText(fileContent);
		file.close();
	}
	else
	{
		QString message = "���ļ�" + fileName + "ʧ�ܣ�";
		QMessageBox::warning(NULL, QString("����"), message);
	}
}

void TinyGUI::btnSave_Clicked()
{
	/* Using QFileDialog to save file */
	QString fileName = QFileDialog::getSaveFileName(this, tr("�����ļ�"), "", tr("TinyԴ�����ļ� (*.tny);;�ı��ļ� (*.txt);;�����ļ� (*)"));
	if (fileName.isEmpty())
	{
		/* Show warning */
		QMessageBox::warning(NULL, QString("��ʾ"), QString("��ȡ�����棡"));
		return;
	}

	/* Write file */
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream out(&file);
		out << ui.inputTinyprogram->toPlainText();
		file.close();
	}
	else
	{
		QString message = "�����ļ�" + fileName + "ʧ�ܣ�";
		QMessageBox::warning(NULL, QString("����"), message);
	}
}

void TinyGUI::btnClear_Clicked()
{
	ui.inputTinyprogram->clear();
}

void TinyGUI::btnGenerate_Clicked()
{
	/*
	* Generate Syntax Tree:
	* 0. Check whether there exists program to analyze.
	* 1. Save text in textbox to temp.tny.
	* 2. Using Tiny funcitons to read temp.tny.
	* 3. Process, compile tny file.
	* 4. Display Syntax Tree in Treeview.
	* 5. Clean up temp.tny.
	*/

	/* Stage 0 */
	if (ui.inputTinyprogram->document()->isEmpty())
	{
		QString message = "��û���ҷ���զ�Է��أ����ڵ��ˣ�\n��ȷ����������TinyԴ����";
		QMessageBox::warning(NULL, QString("����"), message);
		return;
	}

	/* Stage 1 */
	QString fileTemp = "temp.tny";
	QFile file(fileTemp);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream out(&file);
		out << ui.inputTinyprogram->toPlainText();
		file.close();
	}
	else
	{
		QString msg = "�����ļ�����ʧ�ܣ���ȷ�����ӵ����Ӧ��Ȩ���Լ�����ӵ��10MiB���Ͽռ䡣";
		trayIcon->showMessage(QString("����ʧ��"), msg, icon_fail);
		return;
	}

	/* Stage 2 */
	source = fopen("temp.tny", "r");
	if (source == NULL)
	{
		QString msg = "�����ļ���ȡʧ�ܣ���ȷ�����ӵ����Ӧ��Ȩ�ޡ�";
		trayIcon->showMessage(QString("����ʧ��"), msg, icon_fail);
		return;
	}

	/* Stage 3 */
	TreeNode* syntaxTree;
	syntaxTree = parse();

	/* Stage 4 */
	ui.treeWidget->clear();
	QList<QString> topItemName{ "�﷨��" };
	QTreeWidgetItem* topItem = new QTreeWidgetItem(topItemName);  // Get Top node
	ui.treeWidget->addTopLevelItem(topItem);
	ShowTree(syntaxTree, topItem);
	ui.treeWidget->expandAll();
	ShowError();


	/* Stage 5 */
	fclose(source);
	Cleanup();
}

void TinyGUI::actAbout_Clicked()
{
	/* Show About information */
	QString detail = "Ӧ�ð汾\t1.0.0-release\nQt�汾\t6.5.3����";
	QMessageBox::information(NULL, QString("���ڴ�Ӧ��"), detail);
}

void TinyGUI::Cleanup()
{
	/*
	* Clean Up
	* 1. Clean temp file.(temp.tny)
	* 2. Reset all pointer, vectors.
	* 3. Clear TreeWidgets.
	*/
	auto currentPath = QDir::currentPath();
	QString fileTemp = currentPath + QDir::separator() + "temp.tny";
	bool flag = QFile::remove(fileTemp);
	qDebug() << "Remove temp file: " << flag;

	errors.clear();
	lineno = 0;
	memset(tokenString, '\0', sizeof(tokenString));
	resetlinebuf();
}

void TinyGUI::ShowTree(TreeNode* tree, QTreeWidgetItem* qtreeFather)
{
	int i;
	QString nodeText;
	while (tree != NULL)
	{
		if (tree->nodekind == StmtK)
		{
			switch (tree->kind.stmt) {
			case IfK:
				nodeText = "If";
				break;
			case ElseK:
				nodeText = "Else";
				break;
			case RepeatK:
				nodeText = "Repeat";
				break;
			case AssignK:
				nodeText = QString("Assign to: %1").arg(tree->attr.name);
				break;
			case ReadK:
				nodeText = QString("Read: %1").arg(tree->attr.name);
				break;
			case WriteK:
				nodeText = "Write";
				break;
			case ForK:
				nodeText = "For: ";
				break;
			default:
				nodeText = "Unknown ExpNode kind";
				break;
			}
		}
		else if (tree->nodekind == ExpK)
		{
			switch (tree->kind.exp)
			{
			case OpK:
				nodeText = "Op: " + getOpString(tree->attr.op);
				break;
			case ConstK:
				nodeText = QString("Const: %1").arg(tree->attr.val);
				break;
			case IdK:
				nodeText = QString("Id: %1").arg(tree->attr.name);
				break;
			default:
				nodeText = "Unknown ExpNode kind";
				break;
			}
		}
		else
		{
			nodeText = "Unknown node kind";
		}
		QList<QString> childName{ nodeText };
		QTreeWidgetItem* childItem = new QTreeWidgetItem(childName);
		qtreeFather->addChild(childItem);
		for (i = 0; i < MAXCHILDREN; i++)
			ShowTree(tree->child[i], childItem);
		tree = tree->sibling;
	}
}

void TinyGUI::ShowError()
{
	if (errors.empty())
	{
//		ui.tblError->setVisible(false);
		trayIcon->showMessage(QString("�������"), QString("��0������"), icon_info);
		return;
	}

//	ui.tblError->setVisible(true);
	int errorNum = errors.size();

	/* Set tableWidget */
//	ui.tblError->setRowCount(errorNum);
//	ui.tblError->setColumnCount(3);
//	QStringList header;
//	header << "��������" << "�к�" << "������Ϣ";
//	ui.tblError->setHorizontalHeaderLabels(header);

	/* Set tableWidget items */
	for (int i = 0; i < errorNum; i++)
	{
//		ui.tblError->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(errors[i].errorType)));
//		ui.tblError->setItem(i, 1, new QTableWidgetItem(QString::number(errors[i].lineno)));
//		ui.tblError->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(errors[i].msg)));
	}

	/* Fix display */
//	ui.tblError->resizeColumnsToContents();

	/* Push Windows messages */
	string m = "��" + std::to_string(errorNum) + "������";
	trayIcon->showMessage(QString("�������"), QString::fromStdString(m), icon_fail);
}

QString TinyGUI::getOpString(TokenType op)
{
	switch (op)
	{
	case ENDFILE:
		return "ENDFILE";
	case ERROR:
		return "ERROR";
	case IF:
		return "IF";
	case THEN:
		return "THEN";
	case ELSE:
		return "ELSE";
	case END:
		return "END";
	case REPEAT:
		return "REPEAT";
	case UNTIL:
		return "UNTIL";
	case READ:
		return "READ";
	case WRITE:
		return "WRITE";
	case ID:
		return "ID";
	case NUM:
		return "NUM";
	case ASSIGN:
		return "ASSIGN";
	case PLUSASSIGN:
		return "PLUSASSIGN";
	case EQ:
		return "=";
	case LT:
		return "<";
	case GT:
		return ">";
	case LEQ:
		return "<=";
	case GEQ:
		return ">=";
	case NEQ:
		return "<>";
	case PLUS:
		return "+";
	case MINUS:
		return "-";
	case TIMES:
		return "*";
	case OVER:
		return "/";
	case LPAREN:
		return "(";
	case RPAREN:
		return ")";
	case SEMI:
		return ";";
	case REM:
		return "%";
	case POW:
		return "^";
	case FOR:
		return "FOR";
	case TO:
		return "TO";
	case DO:
		return "DO";
	case DOWNTO:
		return "DOWNTO";
	case ENDDO:
		return "ENDDO";
	case RE:
		return "|";
	case RT:
		return "&";
	case RCS:
		return "#";
	case RCQ:
		return "?";
	case RF:
		return "RF";
	case REEXP:
		return "Regular Expression";
	case BITAND:
		return "and";
	case BITOR:
		return "or";
	case BITNOT:
		return "not";
	default:
		return "UNKNOWN";
	}
}
