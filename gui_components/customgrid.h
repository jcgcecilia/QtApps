#ifndef CUSTOMGRID_H
#define CUSTOMGRID_H
#include <QLayout>

class CustomGrid : public QGridLayout
{

public:
    CustomGrid(QWidget * parent);
    ~CustomGrid();
    void selectCurrent();
   void selectCell(int row, int col, bool signal = false);
   void navigateUp();
   void navigateDown();
   void navigateLeft();
   void navigateRight();
   void navigateRow(int row);
   void navigateCol(int col);

   int row() const;
   int col() const;

   void addRowActive(int row);

   QList<int> getRows() const;
   void setRows(const QList<int> &value);
   QWidget *getItem() const;
   void setItem(QWidget *value);

private:
   int m_row;
   int m_col;
   QList<int> rows;
   QWidget * item;
};

#endif // CUSTOMGRID_H
