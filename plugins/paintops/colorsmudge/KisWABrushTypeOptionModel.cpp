#include "KisWABrushTypeOptionModel.h"

#include <KisLager.h>

KisWABrushTypeOptionModel::KisWABrushTypeOptionModel(lager::cursor<KisWABrushTypeOptionData> optionData)
    : optionData(optionData)
    , LAGER_QT(brushType) {optionData[&KisWABrushTypeOptionData::brushType].zoom(kislager::lenses::do_static_cast<KisWABrushTypeOptionData::WABrushType, int>)}
{
}

KisWABrushTypeOptionData KisWABrushTypeOptionModel::bakedOptionDaata() const
{
    KisWABrushTypeOptionData data = optionData.get();
    return data;
}
