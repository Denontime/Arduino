#include <ESP8266WiFi.h>
/* 依赖 PubSubClient 2.4.0 */
#include <PubSubClient.h>
/* 依赖 ArduinoJson 5.13.4 */
#include <ArduinoJson.h>

//#define SENSOR_PIN    D4

/* 连接您的WIFI SSID和密码 */
#define WIFI_SSID         "CMCC-DXKU"
#define WIFI_PASSWD       "xkp5qbi@"

/*
{
  "ProductKey": "a1m6LNzElQ1",
  "DeviceName": "HelloMqtt",
  "DeviceSecret": "XWZZGIfHjBzTDgoFabryjiVZXyho7Z1r"
}
 设备的三元组信息*/
#define PRODUCT_KEY       "a1m6LNzElQ1"
#define DEVICE_NAME       "HelloMqtt"
#define DEVICE_SECRET     "XWZZGIfHjBzTDgoFabryjiVZXyho7Z1r"
#define REGION_ID         "cn-shanghai"

/* 线上环境域名和端口号，不需要改 */
#define MQTT_SERVER       PRODUCT_KEY ".iot-as-mqtt." REGION_ID ".aliyuncs.com"
#define MQTT_PORT         1883
#define MQTT_USRNAME      DEVICE_NAME "&" PRODUCT_KEY

/*
{
  CLIENT_ID ： HelloMqtt|securemode=3,signmethod=hmacsha1|
  MQTT_PASSWD ： 9E22A138A4F09B8F93014C82456F16052708638B
 }
*/
#define CLIENT_ID         "HelloMqtt|securemode=3,signmethod=hmacsha1|"
// 算法工具: http://iot-face.oss-cn-shanghai.aliyuncs.com/tools.htm 进行加密生成password
// password教程 https://www.yuque.com/cloud-dev/iot-tech/mebm5g
#define MQTT_PASSWD       "9E22A138A4F09B8F93014C82456F16052708638B"

#define ALINK_BODY_FORMAT         "{\"id\":\"123\",\"version\":\"1.0\",\"method\":\"thing.event.property.post\",\"params\":%s}"
#define ALINK_TOPIC_PROP_POST     "/sys/" PRODUCT_KEY "/" DEVICE_NAME "/thing/event/property/post"
 
// /sys/a1m6LNzElQ1/HelloMqtt/thing/event/property/post

unsigned long lastMs = 0;
unsigned int t = 0;
WiFiClient espClient;
PubSubClient  client(espClient);


void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    payload[length] = '\0';
    Serial.println((char *)payload);

}


void wifiInit()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWD);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("Connected to AP");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    
    Serial.print("espClient [");


    client.setServer(MQTT_SERVER, MQTT_PORT);   /* 连接WiFi之后，连接MQTT服务器 */
    client.setCallback(callback);
}


void mqttCheckConnect()
{
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT Server ...");
        if (client.connect(CLIENT_ID, MQTT_USRNAME, MQTT_PASSWD))

        {

            Serial.println("MQTT Connected!");

        }
        else
        {
            Serial.print("MQTT Connect err:");
            Serial.println(client.state());
            delay(5000);
        }
    }
}


void mqttIntervalPost()
{
    char param[32];
    char jsonBuf[128];

    sprintf(param, "{\"Data\":\"Hello MQTT-%d\"}",t++);
    sprintf(jsonBuf, ALINK_BODY_FORMAT, param);
    Serial.println(jsonBuf);
    boolean d = client.publish(ALINK_TOPIC_PROP_POST, jsonBuf);
    Serial.println("publish:0 失败;1成功");
    Serial.println(d);
}


void setup() 
{

    //pinMode(SENSOR_PIN,  INPUT);
    /* initialize serial for debugging */
    Serial.begin(115200);
    Serial.println("Demo Start");

    wifiInit();
}


// the loop function runs over and over again forever
void loop()
{
    if (millis() - lastMs >= 5000)
    {
        lastMs = millis();
        mqttCheckConnect(); 

        /* 上报 */
        mqttIntervalPost();
    }

    client.loop();
    
}

/*    
      if (digitalRead(SENSOR_PIN) == HIGH){
        Serial.println("Motion detected!");
        delay(2000);
      }
      else {
        Serial.println("Motion absent!");
        delay(2000);
      }
*/
