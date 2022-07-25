//FADED BY LIGHT PingPongCLub ESP8266 Driver. 
//based on https://www.youtube.com/watch?v=C43EWEYHBQQ wasan dev
//other resources:
///https://www.youtube.com/watch?v=VNgFbQAVboA

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
     
// wifi ssd and password
const char* ssid = "Erica terpstra'$ hotspot";
const char* password = "Roomig23";

//server hosted on the esp8266 
ESP8266WebServer server(80);
//https://tttapa.github.io/ESP8266/Chap08%20-%20mDNS.html mdns responder
MDNSResponder mdns;
     
String webPage = "";
     
int led_pin = 13;
int led_pin2 = 53;     
void setup(void){
     
  // define outputs
  pinMode(led_pin, OUTPUT);
   pinMode(led_pin2, OUTPUT);
  //default button parameter
  digitalWrite(led_pin, LOW);
    digitalWrite(led_pin2, LOW);

  //serial connectopn for serial monitor
  Serial.begin(115200); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  //making the web page TODO: include as "Weblogic.h"
   webPage += "<body style=background-color:powderblue;>";
   webPage += "<h1>ESP8266 Web Server</h1>";
   webPage += "<p>LED state <a href=\"LedON\"><button>ON</button></a>&nbsp;<a href=\"LedOFF\"><button>OFF</button></a></p>";
   webPage += "<br>";      
   webPage += "<p>Smoke state <a href=\"SmokeON\"><button>ON</button></a>&nbsp;<a href=\"SmokeOFF\"><button>OFF</button></a></p>";

  // initialize wifi 
  WiFi.begin(ssid, password);
  Serial.println("");
     

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");  //
  Serial.println(ssid);
  Serial.print("IP address: ");  //
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
     
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
  
  server.on("/LedON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, HIGH);
    Serial.println("[ON]");
    delay(1000);
  });
  
  server.on("/LedOFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });
     server.on("/SmokeON", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin2, HIGH);
    Serial.println("[SMOKEON]");
    delay(1000);
  });
  
    server.on("/SmokeOFF", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin2, LOW);
    Serial.println("[SMOKEOFF]");
    delay(1000);
  });
  
 

    server.on("/Led?????", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(led_pin, LOW);
    Serial.println("[OFF]");
    delay(1000);
  });
  
  server.begin();
  Serial.println("HTTP server started");
  
}
     
void loop(void){
  server.handleClient();
}




  // board information
  /*
  Serial.println("");
  Serial.println("ESP8266 board info:");
  Serial.print("\tChip ID: ");
  Serial.println(ESP.getFlashChipId());
  Serial.print("\tCore Version: ");
  Serial.println(ESP.getCoreVersion());
  Serial.print("\tChip Real Size: ");
  Serial.println(ESP.getFlashChipRealSize());
  Serial.print("\tChip Flash Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("\tChip Flash Speed: ");
  Serial.println(ESP.getFlashChipSpeed());
  Serial.print("\tChip Speed: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("\tChip Mode: ");
  Serial.println(ESP.getFlashChipMode());
  Serial.print("\tSketch Size: ");
  Serial.println(ESP.getSketchSize());
  Serial.print("\tSketch Free Space: ");
  Serial.println(ESP.getFreeSketchSpace());

  // แสดงบนหน้าเว็บ
  webPage += "<h1>ESP8266 Web Server</h1>";
  webPage += "<p>Chip ID: ";
  webPage += ESP.getFlashChipId();
  webPage += "</p>";
  webPage += "<p>Core Version: ";
  webPage += ESP.getCoreVersion();
  webPage += "</p>";
  webPage += "<p>Chip Real Size: ";
  webPage += ESP.getFlashChipRealSize()/1024;
  webPage += " Kbit</p>";
  webPage += "<p>Chip Size: ";
  webPage += ESP.getFlashChipSize()/1024;
  webPage += " Kbit</p>";
  webPage += "<p>Chip Flash Speed: ";
  webPage += ESP.getFlashChipSpeed()/1000000;
  webPage += " MHz</p>";
  webPage += "<p>Chip Work Speed: ";
  webPage += ESP.getCpuFreqMHz();
  webPage += " MHz</p>";
  webPage += "<p>Chip Mode: ";
  webPage += ESP.getFlashChipMode();
  webPage += "</p>";
  webPage += "<p>LED state <a href=\"LedON\"><button>ON</button></a>&nbsp;<a href=\"LedOFF\"><button>OFF</button></a></p>";
*/
