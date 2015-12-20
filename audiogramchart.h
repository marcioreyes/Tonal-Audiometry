#ifndef AUDIOGRAMCHART_H
#define AUDIOGRAMCHART_H
#include <QPaintDevice>
#include <QPaintEngine>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QImage>
#include <QPixmap>
#include "/home/krzysztof/Programming/Qt/QML/Audiometry/Audiometry/TonalAudiometry/audiogram.h"


class AudiogramChart
{
    static constexpr int VERTICAL_LINES = 11;
    static constexpr int HORIZONTAL_LINES = 14;
    static constexpr float TEXT_TO_GRID_SPACING = 0.1;
    static constexpr int TEXT_TO_GRID_PX_DISTANCE = 10;

    QSize chartSize;
    QSize gridSize;
    QPoint startDrawGridPoint;
    QPoint endDrawGridPoint;
    int horizontalStepPx{0};
    int verticalStepPx{0};

public:
    AudiogramChart(int width, int height);
    AudiogramChart(const QSize &size);

    void saveJPG(const QString &noExtensionName);
    QPixmap getPixmap();

private:
    void calculateStepsPx();
    QPainterPath createChartGrid();
    void createTextAxis(QPainter &path, int fontSizePx = 12);
    void createTextLabel(QPainter &path, int fontSizePx = 24);
    void paint(QPainter *painter);
};

#endif // AUDIOGRAMCHART_H