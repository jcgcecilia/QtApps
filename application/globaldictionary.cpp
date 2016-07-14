#include "globaldictionary.h"


GlobalDictionary::GlobalDictionary(XMLStreamDocumentHandler *handler)
    : textsDataHandler(handler)
{

}

GlobalDictionary::~GlobalDictionary()
{

}

void GlobalDictionary::init()
{
    if(textsDataHandler)
    {
        QObject::connect(textsDataHandler, SIGNAL(data(RestDataItem*)),
                         this, SLOT(data(RestDataItem*)));
        QObject::connect(textsDataHandler, SIGNAL(parsingFinished()),
                         this, SLOT(done()));
        QObject::connect(textsDataHandler, SIGNAL(parsingStarted()),
                         this, SLOT(start()));
    }
}

QString GlobalDictionary::getText(int id)
{
    if(textDB.contains(id))
        return textDB.value(id);
    else
        return QString("");
}


void GlobalDictionary::data(RestDataItem * tex)
{
    Texts texts = *(static_cast<Texts *>(tex));
    setTextDB(texts.getTexts());
}

void GlobalDictionary::done()
{

}

void GlobalDictionary::start()
{

}

QHash<int, QString> GlobalDictionary::getTextDB() const
{
    return textDB;
}

void GlobalDictionary::setTextDB(const QHash<int, QString> &value)
{
    textDB = value;
}




