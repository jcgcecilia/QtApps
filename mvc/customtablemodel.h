#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
typedef QPair<Qt::ItemDataRole, QVariant> RowItem;
typedef QList<RowItem> DataRow ;


class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<DataRow> tableData;
    QVector<QHash<int, QVariant> > m_headerInfo;
public:
    explicit CustomTableModel(QObject *parent = 0);
    ~CustomTableModel();

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const ;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::TextAlignmentRole) ;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const ;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) ;

    Qt::ItemFlags flags(const QModelIndex& index) const ;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) ;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) ;

public slots:
    void addHeader(DataRow header);
    void addDataRow(DataRow row, int index);
    void appendDataRow(DataRow row);
    void removeDataRow(int row);
    void clearModel();
};

#endif // CUSTOMTABLEMODEL_H
