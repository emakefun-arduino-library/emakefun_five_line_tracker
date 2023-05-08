#include <Arduino.h>
#include <line_tracker.h>

// 创建 LineTracker 实例
LineTracker line_tracker;

void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  Serial.println("setup");

  // 设置 LineTracker 的敏感度为 500
  line_tracker.SetSensitivity(500);
}

void loop() {
  String log;
  log += "sensor_states: 0x";

  // 获取传感器状态并转换为 16 进制格式字符串
  log += String(line_tracker.GetSensorStates(), HEX);
  log += " ";

  // 获取传感器值数组并逐一添加到 log 字符串中
  auto* sensor_values = line_tracker.GetSensorValues();
  for (uint8_t i = 0; i < LineTracker::LINE_NUMBER; i++) {
    log += i;
    log += ":";
    log += sensor_values[i]; // 获取一路传感器的值加到日志log变量中
    log += " ";
  }

  // 输出 log 字符串到串口
  Serial.println(log);
}
