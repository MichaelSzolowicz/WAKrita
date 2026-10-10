#ifndef KISWABRUSHTYPEOPTIONWIDGET_H
#define KISWABRUSHTYPEOPTIONWIDGET_H

#include <kis_paintop_option.h>
#include <KisWABrushTypeOptionData.h>
#include <lager/cursor.hpp>

class KisWABrushTypeOptionWidget : public KisPaintOpOption
{
public:
    using data_type = KisWABrushTypeOptionData;

    KisWABrushTypeOptionWidget(lager::cursor<KisWABrushTypeOptionData> optionData);
    ~KisWABrushTypeOptionWidget();

    void writeOptionSetting(KisPropertiesConfigurationSP setting) const override;
    void readOptionSetting(const KisPropertiesConfigurationSP setting) override;

private:
    struct Private;
    const QScopedPointer<Private> m_d;
};

#endif // KISWABRUSHTYPEOPTIONWIDGET_H
