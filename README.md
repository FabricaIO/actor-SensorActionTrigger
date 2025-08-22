# actor-SensorActionTrigger
This is a utility actor that can trigger any other action based on a sensor reading. This inherits [PeriodicActionTrigger](https://github.com/FabricaIO/actor-PeriodicActionTrigger/).

## Constructor
The constructor takes two parameters:
* `name`: The name of the device (standard for actors)
* `configFile`: An optional name for the file to store the configuration in (should be unique for each instance)

## Actions
This device has the following actions available to it:
| Action ID | Action name   | Action Payload             | Return Value              | Description                                        |
| --------- | ------------- | -------------------------- | ------------------------- | -------------------------------------------------- |
| 0         | triggeraction | Any string (see below)     | JSON `success` as boolean | Triggers the set action, passing the payload to it |

## Configuration
Once a device hub is set up, these are the configuration parameters that can be set in the web interface:
* `Name`: The name of this device
* `taskPeriod`: An integer number of milliseconds for the period of how often the task runs and checks the sensor value (e.g. 1000 would be once a second)
* `taskEnabled`: A checkbox to enable or disable the task
* `Action`: A drop-down list of available actions to trigger, one can be selected
* `sensorParameter`: A list of sensors and their parameters that can be measured, one can be selected
* `activeState`: What to consider an active state, e.g. `Higher` will trigger the action if the sensor reading is higher than the threshold (see below)
* `threshold`: The threshold value to measure the sensor against
* `Payload`: A string payload that is passed to the action triggered. Refer to each actor's documentation to see what payloads are expected. The template `%SENSOR_VALUE%` can be used to substitute in the sensor value measured when the action was triggered.
