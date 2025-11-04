/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2025 Sam Groveman
* 
* External libraries needed:
* ArduinoJSON: https://arduinojson.org/
*
* Contributors: Sam Groveman
*/
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <PeriodicActionTrigger.h>
#include <ParameterGetter.h>

/// @brief Class providing action triggers based on sensor readings
class SensorActionTrigger : public PeriodicActionTrigger {
	protected:
		/// @brief Trigger configuration
		struct {
			/// @brief Threshold the test sensor value against
			double threshold = 2.5;

			/// @brief What state should trigger the action
			String activeState = "Higher";			
		} sensor_trigger_config;

		/// @brief Path to configuration file
		String config_path;

		/// @brief Provides access to sensor value
		ParameterGetter sensor_value;

		/// @brief Index for action that Checks if the sensor should trigger the action
		int forceTrigger;

		bool configureOutput();
		bool triggerAction(String payload) override;
		JsonDocument addAdditionalConfig();

	public:
		SensorActionTrigger(String Name, String configFile = "SensorActionTrigger.json");
		std::tuple<bool, String> receiveAction(int action, String payload);
		bool begin();
		String getConfig();
		bool setConfig(String config, bool save);
};
