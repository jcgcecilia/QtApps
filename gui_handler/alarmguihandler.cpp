#include "alarmguihandler.h"
#include "managers/alarmmanager.h"
#include "restdatacontrollers/alarmobject.h"
#include "application/application.h"
#include "application/globaldictionary.h"
#include <QIcon>

static QIcon getAlarmIcon( QString state)
{
    if(state == "ACK")
    {
        return QIcon(":ack");
    }
    else if(state == "UNACK")
    {
        return QIcon(":unack");
    }
    else
    {
        return QIcon();
    }
}


AlarmGuiHandler::AlarmGuiHandler(QObject *parent,
                                 ManagerBase *guiData)
    : TableGuiHandler(parent),
      m_businessDataManager(guiData)
{
    // ASSERT here
}

AlarmGuiHandler::~AlarmGuiHandler()
{

}

void AlarmGuiHandler::initialize()
{
    Q_ASSERT(m_businessDataManager != NULL || m_model != NULL);

    if(m_businessDataManager)
    {
        // Support single and multiple items add and remove
        connect(m_businessDataManager, SIGNAL(clearGui()), this, SLOT(clearGui()));
        connect(m_businessDataManager, SIGNAL(addGuiItem(RestDataItem*)), this, SLOT(addGuiItem(RestDataItem*)));
        connect(m_businessDataManager, SIGNAL(removeGuiItem(int)), this, SLOT(removeGuiItem(int)));
    }
    DataRow header;
    header.append(RowItem(Qt::DisplayRole,"Alarm"));
    header.append(RowItem(Qt::DisplayRole,"Time"));
    header.append(RowItem(Qt::DisplayRole,"Alarm Description"));
    header.append(RowItem(Qt::DisplayRole,"Value"));
    header.append(RowItem(Qt::DisplayRole,"Setpoint"));
    header.append(RowItem(Qt::DisplayRole,"Latch"));
//    header.append(RowItem(Qt::DisplayRole,"TEST4"));
    m_model->addHeader(header);

}

void AlarmGuiHandler::footerAction(int col)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__<< col;
    switch (col) {
    case 0:
#ifdef TOUCH
        emit goToPrevious();
#else

#endif
        break;
    case 1:

        break;
    case 2:

        break;
    case 3:
        okAction(actiVeRow);
        //        AlarmManager * manager = static_cast<AlarmManager *>(m_businessDataManager);
        //        emit updateFooter(3, manager->isUnAckAlarm(row));
        //        break;
    default:
        break;
    }
}

void AlarmGuiHandler::navigationAction(int row, int col)
{
    AlarmManager * manager = static_cast<AlarmManager *>(m_businessDataManager);
    emit updateFooter(3, manager->isUnAckAlarm(row, NULL));

}

void AlarmGuiHandler::okAction(int row, int )
{
    AlarmManager * manager = static_cast<AlarmManager *>(m_businessDataManager);
    int * id;
    if( manager->isUnAckAlarm(row, id))
    {
        if(id)
        {
            qDebug() << id << *id;
            emit ackAlarm(*id);
        }
    }
}

void AlarmGuiHandler::clearGui()
{
    m_model->clearModel();
    itemIdList.clear();
}

void AlarmGuiHandler::addGuiItem(RestDataItem * item)
{
    Alarm * alarm = static_cast<Alarm *>(item);
    DataRow tmp;
    tmp.append(RowItem(Qt::DisplayRole,
                       getAlarmIcon(alarm->getState())));
    tmp.append(RowItem(Qt::DisplayRole,
                       alarm->getUtcTime()));
    tmp.append(RowItem(Qt::DisplayRole,
                       ML300Application::getDictionary()->getText(alarm->getNameTextId())));
    tmp.append(RowItem(Qt::DisplayRole,
                       alarm->getAutoAck()));
    tmp.append(RowItem(Qt::DisplayRole,
                       alarm->getPrecision()));
//    tmp.append(RowItem(Qt::DisplayRole,alarm->getLatched()));
    tmp.append(RowItem(Qt::DisplayRole,
                       alarm->getId()));
    m_model->addDataRow(tmp, 0);
    itemIdList.append(alarm->getId());
}

void AlarmGuiHandler::removeGuiItem(int id)
{
    QList<int>::const_iterator i;
    for( i = itemIdList.begin(); i != itemIdList.end(); i++)
    {
        if((*i) == id)
        {
            m_model->removeDataRow(i-itemIdList.begin());
            itemIdList.removeOne(*i);
            break;
        }
    }
}

int TableGuiHandler::getActiVeRow() const
{
    return actiVeRow;
}

void TableGuiHandler::setActiVeRow(int value)
{
    qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__ << value;
    actiVeRow = value;
}



TableGuiHandler::TableGuiHandler(QObject * parent) : GuiHandler(parent)
{

}

TableGuiHandler::~TableGuiHandler()
{

}

void TableGuiHandler::setModel(CustomTableModel *alarmModel)
{
    Q_ASSERT(alarmModel != NULL);
    m_model = alarmModel;
}

CustomTableModel *TableGuiHandler::model() const
{
    return m_model;
}




void AlarmIconDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(!index.isValid())
        return;


//    painter->save();
//    painter->setRenderHint(QPainter::Antialiasing);

//    QStyleOptionViewItemV4 opt = option;
//    QStyledItemDelegate::initStyleOption(&opt, index);
//    QRect rect = opt.rect;

    if(index.data().toString() == "ACK")
    {
        qDebug() << __PRETTY_FUNCTION__ << __LINE__ << __FILE__;
    }

    QStyledItemDelegate::paint(painter, option, index);

    // ... All my custom painting stuff here

//    painter->restore();
}
