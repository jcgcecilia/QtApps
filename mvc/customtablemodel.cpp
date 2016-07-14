#include "customtablemodel.h"
#include "application/globaldictionary.h"
CustomTableModel::CustomTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

CustomTableModel::~CustomTableModel()
{

}

void CustomTableModel::addDataRow(DataRow row, int pos)
{
    int col = 0;
    insertRows(pos, 1);
    foreach (RowItem item, row)
    {
        QModelIndex inde = index(pos, col);

        setData(inde,item.second , item.first);
        col++;
    }
}

void CustomTableModel::appendDataRow(DataRow row)
{
    addDataRow(row, rowCount());
}

void CustomTableModel::removeDataRow(int row)
{
    removeRows(row, 1);
}

void CustomTableModel::clearModel()
{
    for(int i = 0; i < tableData.size(); i++)
    {
        removeDataRow(i);
    }
//    tableData.clear();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        QVariant headerValue = m_headerInfo.value(section).value(role);
        if (!headerValue.isValid()) {
            // Try EditRole if DisplayRole wasn't present
            headerValue = m_headerInfo.value(section).value(Qt::EditRole);
        }
        if (!headerValue.isValid()) {
            headerValue = QVariant(section).toString();
        }
        return headerValue;
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

bool CustomTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    int numColumns = columnCount();
    if (section < 0 || section >= numColumns) {
        return false;
    }

    if (orientation != Qt::Horizontal) {
        // We only care about horizontal headers.
        return false;
    }

    if (m_headerInfo.size() != numColumns) {
        m_headerInfo.resize(numColumns);
    }

    if (value != headerData(section, orientation, role))
    {
        m_headerInfo[section][role] = value;
        emit headerDataChanged(orientation, section, section);
        return true;
    }

    return false;
}


QModelIndex CustomTableModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}


int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return tableData.size();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 7;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(index.row() >= tableData.size() || tableData.isEmpty())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::DecorationRole)
    {
        DataRow p = tableData.at(index.row());
        if(p.isEmpty() || index.column() >= p.size())
            return QVariant();
        else
            return p[index.column()].second;
    }

    return QVariant();
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid())
    {
        if (data(index, role) != value)
        {
            int row = index.row();
            DataRow tmp = tableData.at(row);
            QPair<Qt::ItemDataRole, QVariant> pair;
            pair.first = static_cast<Qt::ItemDataRole>(role);
            pair.second = value;
            tmp.insert(index.column(), pair);
            tableData.replace(index.row(), tmp);
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
            emit dataChanged(index, index, QVector<int>() << role);
#else
            emit dataChanged(index, index);
#endif
            return true;
        }
    }
    return false;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

bool CustomTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for (int i = row; i < row + count; i++)
    {
        DataRow tmp;
        tableData.insert(i, tmp);
    }
    endInsertRows();
    return true;
}

bool CustomTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, 1 /*+ count - 1*/);
    if(row >= tableData.size() || row < 0)
       return false;

//    removeRow(row);
    for (int i = row; i < count; i++)
    {
    tableData.removeAt(row);
    }
    endRemoveRows();
    return true;
}

void CustomTableModel::addHeader(DataRow header)
{
    for(int i = 0; i < header.size(); i ++)
    {
        setHeaderData(i, Qt::Horizontal, header.at(i).second, header.at(i).first);
    }
}
