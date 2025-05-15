/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2025 Sam Groveman
* 
* ArduinoJSON: https://arduinojson.org/
*
* Contributors: Sam Groveman
*/
#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <PeriodicActionTrigger.h>
#include <ParameterTrigger.h>

/// @brief Class providing action triggers based on sensor readings
class SensorActionTrigger : public PeriodicActionTrigger {
	protected:
		/// @brief Output configuration
		struct {
			/// @brief Threshold the test sensor value against
			double threshold = 2.5;

			/// @brief If the pump should activate on a low reading
			String activeState = "Higher";			
		} sensor_trigger_config;

		/// @brief Path to configuration file
		String config_path;

		/// @brief Provides access to sensor value
		ParameterTrigger sensor_value;

		bool configureOutput();
		bool triggerAction(String payload) override;
		JsonDocument addAdditionalConfig();

	public:
		SensorActionTrigger(String Name, String configFile = "SensorActionTrigger.json");
		bool begin();
		String getConfig();
		bool setConfig(String config, bool save);
};
