#include "KisWABrushTypeOptionData.h"

#include <kis_paintop_settings.h>
#include <kis_properties_configuration.h>

bool KisWABrushTypeOptionData::read(const KisPropertiesConfiguration *setting)
{
    brushType = (WABrushType)setting->getInt("brushType", COLOR);
    return true;
}

void KisWABrushTypeOptionData::write(KisPropertiesConfiguration *setting) const
{
    setting->setProperty("brushType", brushType);
}