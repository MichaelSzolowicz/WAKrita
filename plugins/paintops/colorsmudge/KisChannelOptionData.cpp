#include "KisChannelOptionData.h"

KisChannelOptionData::KisChannelOptionData()
    : KisCurveOptionData(
          KoID("ChannelOption", i18n("Channel Option")),
          Checkability::Checkable)
{
}
