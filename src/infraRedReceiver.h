#ifndef IR_RECEIVER_H
#define IR_RECEIVER_H

#include <IRremote.h>

class InfraRedReceiver{
  private:
    IRrecv receiver;
    decode_results receiverResult;
  public:
    // Constructor
    // Methods
    // Destructor
};

  if (receiver.decode(&receiverResult)) {
    Serial.println(receiverResult.value, HEX);
    receiver.resume();
  }
#endif
