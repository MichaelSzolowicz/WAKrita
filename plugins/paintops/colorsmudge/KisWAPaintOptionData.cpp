#include "KisWaPaintOptionData.h"

KisWaPaintOptionData::KisWaPaintOptionData()
    : KisCurveOptionData(
          KoID("WaThicknessOption", i18n("WA Thickness Option")),
          Checkability::Checkable)
{
}
