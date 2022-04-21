#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID         "*********"
#define WIFI_PASSWD       "*********"

#define PRODUCT_KEY       "Product_Key"
#define DEVICE_NAME       "Device_Name"
#define DEVICE_SECRET     "Device_secret"
#define REGION_ID         "cn-shanghai"


#define MQTT_SERVER       PRODUCT_KEY ".iot-as-mqtt." REGION_ID ".aliyuncs.com"
#define MQTT_PORT         1883
#define MQTT_USRNAME      DEVICE_NAME "&" PRODUCT_KEY


#define CLIENT_ID         "*********************"
#define MQTT_PASSWD       "*********************"

#define ALINK_BODY_FORMAT         "{\"id\":\"123\",\"version\":\"1.0\",\"method\":\"thing.event.property.post\",\"params\":%s}"
#define ALINK_TOPIC_PROP_POST     "/sys/" PRODUCT_KEY "/" DEVICE_NAME "/thing/event/property/post"


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


    client.setServer(MQTT_SERVER, MQTT_PORT);
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

    Serial.begin(115200);
    Serial.println("Demo Start");

    wifiInit();
}



void loop()
{
    if (millis() - lastMs >= 5000)
    {
        lastMs = millis();
        mqttCheckConnect(); 

        mqttIntervalPost();
    }

    client.loop();
    
}
