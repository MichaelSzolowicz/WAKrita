/*
 *  SPDX-FileCopyrightText: 2021 Dmitry Kazakov <dimula73@gmail.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef KRITA_KISCOLORSMUDGESTRATEGY_H
#define KRITA_KISCOLORSMUDGESTRATEGY_H

#include <KisOptimizedByteArray.h>
#include <kis_dab_cache.h>

struct KisColorSmudgeStrategyOptions
{
    qreal opacity;
    qreal colorRateValue;
    qreal smudgeRateValue;
    qreal maxPossibleSmudgeRateValue;
    qreal lightnessStrengthValue;
    qreal smudgeRadiusValue;
    qreal waThicknessValue;

    KisColorSmudgeStrategyOptions(qreal opacity,
                                  qreal colorRateValue,
                                  qreal smudgeRateValue,
                                  qreal maxPossibleSmudgeRateValue,
                                  qreal lightnessStrengthValue,
                                  qreal smudgeRadiusValue,
                                  qreal waThicknessValue) :
        opacity(opacity)
        ,   colorRateValue(colorRateValue)
        ,   smudgeRateValue(smudgeRateValue)
        ,   maxPossibleSmudgeRateValue(maxPossibleSmudgeRateValue)
        ,   lightnessStrengthValue(lightnessStrengthValue)
        ,   smudgeRadiusValue(smudgeRadiusValue)
        ,   waThicknessValue(waThicknessValue)
    {

    }
};

class KisColorSmudgeStrategy
{
public:
    KisColorSmudgeStrategy();

    virtual ~KisColorSmudgeStrategy() = default;

    virtual void initializePainting() = 0;

    virtual void updateMask(KisDabCache *dabCache,
                            const KisPaintInformation& info,
                            const KisDabShape &shape,
                            const QPointF &cursorPoint,
                            QRect *dstDabRect,
                            qreal lightnessStrength) = 0;

    virtual QVector<QRect> paintDab(const QRect &srcRect, const QRect &dstRect,
                                    const KoColor &currentPaintColor,
                                    KisColorSmudgeStrategyOptions options) = 0;

    virtual const KoColorSpace* preciseColorSpace() const = 0;

protected:
    KisOptimizedByteArray::MemoryAllocatorSP m_memoryAllocator;
};


#endif //KRITA_KISCOLORSMUDGESTRATEGY_H
