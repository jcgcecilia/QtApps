#include "customgrid.h"
#include "custommenubutton.h"
#include <QDebug>


CustomGrid::CustomGrid(QWidget *parent)
    : QGridLayout(parent),
      m_row(0),
      m_col(0)
{
}

CustomGrid::~CustomGrid()
{

}

void CustomGrid::selectCurrent()
{
    selectCell(m_row, m_col, true);
}

void CustomGrid::selectCell(int row, int col, bool signal)
{
    QLayoutItem * tmp = itemAtPosition(m_row, m_col);
    QLayoutItem * tmp2 = itemAtPosition(row, col);
    if(tmp && tmp2)
    {
        static_cast<CustomButton *>(tmp->widget())->setSelected(false, signal);
        static_cast<CustomButton *>(tmp2->widget())->setSelected(true, signal);
        m_row = row;
        m_col = col;
    }
}
void CustomGrid::navigateUp()
{
    int row = m_row + 1;
    if(row >= rowCount())
    {
        row = 0;
    }
    selectCell(row, m_col);
}

void CustomGrid::navigateDown()
{
    int row = m_row-1;
    if(row < 0)
    {
        row = rowCount()-1;
    }
    selectCell(row, m_col);
}

void CustomGrid::navigateLeft()
{
    int col = m_col - 1;
    if(col < 0)
    {
        col = columnCount()-1;
    }
    selectCell(m_row, col);
}

void CustomGrid::navigateRight()
{
    int col = m_col + 1;
    if(col >= columnCount())
    {
        col = 0;
    }
    selectCell(m_row, col);
}

void CustomGrid::navigateRow(int row)
{
    if(row >= 0 && row < rowCount())
    {
        selectCell(row, m_col);
    }
}

void CustomGrid::navigateCol(int col)
{
    if(col >= 0 && col < columnCount())
    {
        selectCell(m_row, col);
    }
}

int CustomGrid::row() const
{
    return m_row;
}

int CustomGrid::col() const
{
    return m_col;
}

void CustomGrid::addRowActive(int row)
{
    rows.append(row);
}

QList<int> CustomGrid::getRows() const
{
    return rows;
}

void CustomGrid::setRows(const QList<int> &value)
{
    rows = value;
}

QWidget *CustomGrid::getItem() const
{
    return itemAtPosition(m_row, m_col)->widget();
}

void CustomGrid::setItem(QWidget *value)
{
    item = value;
}




