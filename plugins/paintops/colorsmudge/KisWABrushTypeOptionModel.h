#ifndef KISWABRUSHTYPEOPTIONMODEL_H
#define KISWABRUSHTYPEOPTIONMODEL_H

#include <lager/cursor.hpp>
#include <lager/extra/qt.hpp>

#include "KisWABrushTypeOptionData.h"
#include "KisWidgetConnectionUtils.h"

#include <QObject>

class KisWABrushTypeOptionModel : public QObject
{
    Q_OBJECT
public:
    KisWABrushTypeOptionModel(lager::cursor<KisWABrushTypeOptionData> optionData);
    lager::cursor<KisWABrushTypeOptionData> optionData;

    LAGER_QT_CURSOR(int, brushType);

    KisWABrushTypeOptionData bakedOptionDaata() const;
};

#endif // KISWABRUSHTYPEOPTIONMODEL_H
