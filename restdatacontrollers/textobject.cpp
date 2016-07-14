#include "textobject.h"
#include "network/httprequest.h"

Texts::Texts()
{

}

Texts::~Texts()
{

}

void Texts::addText(int id, QString text)
{
    texts.insert(id, text);
}
QHash<int, QString> & Texts::getTexts()
{
    return texts;
}

void Texts::setTexts(const QHash<int, QString> &value)
{
    texts = value;
}

void Texts::clean()
{
    texts.clear();
}

