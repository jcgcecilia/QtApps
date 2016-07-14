#include <QKeyEvent>
#include "customtable.h"
#include "mvc/customtableview.h"
#include "mvc/customtablemodel.h"
#include <QLabel>
#include <QDebug>
#include "customfooter.h"
#include "gui_handler/alarmguihandler.h"
CustomTable::CustomTable(ScreensContainer::ScreenId id,  ScreensContainer *parent, TableGuiHandler * guiHandler)
    : Screen(id, guiHandler, parent)
{
    m_screenTitle = new QLabel(this);
    m_screenTitle->setObjectName("screenLabel");
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(m_screenTitle->sizePolicy().hasHeightForWidth());
    m_screenTitle->setSizePolicy(sizePolicy);
    m_screenTitle->setMinimumSize(QSize(800, 50));
    m_screenTitle->setMaximumSize(QSize(1600, 100));

    QPalette palette1;
    QBrush brush2(QColor(0,141,210));
    brush2.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
    QBrush brush3(QColor(0,141,210));
    brush3.setStyle(Qt::SolidPattern);
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
    palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
    m_screenTitle->setPalette(palette1);
    m_screenTitle->setAutoFillBackground(true);
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    font.setStyleStrategy(QFont::PreferAntialias);
    m_screenTitle->setFont(font);
    m_screenTitle->setLineWidth(0);
    m_screenTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    m_screenTitle->setMargin(10);

    m_mainGrid->addWidget(m_screenTitle, 0, 0, 1, 1);

}

void CustomTable::setScreenTitle(const QString &title)
{
    m_screenTitle->setText(title);
}

//void CustomTable::setDelegate(int col, QStyledItemDelegate *delegate)
//{
//    m_tableView.setDelegate(col, delegate);
//}

void CustomTable::initialize()
{
//    m_tableView = new CustomTableView;
    m_tableView.setParent(this);
    m_mainGrid->addWidget(&m_tableView, 1, 0, 1, 1);
    connect(&m_tableView, SIGNAL(enteredRow(int)), this, SLOT(rowEntered(int)));
    connect(&m_tableView, SIGNAL(selectedRow(int)), this, SLOT(rowSelected(int)));
    connect(m_guiHandler, SIGNAL(updateFooter(int,bool)), this, SLOT(updateFooter(int,bool)));
}
#ifdef KEYS

void CustomTable::keyPressEvent(QKeyEvent *ev)
{

}

void CustomTable::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    switch (ev->key())
    {
    case key_up:
        m_tableView.scrollDown();
        static_cast<TableGuiHandler *>(m_guiHandler)->setActiVeRow(m_tableView.currentIndex().row());
        m_guiHandler->navigationAction(m_tableView.currentIndex().row(),0);
        ev->accept();
        break;
    case key_down:
        m_tableView.scrollUp();
        static_cast<TableGuiHandler *>(m_guiHandler)->setActiVeRow(m_tableView.currentIndex().row());
        m_guiHandler->navigationAction(m_tableView.currentIndex().row(),0);
        ev->accept();
        break;
    case key_ok:
//        emit rowSelected(m_tableView.currentIndex().row());
        m_guiHandler->okAction(m_tableView.currentIndex().row(),0);
        ev->accept();
        break;
    case key_left:
//        m_contentGrid->navigateCol(0);
        footerItemSelected(0);
        break;
    case key_leftcenter:
//        m_contentGrid->navigateCol(1);
        footerItemSelected(1);
        break;
    case key_rightcenter:
//        m_contentGrid->navigateCol(2);
        footerItemSelected(2);
        break;
    case key_right:
//        m_contentGrid->navigateCol(3);
//        footerItemSelected(3);
        if(m_footer->isItemEnabled(3))
            footerItemSelected(3);
//            m_guiHandler->okAction(m_tableView.currentIndex().row(),0);
        break;
//    case key_ok:
//        ev->accept();
//        m_contentGrid->selectCurrent();
//        break;
    default:
        Screen::keyReleaseEvent(ev);
        ev->ignore();
        break;
    }
}
#endif

void CustomTable::rowSelected(int row)
{
    static_cast<TableGuiHandler *>(m_guiHandler)->setActiVeRow(row);
}

void CustomTable::rowEntered(int row)
{
    static_cast<TableGuiHandler *>(m_guiHandler)->setActiVeRow(row);
    m_guiHandler->navigationAction(m_tableView.currentIndex().row(),0);
}


void CustomTable::setTableModel(CustomTableModel  *tableModel)
{
    Q_ASSERT(tableModel != NULL);
//    if(m_tableView)
        m_tableView.setModel(static_cast<TableGuiHandler *>(m_guiHandler)->model());
}
/**
 * @brief CustomTable::setColsWidth
 * @param cols
 * @Desc Set model prior to setting model
 */
void CustomTable::setColsWidth(const QList<int> &cols)
{
    m_tableView.setColsWidth(cols);
}

void CustomTable::showEvent(QShowEvent *event)
{
    m_tableView.selectRow(0);
//    emit rowEntered(0);
    m_guiHandler->navigationAction(0,0);
}

