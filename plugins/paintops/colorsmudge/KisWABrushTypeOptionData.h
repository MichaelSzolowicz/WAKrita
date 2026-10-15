#ifndef KISWABRUSHTYPEOPTIONDATA_H
#define KISWABRUSHTYPEOPTIONDATA_H

#include <QtGlobal>
#include <boost/operators.hpp>

class KisPropertiesConfiguration;
class KisPaintopLodLimitations;

struct KisWABrushTypeOptionData : boost::equality_comparable<KisWABrushTypeOptionData>
{
    inline friend bool operator==(const KisWABrushTypeOptionData &lhs, const KisWABrushTypeOptionData &rhs) {
        return lhs.brushType == rhs.brushType;
    }

    enum WABrushType { COLOR, DETAIL };

    WABrushType brushType {COLOR};

    bool read(const KisPropertiesConfiguration *setting);
    void write(KisPropertiesConfiguration *setting) const;
};

#endif // KISWABRUSHTYPEOPTIONDATA_H
