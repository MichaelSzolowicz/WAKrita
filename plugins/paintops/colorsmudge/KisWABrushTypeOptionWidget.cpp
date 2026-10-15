#include "KisWABrushTypeOptionWidget.h"

#include <KisLager.h>

#include <QWidget>
#include <QComboBox>

#include <KisWABrushTypeOptionModel.h>
#include <KisWidgetConnectionUtils.h>

struct KisWABrushTypeOptionWidget::Private
{
    Private(lager::cursor<KisWABrushTypeOptionData> optionData)
        : model(optionData.zoom(kislager::lenses::to_base<KisWABrushTypeOptionData>))
    {
    }

    KisWABrushTypeOptionModel model;
    QComboBox *cmbBrushType {nullptr};
};

KisWABrushTypeOptionWidget::KisWABrushTypeOptionWidget(lager::cursor<KisWABrushTypeOptionData> optionData)
    : KisPaintOpOption(i18n("WA Brush Type"),
                       KisPaintOpOption::GENERAL,
                       true)
    , m_d(new Private(optionData))
{
    using namespace KisWidgetConnectionUtils;

    QWidget *page = new QWidget();

    m_d->cmbBrushType = new QComboBox(page);
    m_d->cmbBrushType->addItem(i18n("Color"), KisWABrushTypeOptionData::COLOR);
    m_d->cmbBrushType->addItem(i18n("Detail"), KisWABrushTypeOptionData::DETAIL);

    setConfigurationPage(page);

    connectControl(m_d->cmbBrushType, &m_d->model, "brushType");

    m_d->model.optionData.bind(std::bind(&KisWABrushTypeOptionWidget::emitSettingChanged, this));
}

KisWABrushTypeOptionWidget::~KisWABrushTypeOptionWidget()
{

}

void KisWABrushTypeOptionWidget::writeOptionSetting(KisPropertiesConfigurationSP setting) const
{
    m_d->model.bakedOptionDaata().write(setting.data());
}

void KisWABrushTypeOptionWidget::readOptionSetting(const KisPropertiesConfigurationSP setting)
{
    KisWABrushTypeOptionData data = *m_d->model.optionData;
    data.read(setting.data());
    m_d->model.optionData.set(data);
}
