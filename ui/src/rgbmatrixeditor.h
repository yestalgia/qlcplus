/*
  Q Light Controller
  rgbmatrixeditor.h

  Copyright (c) Heikki Junnila

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef RGBMATRIXEDITOR_H
#define RGBMATRIXEDITOR_H

#include <QWidget>
#include <QHash>

#include "ui_rgbmatrixeditor.h"
#include "rgbmatrix.h"
#include "qlcpoint.h"
#include "doc.h"

class SpeedDialWidget;
class QGraphicsScene;
class RGBItem;
class QTimer;

/** @addtogroup ui_functions
 * @{
 */

class RGBMatrixEditor : public QWidget, public Ui_RGBMatrixEditor
{
    Q_OBJECT
    Q_DISABLE_COPY(RGBMatrixEditor)

    /************************************************************************
     * Initialization
     ************************************************************************/
public:
    RGBMatrixEditor(QWidget* parent, RGBMatrix* mtx, Doc* doc);
    ~RGBMatrixEditor();

    void stopTest();

public slots:
    void slotFunctionManagerActive(bool active);

private:
    void init();

    void updateSpeedDials();
    void fillPatternCombo();
    void fillFixtureGroupCombo();
    void fillAnimationCombo();
    void fillImageAnimationCombo();
    void fillGrabberSourceCombo();
    void fillGrabberTurningCombo();
    void fillGrabberFlippingCombo();
    void fillGrabberScalingCombo();
    void updateExtraOptions();
    void updateColors();
    void resetProperties(QLayoutItem *item);
    void displayProperties(RGBScript *script);

    bool createPreviewItems();

private slots:
    void slotPreviewTimeout();
    void slotNameEdited(const QString& text);
    void slotSpeedDialToggle(bool state);
    void slotPatternActivated(int patternIndex);
    void slotFixtureGroupActivated(int index);
    void slotBlendModeChanged(int index);
    void slotControlModeChanged(int index);
    void slotStartColorButtonClicked();
    void slotEndColorButtonClicked();
    void slotResetEndColorButtonClicked();

    void slotTextEdited(const QString& text);
    void slotFontButtonClicked();
    void slotAnimationActivated(int index);
    void slotOffsetSpinChanged();

    void slotImageEdited();
    void slotImageButtonClicked();
    void slotImageAnimationActivated(int index);

    void slotGrabberSourceActivated(const QString& text);
    void slotGrabberTurningActivated(const QString& text);
    void slotGrabberFlippingActivated(const QString& text);
    void slotGrabberScalingActivated(const QString& text);

    void slotLoopClicked();
    void slotPingPongClicked();
    void slotSingleShotClicked();

    void slotForwardClicked();
    void slotBackwardClicked();

    void slotDimmerControlClicked();

    void slotFadeInChanged(int ms);
    void slotFadeOutChanged(int ms);
    void slotHoldChanged(int ms);
    void slotDurationTapped();
    void slotDialDestroyed(QObject* dial);

    void slotTestClicked();
    void slotRestartTest();
    void slotModeChanged(Doc::Mode mode);
    void slotFixtureGroupAdded();
    void slotFixtureGroupRemoved();
    void slotFixtureGroupChanged(quint32 id);

    void slotSaveToSequenceClicked();
    void slotShapeToggle(bool);

    void slotPropertyComboChanged(QString value);
    void slotPropertySpinChanged(int value);
    void slotPropertyDoubleSpinChanged(double value);
    void slotPropertyEditChanged(QString text);

private:
    FunctionParent functionParent() const;

private:
    Doc* m_doc;
    RGBMatrix* m_matrix; // The RGBMatrix being edited
    RGBMatrixStep *m_previewHandler;

    QList <RGBScript> m_scripts;

    SpeedDialWidget *m_speedDials;

    QGraphicsScene* m_scene;
    QTimer* m_previewTimer;
    uint m_previewIterator;

    QHash<QLCPoint, RGBItem*> m_previewHash;
};

/** @} */

#endif
