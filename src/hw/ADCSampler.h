// Copied from https://github.com/christation/Arduino-Due-ADC-DMA

#ifndef ADCSAMPLER_H
#define ADCSAMPLER_H

#include <sam3xa/include/sam3x8e.h>

#include <cstdint>

namespace hw {

class ADCSampler {
public:
    static constexpr auto NUM_CHANNELS = 6;
    /* ch7:A0 ch6:A1 ch5:A2 ch4:A3 ch3:A4 ch2:A5 ch1:A6 ch0:A7, ch10:A8, ch11:A9, ch12:A10, ch13:A11 */
    static constexpr auto ADC_CHANNELS = ADC_CHER_CH0 | ADC_CHER_CH1 | ADC_CHER_CH10 | ADC_CHER_CH11 | ADC_CHER_CH12 | ADC_CHER_CH13;
    static constexpr auto NUM_SAMPLES = 1;
    static constexpr auto BUFFER_SIZE = NUM_SAMPLES*NUM_CHANNELS;
    static constexpr auto NUMBER_OF_BUFFERS = 4; /// Make this 3 or greater

    ADCSampler();
    void begin(unsigned int samplingRate);
    void end();
    void handleInterrupt();
    bool available();
    unsigned int getSamplingRate();
    const uint16_t* getFilledBuffer();
    void readBufferDone();
private:
    unsigned int sampleingRate;
    volatile bool dataReady;
    uint16_t adcBuffer[NUMBER_OF_BUFFERS][BUFFER_SIZE];
    volatile unsigned int adcDMAIndex;        //!< This hold the index of the next DMA buffer
    volatile unsigned int adcTransferIndex;   //!< This hold the last filled buffer
};

} // ns hw

#endif /* ADCSAMPLER_H */
