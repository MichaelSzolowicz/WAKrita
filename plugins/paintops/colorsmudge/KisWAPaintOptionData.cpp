#include "KisWaPaintOptionData.h"

KisWaThicknessOptionData::KisWaThicknessOptionData()
    : KisCurveOptionData(
          KoID("WaThicknessOption", i18n("WA Thickness Option")),
          Checkability::Checkable)
{
}

KisWaPressureOptionData::KisWaPressureOptionData()
    : KisCurveOptionData(
          KoID("WaPressureOption", i18n("WA Pressure Option")),
          Checkability::Checkable)
{
}
