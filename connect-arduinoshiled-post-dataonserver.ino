#include<SPI.h> //Connect Arduino to Sheild
#include<Ethernet.h> //Ethernet Connection

int led=8;
byte mac[]={0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; //Mac address of ethernet sheild
EthernetServer server(80);
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    } else if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // no point in carrying on, so do nothing forevermore:
    while (true) {
      delay(1);
    }
  }
  server.begin();
  Serial.print("Server is at ");
  Serial.print(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if(client){
    while(client.connected()){
      if(client.available()){
        char c = client.read();
        Serial.print(c);

        if(readString.length()<100){
          readString += c;
        }

//check if new data read
        if(c=='\n'){
          Serial.print(readString);
          client.println("<HTTP/1.1 200 OK>");
          client.println("<Connection-Type: text/html>");
          client.println("<Connection: close>");
          client.println("");

          client.println("<!DOCTYPE html");
          client.println("<html><head><title>Webserver</title></head>");
          client.println("<body>");
          client.println("<a href=\"/?button1on\"\"<button>LED ON</button></a>");
          client.println("<a href=\"/?button2off\"\"<button>LED OFF</button></a>");
          client.println("<body style=background-color:powderblue>");

          delay(1);
          client.stop();

          if(readString.indexOf("?button1on")>0){
          digitalWrite(led, HIGH);  
          }
          if(readString.indexOf("?button2off")>0){
          digitalWrite(led, LOW);  
          }

          readString="";
        }
      }
    }
  }

}
