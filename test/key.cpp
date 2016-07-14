#include "key.h"
#include "ui_key.h"

Key::Key(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Key)
{
    ui->setupUi(this);
}

Key::~Key()
{
    delete ui;
}
