#ifndef CIRCULARBUFFER_HPP_INCLUDED
#define CIRCULARBUFFER_HPP_INCLUDED

#include <stdint.h>

class CircularBuffer
{
public:
    /* Construct circular buffer with predetermined size */
    CircularBuffer(uint32_t buffsize);
    ~CircularBuffer();

    /* Insert an item to buffer, return false if fail due to buffer fail */
    bool push(uint8_t inputValue);
    /* Get an item from buffer, return false if buffer is empty. Item is returned via outputValue */
    bool pop(uint8_t* outputValue);
    /* Clear the buffer */
    void clear();
    /* Return the buffer size */
    uint32_t size();
    /* Return the number of items saved in buffer */
    uint32_t count();

private:
    uint8_t* m_buff;
    uint32_t m_head;
    uint32_t m_tail;
    uint32_t m_count;
    uint32_t m_size;
};


#endif // CIRCULARBUFFER_HPP_INCLUDED
