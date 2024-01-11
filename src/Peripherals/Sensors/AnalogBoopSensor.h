#pragma once

/**
 * Boop sensor
 * Overlays a face upon infrared sensor activation
 */

#include "Utilities/Typedefs.h"
#include "Utilities/Globals.h"
#include "AnalogSensor.h"
#include "BoopSensor.h"
#include "Drawing/DisplayManager.h"
#include "Animation/Overlay/OverlayPlayer.h"

class AnalogBoopSensor : public AnalogSensor {
  private:
    BoopSensor* boopSensor;

  protected:
    void onEnable() override {
        boopSensor->onEnable();
    }

    void onDisable() override {
        boopSensor->onDisable();
    }

    void onUpdate() override {
        boopSensor->onUpdate();
    }

    void onCalibrate() override {
        char buf[16];
        sprintf(buf, "%.0f%%", ((f32)calibrationReadings/(f32)maxCalibrationReadings) * 100);
        boopSensor->displayManager->hud->drawText(HUDElement::textBoop, buf);
    }

    void onTrack(u16 value) override {
        char buf[16];
        sprintf(buf, "%3.0f %3.0f %3.0f", value * 0.1, triggerValue * 0.1, baseline * 0.1);
        boopSensor->displayManager->hud->drawText(HUDElement::textBoop, buf);
    }

  public:
    AnalogBoopSensor(
        DisplayManager* displayManager, 
        OverlayPlayer* overlay, 
        OverlaySequence* enableOverlay,
        OverlaySequence* disableOverlay, 
        u8 sensorPin, 
        u8 triggerCount, 
        u8 maxTriggers, 
        f32 triggerMultiplier = 0.5f,
        u16 maxCalibrationReadings = 500,
        bool inverted = false,
        bool enabled = true
    )
        : AnalogSensor(sensorPin, triggerCount, maxTriggers, triggerMultiplier, maxCalibrationReadings, inverted, enabled)
    {
        boopSensor = new BoopSensor(displayManager, overlay, enableOverlay, disableOverlay);
        TOASTER_LOG(
            "Analog boop sensor initialized with Pin: %d, Trigger count: %d, Enabled: %d\n", sensorPin,
            triggerCount, enabled
        );
    }
};